/*
 * Software License Agreement (BSD License)
 * Copyright (c) 2017, UFactory, Inc.
 * All rights reserved.
 * Author: Roger Cui  <roger@ufactory.cc>
 *         David Long <xiaokun.long@ufactory.cc>
 *
 * ROS2 port: 2026
 */
#include <string>
#include <chrono>
#include <thread>
#include <memory>
#include <cstring>

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

#include "swiftpro/msg/swiftpro_state.hpp"
#include "swiftpro/serial_port.hpp"

using namespace std::chrono_literals;


class SwiftproReadNode : public rclcpp::Node
{
public:
  SwiftproReadNode() : Node("swiftpro_read_node")
  {
    pub_ = create_publisher<swiftpro::msg::SwiftproState>("SwiftproState_topic", 1);

    // ── Serial ──
    serial_.setPort("/dev/ttyACM0");
    serial_.setBaudrate(115200);
    serial_.setTimeout(1000);

    try {
      serial_.open();
      RCLCPP_INFO(get_logger(), "Port has been opened successfully");
    } catch (const std::runtime_error & e) {
      RCLCPP_ERROR(get_logger(), "Unable to open port: %s", e.what());
      rclcpp::shutdown();
      return;
    }

    if (serial_.isOpen()) {
      std::this_thread::sleep_for(3000ms);
      serial_.write("M2019\r\n");           // detach
      std::this_thread::sleep_for(500ms);
      serial_.write("M2120 V0.05\r\n");     // report position every 0.05 s
      RCLCPP_INFO(get_logger(), "Start to report data");
    }

    // ── Timer at 20 Hz ──
    timer_ = create_wall_timer(50ms, std::bind(&SwiftproReadNode::timer_callback, this));
  }

private:
  void timer_callback()
  {
    size_t avail = serial_.available();
    if (avail == 0) return;

    std::string data = serial_.read(avail);
    for (size_t i = 0; i < data.length(); i++)
      handlechar(data[i]);

    swiftpro::msg::SwiftproState state;
    state.pump              = 0;
    state.gripper           = 0;
    state.swiftpro_status   = 0;
    state.motor_angle1      = 0.0;
    state.motor_angle2      = 0.0;
    state.motor_angle3      = 0.0;
    state.motor_angle4      = position_[3];
    state.x                 = position_[0];
    state.y                 = position_[1];
    state.z                 = position_[2];
    pub_->publish(state);

    RCLCPP_INFO(get_logger(), "position: %.2f %.2f %.2f %.2f",
                position_[0], position_[1], position_[2], position_[3]);
  }

  // ── Serial string handling (unchanged logic) ─────────────────────
  void handlechar(char c)
  {
    switch (c) {
      case '\r':
        break;
      case '\n':
        strdata_[str_index_] = '\0';
        handlestr();
        str_index_ = 0;
        break;
      default:
        if (str_index_ < sizeof(strdata_) - 1)
          strdata_[str_index_++] = c;
        break;
    }
  }

  void handlestr()
  {
    char * pch = strtok(strdata_, " ");
    float value[8] = {};
    int index = 0;

    while (pch != nullptr && index < 5) {
      value[index] = atof(pch + 1);
      pch = strtok(nullptr, " ");
      index++;
    }
    position_[0] = value[1];
    position_[1] = value[2];
    position_[2] = value[3];
    position_[3] = value[4];
  }

  // ── Members ─────────────────────────────────────────────────────
  SerialPort serial_;
  rclcpp::Publisher<swiftpro::msg::SwiftproState>::SharedPtr pub_;
  rclcpp::TimerBase::SharedPtr timer_;

  float position_[4] = {0.0f};
  char  strdata_[2048] = {};
  int   str_index_ = 0;
};


int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<SwiftproReadNode>());
  rclcpp::shutdown();
  return 0;
}
