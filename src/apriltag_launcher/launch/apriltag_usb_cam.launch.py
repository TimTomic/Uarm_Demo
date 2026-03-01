import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    apriltag_config = os.path.join(
        get_package_share_directory('apriltag_launcher'),
        'config',
        'tags_36h11.yaml'
    )

    usb_cam_node = Node(
        package='usb_cam',
        executable='usb_cam_node_exe',
        name='usb_cam',
        parameters=[
            {'video_device': '/dev/video0'},
            {'framerate': 30.0},
            {'image_width': 640},
            {'image_height': 480},
            {'pixel_format': 'mjpeg2rgb'},
            {'camera_frame_id': 'camera_link'},
            {'camera_name': 'default_cam'}
        ],
        remappings=[
            ('image_raw', '/camera/image_raw'),
            ('camera_info', '/camera/camera_info')
        ]
    )

    apriltag_node = Node(
        package='apriltag_ros',
        executable='apriltag_node',
        name='apriltag_node',
        parameters=[apriltag_config],
        remappings=[
            ('image_rect', '/camera/image_raw'),
            ('camera_info', '/camera/camera_info')
        ]
    )

    # Broadcast static transform from robot's TCP to camera_link
    # Offset: 1cm forward (x=0.01), 3cm up (z=0.03) from tcp_link
    tf_publisher_node = Node(
        package='tf2_ros',
        executable='static_transform_publisher',
        name='camera_static_tf',
        arguments=['0.01', '0.0', '0.03', '0.0', '0.0', '0.0', 'tcp_link', 'camera_link']
    )

    return LaunchDescription([
        usb_cam_node,
        apriltag_node,
        tf_publisher_node
    ])
