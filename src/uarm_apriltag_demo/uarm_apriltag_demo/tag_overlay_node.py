import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from apriltag_msgs.msg import AprilTagDetectionArray
import cv2
from cv_bridge import CvBridge
import message_filters

class TagOverlayNode(Node):
    def __init__(self):
        super().__init__('tag_overlay_node')
        self.bridge = CvBridge()
        
        # Subscribe to raw image and detections
        self.image_sub = message_filters.Subscriber(self, Image, '/camera/image_raw')
        self.tag_sub = message_filters.Subscriber(self, AprilTagDetectionArray, '/detections')
        
        # Synchronize visually
        self.ts = message_filters.ApproximateTimeSynchronizer(
            [self.image_sub, self.tag_sub],
            queue_size=10,
            slop=0.2
        )
        self.ts.registerCallback(self.sync_callback)
        
        self.image_pub = self.create_publisher(Image, '/camera/image_annotated', 10)
        self.get_logger().info("Tag Overlay Node started. Subscribed to /camera/image_raw and /detections.")

    def sync_callback(self, image_msg, detections_msg):
        try:
            # Convert ROS Image to OpenCV image
            cv_image = self.bridge.imgmsg_to_cv2(image_msg, "bgr8")
        except Exception as e:
            self.get_logger().error(f"Failed to convert image: {e}")
            return

        # Draw each detection
        for detection in detections_msg.detections:
            tag_id = detection.id
            
            # Draw the ID near the center
            center_x = int(detection.centre.x)
            center_y = int(detection.centre.y)
            cv2.circle(cv_image, (center_x, center_y), 5, (0, 0, 255), -1)
            cv2.putText(cv_image, f"ID: {tag_id}", (center_x + 10, center_y - 10), 
                        cv2.FONT_HERSHEY_SIMPLEX, 1.0, (0, 255, 0), 2)
            
            # Draw the bounding box (corners)
            corners = detection.corners
            if len(corners) == 4:
                pts = [(int(c.x), int(c.y)) for c in corners]
                cv2.line(cv_image, pts[0], pts[1], (0, 255, 0), 2)
                cv2.line(cv_image, pts[1], pts[2], (0, 255, 0), 2)
                cv2.line(cv_image, pts[2], pts[3], (0, 255, 0), 2)
                cv2.line(cv_image, pts[3], pts[0], (0, 255, 0), 2)

        # Publish the annotated image
        try:
            annotated_msg = self.bridge.cv2_to_imgmsg(cv_image, "bgr8")
            annotated_msg.header = image_msg.header
            self.image_pub.publish(annotated_msg)
        except Exception as e:
            self.get_logger().error(f"Failed to publish annotated image: {e}")

def main(args=None):
    rclpy.init(args=args)
    node = TagOverlayNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
