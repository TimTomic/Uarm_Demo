"""
task_planner_node.py
====================
ROS2 Node:  Task Planner for the uArm Brain.

Responsibilities
----------------
* Reads a .bag file (ROS1 or ROS2) via `bag_reader.py`
* Optimises the task order using a **Greedy Nearest-Neighbour** strategy:
    - Group all tasks by their pick-workstation.
    - Process all picks from one workstation before moving to the next,
      respecting the 3-slot inventory limit.
    - Then deliver all queued objects to their respective place-workstations.
* Publishes the optimised plan as a JSON string on `/brain/task_queue`.
* Exposes an action server `/brain/load_bag` so the TaskManager (or an
  operator) can trigger (re)loading of a new bag file at runtime.

Topics published
----------------
  /brain/task_queue  (std_msgs/String)  JSON list of ordered task groups.
  /brain/status      (std_msgs/String)  Human-readable planner status.

Action servers
--------------
  /brain/load_bag    (uarm_interfaces/action/LoadBag)
"""

from __future__ import annotations
import json
import os
from collections import defaultdict
from typing import Any, Dict, List

import rclpy
from rclpy.node import Node
from rclpy.action import ActionServer, GoalResponse, CancelResponse
from std_msgs.msg import String

from uarm_interfaces.action import LoadBag
from uarm_brain.bag_reader import read_bag

# SubtaskType constants (mirror of generate_bags.py)
PICK_TYPES  = {10, 11, 12}   # PICK, PICK_SHELF, PICK_MOVING
PLACE_TYPES = {20, 21, 22, 23}  # PLACE, PLACE_SHELF, PLACE_PRECISE, PLACE_CONTAINER

INVENTORY_SIZE = 3  # maximum objects the robot can carry simultaneously


class TaskPlannerNode(Node):
    def __init__(self):
        super().__init__('task_planner_node')

        # Parameters
        self.declare_parameter('bag_file_path', '')
        self.declare_parameter('bag_topic', '/task_list')
        self.declare_parameter('inventory_slots', INVENTORY_SIZE)

        self._bag_topic:    str  = self.get_parameter('bag_topic').value
        self._inv_slots:    int  = self.get_parameter('inventory_slots').value
        self._bag_path:     str  = self.get_parameter('bag_file_path').value

        # Publishers
        self._queue_pub  = self.create_publisher(String, '/brain/task_queue',  10)
        self._status_pub = self.create_publisher(String, '/brain/status',       10)

        # Action server
        self._action_server = ActionServer(
            self,
            LoadBag,
            '/brain/load_bag',
            execute_callback=self._load_bag_cb,
            goal_callback=self._goal_cb,
            cancel_callback=self._cancel_cb,
        )

        # Subscriber for live tasks (e.g. from bag play)
        from uarm_brain.bag_reader import _parse_json_message
        self._live_sub = self.create_subscription(
            String,
            self._bag_topic,
            lambda msg: self._on_live_tasks(msg, _parse_json_message),
            10
        )

        self.get_logger().info('TaskPlanner ready. Subscribed to live /task_list.')

        # Auto-load if bag_file_path was provided as a parameter
        if self._bag_path:
            self.get_logger().info(f"Auto-loading bag: {self._bag_path}")
            try:
                self._load_and_publish(self._bag_path)
            except Exception as exc:
                self.get_logger().error(f"Auto-load failed: {exc}")

    # ------------------------------------------------------------------
    # Action callbacks
    # ------------------------------------------------------------------

    def _goal_cb(self, goal_request):
        if not goal_request.bag_path:
            self.get_logger().warn('Rejected goal: empty bag_path')
            return GoalResponse.REJECT
        return GoalResponse.ACCEPT

    def _cancel_cb(self, goal_handle):
        return CancelResponse.ACCEPT

    def _load_bag_cb(self, goal_handle):
        result = LoadBag.Result()
        feedback = LoadBag.Feedback()

        bag_path = goal_handle.request.bag_path
        self.get_logger().info(f"LoadBag action: {bag_path}")

        feedback.status = f"Reading bag: {os.path.basename(bag_path)}"
        goal_handle.publish_feedback(feedback)

        try:
            task_count = self._load_and_publish(bag_path)
            result.success     = True
            result.message     = f"Loaded {task_count} tasks"
            result.task_count  = task_count
            goal_handle.succeed()
        except Exception as exc:
            result.success  = False
            result.message  = str(exc)
            result.task_count = 0
            goal_handle.abort()
            self.get_logger().error(f"LoadBag failed: {exc}")

        return result

    def _on_live_tasks(self, msg, parse_func):
        """Callback for live /task_list messages (e.g. from bag play)."""
        # (Latch removed – TaskManager now handles its own state and re-triggering)
        
        self.get_logger().info('Received live /task_list update. Planning...')
        raw_tasks = parse_func(msg.data, "live_topic")
        
        # Build transports and plan
        transports = self._build_transports(raw_tasks)
        ordered_groups = self._greedy_plan(transports)

        # Publish
        payload = json.dumps(ordered_groups, ensure_ascii=False)
        self._queue_pub.publish(String(data=payload))
        self._publish_status(f"Live Plan published: {len(transports)} transports")

    # ------------------------------------------------------------------
    # Core planning logic
    # ------------------------------------------------------------------

    def _load_and_publish(self, bag_path: str) -> int:
        """
        Load bag, optimise task order, publish to /brain/task_queue.
        Returns the total number of raw subtasks.
        """
        self._publish_status(f"Reading: {os.path.basename(bag_path)}")
        raw_tasks = read_bag(bag_path, self._bag_topic)
        self.get_logger().info(f"Read {len(raw_tasks)} raw subtasks from bag.")

        # Build high-level transport tasks: (pick_ws, place_ws, object_info)
        transports = self._build_transports(raw_tasks)
        self.get_logger().info(f"Derived {len(transports)} transport tasks.")

        # Optimise order
        ordered_groups = self._greedy_plan(transports)

        # Publish
        payload = json.dumps(ordered_groups, ensure_ascii=False)
        msg = String(data=payload)
        self._queue_pub.publish(msg)
        self._publish_status(f"Plan published: {len(transports)} transports in {len(ordered_groups)} groups")
        self.get_logger().info("Task queue published to /brain/task_queue")

        return len(raw_tasks)

    def _build_transports(self, raw_tasks: List[Dict]) -> List[Dict]:
        """
        Pair each PICK with its corresponding PLACE by object occurrence.
        Returns a list of transport-dicts:
            {pick_ws, place_ws, object_id, object_name, subtask_pick_type,
             subtask_place_type, ws_height, ws_type, container_id}
        """
        transports = []
        pending_picks: Dict[int, Dict] = {}  # object_id → pick task

        for task in raw_tasks:
            st = task['subtask_type']
            oid = task['object_id']

            if st in PICK_TYPES:
                pending_picks[oid] = task
            elif st in PLACE_TYPES:
                pick = pending_picks.pop(oid, None)
                if pick is None:
                    self.get_logger().warn(
                        f"Place for object {oid} ({task['object_name']}) "
                        f"has no matching Pick – skipping."
                    )
                    continue
                transports.append({
                    'pick_ws':            pick['workstation'],
                    'pick_type':          pick['subtask_type'],
                    'pick_ws_height':     pick['ws_height'],
                    'pick_ws_type':       pick['ws_type'],
                    'place_ws':           task['workstation'],
                    'place_type':         task['subtask_type'],
                    'place_ws_height':    task['ws_height'],
                    'place_ws_type':      task['ws_type'],
                    'object_id':          oid,
                    'object_name':        task['object_name'],
                    'container_id':       task['container_id'],
                })

        # NEW: Handle standalone Picks (objects that should be picked but not placed)
        for oid, pick in pending_picks.items():
            transports.append({
                'pick_ws':            pick['workstation'],
                'pick_type':          pick['subtask_type'],
                'pick_ws_height':     pick['ws_height'],
                'pick_ws_type':       pick['ws_type'],
                'place_ws':           'STAY', # Flag for TaskManager
                'place_type':         0,
                'place_ws_height':    '0cm',
                'place_ws_type':      0,
                'object_id':          oid,
                'object_name':        pick['object_name'],
                'container_id':       pick['container_id'],
            })

        return transports

    def _greedy_plan(self, transports: List[Dict]) -> List[Dict]:
        """
        Greedy nearest-neighbour planning.

        Strategy
        --------
        Group all transports by their pick_ws.
        Process one pick_ws at a time (all picks from that station before
        moving on), respecting the inventory limit.

        Returns a list of *execution group* dicts:
            {
              "group_id":   int,
              "pick_ws":    str,
              "picks":      [{object_id, object_name, pick_type,
                              pick_ws_height, pick_ws_type}, ...],
              "deliveries": [{object_id, object_name, place_ws,
                              place_type, place_ws_height,
                              place_ws_type, container_id}, ...],
            }

        The TaskManager processes one group at a time:
          1. Navigate to pick_ws
          2. Execute all picks (up to inventory limit)
          3. Navigate to each place_ws and place the objects
        """
        # Bucket by pick_ws, preserving encounter order
        ws_order: List[str] = []
        ws_buckets: Dict[str, List[Dict]] = defaultdict(list)
        for t in transports:
            ws = t['pick_ws']
            if ws not in ws_buckets:
                ws_order.append(ws)
            ws_buckets[ws].append(t)

        groups: List[Dict] = []
        group_id = 0
        inv = self._inv_slots

        for ws in ws_order:
            batch_source = ws_buckets[ws]
            while batch_source:
                # Build a sub-batch of up to 'inv' transports, but ONLY unique object IDs
                sub = []
                seen_ids = set()
                remaining = []
                
                for t in batch_source:
                    oid = t['object_id']
                    if len(sub) < inv and oid not in seen_ids:
                        sub.append(t)
                        seen_ids.add(oid)
                    else:
                        remaining.append(t)
                
                batch_source = remaining
                
                if not sub:
                    break

                picks = [{
                    'object_id':      t['object_id'],
                    'object_name':    t['object_name'],
                    'pick_type':      t['pick_type'],
                    'pick_ws_height': t['pick_ws_height'],
                    'pick_ws_type':   t['pick_ws_type'],
                } for t in sub]

                deliveries = [{
                    'object_id':       t['object_id'],
                    'object_name':     t['object_name'],
                    'place_ws':        t['place_ws'],
                    'place_type':      t['place_type'],
                    'place_ws_height': t['place_ws_height'],
                    'place_ws_type':   t['place_ws_type'],
                    'container_id':    t['container_id'],
                } for t in sub]

                groups.append({
                    'group_id':   group_id,
                    'pick_ws':    ws,
                    'picks':      picks,
                    'deliveries': deliveries,
                })
                group_id += 1

        self.get_logger().info(
            f"Greedy plan: {len(ws_order)} workstations → {len(groups)} groups"
        )
        return groups

    # ------------------------------------------------------------------
    # Helpers
    # ------------------------------------------------------------------

    def _publish_status(self, msg: str):
        self._status_pub.publish(String(data=f"[TaskPlanner] {msg}"))
        self.get_logger().info(msg)


def main(args=None):
    rclpy.init(args=args)
    node = TaskPlannerNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
