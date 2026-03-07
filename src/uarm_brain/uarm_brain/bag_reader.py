"""
bag_reader.py
=============
Unified reader for ROS1 (.bag) and ROS2 (rosbag2) bag files.

For ROS1 bags: uses the pure-Python `rosbags` library
    pip install rosbags
For ROS2 bags: uses rosbag2_py (available inside the ROS2 Docker container)

The reader always returns a flat list of task-dicts matching the
schema produced by generate_bags.py:

    {
        "subtask_type":  int,    # SubtaskType enum value  (10=PICK, 20=PLACE …)
        "subtask_name":  str,    # "Pick" / "Place" / …
        "workstation":   str,    # "WS01" / "SH01" / …
        "ws_height":     str,    # "0cm" / "5cm" / …
        "ws_type":       int,    # WorkstationType enum value
        "object_id":     int,
        "object_name":   str,
        "container_id":  int,
    }

The task messages inside the bag are expected to be published as
std_msgs/String (JSON-encoded list of the above dicts) on the topic
that is passed as `topic_name` (default "/task_list").
"""

from __future__ import annotations
import json
import logging
import os
import struct
from typing import List, Dict, Any

logger = logging.getLogger(__name__)


# ---------------------------------------------------------------------------
# Public API
# ---------------------------------------------------------------------------

def read_bag(bag_path: str, topic_name: str = "/task_list") -> List[Dict[str, Any]]:
    """
    Read tasks from a ROS1 or ROS2 bag file.

    Parameters
    ----------
    bag_path   : Absolute path to the bag file / directory.
    topic_name : Topic that contains std_msgs/String (JSON task list).

    Returns
    -------
    List of task dicts (flat list, one dict per subtask row).
    Raises FileNotFoundError if the path does not exist.
    Raises RuntimeError if no suitable library is found.
    """
    if not os.path.exists(bag_path):
        raise FileNotFoundError(f"Bag file not found: {bag_path}")

    # Detect format
    if os.path.isfile(bag_path) and bag_path.endswith(".bag"):
        logger.info("Detected ROS1 bag format: %s", bag_path)
        return _read_ros1_bag(bag_path, topic_name)
    elif os.path.isdir(bag_path):
        logger.info("Detected ROS2 bag directory: %s", bag_path)
        return _read_ros2_bag(bag_path, topic_name)
    else:
        # Try ROS2 (could be a file without extension for some storage plugins)
        logger.info("Trying ROS2 reader for: %s", bag_path)
        return _read_ros2_bag(bag_path, topic_name)


# ---------------------------------------------------------------------------
# ROS1 reader  (via `rosbags` – pure Python, no ROS1 needed)
# ---------------------------------------------------------------------------

def _read_ros1_bag(bag_path: str, topic_name: str) -> List[Dict[str, Any]]:
    """Read tasks from a ROS1 .bag file using the `rosbags` library."""
    try:
        from rosbags.rosbag1 import Reader as Ros1Reader
        from rosbags.typesys import Stores, get_typestore
    except ImportError as exc:
        raise RuntimeError(
            "ROS1 bag reading requires the `rosbags` library. "
            "Install it inside the container:  pip install rosbags"
        ) from exc

    typestore = get_typestore(Stores.ROS1_NOETIC)
    tasks: List[Dict[str, Any]] = []

    with Ros1Reader(bag_path) as bag:
        connections = [c for c in bag.connections if c.topic == topic_name]
        if not connections:
            available = sorted({c.topic for c in bag.connections})
            raise RuntimeError(
                f"Topic '{topic_name}' not found in ROS1 bag.\n"
                f"Available topics: {available}"
            )

        for _connection, _timestamp, rawdata in bag.messages(connections=connections):
            msg = typestore.deserialize_ros1(rawdata, connections[0].msgtype)
            tasks.extend(_parse_json_message(msg.data, bag_path))

    logger.info("ROS1 bag: read %d tasks from '%s'", len(tasks), topic_name)
    return tasks


# ---------------------------------------------------------------------------
# ROS2 reader  (via rosbag2_py – available inside ROS2 environment)
# ---------------------------------------------------------------------------

def _read_ros2_bag(bag_path: str, topic_name: str) -> List[Dict[str, Any]]:
    """Read tasks from a ROS2 bag using rosbag2_py."""
    try:
        import rosbag2_py
        from rclpy.serialization import deserialize_message
        from std_msgs.msg import String
    except ImportError as exc:
        raise RuntimeError(
            "ROS2 bag reading requires rosbag2_py (available in the ROS2 environment). "
            "Make sure you have sourced the ROS2 workspace."
        ) from exc

    storage_options = rosbag2_py.StorageOptions(uri=bag_path, storage_id="")
    converter_options = rosbag2_py.ConverterOptions(
        input_serialization_format="cdr",
        output_serialization_format="cdr"
    )

    reader = rosbag2_py.SequentialReader()
    reader.open(storage_options, converter_options)

    topic_types = reader.get_all_topics_and_types()
    type_map = {t.name: t.type for t in topic_types}

    if topic_name not in type_map:
        available = sorted(type_map.keys())
        raise RuntimeError(
            f"Topic '{topic_name}' not found in ROS2 bag.\n"
            f"Available topics: {available}"
        )

    tasks: List[Dict[str, Any]] = []
    while reader.has_next():
        (topic, raw_data, _) = reader.read_next()
        if topic == topic_name:
            msg = deserialize_message(raw_data, String)
            tasks.extend(_parse_json_message(msg.data, bag_path))

    logger.info("ROS2 bag: read %d tasks from '%s'", len(tasks), topic_name)
    return tasks


# ---------------------------------------------------------------------------
# Helpers
# ---------------------------------------------------------------------------

def _parse_json_message(json_str: str, source: str) -> List[Dict[str, Any]]:
    """
    Parse a JSON string that encodes a list of task dicts.

    Accepts two formats:
      1. A JSON list:   [{"subtask_type": 10, ...}, ...]
      2. A JSON dict:   {"subtask_type": 10, ...}  (single task, wrapped in list)
    """
    try:
        data = json.loads(json_str)
    except json.JSONDecodeError as exc:
        logger.warning("Could not decode JSON from bag message in %s: %s", source, exc)
        return []

    if isinstance(data, dict):
        data = [data]

    result = []
    for item in data:
        task = {
            "subtask_type": int(item.get("subtask_type", item.get("Subtask-Type", 0))),
            "subtask_name": str(item.get("subtask_name", item.get("Subtask-Name", "Unknown"))),
            "workstation":  str(item.get("workstation",  item.get("Workstation-Name", "?"))),
            "ws_height":    str(item.get("ws_height",    item.get("Workstation-Height", "0cm"))),
            "ws_type":      int(item.get("ws_type",      item.get("Workstation-Type", 0))),
            "object_id":    int(item.get("object_id",    item.get("Object-ID", 0))),
            "object_name":  str(item.get("object_name",  item.get("Object-name", "Unknown"))),
            "container_id": int(item.get("container_id", item.get("Container-ID", 0))),
        }
        result.append(task)
    return result
