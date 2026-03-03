#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from swiftpro.msg import SwiftproState

class PositionTeacher(Node):
    def __init__(self):
        super().__init__('position_teacher')
        self.get_logger().info("Listening to /SwiftproState_topic...")
        self.get_logger().info("Move the arm around manually (or via another script) and note the coordinates below.")
        self.get_logger().info("--------------------------------------------------")
        
        self.subscription = self.create_subscription(
            SwiftproState,
            '/SwiftproState_topic',
            self.listener_callback,
            10)
        self.last_print_time = self.get_clock().now()
        
    def listener_callback(self, msg):
        now = self.get_clock().now()
        # Print every 1.0 seconds to avoid spamming the terminal
        if (now - self.last_print_time).nanoseconds > 1e9:
            self.get_logger().info(f"Current Position -> X: {msg.x:.1f},  Y: {msg.y:.1f},  Z: {msg.z:.1f}")
            self.last_print_time = now

def main(args=None):
    rclpy.init(args=args)
    node = PositionTeacher()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
