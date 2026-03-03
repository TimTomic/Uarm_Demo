import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    poses_config_file = os.path.join(
        get_package_share_directory('uarm_arm_controller'),
        'config',
        'poses.yaml'
    )

    arm_controller_node = Node(
        package='uarm_arm_controller',
        executable='arm_controller_node',
        name='arm_controller_node',
        output='screen',
        parameters=[poses_config_file]
    )

    return LaunchDescription([
        arm_controller_node
    ])
