#!/bin/bash
source /opt/ros/jazzy/setup.bash
source install/setup.bash
ros2 action send_goal /brain/load_bag uarm_interfaces/action/LoadBag "{bag_path: '/home/ros2/ros2_ws/Example BAG FIles/test_03_bag2'}"
