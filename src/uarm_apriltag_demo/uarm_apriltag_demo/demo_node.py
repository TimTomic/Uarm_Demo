import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
import tf2_ros
import time
import math

from uarm_interfaces.action import DriveToPose, PickAndPlace

class DemoNode(Node):
    def __init__(self):
        super().__init__('demo_node')
        
        # TF Listener to find tags
        self.tf_buffer = tf2_ros.Buffer()
        self.tf_listener = tf2_ros.TransformListener(self.tf_buffer, self)
        
        # Action Clients
        self.drive_client = ActionClient(self, DriveToPose, 'drive_to_pose')
        self.pick_place_client = ActionClient(self, PickAndPlace, 'pick_and_place')

        # Declare config for target place position
        self.declare_parameter('pose_inv_x', 21.0)
        self.declare_parameter('pose_inv_y', 200.0)
        self.declare_parameter('pose_inv_z', 30.0)
        
        self.target_place_x = self.get_parameter('pose_inv_x').value
        self.target_place_y = self.get_parameter('pose_inv_y').value
        self.target_place_z = self.get_parameter('pose_inv_z').value
        
        # State machine timer
        self.timer = self.create_timer(0.1, self.state_machine)
        self.state = "INIT"
        self.action_in_progress = False
        
        self.get_logger().info("Demo Node started. Waiting for Action Servers...")
        self.drive_client.wait_for_server()
        self.pick_place_client.wait_for_server()
        self.get_logger().info("Action Servers available.")

    def get_tag_transform(self):
        # Look for tag_3 (you can change the ID if needed)
        try:
            # We want the transform from the robot Base to the tag
            t = self.tf_buffer.lookup_transform(
                'Base',
                'tag_3',
                rclpy.time.Time())
            return t
        except tf2_ros.LookupException:
            pass # Tag not found
        except tf2_ros.ConnectivityException:
            pass
        except tf2_ros.ExtrapolationException:
            pass
        return None

    def send_drive_goal(self, pose_name):
        goal_msg = DriveToPose.Goal()
        goal_msg.pose_name = pose_name
        self.action_in_progress = True
        self.get_logger().info(f"Sending Drive goal to {pose_name}")
        self._send_goal_future = self.drive_client.send_goal_async(goal_msg, feedback_callback=self.feedback_callback)
        self._send_goal_future.add_done_callback(self.goal_response_callback)

    def send_pick_place_goal(self, px, py, pz, dx, dy, dz):
        goal_msg = PickAndPlace.Goal()
        goal_msg.pick_x = float(px)
        goal_msg.pick_y = float(py)
        goal_msg.pick_z = float(pz)
        goal_msg.place_x = float(dx)
        goal_msg.place_y = float(dy)
        goal_msg.place_z = float(dz)
        
        self.action_in_progress = True
        self.get_logger().info(f"Sending PickAndPlace goal: Pick({px:.1f}, {py:.1f}, {pz:.1f}) -> Place({dx:.1f}, {dy:.1f}, {dz:.1f})")
        self._send_goal_future = self.pick_place_client.send_goal_async(goal_msg, feedback_callback=self.feedback_callback)
        self._send_goal_future.add_done_callback(self.goal_response_callback)

    def feedback_callback(self, feedback_msg):
        self.get_logger().info(f"Action Feedback: {feedback_msg.feedback.current_state}")

    def goal_response_callback(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().error('Goal rejected :(')
            self.action_in_progress = False
            self.state = "INIT"
            return

        self.get_logger().info('Goal accepted')
        self._get_result_future = goal_handle.get_result_async()
        self._get_result_future.add_done_callback(self.get_result_callback)

    def get_result_callback(self, future):
        result = future.result().result
        self.get_logger().info(f'Action Result: {result.message} (Success: {result.success})')
        self.action_in_progress = False
        
        if self.state == "DRIVING_TO_SCAN":
            self.get_logger().info("Scan pose reached. Waiting 3 seconds to settle...")
            self.state = "WAIT_SCAN"
            self.wait_time = time.time()
        elif self.state == "EXECUTING_PICK_PLACE":
            self.get_logger().info("Pick and place finished. Returning to start...")
            self.state = "INIT"

    def state_machine(self):
        if self.action_in_progress:
            return # Block state machine while an action is running
            
        if self.state == "INIT":
            self.state = "DRIVING_TO_SCAN"
            self.send_drive_goal("SCAN")
            
        elif self.state == "WAIT_SCAN":
            if time.time() - self.wait_time > 3.0:
                self.get_logger().info("Scanning for AprilTag 3...")
                self.state = "SCANNING"
                
        elif self.state == "SCANNING":
            tag_tf = self.get_tag_transform()
            if tag_tf is not None:
                # 3D Tag translation in meters -> convert to mm for uArm
                target_x = tag_tf.transform.translation.x * 1000.0
                target_y = tag_tf.transform.translation.y * 1000.0
                target_z = tag_tf.transform.translation.z * 1000.0
                
                # Basic safety limits for uArm workspace (approx)
                radius = math.sqrt(target_x**2 + target_y**2)
                if radius > 320 or radius < 100:
                    self.get_logger().warn(f"Tag at ({target_x:.1f}, {target_y:.1f}, {target_z:.1f}) is out of reach! Radius: {radius:.1f}")
                    return
                    
                self.get_logger().info(f"Tag found: X={target_x:.1f}, Y={target_y:.1f}, Z={target_z:.1f}")
                
                self.state = "EXECUTING_PICK_PLACE"
                # Send the action to pick at tag location and place at inventory location loaded from config
                self.send_pick_place_goal(
                    target_x, target_y, target_z, 
                    self.target_place_x, self.target_place_y, self.target_place_z
                )

def main(args=None):
    rclpy.init(args=args)
    node = DemoNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
