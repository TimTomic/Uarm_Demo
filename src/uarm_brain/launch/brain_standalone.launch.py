"""
brain_standalone.launch.py
==========================
Starts ONLY the uArm Brain stack (Planner + Manager).
Intended to be run in its own standalone Docker container.

Assumes that Vision and Arm Controller are running in other containers
and communicating over the shared ROS 2 network.

Usage
-----
  ros2 launch uarm_brain brain_standalone.launch.py bag_file:=/path/to/tasks.bag
"""

import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node

def generate_launch_description():
    bag_file_arg = DeclareLaunchArgument('bag_file', default_value='',
        description='Path to .bag file to load on startup')
    dry_run_arg  = DeclareLaunchArgument('dry_run',  default_value='false',
        description='Dry-run: log arm commands, do not call action servers')

    bag_file = LaunchConfiguration('bag_file')
    dry_run  = LaunchConfiguration('dry_run')

    brain_config = os.path.join(
        get_package_share_directory('uarm_brain'), 'config', 'brain_config.yaml')

    task_planner = Node(
        package='uarm_brain',
        executable='task_planner_node',
        name='task_planner_node',
        output='screen',
        parameters=[
            brain_config,
            {'bag_file_path': bag_file},
        ],
    )

    task_manager = Node(
        package='uarm_brain',
        executable='task_manager_node',
        name='task_manager_node',
        output='screen',
        parameters=[
            brain_config,
            {'dry_run': dry_run},
        ],
    )

    return LaunchDescription([
        bag_file_arg,
        dry_run_arg,
        task_planner,
        task_manager,
    ])
