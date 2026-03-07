import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.substitutions import LaunchConfiguration
from launch.launch_description_sources import PythonLaunchDescriptionSource
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

    realsense_node = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(get_package_share_directory('realsense2_camera'), 'launch', 'rs_launch.py')
        ),
        launch_arguments={
            'enable_color': 'true',
            'enable_depth': 'false', # we only need RGB for the basic tag recognition right now
            'rgb_camera.profile': '640x480x30'
        }.items()
    )

    apriltag_node = Node(
        package='apriltag_ros',
        executable='apriltag_node',
        name='apriltag_node',
        parameters=[
            apriltag_config,
            {'approx_sync': True}
        ],
        remappings=[
            ('image_rect', '/camera/camera/color/image_raw'),
            ('camera_info', '/camera/camera/color/camera_info')
        ]
    )

    tf_publisher_node = Node(
        package='tf2_ros',
        executable='static_transform_publisher',
        name='camera_static_tf',
        arguments=[camera_x, camera_y, camera_z, camera_yaw, camera_pitch, camera_roll, 'tcp_link', 'camera_link'] # Realsense uses camera_link natively
    )

    return LaunchDescription([
        x_arg,
        y_arg,
        z_arg,
        roll_arg,
        pitch_arg,
        yaw_arg,
        realsense_node,
        apriltag_node,
        tf_publisher_node
    ])
