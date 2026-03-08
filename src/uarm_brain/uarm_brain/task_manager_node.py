"""
task_manager_node.py
====================
ROS2 Node: Task Manager for the uArm Brain.

Connects to the NEW Arm Controller (feature/arm_controller_cpp branch) which
exposes two action servers:

  /pick_and_place  (uarm_interfaces/action/PickAndPlace)
      Goal: pick_x/y/z  +  place_x/y/z  (all in mm)
      The arm picks from (pick_x,y,z) and places at (place_x,y,z).

  /drive_to_pose   (uarm_interfaces/action/DriveToPose)
      Goal: pose_name (string, must match a key in the arm controller's
            pose config, e.g. "scan_center", "scan_left", "scan_right", "drive")

State Machine
-------------
IDLE -> LOADING -> NAV_TO_PICK -> SCAN_CENTER -> [SCAN_LEFT -> SCAN_RIGHT ->] SKIP
                                                        |
                                              PICKING (pick xyz from TF) + STOW (to inv slot)
                                                        |
                                        [more picks?] --+-- NAV_TO_PLACE
                                                              |
                                                        PLACING (from inv slot)
                                                              |
                                                  [more places?] -- DONE

Topics subscribed
-----------------
  /brain/task_queue          (std_msgs/String)  JSON plan from TaskPlanner
  /tf                        (tf2_ros)           for AprilTag 3D pose

Topics published
----------------
  /brain/status              (std_msgs/String)
  /brain/inventory           (std_msgs/String)  JSON

Action clients used
-------------------
  /pick_and_place            PickAndPlace  (uarm_interfaces)
  /drive_to_pose             DriveToPose   (uarm_interfaces)
"""

from __future__ import annotations
import json
import time
import threading
from enum import Enum, auto
from typing import Any, Dict, List, Optional

import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from rclpy.executors import MultiThreadedExecutor
from std_msgs.msg import String
import tf2_ros

# AprilTag detections fallback (now using generic vision_msgs from new detector)
try:
    from vision_msgs.msg import Detection2DArray
    APRILTAG_AVAILABLE = True
except ImportError:
    APRILTAG_AVAILABLE = False

from uarm_interfaces.action import PickAndPlace, DriveToPose


# ---------------------------------------------------------------------------
# State enum
# ---------------------------------------------------------------------------

class State(Enum):
    IDLE          = auto()
    LOADING       = auto()
    NAV_TO_PICK   = auto()
    SCAN_CENTER   = auto()
    SCAN_LEFT     = auto()
    SCAN_RIGHT    = auto()
    SKIP_TASK     = auto()
    PICKING       = auto()
    STOWING       = auto()
    NAV_TO_PLACE  = auto()
    PLACING       = auto()
    DONE          = auto()
    ERROR         = auto()


# ---------------------------------------------------------------------------
# Inventory slot
# ---------------------------------------------------------------------------

class InventorySlot:
    def __init__(self, idx: int, x: float, y: float, z: float):
        self.idx = idx
        self.x = x
        self.y = y
        self.z = z
        self.object_name: Optional[str] = None
        self.object_id: Optional[int] = None

    @property
    def is_empty(self) -> bool:
        return self.object_name is None

    def store(self, obj_name: str, obj_id: int):
        self.object_name = obj_name
        self.object_id   = obj_id

    def clear(self):
        self.object_name = None
        self.object_id   = None

    def to_dict(self) -> Dict[str, Any]:
        return {
            'slot': self.idx,
            'x': self.x, 'y': self.y, 'z': self.z,
            'object': self.object_name or 'empty',
            'object_id': self.object_id,
        }


# ---------------------------------------------------------------------------
# TaskManager Node
# ---------------------------------------------------------------------------

class TaskManagerNode(Node):

    # Pose names understood by the Arm Controller's DriveToPose server.
    # Must EXACTLY match the keys in arm_controller/config/poses.yaml (case-sensitive).
    POSE_SCAN_CENTER = 'SCAN'
    POSE_SCAN_LEFT   = 'SCAN_LEFT'
    POSE_SCAN_RIGHT  = 'SCAN_RIGHT'
    POSE_DRIVE       = 'DRIVE'

    def __init__(self):
        super().__init__('task_manager_node')

        # --- Parameters ---
        self._declare_all_parameters()
        self._read_parameters()

        # --- Inventory (3 physical slots) ---
        self._inventory: List[InventorySlot] = [
            InventorySlot(0, *self._inv_coords[0]),
            InventorySlot(1, *self._inv_coords[1]),
            InventorySlot(2, *self._inv_coords[2]),
        ]

        # --- Plan state ---
        self._plan: List[Dict] = []
        self._state = State.IDLE

        # Live tag detections: {tag_id: (x_mm, y_mm, z_mm)}
        self._tag_poses: Dict[int, tuple] = {}
        self._tag_lock = threading.Lock()

        # --- TF for AprilTag lookup ---
        self._tf_buffer   = tf2_ros.Buffer()
        self._tf_listener = tf2_ros.TransformListener(self._tf_buffer, self)

        # --- Publishers ---
        self._status_pub    = self.create_publisher(String, '/brain/status',    10)
        self._inventory_pub = self.create_publisher(String, '/brain/inventory', 10)

        # --- Subscribers ---
        self._queue_sub = self.create_subscription(
            String, '/brain/task_queue', self._on_task_queue, 10)

        if APRILTAG_AVAILABLE:
            self._tag_sub = self.create_subscription(
                Detection2DArray, '/apriltag/detections', self._on_detections, 10)
        else:
            self.get_logger().warn('vision_msgs not available – using TF lookup only.')

        # --- Action clients ---
        self._pick_place_client = ActionClient(self, PickAndPlace, '/pick_and_place')
        self._drive_pose_client = ActionClient(self, DriveToPose,  '/drive_to_pose')

        # --- Worker thread ---
        self._worker_thread: Optional[threading.Thread] = None

        self.get_logger().info('TaskManager ready. Waiting for /brain/task_queue ...')
        self._publish_status('IDLE')
        self._publish_inventory()

    # ------------------------------------------------------------------
    # Parameter helpers
    # ------------------------------------------------------------------

    def _declare_all_parameters(self):
        p = self.declare_parameter
        p('nav_stub_delay',  3.0)
        p('max_retries',     2)
        p('vision_timeout',  10.0)
        p('dry_run',         False)

        # Inventory slot coordinates (mm)
        p('inventory_slot_0_x', 150.0); p('inventory_slot_0_y', -120.0); p('inventory_slot_0_z', 0.0)
        p('inventory_slot_1_x', 150.0); p('inventory_slot_1_y', -170.0); p('inventory_slot_1_z', 0.0)
        p('inventory_slot_2_x', 150.0); p('inventory_slot_2_y', -220.0); p('inventory_slot_2_z', 0.0)

    def _read_parameters(self):
        g = lambda n: self.get_parameter(n).value
        self._nav_delay     = g('nav_stub_delay')
        self._max_retries   = g('max_retries')
        self._vision_timeout = g('vision_timeout')
        self._dry_run       = g('dry_run')

        self._inv_coords = [
            (g('inventory_slot_0_x'), g('inventory_slot_0_y'), g('inventory_slot_0_z')),
            (g('inventory_slot_1_x'), g('inventory_slot_1_y'), g('inventory_slot_1_z')),
            (g('inventory_slot_2_x'), g('inventory_slot_2_y'), g('inventory_slot_2_z')),
        ]

    # ------------------------------------------------------------------
    # Subscribers
    # ------------------------------------------------------------------

    def _on_task_queue(self, msg: String):
        if self._state not in (State.IDLE, State.DONE, State.ERROR):
            self.get_logger().warn('New task_queue received but manager is busy – ignoring.')
            return
        # --- Plan re-trigger protection ---
        if hasattr(self, '_last_plan_data') and self._last_plan_data == msg.data:
            # If we are done, maybe it's just a latch or re-publish of the same plan
            if self._state == State.DONE:
                self.get_logger().info('Ignoring identical plan message (already DONE).')
                return

        self._last_plan_data = msg.data
        self._plan = json.loads(msg.data)
        self.get_logger().info(f'Received plan with {len(self._plan)} groups.')
        self._set_state(State.LOADING)

        if self._worker_thread and self._worker_thread.is_alive():
            self.get_logger().info('Joining previous worker thread...')
            self._worker_thread.join(timeout=2.0)

        self._worker_thread = threading.Thread(target=self._execute_plan, daemon=True)
        self._worker_thread.start()

    def _on_detections(self, msg):
        """Cache currently visible AprilTag IDs (ID → pixel center, used for presence check)."""
        with self._tag_lock:
            self._tag_poses = {}
            for d in msg.detections:
                if d.results:
                    try:
                        tag_id = int(d.results[0].hypothesis.class_id)
                        self._tag_poses[tag_id] = None
                    except (ValueError, TypeError):
                        pass

    # ------------------------------------------------------------------
    # Plan execution (worker thread)
    # ------------------------------------------------------------------

    def _execute_plan(self):
        self.get_logger().info('Starting plan execution ...')
        self._publish_status('Executing plan')

        for grp_idx, group in enumerate(self._plan):
            pick_ws    = group['pick_ws']
            picks      = group['picks']
            deliveries = group['deliveries']

            self.get_logger().info(
                f"[Group {grp_idx}] pick_ws={pick_ws}  "
                f"{len(picks)} picks, {len(deliveries)} deliveries"
            )

            # --- Navigate to pick workstation (stub) ---
            self._set_state(State.NAV_TO_PICK)
            self._publish_status(f"NAV -> pick WS: {pick_ws}")
            self._nav_stub(pick_ws)

            # --- Pick each object ---
            # Build mapping: object_id -> delivery info (for place step)
            delivery_map = {d['object_id']: d for d in deliveries}
            picked_deliveries: List[Dict] = []

            for pick_info in picks:
                obj_name  = pick_info['object_name']
                obj_id    = pick_info['object_id']

                self.get_logger().info(f"  Trying to pick {obj_name} (tag_id={obj_id})")
                slot = self._get_free_slot()
                if slot is None:
                    self.get_logger().error('Inventory full! This should not happen due to planner.')
                    break

                dest = delivery_map.get(obj_id, {}).get('place_ws', 'STAY')
                success = self._find_and_pick(obj_name, obj_id, slot, dest)
                if success:
                    picked_deliveries.append(delivery_map[obj_id])
                else:
                    self.get_logger().warn(f"  Skipping {obj_name} – not found after all scan poses.")
                    self._publish_status(f"SKIP: {obj_name} not found")

            # --- Deliver each picked object ---
            for delivery in picked_deliveries:
                obj_name  = delivery['object_name']
                obj_id    = delivery['object_id']
                place_ws  = delivery['place_ws']

                if place_ws == 'STAY':
                    self.get_logger().info(f"  Object {obj_name} is set to STAY – skipping placement.")
                    continue

                self._set_state(State.NAV_TO_PLACE)
                self._publish_status(f"NAV -> place WS: {place_ws} (delivering {obj_name})")
                self._nav_stub(place_ws)

                self._set_state(State.PLACING)
                self._publish_status(f"PLACING {obj_name} at {place_ws}")
                self._do_place(obj_name, obj_id)

        self.get_logger().info('Plan groups complete. Returning to DRIVE posture...')
        self._publish_status('Returning to DRIVE')
        self._drive_to_pose_blocking(self.POSE_DRIVE)

        self._set_state(State.DONE)
        self._publish_status('DONE – all tasks complete')
        self.get_logger().info('Plan execution finished.')
        
        # Clear latch to allow re-trigger (e.g. from bag loop)
        if hasattr(self, '_last_plan_data'):
            del self._last_plan_data

    # ------------------------------------------------------------------
    # Find & Pick sequence
    # ------------------------------------------------------------------

    def _find_and_pick(self, obj_name: str, obj_id: int, slot: InventorySlot, dest: str = '') -> bool:
        """
        Try scan_center, scan_left, scan_right to find the target tag.
        Once found, call PickAndPlace with:
          pick coords  = tag XYZ from TF (mm)
          place coords = inventory slot coords (or STAY flag)
        """
        scan_sequence = [
            (State.SCAN_CENTER, self.POSE_SCAN_CENTER),
            (State.SCAN_LEFT,   self.POSE_SCAN_LEFT),
            (State.SCAN_RIGHT,  self.POSE_SCAN_RIGHT),
        ]

        for state, pose_name in scan_sequence:
            self._set_state(state)
            self._publish_status(f"{state.name}: looking for {obj_name} (tag {obj_id})")

            # Tell arm to drive to scan pose
            if not self._drive_to_pose_blocking(pose_name):
                self.get_logger().warn(f"DriveToPose({pose_name}) failed – continuing anyway")

            # Wait for the tag to appear (TF or detections)
            tag_xyz = self._wait_for_tag_xyz(obj_id, self._vision_timeout)
            if tag_xyz is not None:
                tx, ty, tz = tag_xyz
                self.get_logger().info(
                    f"  Found tag {obj_id} at ({tx:.1f}, {ty:.1f}, {tz:.1f}) mm"
                )

                # Pick from tag XYZ, place into inventory slot
                self._set_state(State.PICKING)
                self._publish_status(f"PICKING {obj_name} -> slot {slot.idx}")

                # Pick from tag XYZ, place into inventory slot
                self._set_state(State.PICKING)
                self._publish_status(f"PICKING {obj_name} -> slot {slot.idx}")

                pick_ok = self._do_pick_and_place(
                    pick_x=tx, pick_y=ty, pick_z=tz,
                    place_x=slot.x, place_y=slot.y, place_z=slot.z,
                )

                if pick_ok:
                    self._set_state(State.STOWING)
                    slot.store(obj_name, obj_id)
                    self._publish_inventory()
                    return True
                else:
                    self.get_logger().warn(f"  PickAndPlace failed for {obj_name} – trying next pose")

        self._set_state(State.SKIP_TASK)
        return False

    def _wait_for_tag_xyz(self, tag_id: int, timeout: float) -> Optional[tuple]:
        """
        Wait up to `timeout` seconds for a TF transform for 'tag_<tag_id>'.
        First tries 'Base' -> 'tag_<id>' (full arm transform).
        Falls back to 'camera_color_optical_frame' -> 'tag_<id>' if that fails.
        Returns (x_mm, y_mm, z_mm) or None.
        """
        frame_id = f'tag_{tag_id}'
        deadline = time.time() + timeout

        # TF lookup for exact 3D position — try 'Base' first, fall back to camera frame
        while time.time() < deadline:
            for ref_frame in ('Base', 'camera_color_optical_frame'):
                try:
                    transform = self._tf_buffer.lookup_transform(
                        ref_frame, frame_id, rclpy.time.Time())
                    x_mm = transform.transform.translation.x * 1000.0
                    y_mm = transform.transform.translation.y * 1000.0
                    z_mm = transform.transform.translation.z * 1000.0
                    self.get_logger().info(
                        f'  TF lookup [{ref_frame}->{frame_id}]: '
                        f'x={x_mm:.1f}mm  y={y_mm:.1f}mm  z={z_mm:.1f}mm')
                    return (x_mm, y_mm, z_mm)
                except (tf2_ros.LookupException,
                        tf2_ros.ConnectivityException,
                        tf2_ros.ExtrapolationException) as e:
                    self.get_logger().debug(f'  TF [{ref_frame}->{frame_id}] failed: {e}')

            time.sleep(0.2)

        return None

    # ------------------------------------------------------------------
    # Arm Action Calls
    # ------------------------------------------------------------------

    def _drive_to_pose_blocking(self, pose_name: str) -> bool:
        """
        Send a DriveToPose goal to the arm controller and block until done.
        Returns True on success.
        """
        if self._dry_run:
            self.get_logger().info(f"[DRY-RUN] drive_to_pose({pose_name})")
            time.sleep(0.5)
            return True

        while rclpy.ok() and not self._drive_pose_client.wait_for_server(timeout_sec=2.0):
            self.get_logger().info('Waiting for /drive_to_pose action server (Arm Controller might be down or starting)...')
            self._publish_status('WAITING for Arm Controller (/drive_to_pose)')

        if not rclpy.ok():
            return False

        goal = DriveToPose.Goal(pose_name=pose_name)
        future = self._drive_pose_client.send_goal_async(goal)
        rclpy.spin_until_future_complete(self, future, timeout_sec=15.0)

        gh = future.result()
        if not gh or not gh.accepted:
            self.get_logger().error(f'DriveToPose({pose_name}) rejected by arm.')
            return False

        result_future = gh.get_result_async()
        rclpy.spin_until_future_complete(self, result_future, timeout_sec=15.0)
        res = result_future.result().result
        if not res.success:
            self.get_logger().warn(f'DriveToPose({pose_name}) failed: {res.message}')
        return res.success

    def _do_pick_and_place(
        self,
        pick_x: float, pick_y: float, pick_z: float,
        place_x: float, place_y: float, place_z: float,
    ) -> bool:
        """
        Call the arm controller's PickAndPlace action with direct XYZ coordinates.
        Returns True on success.
        """
        if self._dry_run:
            self.get_logger().info(
                f"[DRY-RUN] pick_and_place "
                f"pick=({pick_x:.1f},{pick_y:.1f},{pick_z:.1f}) "
                f"place=({place_x:.1f},{place_y:.1f},{place_z:.1f})"
            )
            time.sleep(1.0)
            return True

        while rclpy.ok() and not self._pick_place_client.wait_for_server(timeout_sec=2.0):
            self.get_logger().info('Waiting for /pick_and_place action server (Arm Controller might be down or starting)...')
            self._publish_status('WAITING for Arm Controller (/pick_and_place)')

        if not rclpy.ok():
            return False

        goal = PickAndPlace.Goal(
            pick_x=float(pick_x),
            pick_y=float(pick_y),
            pick_z=float(pick_z),
            place_x=float(place_x),
            place_y=float(place_y),
            place_z=float(place_z),
        )
        future = self._pick_place_client.send_goal_async(goal)
        rclpy.spin_until_future_complete(self, future, timeout_sec=120.0)

        gh = future.result()
        if not gh or not gh.accepted:
            self.get_logger().error('PickAndPlace goal rejected by arm.')
            return False

        result_future = gh.get_result_async()
        rclpy.spin_until_future_complete(self, result_future, timeout_sec=120.0)
        res = result_future.result().result

        if not res.success:
            self.get_logger().warn(f'PickAndPlace failed: {res.message}')
        return res.success

    def _do_place(self, obj_name: str, obj_id: int) -> bool:
        """
        Retrieve object from its inventory slot and place at the current workstation.

        Since the arm controller's PickAndPlace action takes explicit coordinates,
        we need the target workstation XYZ. For now the arm is already near the
        place_ws (after nav_stub), so we use the arm's internal 'place' pose.
        In the future, the NAV system will provide the exact pose.

        Current workaround: re-use DriveToPose('place_pose') if configured,
        otherwise use a fallback fixed drop pose.
        """
        slot = self._get_slot_for(obj_id)
        if slot is None:
            self.get_logger().error(f'Object {obj_name} (id={obj_id}) not in inventory!')
            return False

        if self._dry_run:
            self.get_logger().info(f"[DRY-RUN] place {obj_name} from slot {slot.idx}")
            slot.clear()
            self._publish_inventory()
            return True

        # Use a named drop pose defined in arm controller config
        # The arm moves to the drop position first, then we do pick(slot) -> place(drop)
        # For v1: drive to 'place_ws_pose' (must be configured in arm controller YAML as 'drop')
        # Then pick from inventory slot XY and place at arm's current position (drop XYZ).
        # Since we cannot query the arm's current position, we use a configured drop pose.
        # TODO: when NAV provides a transform, pass actual WS coordinates here.
        DROP_POSE_NAME = 'DROP'  # Must match key in arm_controller/config/poses.yaml
        if not self._drive_to_pose_blocking(DROP_POSE_NAME):
            self.get_logger().warn(
                f"Could not drive to '{DROP_POSE_NAME}' pose – using fallback coords."
            )
        # DROP pose coords from poses.yaml (must stay in sync)
        drop_x, drop_y, drop_z = 150.0, 150.0, 50.0

        ok = self._do_pick_and_place(
            pick_x=slot.x,  pick_y=slot.y,  pick_z=slot.z,
            place_x=drop_x, place_y=drop_y, place_z=drop_z,
        )
        if ok:
            slot.clear()
            self._publish_inventory()
        return ok

    # ------------------------------------------------------------------
    # Inventory helpers
    # ------------------------------------------------------------------

    def _get_free_slot(self) -> Optional[InventorySlot]:
        for s in self._inventory:
            if s.is_empty:
                return s
        return None

    def _get_slot_for(self, obj_id: int) -> Optional[InventorySlot]:
        for s in self._inventory:
            if s.object_id == obj_id:
                return s
        return None

    # ------------------------------------------------------------------
    # Navigation stub
    # ------------------------------------------------------------------

    def _nav_stub(self, workstation: str):
        self.get_logger().info(
            f"[NAV-STUB] Navigating to {workstation} "
            f"(waiting {self._nav_delay:.1f}s). "
            "Replace with Nav2 action client later."
        )
        time.sleep(self._nav_delay)

    # ------------------------------------------------------------------
    # Publishing helpers
    # ------------------------------------------------------------------

    def _set_state(self, state: State):
        self._state = state
        self.get_logger().debug(f'State -> {state.name}')

    def _publish_status(self, msg: str):
        self._status_pub.publish(String(data=f'[TaskManager|{self._state.name}] {msg}'))

    def _publish_inventory(self):
        data = json.dumps([s.to_dict() for s in self._inventory], ensure_ascii=False)
        self._inventory_pub.publish(String(data=data))


# ---------------------------------------------------------------------------
# Entry point
# ---------------------------------------------------------------------------

def main(args=None):
    rclpy.init(args=args)
    node = TaskManagerNode()
    executor = MultiThreadedExecutor(num_threads=4)
    executor.add_node(node)
    try:
        executor.spin()
    except KeyboardInterrupt:
        pass
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
