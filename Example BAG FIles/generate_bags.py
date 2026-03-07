import csv
import sys
import random
from enum import IntEnum

class WorkstationType(IntEnum):
    UNKNOWN = 0
    KNOWN = 1
    SCANNED = 2
    GROUND = 0
    TABLE = 1
    ROTATING_TABLE = 2
    PRECISE_PLACE = 3
    SHELF = 4
    ARBITRARY = 5
    SHOP_SHELF = 6
    SHOP_BOX = 7



# Kombinierte Struktur mit Typ und Zusatzangabe (z. B. cm-Höhe)
workstations = {
    "WS01": (WorkstationType.TABLE, "10cm"),
    "WS02": (WorkstationType.TABLE, "5cm"),
    "WS03": (WorkstationType.TABLE, "10cm"),
    "WS04": (WorkstationType.TABLE, "5cm"),
    "WS05": (WorkstationType.TABLE, "10cm"),
    "WS06": (WorkstationType.GROUND, "0cm"),
    "WS07": (WorkstationType.GROUND, "0cm"),
    "WS08": (WorkstationType.TABLE, "10cm"),
    "WS09": (WorkstationType.TABLE, "10cm"),
    "WS10": (WorkstationType.TABLE, "10cm"),
    "WS11": (WorkstationType.TABLE, "15cm"),
    "SH01": (WorkstationType.SHELF, "Shelve"),
    "RT01": (WorkstationType.ROTATING_TABLE, "Rotating Table"),
    "PP01": (WorkstationType.PRECISE_PLACE, "Precise Placement Table")
}

class SubtaskType(IntEnum):
    WAIT = 0
    PICK = 10
    PICK_SHELF = 11
    PICK_MOVING = 12
    PLACE = 20
    PLACE_SHELF = 21
    PLACE_PRECISE = 22
    PLACE_CONTAINER = 23
    MOVE_NAV = 30
    MOVE_APPROACH = 31
    DETECT = 40
    DETECT_MOVING = 41
    OBSERVE = 50
    CREATE_MATCHES = 51

object_id_to_name = {
    # Basic Set
    11: "F20_20_B", # grey small aluminum profile
    12: "F20_20_G",
    13: "S40_40_B",
    14: "S40_40_G",
    15: "M20_100",
    16: "M20",
    17: "M30",

    # Advanced Set
    20: "Axis2",
    21: "Bearing2",
    22: "Housing",
    23: "Motor2",
    24: "Spacer",
    25: "Screwdriver",
    26: "Wrench",
    27: "Drill",
    28: "AllenKey",
}

container_ids = {
    "red": 40,
    "blue": 41
}

# Objektgruppen (für Wiederverwendung in allen Tests)
basic_objects = [11, 12, 13, 14, 15, 16, 17]
advanced_objects = [20, 21, 22, 23, 24, 25, 26, 27, 28]

# Spezifische Sets für Tests
bmt_objects = [11, 15, 16]

# rockin? cavity?

class TaskPlanner:
    # This class is used to plan tasks for the robot and manage the workstations. Its used to make sure that there is never the possibility that the robots tries to place 4 objects on a workstation
    def __init__(self, workstations, max_ws_load=3, max_robot_load=3):
        self.workstations = workstations
        self.max_ws_load = max_ws_load
        self.max_robot_load = max_robot_load

        self.ws_loads = {name: 0 for name in workstations}
        self.tasks = []

    def can_place(self, ws):
        return self.ws_loads[ws] < self.max_ws_load

    def can_pick(self, ws):
        return self.ws_loads[ws] > 0

    def add_task(self, subtask_type, ws_name, obj_id, container_id=0):
        ws_type, ws_height = self.workstations[ws_name]
        self.tasks.append({
            "Subtask-Type": subtask_type,
            "Subtask-Name": subtask_type.name.capitalize(),
            "Workstation-Name": ws_name,
            "Workstation-Height": ws_height,
            "Workstation-Type": ws_type,
            "Object-ID": obj_id,
            "Object-name": object_id_to_name.get(obj_id, "Unknown"),
            "Container-ID": container_id
        })

        # Update WS load
        if subtask_type in [SubtaskType.PLACE, SubtaskType.PLACE_SHELF, SubtaskType.PLACE_PRECISE, SubtaskType.PLACE_CONTAINER]:
            self.ws_loads[ws_name] += 1
        elif subtask_type in [SubtaskType.PICK, SubtaskType.PICK_SHELF, SubtaskType.PICK_MOVING]:
            self.ws_loads[ws_name] = max(0, self.ws_loads[ws_name] - 1)

    def write_csv(self, filename):
        with open(filename, mode="w", newline="") as file:
            writer = csv.DictWriter(file, fieldnames=[
                "Subtask-Type", "Subtask-Name", "Workstation-Name",
                "Workstation-Height", "Workstation-Type", "Object-ID",
                "Object-name", "Container-ID"
            ])
            writer.writeheader()
            for task in self.tasks:
                writer.writerow(task)



# Choose Test
# 1. BMT:  3 objects (11, 15 and 16), 2 Workstations next to each other 
# 2. BTT1: 4 objects from basic set (11-17), 3 Workstations, Table height 10cm
# 3. BTT2: 5 objects, 2 decoys, 4 workstations, all 4 table heights (1 blocking, 1 1/2 blocking obstacle)
# 4. ATT1: 6 objects, 3 decoys, 3 workstations, 1 shelve (place on top), ppt 
#          (barriertape 1 blocking, 1 non-blocking, 2 arbitraty surface)
# 5. ATT2: 7 objects, 5 decoys, 6 workstations (4 tables, 1 shelf (pick lower), 1 rotating table (pick))
#          all table heights, 2 objects in container (1 red, 1 blue), 1 visual + 1 physical obstacle (semi-blocking),
#          3 arbitrary surfaces
# 6. Final: 10 objects, 8 decoys, 8 workstations (4 tables, 2 shelfs (pick lower + place top), 
#          1 rotating table (pick 2), 1 ppt (place 2)), all table heights, 4 objects in container 
#          (2 red, 2 blue), 2 visual + 2 physical obstacles (2 blocking, 1 semi-blocking, 1 non-blocking),
#          4 arbitrary surfaces

def choose_test():
   tests = {
      "bmt": "BMT: 3 objects (11, 15 and 16), 2 Workstations next to each other",
        "btt1": "BTT1: 4 objects from basic set (11-17), 3 Workstations, Table height 10cm",
        "btt2": "BTT2: 5 objects, 2 decoys, 4 workstations, all 4 table heights (1 blocking, 1 1/2 blocking obstacle)",
        "att1": "ATT1: 6 objects, 3 decoys, 3 workstations, 1 shelve (place on top), ppt "
                "(barriertape 1 blocking, 1 non-blocking, 2 arbitrary surface)",
        "att2": "ATT2: 7 objects, 5 decoys, 6 workstations (4 tables, 1 shelf (pick lower), 1 rotating table (pick)), "
                "all table heights, 2 objects in container (1 red, 1 blue), 1 visual + 1 physical obstacle (semi-blocking), "
                "3 arbitrary surfaces",
        "final": "Final: 10 objects, 8 decoys, 8 workstations (4 tables, 2 shelfs (pick lower + place top), "
                 "1 rotating table (pick 2), 1 ppt (place 2)), all table heights, 4 objects in container "
                 "(2 red, 2 blue), 2 visual + 2 physical obstacles (2 blocking, 1 semi-blocking, 1 non-blocking), "
                 "4 arbitrary surfaces"
   }

   test_key = input("Enter test name (bmt, btt1, btt2, att1, att2, final)").strip().lower()
   
   if test_key in tests:
      print(f"\nYou selected: {tests[test_key]}")
      return tests[test_key]
   else:
      print("Invalid name.")
      return choose_test()
   
# BMT: 3 objects (11, 15 and 16), 2 Workstations next to each other
def generate_bmt_bag(filename="bmt_bag.csv"):
    objects = bmt_objects  # [11, 15, 16]

    # Filtere nur WS (keine Shelves oder Sonderstationen)
    sorted_ws = sorted(
        [(name, height) for name, height in workstations.items() if name.startswith("WS")],
        key=lambda x: int(x[0][2:])  # sortiere numerisch nach WS-Nummer
    )

    # Suche benachbarte Workstations mit gleicher Höhe
    
    valid_pairs = []
    for i in range(len(sorted_ws) - 1):
        ws1, (type1, height1) = sorted_ws[i]
        ws2, (type2, height2) = sorted_ws[i + 1]
        if type1 == type2 and height1 == height2:
            valid_pairs.append((ws1, ws2))

    if not valid_pairs:
        print("❌ No valid workstation pairs with matching height found.")
        return

    from_ws, to_ws = random.choice(valid_pairs)

    # Schreibe CSV-Datei
    with open(filename, mode="w", newline="") as file:
        writer = csv.writer(file)
        writer.writerow([
            "Subtask-Type", "Subtask-Name", "Workstation-Name", "Workstation-Height",
            "Workstation-Type", "Object-ID", "Object-name", "Container-ID"
        ])
        for obj in objects:
            writer.writerow([
                SubtaskType.PICK, "Pick", from_ws, workstations[from_ws][1],
                workstations[from_ws][0], obj, object_id_to_name.get(obj, "Unknown"), 0
            ])
            writer.writerow([
                SubtaskType.PLACE, "Place", to_ws, workstations[to_ws][1],
                workstations[to_ws][0], obj, object_id_to_name.get(obj, "Unknown"), 0
            ])

    print(f"✅ BMT bag written to {filename} with:")
    print(f"   Objects: {objects}")

# BTT1: 4 objects from basic set (11-17), 3 Workstations, Table height 10cm
def generate_btt1_bag(filename="btt1_bag.csv"):
    objects = random.sample(basic_objects, 4)

    valid_ws = [name for name, (typ, height) in workstations.items()
                if name.startswith("WS") and typ == WorkstationType.TABLE and height == "10cm"]
    if len(valid_ws) < 3:
        print("❌ Not enough 10cm TABLEs.")
        return

    selected_ws = random.sample(valid_ws, 3)
    planner = TaskPlanner({ws: workstations[ws] for ws in selected_ws})

    for obj in objects:
        # Finde gültigen Zieltisch (to_ws)
        possible_places = [ws for ws in selected_ws if planner.can_place(ws)]
        if not possible_places:
            print("❌ All workstations full for placing.")
            break
        to_ws = random.choice(possible_places)

        # Wähle FROM: ≠ TO und (wenn möglich) mit Objekt zum Abholen
        possible_picks = [ws for ws in selected_ws if ws != to_ws and planner.can_pick(ws)]
        if not possible_picks:
            possible_picks = [ws for ws in selected_ws if ws != to_ws]
        from_ws = random.choice(possible_picks)

        # Register Tasks
        planner.add_task(SubtaskType.PICK, from_ws, obj)
        planner.add_task(SubtaskType.PLACE, to_ws, obj)

    planner.write_csv(filename)
    print(f"✅ BTT1 written to {filename}")



# BTT2: 5 objects, 2 decoys, 4 workstations, all 4 table heights (1 blocking, 1 1/2 blocking obstacle)
def generate_btt2_bag(filename="btt2_bag.csv"):
    objects = random.sample(basic_objects, 5)

    # Zielhöhen mit genau einem passenden Typ
    required_heights = {
        "0cm": WorkstationType.GROUND,
        "5cm": WorkstationType.TABLE,
        "10cm": WorkstationType.TABLE,
        "15cm": WorkstationType.TABLE
    }

    # Wähle pro Höhe eine gültige Workstation
    height_ws_map = {}
    for height, ws_type in required_heights.items():
        candidates = [
            name for name, (typ, h) in workstations.items()
            if typ == ws_type and h == height
        ]
        if not candidates:
            print(f"❌ No workstation found for height {height} with type {ws_type.name}.")
            return
        height_ws_map[height] = random.choice(candidates)

    selected_ws = list(height_ws_map.values())
    planner = TaskPlanner({ws: workstations[ws] for ws in selected_ws})

    # Initialverteilung: Nutze jede WS einmal garantiert
    used_ws = selected_ws.copy()
    random.shuffle(used_ws)
    obj_cycle = objects[:len(used_ws)]

    for i, ws in enumerate(used_ws):
        obj = obj_cycle[i]
        # Wähle anderes WS als Quelle/Ziel
        other_ws = [w for w in selected_ws if w != ws]
        from_ws = random.choice(other_ws)
        to_ws = ws

        planner.add_task(SubtaskType.PICK, from_ws, obj)
        planner.add_task(SubtaskType.PLACE, to_ws, obj)

    # Restliche Objekte zufällig, unter Beachtung der Limits
    for obj in objects[len(used_ws):]:
        possible_places = [ws for ws in selected_ws if planner.can_place(ws)]
        if not possible_places:
            print("❌ All workstations full (place).")
            break
        to_ws = random.choice(possible_places)

        possible_picks = [ws for ws in selected_ws if ws != to_ws and planner.can_pick(ws)]
        if not possible_picks:
            possible_picks = [ws for ws in selected_ws if ws != to_ws]
        from_ws = random.choice(possible_picks)

        planner.add_task(SubtaskType.PICK, from_ws, obj)
        planner.add_task(SubtaskType.PLACE, to_ws, obj)

    planner.write_csv(filename)
    print(f"✅ BTT2 bag written to {filename}")
    print(f"   Used WS (with heights): {height_ws_map}")

# ATT1: 6 objects, 3 decoys, 3 workstations, 1 shelve (place on top), ppt

def generate_att1_bag(filename="att1_bag.csv"):
    objects = random.sample(basic_objects, 6)

    # === 1. Wähle 3 normale Workstations (beliebige Höhen + Typ TABLE/GROUND erlaubt)
    candidate_ws = [
        (name, data) for name, data in workstations.items()
        if name.startswith("WS") and data[0] in [WorkstationType.TABLE, WorkstationType.GROUND]
    ]

    if len(candidate_ws) < 3:
        print("❌ Not enough table/ground workstations.")
        return

    selected_table_ws = random.sample(candidate_ws, 3)

    # === 2. Shelf finden
    shelf_ws = [name for name, (typ, _) in workstations.items() if typ == WorkstationType.SHELF]
    if not shelf_ws:
        print("❌ No shelf workstation available.")
        return
    shelf = random.choice(shelf_ws)

    # === 3. PPT finden
    ppt_ws = [name for name, (typ, _) in workstations.items() if typ == WorkstationType.PRECISE_PLACE]
    if not ppt_ws:
        print("❌ No precise placement table (PPT) available.")
        return
    ppt = random.choice(ppt_ws)

    # === 4. Final Workstation-Auswahl
    all_ws = selected_table_ws + [(shelf, workstations[shelf]), (ppt, workstations[ppt])]
    selected_ws_names = [ws[0] for ws in all_ws]
    planner = TaskPlanner({ws: workstations[ws] for ws in selected_ws_names})

    # === 5. Verteilen der Objekte
    for i, obj in enumerate(objects):
        # Jedes Objekt bekommt:
        #   - Pick: eine WS ≠ Ziel
        #   - Place: eine WS (kann Shelf, Tisch oder PPT sein)

        # Zielwahl: 2 gehen auf Shelf, 2 auf PPT, Rest auf Workstations
        if i < 2:
            to_ws = shelf
            place_type = SubtaskType.PLACE_SHELF
        elif i < 4:
            to_ws = ppt
            place_type = SubtaskType.PLACE_PRECISE
        else:
            available = [ws[0] for ws in selected_table_ws if planner.can_place(ws[0])]
            if not available:
                print("❌ No free table-like workstations for placement.")
                break
            to_ws = random.choice(available)
            place_type = SubtaskType.PLACE

        # Pick von anderer Station
        other_ws = [ws for ws in selected_ws_names if ws != to_ws]
        possible_picks = [ws for ws in other_ws if planner.can_pick(ws)]
        if not possible_picks:
            possible_picks = [ws for ws in other_ws]
        from_ws = random.choice(possible_picks)

        planner.add_task(SubtaskType.PICK, from_ws, obj)
        planner.add_task(place_type, to_ws, obj)

    planner.write_csv(filename)
    print(f"✅ ATT1 bag written to {filename}")
    print(f"   Used tables: {[ws[0] for ws in selected_table_ws]}")
    print(f"   Shelf: {shelf}, PPT: {ppt}")

# ATT2: 7 objects, 5 decoys, 6 workstations (4 tables, 1 shelf (pick lower), 1 rotating table (pick)),

# Strategie:
# 2 Objekte → Platzierung in Container
# 2 Objekte → Pick von Shelf / Rotating Table
# 3 Objekte → normale Tisch-to-Tisch Moves
# Jeder Pick ≠ Place
# Jede Station max. 3 gleichzeitige Objekte
# Nur 1 Objekt pro Zeile (kein Multi-Transport im CSV)

def generate_att2_bag(filename="att2_bag.csv"):
    objects = random.sample(basic_objects + advanced_objects, 7)

    # === 1. Container-Objekte (1x rot, 1x blau)
    container_pair = random.sample(objects, 2)
    container_assignment = {
        container_pair[0]: container_ids["red"],
        container_pair[1]: container_ids["blue"]
    }

    # === 2. Workstation-Auswahl vorbereiten

    # Tische (GROUND & TABLE)
    table_ws = [
        (name, data) for name, data in workstations.items()
        if name.startswith("WS") and data[0] in [WorkstationType.TABLE, WorkstationType.GROUND]
    ]
    if len(table_ws) < 4:
        print("❌ Not enough table/ground workstations.")
        return
    selected_table_ws = random.sample(table_ws, 4)

    # Shelf (für Pick)
    shelf_ws = [name for name, (typ, _) in workstations.items() if typ == WorkstationType.SHELF]
    if not shelf_ws:
        print("❌ No shelf available.")
        return
    shelf = random.choice(shelf_ws)

    # Rotating Table (für Pick)
    rt_ws = [name for name, (typ, _) in workstations.items() if typ == WorkstationType.ROTATING_TABLE]
    if not rt_ws:
        print("❌ No rotating table available.")
        return
    rotating = random.choice(rt_ws)

    # Alle involvierten Workstations
    all_ws = selected_table_ws + [(shelf, workstations[shelf]), (rotating, workstations[rotating])]
    selected_ws_names = [ws[0] for ws in all_ws]
    planner = TaskPlanner({ws: workstations[ws] for ws in selected_ws_names})

    # === 3. Verteilung der Tasks
    for obj in objects:
        if obj in container_assignment:
            # Ziel: Container (genau festgelegt)
            to_ws = random.choice(selected_ws_names)
            from_ws_candidates = [ws for ws in selected_ws_names if ws != to_ws]
            from_ws = random.choice(from_ws_candidates)

            container_id = container_assignment[obj]

            planner.add_task(SubtaskType.PICK, from_ws, obj)
            planner.add_task(SubtaskType.PLACE_CONTAINER, to_ws, obj, container_id)

        elif objects.index(obj) < 4:
            # Die ersten 2 (nicht Container) → PICK von Shelf / Rotating
            if objects.index(obj) % 2 == 0:
                from_ws = shelf
                pick_type = SubtaskType.PICK_SHELF
            else:
                from_ws = rotating
                pick_type = SubtaskType.PICK_MOVING

            place_ws = random.choice([ws[0] for ws in selected_table_ws if planner.can_place(ws[0])])
            planner.add_task(pick_type, from_ws, obj)
            planner.add_task(SubtaskType.PLACE, place_ws, obj)

        else:
            # Normale Tisch-Tisch Moves
            place_ws = random.choice([ws[0] for ws in selected_table_ws if planner.can_place(ws[0])])
            pick_ws_candidates = [ws[0] for ws in selected_table_ws if ws[0] != place_ws]
            pick_ws = random.choice(pick_ws_candidates)

            planner.add_task(SubtaskType.PICK, pick_ws, obj)
            planner.add_task(SubtaskType.PLACE, place_ws, obj)

    planner.write_csv(filename)
    print(f"✅ ATT2 bag written to {filename}")
    print(f"   Tables: {[ws[0] for ws in selected_table_ws]}")
    print(f"   Shelf (Pick): {shelf}, Rotating Table (Pick): {rotating}")
    print(f"   Container assignments: {container_assignment}")

# Final: 10 objects, 8 decoys, 8 workstations (4 tables, 2 shelfs (pick lower + place top), 
# 1 rotating table (pick 2), 
# 1 ppt (place 2)), all table heights, 4 objects in container (2 red, 2 blue), 2 visual + 2 physical obstacles (2 blocking, 1 semi-blocking, 1 non-blocking), 4 arbitrary surfaces

def generate_final_bag(filename="final_bag.csv"):
    objects = random.sample(basic_objects + advanced_objects, 10)
    container_objs = random.sample(objects, 4)
    red_objs = container_objs[:2]
    blue_objs = container_objs[2:]
    container_assignment = {
        obj: container_ids["red"] for obj in red_objs
    }
    container_assignment.update({
        obj: container_ids["blue"] for obj in blue_objs
    })

    # === Workstation Auswahl ===

    # Tische (alle 4 Tischhöhen + GROUND)
    table_ws = [
        (name, data) for name, data in workstations.items()
        if name.startswith("WS") and data[0] in [WorkstationType.TABLE, WorkstationType.GROUND]
    ]
    if len(table_ws) < 4:
        print("❌ Not enough table/ground workstations.")
        return
    selected_tables = random.sample(table_ws, 4)

    # Shelf (Pick + Place)
    shelf_ws = [name for name, (typ, _) in workstations.items() if typ == WorkstationType.SHELF]
    if len(shelf_ws) < 2:
        print("❌ Need 2 shelves (1 pick, 1 place).")
        return
    shelf_pick, shelf_place = random.sample(shelf_ws, 2)

    # Rotating Table
    rt_ws = [name for name, (typ, _) in workstations.items() if typ == WorkstationType.ROTATING_TABLE]
    if not rt_ws:
        print("❌ No rotating table available.")
        return
    rotating = random.choice(rt_ws)

    # PPT
    ppt_ws = [name for name, (typ, _) in workstations.items() if typ == WorkstationType.PRECISE_PLACE]
    if not ppt_ws:
        print("❌ No PPT available.")
        return
    ppt = random.choice(ppt_ws)

    # === Alle Workstations an Planner übergeben ===
    all_ws = selected_tables + [
        (shelf_pick, workstations[shelf_pick]),
        (shelf_place, workstations[shelf_place]),
        (rotating, workstations[rotating]),
        (ppt, workstations[ppt])
    ]
    ws_names = [ws[0] for ws in all_ws]
    planner = TaskPlanner({ws: workstations[ws] for ws in ws_names})

    # === Aufgabenverteilung ===

    for i, obj in enumerate(objects):
        if obj in container_assignment:
            to_ws = random.choice(ws_names)
            from_ws_choices = [ws for ws in ws_names if ws != to_ws]
            if not from_ws_choices:
                print("❌ No valid pick source for container object.")
                return
            from_ws = random.choice(from_ws_choices)
            container_id = container_assignment[obj]

            planner.add_task(SubtaskType.PICK, from_ws, obj)
            planner.add_task(SubtaskType.PLACE_CONTAINER, to_ws, obj, container_id)

        elif i < 2:
            # 2x Pick from Rotating Table
            target_ws = [ws[0] for ws in selected_tables if planner.can_place(ws[0])]
            if not target_ws:
                print("❌ No valid table for rotating placement.")
                return
            to_ws = random.choice(target_ws)
            planner.add_task(SubtaskType.PICK_MOVING, rotating, obj)
            planner.add_task(SubtaskType.PLACE, to_ws, obj)

        elif i < 4:
            # 2x Place to PPT
            pick_ws = [ws[0] for ws in selected_tables if planner.can_pick(ws[0])]
            if not pick_ws:
                print("❌ No valid table for precise pick.")
                return
            from_ws = random.choice(pick_ws)
            planner.add_task(SubtaskType.PICK, from_ws, obj)
            planner.add_task(SubtaskType.PLACE_PRECISE, ppt, obj)

        elif i < 6:
            # 1x Shelf Pick
            target_ws = [ws[0] for ws in selected_tables if planner.can_place(ws[0])]
            if not target_ws:
                print("❌ No valid table for shelf pick placement.")
                return
            to_ws = random.choice(target_ws)
            planner.add_task(SubtaskType.PICK_SHELF, shelf_pick, obj)
            planner.add_task(SubtaskType.PLACE, to_ws, obj)

        elif i < 8:
            # 1x Shelf Place
            source_ws = [ws[0] for ws in selected_tables if planner.can_pick(ws[0])]
            if not source_ws:
                print("❌ No valid table for shelf pick.")
                return
            from_ws = random.choice(source_ws)
            planner.add_task(SubtaskType.PICK, from_ws, obj)
            planner.add_task(SubtaskType.PLACE_SHELF, shelf_place, obj)

        else:
            # Normale Tisch-Tisch Bewegung
            place_targets = [ws[0] for ws in selected_tables if planner.can_place(ws[0])]
            if not place_targets:
                print("❌ No valid table to place.")
                return
            to_ws = random.choice(place_targets)

            pick_sources = [ws[0] for ws in selected_tables if ws[0] != to_ws and planner.can_pick(ws[0])]
            if not pick_sources:
                print("❌ No valid source table.")
                return
            from_ws = random.choice(pick_sources)

            planner.add_task(SubtaskType.PICK, from_ws, obj)
            planner.add_task(SubtaskType.PLACE, to_ws, obj)

    # === Export
    planner.write_csv(filename)
    print(f"✅ FINAL bag written to {filename}")
    print(f"   Tables: {[ws[0] for ws in selected_tables]}")
    print(f"   Shelf PICK: {shelf_pick}, Shelf PLACE: {shelf_place}")
    print(f"   Rotating (Pick 2): {rotating}, PPT (Place 2): {ppt}")
    print(f"   Containers: RED={red_objs}, BLUE={blue_objs}")


def main():
    # Wenn ein Argument (z. B. "bmt") übergeben wird → direkt ausführen
    if len(sys.argv) > 1:
        selected_test = sys.argv[1].strip().lower()
    else:
        # Fallback auf Eingabe (z. B. bei manueller CLI-Nutzung)
        selected_test = choose_test().lower()

    if selected_test.startswith("bmt"):
        generate_bmt_bag()

    elif selected_test.startswith("btt1"):
        generate_btt1_bag()

    elif selected_test.startswith("btt2"):
        generate_btt2_bag()

    elif selected_test.startswith("att1"):
        generate_att1_bag()

    elif selected_test.startswith("att2"):
        generate_att2_bag()

    elif selected_test.startswith("final"):
        generate_final_bag()

    else:
        print("❌ Invalid test selected.")
        return

if __name__ == "__main__":
    main()