import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
import cv2
import numpy as np
import sys
import os

class ImageSaver(Node):
    def __init__(self):
        super().__init__('image_saver_node')
        self.subscription = self.create_subscription(
            Image,
            '/camera/camera/color/image_raw',
            self.listener_callback,
            10)
        self.get_logger().info("Waiting for an image from /camera/camera/color/image_raw...")
        self.saved = False

    def listener_callback(self, msg):
        if self.saved:
            return
        self.get_logger().info('Received image, saving to current_camera_view.jpg...')
        # Convert ROS Image to OpenCV Image
        # Assuming encoding is rgb8 as reported by realsense color camera
        img_data = np.array(msg.data, dtype=np.uint8)
        img_np = img_data.reshape((msg.height, msg.width, 3))
        
        # OpenCV uses BGR, so convert RGB to BGR
        img_bgr = cv2.cvtColor(img_np, cv2.COLOR_RGB2BGR)
        
        cv2.imwrite('/home/ros2/ros2_ws/current_camera_view.jpg', img_bgr)
        self.get_logger().info('Saved successfully!')
        self.saved = True
        sys.exit(0)

def main(args=None):
    rclpy.init(args=args)
    image_saver = ImageSaver()
    try:
        rclpy.spin(image_saver)
    except SystemExit:
        pass
    except KeyboardInterrupt:
        pass
    finally:
        image_saver.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
