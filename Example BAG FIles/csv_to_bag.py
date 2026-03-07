import rclpy
from rclpy.serialization import serialize_message
import rosbag2_py
from std_msgs.msg import String
import json
import csv
import time
import os
import shutil

bag_dir = 'test_03_bag2'
if os.path.exists(bag_dir):
    shutil.rmtree(bag_dir)

tasks = []
with open("test_03.csv", newline='') as f:
    for row in csv.DictReader(f):
        tasks.append(row)

writer = rosbag2_py.SequentialWriter()
storage_options = rosbag2_py.StorageOptions(uri=bag_dir, storage_id='sqlite3')
converter_options = rosbag2_py.ConverterOptions(input_serialization_format='cdr', output_serialization_format='cdr')
writer.open(storage_options, converter_options)

topic_info = rosbag2_py.TopicMetadata(
    id=0,
    name='/task_list',
    type='std_msgs/msg/String',
    serialization_format='cdr'
)
writer.create_topic(topic_info)

msg = String()
msg.data = json.dumps(tasks)
writer.write('/task_list', serialize_message(msg), int(time.time() * 1e9))

print(f"ROS2 bag {bag_dir} created successfully!")
