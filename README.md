# uArm ROS 2 Pick & Place System (Raspberry Pi 5)

Diese Anleitung beschreibt das komplette ROS 2 Projekt:
**uArm Treiber + AprilTag Kamera + Arm Controller + Brain (Task Planner & Manager)** – alles auf einem Raspberry Pi 5 innerhalb eines Docker-Containers.

---

## Systemübersicht: Das Brain

Das **Brain** (`uarm_brain`) ist die zentrale Intelligenz des Systems. Es liest `.bag`-Dateien mit Aufgabenlisten, plant die optimale Reihenfolge und steuert Arm und Kamera.

### Architektur

```
┌─────────────────────────────────────────────────────────┐
│                     uArm Brain                          │
│                                                         │
│  .bag Datei ──► [TaskPlannerNode]                       │
│                   • Liest Bag (ROS1 + ROS2)             │
│                   • Greedy-Gruppierung nach Workstation  │
│                   • Inventar-Limit (max. 3 Objekte)     │
│                   • Publiziert /brain/task_queue (JSON)  │
│                         │                               │
│                 [TaskManagerNode]                        │
│                   • State Machine                        │
│                   • 3-Slot Inventar-Verwaltung          │
│                   • Sucht Objekte per AprilTag-TF        │
└──────────┬──────────────────────────────┬───────────────┘
           │                              │
           ▼                              ▼
  /drive_to_pose                /pick_and_place
  (DriveToPose Action)          (PickAndPlace Action)
           │                              │
           └──────────┬───────────────────┘
                      ▼
          [ArmControllerNode]  (C++, uarm_arm_controller)
              • Steuert Arm-Positionen
              • Limit-Switch Handling
              • Pump an/aus
```

### Scan-Strategie

Der Brain sucht jedes Zielobjekt in 3 Posen:
1. **SCAN** (Mitte) – Standardposition
2. **SCAN_LEFT** – links schwenken
3. **SCAN_RIGHT** – rechts schwenken
4. → Objekt nicht gefunden: Task **überspringen**, nächstes Objekt

### Inventar

Der Roboter kann bis zu **3 Objekte gleichzeitig** transportieren. Die Koordinaten der 3 Inventar-Slots sind in `brain_config.yaml` konfigurierbar (in mm, relativ zum Arm-Ursprung).

---

## Packages Übersicht

| Package | Beschreibung |
|---------|-------------|
| `uarm_driver` | Treiber für den uArm Swift Pro (Serial) |
| `apriltag_launcher` | USB-Kamera + AprilTag Erkennung |
| `uarm_arm_controller` | **C++ Arm Controller** mit `pick_and_place` + `drive_to_pose` Actions |
| `uarm_brain` | **Brain**: Task Planner + Task Manager |
| `uarm_interfaces` | Action-Definitionen für alle Komponenten |

---

## System Starten (Multi-Container Architektur)

Das System besteht aus **mehreren strikt voneinander getrennten Docker-Containern**, die über ein eigenes ROS 2 Netzwerk (`uarm_ros_net`) miteinander kommunizieren. 
Dies ermöglicht höchste Stabilität: Falls ein Container abstürzt (z.B. Kamera-Disconnect), startet er sich automatisch neu; das Brain wartet derweil selbstständig, bis die Action-Server wieder verfügbar sind.

### 1. Netzwerk erstellen (Einmalig)
Bevor die Container gestartet werden können, muss das Docker-Netzwerk angelegt werden:
```bash
docker network create uarm_ros_net
```

### 2. Images Bauen & Starten
Wechsle in den `docker/`-Ordner und starte das gesamte Roboter-System:
```bash
cd docker
docker compose up -d
```
Dies startet alle notwendigen Nodes vollautomatisch im Hintergrund:
- **vision**: Kamera & AprilTag Erkennung (inkl. Web-Viewer auf Port 8080)
- **manipulator**: Arm Controller & SwiftPro Treiber
- **brain**: Task Planner & Task Manager (startet ohne Initial-Task)
- **discovery_server**: Zentrale Kommunikations-Bridge für ROS 2
- **nav**: Platzhalter für zukünftige Navigation

### 3. Einzelne Container steuern
Du kannst Container auch einzeln neustarten oder deren Logs live anschauen:
```bash
docker compose logs -f brain
docker compose restart vision
```

### 4. Remote Visualisierung (RViz) & Fernsteuerung
Es gibt einen dedizierten **Operator Container**, der direkt auf deinem Laptop/PC ausgeführt wird. Er zeigt RViz an und ermöglicht die Steuerung per PS5-Controller.

**Voraussetzung (WSL/Linux):** Erlaube Docker den Zugriff auf den X-Server:
```bash
# Auf dem Host ausführen:
xhost +local:docker
```

**Starten des Operators:**
```bash
# Im docker/ Ordner deines Laptops:
docker compose -f operator-compose.yml up -d
```
RViz öffnet sich nun mit dem vorkonfigurierten uArm-Setup (TF-Tree, Live-Kamera, Roboter-Modell).

---

## Brain & Aufgaben (BAG-Dateien)

Das Brain wartet nach dem Start auf eine Aufgabenliste. Diese wird typischerweise aus einer `.bag`-Datei geladen.

### Aufgabe zur Laufzeit laden (Action Server)
Du kannst dem laufenden Roboter jederzeit eine neue Aufgabe schicken.

Das **Beispiel-Bag** für den empfohlenen Testlauf liegt **im Repository** unter  
`Example BAG FIles/test_03_bag2/`. Durch das Volume-Mapping in der
`docker-compose.yml` wird dieses Verzeichnis im `uarm_brain`‑Container nach  
`/home/ros2/ros2_ws/Example BAG FIles/test_03_bag2/` gemountet – genau auf
den Pfad, der im folgenden Befehl verwendet wird.

**Beispiel: Tag 03 Test-Lauf (empfohlener Befehl)**
```bash
docker exec uarm_brain bash -lc \
  "source /opt/ros/jazzy/setup.bash && \
   source /home/ros2/ros2_ws/install/setup.bash 2>/dev/null || true; \
   ros2 action send_goal /brain/load_bag uarm_interfaces/action/LoadBag \"{bag_path: '/home/ros2/ros2_ws/Example BAG FIles/test_03_bag2/'}\""
```

Falls du eine Fehlermeldung wie **`ros2: command not found`** siehst, fehlt das Sourcen von `/opt/ros/jazzy/setup.bash`. Der obige Befehl erledigt das automatisch im Container.

### Aufgabe direkt beim Start laden
Falls du das Brain mit einer festen Aufgabe starten möchtest, ändere den Befehl in der `docker-compose.yml`:
```yaml
command: bash -c "... ros2 launch uarm_brain brain_standalone.launch.py bag_file:='/home/ros2/ros2_ws/Example BAG Files/test_03_bag2/'"
```

### Manueller Bag-Test (Status prüfen)
Überprüfe den Fortschritt der Aufgabe auf den Status-Topics:
```bash
# Was plant das Brain gerade?
docker exec uarm_brain ros2 topic echo /brain/status

# Was ist im Inventar?
docker exec uarm_brain ros2 topic echo /brain/inventory
```

---

## Konfiguration

### Brain Konfiguration: `uarm_brain/config/brain_config.yaml`

```yaml
brain_node:
  ros__parameters:
    nav_stub_delay: 3.0          # Sekunden warten beim Workstation-Wechsel (NAV-Stub)
    vision_timeout: 10.0         # Sekunden auf Tag warten pro Scan-Pose
    dry_run: false

    # 3 Inventar-Slots (X, Y, Z in mm)
    inventory_slot_0_x: 150.0
    inventory_slot_0_y: -120.0
    inventory_slot_0_z: 0.0
    # ... slot 1, slot 2 analog
```

### Arm-Posen: `uarm_arm_controller/config/poses.yaml`

Hier werden alle benannten Posen definiert. Das Brain nutzt folgende Pose-Namen:

| Pose-Name | Beschreibung |
|-----------|-------------|
| `SCAN` | Mittlere Scan-Position |
| `SCAN_LEFT` | Scan links (breiterer Suchbereich) |
| `SCAN_RIGHT` | Scan rechts (breiterer Suchbereich) |
| `DRIVE` | Fahrt-/Reiseposition |
| `DROP` | Ablage-Zielposition für Place-Tasks |
| `INVENTORY` | Inventar-Ablage (wird intern genutzt) |

> **Tipp:** Nutze `teach_position.py` aus dem `uarm_arm_controller`-Package, um Posen einzuteachen.

### AprilTag → Objekt Mapping: `uarm_brain/config/object_tags.yaml`

```yaml
object_tag_map:
  F20_20_B:  11   # AprilTag ID = Object-ID aus dem Bag
  M20_100:   15
  M20:       16
  # ... alle Objekte
```

---

## BAG-Datei Format

Die Brain-Bag-Datei muss auf Topic `/task_list` eine `std_msgs/String`-Nachricht mit JSON-Inhalt enthalten:

```json
[
  {
    "Subtask-Type": 10, "Subtask-Name": "Pick",
    "Workstation-Name": "WS07", "Workstation-Height": "5cm",
    "Workstation-Type": 1, "Object-ID": 11,
    "Object-name": "F20_20_B", "Container-ID": 0
  },
  {
    "Subtask-Type": 20, "Subtask-Name": "Place",
    "Workstation-Name": "WS08", "Workstation-Height": "5cm",
    "Workstation-Type": 1, "Object-ID": 11,
    "Object-name": "F20_20_B", "Container-ID": 0
  }
]
```

**Subtask-Typen:**

| Typ | Name |
|-----|------|
| 10 | Pick |
| 11 | Pick_Shelf |
| 12 | Pick_Moving |
| 20 | Place |
| 21 | Place_Shelf |
| 22 | Place_Precise |
| 23 | Place_Container |

> **ROS1 Bags:** Die `rosbags` Library wird benötigt. Einmalig im Container installieren:
> ```bash
> pip install rosbags
> ```

---

## Offline Planner-Test (ohne Hardware/ROS2)

```bash
# Alle 3 Tests müssen grün sein:
python3 src/uarm_brain/test/dry_run_test.py --csv

# Mit echter Bag-Datei (nur Planer-Logik, kein ROS nötig):
python3 src/uarm_brain/test/dry_run_test.py \
  --bag "/path/to/BTT2.bag" --topic "/task_list"
```

---



## 1. Vorbereitung auf dem Raspberry Pi (Host)

### 1.1 Docker installieren
Verbinde dich per SSH auf deinen Pi und installiere Docker (falls noch nicht geschehen):
```bash
curl -sSL https://get.docker.com | sh
sudo usermod -aG docker $USER
```
*Nach diesem Befehl abmelden und neu anmelden (oder Pi neustarten), damit die Gruppenrechte greifen!*

### 1.2 USB-Geräte überprüfen
Schließe deinen uArm und die USB-Kamera an den Pi an. Prüfe, ob sie erkannt werden:
```bash
ls /dev/ttyUSB*   # Sollte z.B. /dev/ttyUSB0 ausgeben
ls /dev/video*    # Sollte z.B. /dev/video0 ausgeben
```

---

## 2. Docker Container starten (mit Docker Compose)

Wir verwenden eine vorbereitete `docker-compose.yml`, die das offizielle ROS 2 Jazzy Image baut und alle Rechte sowie den Workspace automatisch mappt.

```bash
# Wechsle in den Docker-Ordner deines Workspaces
cd ~/ros2_ws/docker

# Baue das Image und starte den Container im Hintergrund
docker-compose up -d --build
```
> **Info:** Docker Compose mappt `/dev` komplett durch (Kamera `/dev/video0` und Arm `/dev/ttyUSB0`) und mountet deinen `ros2_ws`-Ordner sicher in den Container (ohne Root-Rechte-Probleme).

---

## 3. Workspace im Container aufbauen

Klinke dich nun in den laufenden Container ein:

```bash
docker exec -it uarm_demo_container bash
```

Dort startest du automatisch im gemappten Container-Verzeichnis `/home/ros2/ros2_ws`. Kompiliere den Code:

```bash
colcon build --symlink-install
```

---

## 4. Kamera-Kalibrierung (WICHTIG für exaktes 3D-Greifen!)

Damit die AprilTags nicht nur als Pixel, sondern in exakten 3D-Koordinaten vom Roboter gegriffen werden können, **muss** die Kamera einmalig kalibriert werden.

1. **Öffne 2 Terminals im Container:**
   ```bash
   # Host: Neues Terminal öffnen und in den laufenden Container einklinken
   docker exec -it uarm_demo_container bash
   ```
2. **Kamera starten (Terminal 1):**
   ```bash
   source /home/ros2/ros2_ws/install/setup.bash
   ros2 launch apriltag_launcher apriltag_usb_cam.launch.py
   ```
3. **Kalibrierer starten (Terminal 2):**
   Drucke ein [Standard OpenCV Schachbrettmuster](https://docs.opencv.org/2.4/_downloads/pattern.png) (z.B. 8x6 Quadrate à 25mm) auf feste Pappe (100% Skalierung!).
   ```bash
   source /opt/ros/jazzy/setup.bash
   ros2 run camera_calibration cameracalibrator --size 8x6 --square 0.025 --ros-args -r image:=/camera/image_raw -r camera:=/camera
   ```
4. Bewege das Muster vor der Kamera (links, rechts, drehen, neigen). Klicke **"Calibrate"**, dann **"Save"** und **"Commit"**, sobald die Buttons grün werden. Starte danach den Kamera-Launch neu.

---

## 5. Demos Ausführen

Wir bieten zwei Varianten der Pick & Place Logik an. Da der Pi headless (ohne GUI) läuft, unterdrücken wir das Starten von Rviz mit `use_rviz:=false`.

### Variante A: Automatische Loop Demo
Diese Demo scannt ununterbrochen nach Tags, hebt sie an und legt sie an einer definierten Ablage ab.
```bash
# Im Docker Container ausführen:
source /home/ros2/ros2_ws/install/setup.bash
ros2 launch uarm_apriltag_demo demo.launch.py use_rviz:=false
```

### Variante B: ROS 2 Action Server Demo (Pick & Place auf Kommando)
Diese moderne Implementierung öffnet einen Action-Server. Der Arm fährt erst los, wenn er einen expliziten Befehl (`Pick` oder `Place`) erhält. Der Arm nutzt dabei immer den **Limit Switch** für ein haargenaues, gefedertes Aufsetzen!

**Terminal 1 (Server Starten):**
```bash
source /home/ros2/ros2_ws/install/setup.bash
ros2 launch uarm_apriltag_demo action_demo.launch.py use_rviz:=false
```
*Der Arm geht in Lauerstellung (Drive) und wartet auf dein Kommando.*

**Terminal 2 (Kommandos schicken):**
Öffne ein weiteres Container-Terminal und sende Goals an den Action Server:

**Befehl Pick:**
*(Arm sucht bis zu 30s nach einem AprilTag, hebt ihn auf, legt ihn ins Inventar ab und fährt in Startposition)*
```bash
source /home/ros2/ros2_ws/install/setup.bash
ros2 action send_goal /uarm_action uarm_interfaces/action/PickPlace "{command: 'pick'}"
```

**Befehl Place:**
*(Arm greift den Block aus dem Inventar auf und transportiert ihn zur Ablage-Zielposition)*
```bash
source /home/ros2/ros2_ws/install/setup.bash
ros2 action send_goal /uarm_action uarm_interfaces/action/PickPlace "{command: 'place'}"
```

---

## 6. Remote Visualisierung (von deinem PC aus)

Da ROS 2 über DDS kommuniziert, kannst du den Roboter von deinem eigenen Laptop / PC aus via WLAN beobachten, ohne X11-Forwarding nutzen zu müssen:

1. Lass die Demo auf dem Pi (wie oben beschrieben mit `use_rviz:=false`) laufen.
2. Verbinde PC und Pi ins selbe WLAN.
3. Öffne auf deinem Windows-PC (in deinem nativen WSL, nicht über SSH) ein Terminal:
   ```bash
   source ~/ros2_ws/install/setup.bash
   ros2 run rviz2 rviz2 -d ~/ros2_ws/src/uarm_apriltag_demo/rviz/demo.rviz
   ```
Du siehst sofort, flüssig und ohne Verzögerung den TF-Tree und den live Kamera-Stream (inkl. eingezeichneter Tag-Koordinaten) deines Raspberry Pis!

---

## 7. Konfiguration und "Teachen" von Posen (NEU!)

Das gesamte Verhalten, alle Posen und die Greif-Abstände sind nun zentral in einer einzigen Datei ausgelagert. Keine Zahlen mehr im Code selbst suchen!

Hier findest du die Datei:
`~/ros2_ws/src/uarm_apriltag_demo/config/demo_config.yaml`

### Was du dort einstellen kannst:
1. **Kamera-Offset (`camera_x_offset`, `camera_y_offset`, `camera_z_offset`)**: 
   Liefert dem TF-Tree den exakten Abstand der Kamera-Linse zum `tcp_link`. Hier kannst du korrigieren, falls der Roboter systematisch immer z.B. 1cm neben das Tag greift.
2. **Alle Posen (`pose_drive`, `pose_scan`, `pose_inv`, `pose_drop`)**: 
   Definieren die fixen Stationen der Bewegung in Millimetern. Stelle den Arm per Hand (z.B. in der uArm Studio Software oder über dein RViz Tool) dorthin, wo er sein soll, lies die Koordinaten ab und trage sie hier ein!
3. **`hover_z_offset`**:
   Der Roboter rast nicht direkt auf das Ziel, sondern fährt genau diesen Betrag (in mm) *darüber*. Erst danach beginnt er sicher abzusteigen, bis der Schalter auslöst.
4. **`target_z_base`**:
   Gibt die Tischhöhe für Inventar und Ablage vor. Ist standardmäßig `0.0`, da der Schalter sowieso abfedert.

**Nach einer Änderung der YAML-Datei:**
Da das System aktuell als Symlink installiert ist, erkennt ROS Änderungen meist sofort beim nächsten Neustart der `.launch.py`. Falls nicht, baue das Setup kurz neu:
```bash
colcon build --symlink-install --packages-select uarm_apriltag_demo
```
