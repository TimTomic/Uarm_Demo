"""
operator_monitoring.launch.py
=============================
Starts the tools required for the remote Operator (RViz, Joy, Teleop).

This launch file is intended to run on the Operator's Laptop or Remote-PC
via the operator-compose.yml Docker environment.

Nodes Started:
  1. RViz2 (with pre-configured operator.rviz)
  2. joy_node (reads /dev/input/js* from PS5 controller)
  3. teleop_twist_joy (translates gamepad to /cmd_vel)
"""

import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():

    # 1. RViz2
    rviz_config_file = os.path.join(
        get_package_share_directory('uarm_brain'), 'rviz', 'operator.rviz')
        
    rviz_node = Node(
        package='rviz2',
        executable='rviz2',
        name='rviz_operator',
        arguments=['-d', rviz_config_file],
        output='screen'
    )

    # 2. Joy Node (reads the PS5 controller connected to the laptop)
    joy_node = Node(
        package='joy',
        executable='joy_node',
        name='joy_node',
        parameters=[{
            'dev': '/dev/input/js0',  # Typical path for first connected gamepad
            'deadzone': 0.1,
            'autorepeat_rate': 20.0,
        }],
        output='screen'
    )

    # 3. Teleop Twist Joy (translates /joy into /cmd_vel)
    # Using default PS4/PS5 mapping config included in teleop_twist_joy
    teleop_config = os.path.join(
        get_package_share_directory('teleop_twist_joy'), 'config', 'ps3.config.yaml')
        
    teleop_node = Node(
        package='teleop_twist_joy',
        executable='teleop_node',
        name='teleop_twist_joy_node',
        parameters=[teleop_config], # You might want to remap cmd_vel if needed
        output='screen'
    )

    return LaunchDescription([
        rviz_node,
        joy_node,
        teleop_node
    ])
