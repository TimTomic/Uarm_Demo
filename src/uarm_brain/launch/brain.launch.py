"""
brain.launch.py
===============
Starts the complete uArm Brain stack on feature/arm_controller_cpp:

  1. uArm SwiftPro driver            (from uarm_arm_controller launch)
  2. Arm Controller Node             (pick_and_place + drive_to_pose actions)
  3. USB camera + AprilTag detection
  4. Task Planner node
  5. Task Manager node

Usage
-----
  ros2 launch uarm_brain brain.launch.py bag_file:=/path/to/tasks.bag
  ros2 launch uarm_brain brain.launch.py bag_file:=... dry_run:=true use_rviz:=false

Launch arguments
----------------
  use_rviz   [true/false]  RViz2 (default: false)
  bag_file   [string]      Path to .bag file (auto-loaded on start)
  dry_run    [true/false]  Log arm commands without executing (default: false)
"""

import os
import yaml

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.conditions import IfCondition
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def _yaml_params(package, config_file):
    path = os.path.join(get_package_share_directory(package), 'config', config_file)
    with open(path, 'r') as f:
        return yaml.safe_load(f)


def generate_launch_description():

    # ------------------------------------------------------------------ args
    use_rviz_arg = DeclareLaunchArgument('use_rviz', default_value='false')
    bag_file_arg = DeclareLaunchArgument('bag_file', default_value='',
        description='Path to .bag file to load on startup')
    dry_run_arg  = DeclareLaunchArgument('dry_run',  default_value='false',
        description='Dry-run: log arm commands, do not call action servers')

    use_rviz = LaunchConfiguration('use_rviz')
    bag_file = LaunchConfiguration('bag_file')
    dry_run  = LaunchConfiguration('dry_run')

    # --------------------------------------------------------------- configs
    brain_config = os.path.join(
        get_package_share_directory('uarm_brain'), 'config', 'brain_config.yaml')

    arm_controller_config = os.path.join(
        get_package_share_directory('uarm_arm_controller'), 'config', 'poses.yaml')

    demo_cfg = _yaml_params('uarm_apriltag_demo', 'demo_config.yaml')
    demo_p   = demo_cfg.get('/**', {}).get('ros__parameters', {})
    cam_x = str(demo_p.get('camera_x_offset', '0.025'))
    cam_y = str(demo_p.get('camera_y_offset', '0.010'))
    cam_z = str(demo_p.get('camera_z_offset', '0.010'))

    # ------------------------------------------------------- 1. SwiftPro driver
    swiftpro_launch_dir = os.path.join(
        get_package_share_directory('swiftpro'), 'launch')
    swiftpro_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(swiftpro_launch_dir, 'pro_control.launch.py')))

    # ------------------------------------------------------- 2. Arm Controller
    arm_controller_node = Node(
        package='uarm_arm_controller',
        executable='arm_controller_node',
        name='arm_controller_node',
        output='screen',
        parameters=[arm_controller_config],
    )

    # ------------------------------------------------------- 3. AprilTag + Camera
    apriltag_launch_dir = os.path.join(
        get_package_share_directory('apriltag_launcher'), 'launch')
    apriltag_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(apriltag_launch_dir, 'apriltag_usb_cam.launch.py')),
        launch_arguments={
            'camera_x_offset': cam_x,
            'camera_y_offset': cam_y,
            'camera_z_offset': cam_z,
        }.items())

    # ------------------------------------------------------- 4. Task Planner
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

    # ------------------------------------------------------- 5. Task Manager
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

    # ------------------------------------------------------- 6. Optional RViz
    rviz_config = os.path.join(
        get_package_share_directory('uarm_apriltag_demo'), 'rviz', 'demo.rviz')
    rviz_node = Node(
        package='rviz2', executable='rviz2', name='rviz2',
        arguments=['-d', rviz_config],
        output='screen',
        condition=IfCondition(use_rviz),
    )

    return LaunchDescription([
        use_rviz_arg,
        bag_file_arg,
        dry_run_arg,
        swiftpro_launch,
        arm_controller_node,
        apriltag_launch,
        task_planner,
        task_manager,
        rviz_node,
    ])
