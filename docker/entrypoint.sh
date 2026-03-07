#!/bin/bash
set -e

# Setup ROS 2 environment
source /opt/ros/jazzy/setup.bash

# Setup local workspace if it exists (for native builds inside Docker)
if [ -f /home/ros2/ros2_ws/install/setup.bash ]; then
    source /home/ros2/ros2_ws/install/setup.bash
fi

# Execute the specified command
exec "$@"
