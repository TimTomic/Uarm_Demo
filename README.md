# uArm ROS 2 Pick & Place Demos (Raspberry Pi 5)

Diese Anleitung beschreibt, wie das komplette ROS 2 Projekt (uArm Treiber + AprilTag Kamera + State Machine / Action Server) auf einem **Raspberry Pi 5** innerhalb eines Docker-Containers gestartet wird.

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
