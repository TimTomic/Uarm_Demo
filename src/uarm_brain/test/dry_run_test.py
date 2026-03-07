#!/usr/bin/env python3
"""
dry_run_test.py
===============
Offline dry-run test for the uarm_brain TaskPlanner logic.
Does NOT require a running ROS2 environment or hardware.

Run from the workspace root (on the Pi or locally):
    python3 src/uarm_brain/test/dry_run_test.py \
        --bag "/path/to/BTT2.bag" \
        --topic "/task_list"

For a CSV-based quick test (converts the CSV inline):
    python3 src/uarm_brain/test/dry_run_test.py --csv

Exit codes:
    0 - All checks passed
    1 - One or more checks failed
"""

import argparse
import json
import sys
import os

# Make sure local src is importable when running from repo root
sys.path.insert(0, os.path.join(os.path.dirname(__file__), '..', '..', '..'))

# ---------------------------------------------------------------------------
# Mini stubs so we can import the planner without a full ROS2 environment
# ---------------------------------------------------------------------------

class _FakeLogger:
    def info(self, m, *a):    print(f"[INFO]  {m % a if a else m}")
    def warn(self, m, *a):    print(f"[WARN]  {m % a if a else m}")
    def warning(self, m, *a): print(f"[WARN]  {m % a if a else m}")
    def error(self, m, *a):   print(f"[ERROR] {m % a if a else m}")
    def debug(self, m, *a):   pass

# Patch bag_reader logger
import logging
logging.basicConfig(level=logging.WARNING)


# ---------------------------------------------------------------------------
# Inline TaskPlanner (extracts only the planning logic, no ROS needed)
# ---------------------------------------------------------------------------

PICK_TYPES  = {10, 11, 12}
PLACE_TYPES = {20, 21, 22, 23}
INVENTORY_SIZE = 3

log = _FakeLogger()


def build_transports(raw_tasks):
    transports = []
    pending = {}
    for task in raw_tasks:
        st  = task['subtask_type']
        oid = task['object_id']
        if st in PICK_TYPES:
            pending[oid] = task
        elif st in PLACE_TYPES:
            pick = pending.pop(oid, None)
            if pick is None:
                log.warn("No Pick for object %s – skip", oid)
                continue
            transports.append({
                'pick_ws':   pick['workstation'],
                'pick_type': pick['subtask_type'],
                'place_ws':  task['workstation'],
                'place_type':task['subtask_type'],
                'object_id': oid,
                'object_name': task['object_name'],
                'container_id': task['container_id'],
            })
    return transports


def greedy_plan(transports, inv=INVENTORY_SIZE):
    from collections import defaultdict
    ws_order = []
    ws_buckets = defaultdict(list)
    for t in transports:
        ws = t['pick_ws']
        if ws not in ws_buckets:
            ws_order.append(ws)
        ws_buckets[ws].append(t)
    groups = []
    gid = 0
    for ws in ws_order:
        batch = ws_buckets[ws]
        for i in range(0, len(batch), inv):
            sub = batch[i:i+inv]
            groups.append({
                'group_id': gid,
                'pick_ws':  ws,
                'picks':      [{'object_id': t['object_id'],
                                'object_name': t['object_name'],
                                'pick_type': t['pick_type']} for t in sub],
                'deliveries': [{'object_id': t['object_id'],
                                'object_name': t['object_name'],
                                'place_ws': t['place_ws'],
                                'place_type': t['place_type'],
                                'container_id': t['container_id']} for t in sub],
            })
            gid += 1
    return groups


# ---------------------------------------------------------------------------
# Inline CSV fallback task list (mirrors bmt_bag.csv content)
# ---------------------------------------------------------------------------

DEMO_TASKS_BMT = [
    {"subtask_type":10,"subtask_name":"Pick","workstation":"WS07","ws_height":"5cm","ws_type":1,"object_id":11,"object_name":"F20_20_B","container_id":0},
    {"subtask_type":20,"subtask_name":"Place","workstation":"WS08","ws_height":"5cm","ws_type":1,"object_id":11,"object_name":"F20_20_B","container_id":0},
    {"subtask_type":10,"subtask_name":"Pick","workstation":"WS07","ws_height":"5cm","ws_type":1,"object_id":15,"object_name":"M20_100","container_id":0},
    {"subtask_type":20,"subtask_name":"Place","workstation":"WS08","ws_height":"5cm","ws_type":1,"object_id":15,"object_name":"M20_100","container_id":0},
    {"subtask_type":10,"subtask_name":"Pick","workstation":"WS07","ws_height":"5cm","ws_type":1,"object_id":16,"object_name":"M20","container_id":0},
    {"subtask_type":20,"subtask_name":"Place","workstation":"WS08","ws_height":"5cm","ws_type":1,"object_id":16,"object_name":"M20","container_id":0},
]


# ---------------------------------------------------------------------------
# Tests
# ---------------------------------------------------------------------------

def test_bmt_grouping():
    print("\n=== TEST 1: BMT grouping (3 objects, WS07->WS08) ===")
    tasks = DEMO_TASKS_BMT
    transports = build_transports(tasks)
    print(f"  Transports derived: {len(transports)}  (expected 3)")
    assert len(transports) == 3, f"Expected 3 transports, got {len(transports)}"

    groups = greedy_plan(transports)
    print(f"  Groups generated: {len(groups)}  (expected 1 – all from WS07)")
    assert len(groups) == 1, f"Expected 1 group, got {len(groups)}"
    assert groups[0]['pick_ws'] == 'WS07'
    assert len(groups[0]['picks']) == 3
    print(f"  Group 0 picks: {[p['object_name'] for p in groups[0]['picks']]}")
    print("  PASSED OK")


def test_inventory_limit():
    """When > 3 objects from same WS, they should be split into batches."""
    print("\n=== TEST 2: Inventory limit (4 objects -> 2 groups) ===")
    extra = [
        {"subtask_type":10,"subtask_name":"Pick","workstation":"WS01","ws_height":"10cm","ws_type":1,"object_id":i,"object_name":f"OBJ{i}","container_id":0}
        for i in range(1, 5)
    ]
    places = [
        {"subtask_type":20,"subtask_name":"Place","workstation":"WS02","ws_height":"10cm","ws_type":1,"object_id":i,"object_name":f"OBJ{i}","container_id":0}
        for i in range(1, 5)
    ]
    tasks = []
    for p, pl in zip(extra, places):
        tasks.append(p); tasks.append(pl)
    transports = build_transports(tasks)
    groups = greedy_plan(transports, inv=3)
    print(f"  Groups: {len(groups)}  (expected 2: batch of 3 + batch of 1)")
    assert len(groups) == 2, f"Expected 2 groups, got {len(groups)}"
    assert len(groups[0]['picks']) == 3
    assert len(groups[1]['picks']) == 1
    print("  PASSED OK")


def test_multi_ws_ordering():
    """Objects from WS01 and WS02 should be grouped separately."""
    print("\n=== TEST 3: Multi-WS ordering (WS01 first, then WS02) ===")
    tasks = [
        {"subtask_type":10,"workstation":"WS01","object_id":1,"object_name":"A","ws_height":"10cm","ws_type":1,"container_id":0},
        {"subtask_type":20,"workstation":"WS03","object_id":1,"object_name":"A","ws_height":"10cm","ws_type":1,"container_id":0},
        {"subtask_type":10,"workstation":"WS02","object_id":2,"object_name":"B","ws_height":"10cm","ws_type":1,"container_id":0},
        {"subtask_type":20,"workstation":"WS03","object_id":2,"object_name":"B","ws_height":"10cm","ws_type":1,"container_id":0},
        {"subtask_type":10,"workstation":"WS01","object_id":3,"object_name":"C","ws_height":"10cm","ws_type":1,"container_id":0},
        {"subtask_type":20,"workstation":"WS04","object_id":3,"object_name":"C","ws_height":"10cm","ws_type":1,"container_id":0},
    ]
    transports = build_transports(tasks)
    groups = greedy_plan(transports)
    print(f"  Groups: {[(g['group_id'], g['pick_ws']) for g in groups]}")
    # WS01 has 2 items (A, C) in one group, WS02 has 1 item
    ws_order = [g['pick_ws'] for g in groups]
    assert ws_order[0] == 'WS01', f"Expected WS01 first, got {ws_order}"
    assert ws_order[1] == 'WS02', f"Expected WS02 second, got {ws_order}"
    print("  PASSED OK")


def test_bag_reader(bag_path, topic):
    print(f"\n=== TEST 4: BAG reader – {os.path.basename(bag_path)} ===")
    try:
        from uarm_brain.bag_reader import read_bag
        tasks = read_bag(bag_path, topic)
        print(f"  Read {len(tasks)} tasks.")
        if tasks:
            print(f"  First task: {tasks[0]}")
        transports = build_transports(tasks)
        groups = greedy_plan(transports)
        print(f"  -> {len(transports)} transports, {len(groups)} groups")
        print(f"  Group plan:")
        for g in groups:
            print(f"    [Group {g['group_id']}] pick_ws={g['pick_ws']} "
                  f"picks={[p['object_name'] for p in g['picks']]}")
        print("  PASSED OK")
    except Exception as exc:
        print(f"  FAILED FAIL – {exc}")
        return False
    return True


# ---------------------------------------------------------------------------
# Main
# ---------------------------------------------------------------------------

def main():
    parser = argparse.ArgumentParser(description='Dry-run test for uarm_brain planner')
    parser.add_argument('--bag',   default='', help='Path to .bag file')
    parser.add_argument('--topic', default='/task_list', help='Bag topic')
    parser.add_argument('--csv',   action='store_true',
                        help='Run offline CSV-based tests only (no bag file needed)')
    args = parser.parse_args()

    passed = 0
    failed = 0

    tests = [test_bmt_grouping, test_inventory_limit, test_multi_ws_ordering]
    for t in tests:
        try:
            t()
            passed += 1
        except AssertionError as e:
            print(f"  FAILED FAIL – {e}")
            failed += 1

    if args.bag and not args.csv:
        ok = test_bag_reader(args.bag, args.topic)
        if ok:
            passed += 1
        else:
            failed += 1

    print(f"\n{'='*50}")
    print(f"Results: {passed} passed, {failed} failed")
    return 0 if failed == 0 else 1


if __name__ == '__main__':
    sys.exit(main())
