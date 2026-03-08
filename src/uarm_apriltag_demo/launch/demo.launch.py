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

    hover_z_offset = str(params.get('hover_z_offset', '0.010'))
    target_z_base = str(params.get('target_z_base', '0.0'))

    # 1. Start the uArm Controller (which internally starts the swiftpro driver)
    arm_controller_launch_dir = os.path.join(get_package_share_directory('uarm_arm_controller'), 'launch')
    arm_controller_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(os.path.join(arm_controller_launch_dir, 'arm_controller.launch.py'))
    )

    # 2. Start the RealSense camera
    realsense_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(get_package_share_directory('realsense2_camera'), 'launch', 'rs_launch.py')
        ),
        launch_arguments={
            'enable_color': 'true',
            'enable_depth': 'false', 
            'rgb_camera.profile': '640x480x30'
        }.items()
    )

    # 3. Start the custom AprilTag detector (from F-Fer's repo)
    apriltag_detector = Node(
        package='apriltag_detector',
        executable='apriltag_detector_node',
        name='apriltag_detector',
        output='screen',
        parameters=[{
            'tag_family': 'tag36h11',
            'tag_size': 0.032, # Hardcoded exactly to the user's previously measured 32mm tag
            'camera_frame': 'camera_color_optical_frame',
        }],
        remappings=[
            ('/camera/image_raw', '/camera/camera/color/image_raw'),
            ('/camera/camera_info', '/camera/camera/color/camera_info')
        ]
    )

    # 4. Camera Static Transform Publisher
    camera_tf_node = Node(
        package='tf2_ros',
        executable='static_transform_publisher',
        name='camera_static_tf',
        arguments=[
            '--x', cam_x, '--y', cam_y, '--z', cam_z, 
            '--yaw', cam_yaw, '--pitch', cam_pitch, '--roll', cam_roll, 
            '--frame-id', 'tcp_link', '--child-frame-id', 'camera_link'
        ] 
    )

    # 5. Start the Demo State Machine
    demo_node = Node(
        package='uarm_apriltag_demo',
        executable='demo_node',
        name='demo_node',
        output='screen',
        parameters=[demo_config_file]
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
        arguments=[
            '--x', tcp_x, '--y', tcp_y, '--z', tcp_z, 
            '--yaw', tcp_yaw, '--pitch', tcp_pitch, '--roll', tcp_roll, 
            '--frame-id', 'Link8', '--child-frame-id', 'tcp_link'
        ]
    )

    return LaunchDescription([
        use_rviz_arg,
        arm_controller_launch,
        realsense_launch,
        apriltag_detector,
        camera_tf_node,
        demo_node,
        rviz_node,
        tcp_tf_node
    ])
