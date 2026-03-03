from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, DeclareLaunchArgument
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch.conditions import IfCondition
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
import os
import yaml

def get_yaml_config(package_name, config_file):
    config_path = os.path.join(get_package_share_directory(package_name), 'config', config_file)
    with open(config_path, 'r') as f:
        return yaml.safe_load(f)

def generate_launch_description():
    use_rviz = LaunchConfiguration('use_rviz')
    
    use_rviz_arg = DeclareLaunchArgument(
        'use_rviz',
        default_value='true',
        description='Whether to start RViz2'
    )
    # Load Config to read tf properties early
    demo_config_file = os.path.join(get_package_share_directory('uarm_apriltag_demo'), 'config', 'demo_config.yaml')
    demo_config_yaml = get_yaml_config('uarm_apriltag_demo', 'demo_config.yaml')
    
    # Read TF offsets from yaml
    # the yaml is nested under `/**: ros__parameters:`
    params = demo_config_yaml.get('/**', {}).get('ros__parameters', {})
    cam_x = str(params.get('camera_x_offset', '0.010'))
    cam_y = str(params.get('camera_y_offset', '0.0'))
    cam_z = str(params.get('camera_z_offset', '0.050'))
    cam_roll = str(params.get('camera_roll_offset', '3.14159'))
    cam_pitch = str(params.get('camera_pitch_offset', '0.0'))
    cam_yaw = str(params.get('camera_yaw_offset', '0.0'))

    tcp_x = str(params.get('tcp_x_offset', '0.060'))
    tcp_y = str(params.get('tcp_y_offset', '0.0'))
    tcp_z = str(params.get('tcp_z_offset', '-0.073'))
    tcp_roll = str(params.get('tcp_roll_offset', '0.0'))
    tcp_pitch = str(params.get('tcp_pitch_offset', '0.0'))
    tcp_yaw = str(params.get('tcp_yaw_offset', '0.0'))

    # 1. Start the uArm driver
    swiftpro_launch_dir = os.path.join(get_package_share_directory('swiftpro'), 'launch')
    swiftpro_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(os.path.join(swiftpro_launch_dir, 'pro_control.launch.py'))
    )

    # 2. Start the USB camera and AprilTag detection
    apriltag_launch_dir = os.path.join(get_package_share_directory('apriltag_launcher'), 'launch')
    apriltag_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(os.path.join(apriltag_launch_dir, 'apriltag_usb_cam.launch.py')),
        launch_arguments={
            'camera_x_offset': cam_x,
            'camera_y_offset': cam_y,
            'camera_z_offset': cam_z,
            'camera_roll_offset': cam_roll,
            'camera_pitch_offset': cam_pitch,
            'camera_yaw_offset': cam_yaw
        }.items()
    )

    # 3. Start the Demo State Machine
    demo_node = Node(
        package='uarm_apriltag_demo',
        executable='demo_node',
        name='demo_node',
        output='screen',
        parameters=[demo_config_file]
    )

    # 4. Start the Image Overlay Node
    overlay_node = Node(
        package='uarm_apriltag_demo',
        executable='tag_overlay_node',
        name='tag_overlay_node',
        output='screen'
    )

    # 5. Start RViz2
    rviz_config_file = os.path.join(get_package_share_directory('uarm_apriltag_demo'), 'rviz', 'demo.rviz')
    rviz_node = Node(
        package='rviz2',
        executable='rviz2',
        name='rviz2',
        arguments=['-d', rviz_config_file],
        output='screen',
        condition=IfCondition(use_rviz)
    )

    # 6. TCP Static Transform Publisher
    tcp_tf_node = Node(
        package='tf2_ros',
        executable='static_transform_publisher',
        name='tcp_static_tf',
        arguments=[tcp_x, tcp_y, tcp_z, tcp_yaw, tcp_pitch, tcp_roll, 'Link8', 'tcp_link']
    )

    return LaunchDescription([
        use_rviz_arg,
        swiftpro_launch,
        apriltag_launch,
        demo_node,
        overlay_node,
        rviz_node,
        tcp_tf_node
    ])
