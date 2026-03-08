"""
ROS2 Launch file for uArm Swift Pro control.
Starts: swiftpro_write_node, swiftpro_rviz_node, robot_state_publisher
"""
import os
from launch import LaunchDescription
from launch_ros.actions import Node
from launch_ros.parameter_descriptions import ParameterValue
from launch.substitutions import Command
from ament_index_python.packages import get_package_share_directory


def generate_launch_description():
    pkg_share = get_package_share_directory('swiftpro')
    xacro_file = os.path.join(pkg_share, 'urdf', 'pro_model.xacro')

    # If xacro is installed, process the file; otherwise fall back to cat
    try:
        robot_description = Command(['xacro ', xacro_file])
    except Exception:
        with open(xacro_file, 'r') as f:
            robot_description = f.read()

    from launch.actions import DeclareLaunchArgument
    from launch.substitutions import LaunchConfiguration

    port_arg = DeclareLaunchArgument(
        'port', default_value='/dev/ttyACM1',
        description='Serial port for the uArm'
    )
    port = LaunchConfiguration('port')

    return LaunchDescription([
        port_arg,
        Node(
            package='swiftpro',
            executable='swiftpro_write_node',
            name='swiftpro_write_node',
            output='screen',
            parameters=[{'port': port}]
        ),
        Node(
            package='swiftpro',
            executable='swiftpro_rviz_node',
            name='swiftpro_rviz_node',
            output='screen',
        ),
        Node(
            package='robot_state_publisher',
            executable='robot_state_publisher',
            name='robot_state_publisher',
            parameters=[{'robot_description': ParameterValue(robot_description, value_type=str)}],
            output='screen',
        ),
    ])
