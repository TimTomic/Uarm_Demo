import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node

from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource

def generate_launch_description():
    poses_config_file = os.path.join(
        get_package_share_directory('uarm_arm_controller'),
        'config',
        'poses.yaml'
    )
    
    # Use the SOURCE version of the demo config to avoid install caching issues
    demo_config_file = "/home/ros2/ros2_ws/src/uarm_apriltag_demo/config/demo_config.yaml"

    arm_controller_node = Node(
        package='uarm_arm_controller',
        executable='arm_controller_node',
        name='arm_controller_node',
        output='screen',
        parameters=[poses_config_file, demo_config_file]
    )

    swiftpro_launch_dir = os.path.join(get_package_share_directory('swiftpro'), 'launch')
    swiftpro_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(os.path.join(swiftpro_launch_dir, 'pro_control.launch.py')),
        launch_arguments={'port': '/dev/serial/by-id/usb-Arduino__www.arduino.cc__Arduino_Mega_2560_8573031373635160D0A1-if00'}.items()
    )

    return LaunchDescription([
        swiftpro_launch,
        arm_controller_node
    ])
