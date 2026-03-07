from setuptools import find_packages, setup
import os
from glob import glob

package_name = 'uarm_brain'

setup(
    name=package_name,
    version='0.0.1',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name, 'launch'), glob(os.path.join('launch', '*launch.[pxy][yma]*'))),
        (os.path.join('share', package_name, 'config'), glob(os.path.join('config', '*.yaml'))),
        (os.path.join('share', package_name, 'launch'), glob(os.path.join('launch', 'operator_launch.py'))),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='ros2',
    maintainer_email='ros2@todo.todo',
    description='Brain package with Task Planner and Task Manager for uArm robot',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'task_planner_node = uarm_brain.task_planner_node:main',
            'task_manager_node = uarm_brain.task_manager_node:main',
        ],
    },
)
