import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node

def generate_launch_description():
    apriltag_config = os.path.join(
        get_package_share_directory('apriltag_launcher'),
        'config',
        'tags_36h11.yaml'
    )

    camera_x = LaunchConfiguration('camera_x_offset')
    camera_y = LaunchConfiguration('camera_y_offset')
    camera_z = LaunchConfiguration('camera_z_offset')

    x_arg = DeclareLaunchArgument('camera_x_offset', default_value='0.01')
    y_arg = DeclareLaunchArgument('camera_y_offset', default_value='0.0')
    z_arg = DeclareLaunchArgument('camera_z_offset', default_value='0.03')
    roll_arg = DeclareLaunchArgument('camera_roll_offset', default_value='3.14159')
    pitch_arg = DeclareLaunchArgument('camera_pitch_offset', default_value='0.0')
    yaw_arg = DeclareLaunchArgument('camera_yaw_offset', default_value='0.0')

    camera_roll = LaunchConfiguration('camera_roll_offset')
    camera_pitch = LaunchConfiguration('camera_pitch_offset')
    camera_yaw = LaunchConfiguration('camera_yaw_offset')

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
    tf_publisher_node = Node(
        package='tf2_ros',
        executable='static_transform_publisher',
        name='camera_static_tf',
        arguments=[camera_x, camera_y, camera_z, camera_yaw, camera_pitch, camera_roll, 'tcp_link', 'default_cam']
    )

    return LaunchDescription([
        x_arg,
        y_arg,
        z_arg,
        roll_arg,
        pitch_arg,
        yaw_arg,
        usb_cam_node,
        apriltag_node,
        tf_publisher_node
    ])
