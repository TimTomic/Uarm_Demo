import rclpy
from rclpy.node import Node
import tf2_ros
import time
import math
from swiftpro.msg import Position
from swiftpro.msg import Status
from swiftpro.msg import SwiftproState

class DemoNode(Node):
    def __init__(self):
        super().__init__('demo_node')
        
        # Publishers for uArm control
        self.pos_pub = self.create_publisher(Position, '/position_write_topic', 10)
        self.pump_pub = self.create_publisher(Status, '/pump_topic', 10)
        
        # TF Listener to find tags
        self.tf_buffer = tf2_ros.Buffer()
        self.tf_listener = tf2_ros.TransformListener(self.tf_buffer, self)
        
        # State Subscriber
        self.state_sub = self.create_subscription(SwiftproState, '/SwiftproState_topic', self.state_callback, 10)
        self.limit_switch = 0
        self.current_z = 150.0
        # Declare Parameters
        self.declare_parameter('pose_drive_x', 200.0)
        self.declare_parameter('pose_drive_y', 0.0)
        self.declare_parameter('pose_drive_z', 150.0)
        
        self.declare_parameter('pose_scan_x', 200.0)
        self.declare_parameter('pose_scan_y', 0.0)
        self.declare_parameter('pose_scan_z', 150.0)
        
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
        self.pose_drop = Position(
            x=self.get_parameter('pose_drop_x').value,
            y=self.get_parameter('pose_drop_y').value,
            z=self.get_parameter('pose_drop_z').value
        )
        self.hover_offset = self.get_parameter('hover_z_offset').value
        self.target_z_base = self.get_parameter('target_z_base').value
        
        # State machine timer
        self.timer = self.create_timer(0.1, self.state_machine)
        self.state = "INIT"
        
        self.get_logger().info("Demo Node started. Initializing...")

    def state_callback(self, msg):
        self.limit_switch = msg.limit_switch
        self.current_z = msg.z

    def move_arm(self, x, y, z, silent=False):
        msg = Position()
        msg.x = float(x)
        msg.y = float(y)
        msg.z = float(z)
        self.pos_pub.publish(msg)
        if not silent:
            self.get_logger().info(f"Moving to: X={x:.1f}, Y={y:.1f}, Z={z:.1f}")

    def set_pump(self, state):
        msg = Status()
        msg.status = 1 if state else 0
        self.pump_pub.publish(msg)
        action = "ON" if state else "OFF"
        self.get_logger().info(f"Pump turned {action}")

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

    def state_machine(self):
        if self.state == "INIT":
            self.set_pump(False)
            self.move_arm(self.pose_scan.x, self.pose_scan.y, self.pose_scan.z)
            self.get_logger().info("Moved to SCAN pose. Waiting 3 seconds to settle...")
            self.state = "WAIT_SCAN"
            self.wait_time = time.time()
            
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
                
                # Check for configured limit 
                hover_z = target_z + self.hover_offset
                
                # Basic safety limits for uArm workspace (approx)
                radius = math.sqrt(target_x**2 + target_y**2)
                if radius > 320 or radius < 100 or hover_z < 0:
                    self.get_logger().warn(f"Tag at ({target_x:.1f}, {target_y:.1f}, {hover_z:.1f}) is out of reach! Radius: {radius:.1f}")
                    return
                    
                self.get_logger().info(f"Tag found: X={target_x:.1f}, Y={target_y:.1f}, Z={target_z:.1f}")
                self.pick_x = target_x
                self.pick_y = target_y
                self.pick_z_hover = hover_z # Set the hover dynamically
                self.target_z = hover_z
                
                self.state = "PICKING_HOVER"
                self.move_arm(self.pick_x, self.pick_y, self.pick_z_hover)
                self.wait_time = time.time()
                
        elif self.state == "PICKING_HOVER":
            if time.time() - self.wait_time > 2.0:
                self.state = "PICKING_DOWN"
                self.target_z = self.pick_z_hover
                self.get_logger().info("Moving down until limit switch triggers...")
                self.wait_time = time.time()
                
        elif self.state == "PICKING_DOWN":
            if self.limit_switch == 1:
                # Grab it
                self.get_logger().info("Limit switch triggered! Activating pump.")
                self.set_pump(True)
                self.state = "PICKING_UP"
                self.wait_time = time.time()
            else:
                # move down by 3mm every 0.1s (schnell genug, aber sicher)
                if time.time() - self.wait_time > 0.1:
                    self.target_z -= 2.0
                    if self.target_z < self.target_z_base: # safety check against config limit
                        self.get_logger().warn(f"Z < {self.target_z_base} reached, limit switch not triggered. Aborting.")
                        self.state = "RETURNING"
                        self.wait_time = time.time()
                    else:
                        self.move_arm(self.pick_x, self.pick_y, self.target_z, silent=True)
                        self.wait_time = time.time()
                
        elif self.state == "PICKING_UP":
            if time.time() - self.wait_time > 1.0: # give pump time to seal
                self.move_arm(self.pick_x, self.pick_y, self.pick_z_hover)
                self.state = "MOVING_DROP"
                self.wait_time = time.time()
                
        elif self.state == "MOVING_DROP":
            if time.time() - self.wait_time > 1.5:
                self.move_arm(self.pose_drop.x, self.pose_drop.y, self.pose_drop.z)
                self.state = "DROPPING"
                self.wait_time = time.time()
                
        elif self.state == "DROPPING":
            if time.time() - self.wait_time > 3.0:
                self.set_pump(False)
                self.state = "RETURNING"
                self.wait_time = time.time()
                
        elif self.state == "RETURNING":
            if time.time() - self.wait_time > 1.0: # give time to drop
                # back to start
                self.state = "INIT"

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
