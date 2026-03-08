import rclpy
from rclpy.node import Node
from rclpy.action import ActionServer, CancelResponse, GoalResponse
from rclpy.executors import MultiThreadedExecutor
import tf2_ros
import time
import math
import threading

from swiftpro.msg import Position
from swiftpro.msg import Status
from swiftpro.msg import SwiftproState
from uarm_interfaces.action import PickPlace

class ActionDemoNode(Node):
    def __init__(self):
        super().__init__('action_demo_node')
        
        # Publishers
        self.pos_pub = self.create_publisher(Position, '/position_write_topic', 10)
        self.pump_pub = self.create_publisher(Status, '/pump_topic', 10)
        
        # Subscribers
        self.state_sub = self.create_subscription(SwiftproState, '/SwiftproState_topic', self.state_callback, 10)
        
        # TF
        self.tf_buffer = tf2_ros.Buffer()
        self.tf_listener = tf2_ros.TransformListener(self.tf_buffer, self)
        
        # Action Server
        self._action_server = ActionServer(
            self,
            PickPlace,
            '/uarm_action',
            execute_callback=self.execute_callback,
            goal_callback=self.goal_callback,
            cancel_callback=self.cancel_callback)
        
        # State Data
        self.limit_switch = 0
        self.current_z = 150.0
        
        # Declare Parameters
        self.declare_parameter('pose_drive_x', 200.0)
        self.declare_parameter('pose_drive_y', 0.0)
        self.declare_parameter('pose_drive_z', 150.0)
        
        self.declare_parameter('pose_scan_x', 200.0)
        self.declare_parameter('pose_scan_y', 0.0)
        self.declare_parameter('pose_scan_z', 150.0)
        
        self.declare_parameter('pose_inv_x', 150.0)
        self.declare_parameter('pose_inv_y', -150.0)
        self.declare_parameter('pose_inv_z', 50.0)
        
        self.declare_parameter('pose_drop_x', 150.0)
        self.declare_parameter('pose_drop_y', 150.0)
        self.declare_parameter('pose_drop_z', 50.0)
        
        self.declare_parameter('hover_z_offset', 30.0)
        self.declare_parameter('target_z_base', 0.0)

        # Read Parameters
        self.pose_drive = Position(
            x=self.get_parameter('pose_drive_x').value,
            y=self.get_parameter('pose_drive_y').value,
            z=self.get_parameter('pose_drive_z').value
        )
        self.pose_scan = Position(
            x=self.get_parameter('pose_scan_x').value,
            y=self.get_parameter('pose_scan_y').value,
            z=self.get_parameter('pose_scan_z').value
        )
        self.pose_inv = Position(
            x=self.get_parameter('pose_inv_x').value,
            y=self.get_parameter('pose_inv_y').value,
            z=self.get_parameter('pose_inv_z').value
        )
        self.pose_drop = Position(
            x=self.get_parameter('pose_drop_x').value,
            y=self.get_parameter('pose_drop_y').value,
            z=self.get_parameter('pose_drop_z').value
        )
        self.hover_offset = self.get_parameter('hover_z_offset').value
        self.target_z_base = self.get_parameter('target_z_base').value

        # Go to initial drive pose
        self.move_arm(self.pose_drive.x, self.pose_drive.y, self.pose_drive.z)
        self.set_pump(False)
        self.get_logger().info("Action Demo Node started. Ready to accept goals on /uarm_action")

    def state_callback(self, msg):
        self.limit_switch = msg.limit_switch
        self.current_z = msg.z

    def get_tag_transform(self):
        try:
            return self.tf_buffer.lookup_transform('Base', 'tag36h11:0', rclpy.time.Time())
        except (tf2_ros.LookupException, tf2_ros.ConnectivityException, tf2_ros.ExtrapolationException):
            return None

    def move_arm(self, x, y, z):
        msg = Position(x=float(x), y=float(y), z=float(z))
        self.pos_pub.publish(msg)
        time.sleep(0.05) # small delay to prevent flooding serial

    def set_pump(self, state):
        msg = Status(status=1 if state else 0)
        self.pump_pub.publish(msg)
        time.sleep(0.5)

    def hover_and_descend(self, x, y, target_z_base, goal_handle, state_msg):
        """
        Moves offset above target_z_base, then descends until limit switch == 1.
        """
        hover_z = target_z_base + self.hover_offset
        self.get_logger().info(f"Hovering at Z={hover_z:.1f}")
        
        # Update feedback
        feedback = PickPlace.Feedback()
        feedback.current_state = f"{state_msg} (Hover)"
        goal_handle.publish_feedback(feedback)
        
        self.move_arm(x, y, hover_z)
        time.sleep(2.0) # wait for move to finish
        
        feedback.current_state = f"{state_msg} (Descending)"
        goal_handle.publish_feedback(feedback)
        
        current_descent_z = hover_z
        self.get_logger().info("Descending looking for limit switch...")
        
        while rclpy.ok() and self.limit_switch == 0 and current_descent_z > 0.0:
            if goal_handle.is_cancel_requested:
                return False

            current_descent_z -= 2.0
            self.move_arm(x, y, current_descent_z)
            time.sleep(0.1) # 2mm per 0.1s
            
        if self.limit_switch == 1:
            self.get_logger().info("Limit switch triggered!")
            return True
        else:
            self.get_logger().warn("Descended to Z=0 without triggering limit switch!")
            return False

    def goal_callback(self, goal_request):
        cmd = goal_request.command.lower()
        if cmd in ["pick", "place"]:
            self.get_logger().info(f"Accepted goal request: {cmd}")
            return GoalResponse.ACCEPT
        self.get_logger().warn(f"Rejected unknown goal: {cmd}")
        return GoalResponse.REJECT

    def cancel_callback(self, goal_handle):
        self.get_logger().info("Goal canceled.")
        return CancelResponse.ACCEPT

    def execute_callback(self, goal_handle):
        cmd = goal_handle.request.command.lower()
        result = PickPlace.Result()
        feedback = PickPlace.Feedback()
        
        try:
            if cmd == "pick":
                success, msg = self.do_pick(goal_handle, feedback)
            else: # place
                success, msg = self.do_place(goal_handle, feedback)
                
            if goal_handle.is_cancel_requested:
                goal_handle.canceled()
                result.success = False
                result.message = "Canceled by user"
                # Always reset safely
                self.set_pump(False)
                self.move_arm(self.pose_drive.x, self.pose_drive.y, self.pose_drive.z)
                return result

            # Return to base position
            feedback.current_state = "Returning to Drive Pose"
            goal_handle.publish_feedback(feedback)
            self.move_arm(self.pose_drive.x, self.pose_drive.y, self.pose_drive.z)
            time.sleep(2.0)

            if success:
                goal_handle.succeed()
            else:
                goal_handle.abort()
                
            result.success = success
            result.message = msg
            return result
            
        except Exception as e:
            self.get_logger().error(f"Error during action: {e}")
            goal_handle.abort()
            result.success = False
            result.message = str(e)
            
            # fail safe
            self.set_pump(False)
            self.move_arm(self.pose_drive.x, self.pose_drive.y, self.pose_drive.z)
            return result

    def do_pick(self, goal_handle, feedback):
        # 1. Drive to scan pose
        feedback.current_state = "Moving to Scan Pose"
        goal_handle.publish_feedback(feedback)
        self.move_arm(self.pose_scan.x, self.pose_scan.y, self.pose_scan.z)
        time.sleep(2.0)
        
        # 2. Look for tag (timeout 30s)
        feedback.current_state = "Scanning for AprilTag (max 30s)"
        goal_handle.publish_feedback(feedback)
        self.get_logger().info("Scanning for AprilTag...")
        
        start_time = time.time()
        tag_tf = None
        while time.time() - start_time < 30.0 and rclpy.ok():
            if goal_handle.is_cancel_requested:
                return False, "Canceled"
                
            tag_tf = self.get_tag_transform()
            if tag_tf is not None:
                break
            time.sleep(0.2)
            
        if tag_tf is None:
            self.get_logger().warn("No Tag seen within 30s timeout!")
            return False, "Tag not found (timeout)"
            
        target_x = tag_tf.transform.translation.x * 1000.0
        target_y = tag_tf.transform.translation.y * 1000.0
        target_z = tag_tf.transform.translation.z * 1000.0
        
        # limit check
        radius = math.sqrt(target_x**2 + target_y**2)
        if radius > 320 or radius < 100:
            return False, f"Tag out of reach (R={radius:.1f})"

        # 3. Descend to pick up
        contact = self.hover_and_descend(target_x, target_y, target_z, goal_handle, "Picking Object")
        if not contact:
            return False, "Missed object during downward pick"
            
        self.set_pump(True)
        time.sleep(1.0)
        
        # Lift
        self.move_arm(target_x, target_y, target_z + 80.0)
        time.sleep(1.5)
        
        # 4. Move to Inventory (Pose 3) and descend to place
        # Using configured ground base Z
        contact = self.hover_and_descend(self.pose_inv.x, self.pose_inv.y, self.target_z_base, goal_handle, "Dropping at Inventory")
        self.set_pump(False)
        time.sleep(1.0)
        
        # Lift
        self.move_arm(self.pose_inv.x, self.pose_inv.y, 100.0)
        time.sleep(1.5)
        
        return True, "Pick sequence successful"

    def do_place(self, goal_handle, feedback):
        # 1. Drive to Inventory and pick object
        contact = self.hover_and_descend(self.pose_inv.x, self.pose_inv.y, self.target_z_base, goal_handle, "Fetching from Inventory")
        if not contact:
            return False, "Did not hit switch at inventory"
            
        self.set_pump(True)
        time.sleep(1.0)
        
        # Lift
        self.move_arm(self.pose_inv.x, self.pose_inv.y, 100.0)
        time.sleep(1.5)
        
        # 2. Move to Place/Drop location (Pose 4) and place it
        contact = self.hover_and_descend(self.pose_drop.x, self.pose_drop.y, self.target_z_base, goal_handle, "Dropping at Target")
        self.set_pump(False)
        time.sleep(1.0)
        
        # Lift
        self.move_arm(self.pose_drop.x, self.pose_drop.y, 100.0)
        time.sleep(1.5)
        
        return True, "Place sequence successful"


def main(args=None):
    rclpy.init(args=args)
    node = ActionDemoNode()
    
    # We use a MultiThreadedExecutor so the action server's blocking execute_callback 
    # doesn't starve the incoming TF or state subscriber callbacks.
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
