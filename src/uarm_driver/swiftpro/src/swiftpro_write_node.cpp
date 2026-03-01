/*
 * Software License Agreement (BSD License)
 * Copyright (c) 2017, UFactory, Inc.
 * All rights reserved.
 * Author: Roger Cui  <roger@ufactory.cc>
 *
 * ROS2 port: 2026
 */
#include <string>
#include <mutex>
#include <chrono>
#include <thread>
#include <deque>
#include <memory>
#include <vector>
#include <sstream>
#include <cmath>

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>
#include <sensor_msgs/msg/joint_state.hpp>

#include "swiftpro/msg/swiftpro_state.hpp"
#include "swiftpro/msg/position.hpp"
#include "swiftpro/msg/status.hpp"
#include "swiftpro/msg/angle4th.hpp"

#include "swiftpro/serial_port.hpp"

using namespace std::chrono_literals;
using LockGuard = std::lock_guard<std::mutex>;

// ═══════════════════════════════════════════════════════════════════
//  Event base + concrete commands  (unchanged logic, new serial API)
// ═══════════════════════════════════════════════════════════════════

class Event
{
public:
  virtual ~Event() = default;
  virtual void action() {}

protected:
  static std::string send_command(SerialPort & serial, const std::string & cmd)
  {
    serial.flushInput();
    serial.write(cmd);
    return serial.readline(100, "\r\n");
  }
};

// ── Position write ──────────────────────────────────────────────────
class EventPositionWrite : public Event
{
public:
  explicit EventPositionWrite(SerialPort & s, const swiftpro::msg::Position & msg,
                              rclcpp::Logger logger)
    : serial_(s), msg_(msg), logger_(logger) {}

  void action() override
  {
    char x[10], y[10], z[10];
    snprintf(x, sizeof(x), "%.2f", msg_.x);
    snprintf(y, sizeof(y), "%.2f", msg_.y);
    snprintf(z, sizeof(z), "%.2f", msg_.z);
    std::string gcode = std::string("G0 X") + x + " Y" + y + " Z" + z + " F10000\r\n";
    RCLCPP_INFO(logger_, "%s", gcode.c_str());
    send_command(serial_, gcode);
  }

private:
  SerialPort & serial_;
  swiftpro::msg::Position msg_;
  rclcpp::Logger logger_;
};

// ── 4th axis angle ──────────────────────────────────────────────────
class EventAngle4th : public Event
{
public:
  EventAngle4th(SerialPort & s, const swiftpro::msg::Angle4th & msg,
                std::mutex & mtx, swiftpro::msg::SwiftproState & pos,
                rclcpp::Logger logger)
    : serial_(s), msg_(msg), mtx_(mtx), pos_(pos), logger_(logger) {}

  void action() override
  {
    char m4[10];
    {
      LockGuard guard(mtx_);
      pos_.motor_angle4 = msg_.angle4th;
    }
    snprintf(m4, sizeof(m4), "%.2f", msg_.angle4th);
    std::string gcode = std::string("G2202 N3 V") + m4 + "\r\n";
    RCLCPP_INFO(logger_, "%s", gcode.c_str());
    send_command(serial_, gcode);
  }

private:
  SerialPort & serial_;
  swiftpro::msg::Angle4th msg_;
  std::mutex & mtx_;
  swiftpro::msg::SwiftproState & pos_;
  rclcpp::Logger logger_;
};

// ── Status (attach / detach) ────────────────────────────────────────
class EventStatus : public Event
{
public:
  EventStatus(SerialPort & s, const swiftpro::msg::Status & msg,
              std::mutex & mtx, swiftpro::msg::SwiftproState & pos,
              rclcpp::Logger logger)
    : serial_(s), msg_(msg), mtx_(mtx), pos_(pos), logger_(logger) {}

  void action() override
  {
    std::string gcode;
    if (msg_.status == 1)
      gcode = "M17\r\n";
    else if (msg_.status == 0)
      gcode = "M2019\r\n";
    else {
      RCLCPP_INFO(logger_, "Error: Wrong swiftpro status input");
      return;
    }
    {
      LockGuard guard(mtx_);
      pos_.swiftpro_status = msg_.status;
    }
    RCLCPP_INFO(logger_, "%s", gcode.c_str());
    send_command(serial_, gcode);
  }

private:
  SerialPort & serial_;
  swiftpro::msg::Status msg_;
  std::mutex & mtx_;
  swiftpro::msg::SwiftproState & pos_;
  rclcpp::Logger logger_;
};

// ── Gripper ─────────────────────────────────────────────────────────
class EventGripper : public Event
{
public:
  EventGripper(SerialPort & s, const swiftpro::msg::Status & msg,
               std::mutex & mtx, swiftpro::msg::SwiftproState & pos,
               rclcpp::Logger logger)
    : serial_(s), msg_(msg), mtx_(mtx), pos_(pos), logger_(logger) {}

  void action() override
  {
    std::string gcode;
    if (msg_.status == 1)
      gcode = "M2232 V1\r\n";
    else if (msg_.status == 0)
      gcode = "M2232 V0\r\n";
    else {
      RCLCPP_INFO(logger_, "Error: Wrong gripper status input");
      return;
    }
    {
      LockGuard guard(mtx_);
      pos_.gripper = msg_.status;
    }
    RCLCPP_INFO(logger_, "%s", gcode.c_str());
    send_command(serial_, gcode);
  }

private:
  SerialPort & serial_;
  swiftpro::msg::Status msg_;
  std::mutex & mtx_;
  swiftpro::msg::SwiftproState & pos_;
  rclcpp::Logger logger_;
};

// ── Pump ────────────────────────────────────────────────────────────
class EventPump : public Event
{
public:
  EventPump(SerialPort & s, const swiftpro::msg::Status & msg,
            std::mutex & mtx, swiftpro::msg::SwiftproState & pos,
            rclcpp::Logger logger)
    : serial_(s), msg_(msg), mtx_(mtx), pos_(pos), logger_(logger) {}

  void action() override
  {
    std::string gcode;
    if (msg_.status == 1)
      gcode = "M2231 V1\r\n";
    else if (msg_.status == 0)
      gcode = "M2231 V0\r\n";
    else {
      RCLCPP_INFO(logger_, "Error: Wrong pump status input");
      return;
    }
    {
      LockGuard guard(mtx_);
      pos_.pump = msg_.status;
    }
    RCLCPP_INFO(logger_, "%s", gcode.c_str());
    send_command(serial_, gcode);
  }

private:
  SerialPort & serial_;
  swiftpro::msg::Status msg_;
  std::mutex & mtx_;
  swiftpro::msg::SwiftproState & pos_;
  rclcpp::Logger logger_;
};

// ── Read joint angles ───────────────────────────────────────────────
class EventGetJoints : public Event
{
public:
  EventGetJoints(SerialPort & s,
                 rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr pub,
                 std::mutex & mtx, swiftpro::msg::SwiftproState & pos,
                 rclcpp::Node & node)
    : serial_(s), pub_(pub), mtx_(mtx), pos_(pos), node_(node) {}

  void action() override
  {
    std::vector<float> p = {0, 0, 0};
    std::string result = send_command(serial_, "P2200\r\n");

    if (result.length() > 3 && result.length() < 30) {
      std::stringstream ss(result);
      std::string token;
      ss >> token;
      if (token == "ok") {
        while (ss >> token) {
          if (token[0] == 'X' || token[0] == 'B')
            p[0] = std::stof(token.substr(1));
          else if (token[0] == 'Y' || token[0] == 'L')
            p[1] = std::stof(token.substr(1));
          else if (token[0] == 'Z' || token[0] == 'R')
            p[2] = std::stof(token.substr(1));
        }
      }

      if (p[0] != 0 && p[1] != 0 && p[2] != 0) {
        p[0] =   p[0] - 90.0f;
        p[1] = - p[1] + 90.0f;
        p[2] =   p[2];

        for (auto & e : p)
          e = e / 180.0f * static_cast<float>(M_PI);

        sensor_msgs::msg::JointState joint_state;
        joint_state.header.stamp = node_.now();
        joint_state.name  = {"Joint1", "Joint2", "Joint3", "Joint8"};
        joint_state.position = {p[0], p[1], p[2], static_cast<double>(-p[1] - p[2])};
        pub_->publish(joint_state);

        {
          LockGuard guard(mtx_);
          pos_.motor_angle1 = p[0];
          pos_.motor_angle2 = p[1];
          pos_.motor_angle3 = p[2];
          pos_.motor_angle4 = -p[1] - p[2];
        }
      }
    }
  }

private:
  SerialPort & serial_;
  rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr pub_;
  std::mutex & mtx_;
  swiftpro::msg::SwiftproState & pos_;
  rclcpp::Node & node_;
};

// ── Read cartesian position ─────────────────────────────────────────
class EventGetPosition : public Event
{
public:
  EventGetPosition(SerialPort & s, std::mutex & mtx, swiftpro::msg::SwiftproState & pos)
    : serial_(s), mtx_(mtx), pos_(pos) {}

  void action() override
  {
    std::vector<float> p = {0, 0, 0};
    std::string result = send_command(serial_, "P2220\r\n");

    if (result.length() > 3 && result.length() < 30) {
      std::stringstream ss(result);
      std::string token;
      ss >> token;
      if (token == "ok") {
        while (ss >> token) {
          if (token[0] == 'X' || token[0] == 'B')
            p[0] = std::stof(token.substr(1));
          else if (token[0] == 'Y' || token[0] == 'L')
            p[1] = std::stof(token.substr(1));
          else if (token[0] == 'Z' || token[0] == 'R')
            p[2] = std::stof(token.substr(1));
        }
        {
          LockGuard guard(mtx_);
          pos_.x = p[0];
          pos_.y = p[1];
          pos_.z = p[2];
        }
      }
    }
  }

private:
  SerialPort & serial_;
  std::mutex & mtx_;
  swiftpro::msg::SwiftproState & pos_;
};

// ── Read limit switch ───────────────────────────────────────────────
class EventGetLimitSwitch : public Event
{
public:
  EventGetLimitSwitch(SerialPort & s, std::mutex & mtx, swiftpro::msg::SwiftproState & pos)
    : serial_(s), mtx_(mtx), pos_(pos) {}

  void action() override
  {
    int limit_switch = 0;
    std::string result = send_command(serial_, "P2233\r\n");

    if (result.length() > 3 && result.length() < 30) {
      std::stringstream ss(result);
      std::string token;
      ss >> token;
      if (token == "ok") {
        while (ss >> token) {
          if (token[0] == 'V')
            limit_switch = std::stoi(token.substr(1));
        }
        {
          LockGuard guard(mtx_);
          pos_.limit_switch = limit_switch;
        }
      }
    }
  }

private:
  SerialPort & serial_;
  std::mutex & mtx_;
  swiftpro::msg::SwiftproState & pos_;
};


// ═══════════════════════════════════════════════════════════════════
//  SwiftproWriteNode
// ═══════════════════════════════════════════════════════════════════
class SwiftproWriteNode : public rclcpp::Node
{
public:
  SwiftproWriteNode() : Node("swiftpro_write_node")
  {
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
      std::this_thread::sleep_for(3500ms);
      serial_.write("M2120 V0\r\n");   // stop report position
      std::this_thread::sleep_for(100ms);
      serial_.write("M17\r\n");        // attach
      std::this_thread::sleep_for(100ms);
      RCLCPP_INFO(get_logger(), "Attach and wait for commands");
    }

    // ── Publishers ──
    pub_state_ = create_publisher<swiftpro::msg::SwiftproState>("SwiftproState_topic", 1);
    pub_joints_ = create_publisher<sensor_msgs::msg::JointState>("joint_states", 1);

    // ── Subscribers ──
    sub_pos_ = create_subscription<swiftpro::msg::Position>(
      "position_write_topic", 1,
      [this](const swiftpro::msg::Position & msg) {
        LockGuard guard(mutex_);
        event_queue_.push_back(
          std::make_unique<EventPositionWrite>(serial_, msg, get_logger()));
      });

    sub_status_ = create_subscription<swiftpro::msg::Status>(
      "swiftpro_status_topic", 1,
      [this](const swiftpro::msg::Status & msg) {
        LockGuard guard(mutex_);
        event_queue_.push_back(
          std::make_unique<EventStatus>(serial_, msg, mutex_pos_, pos_, get_logger()));
      });

    sub_angle4th_ = create_subscription<swiftpro::msg::Angle4th>(
      "angle4th_topic", 1,
      [this](const swiftpro::msg::Angle4th & msg) {
        LockGuard guard(mutex_);
        event_queue_.push_back(
          std::make_unique<EventAngle4th>(serial_, msg, mutex_pos_, pos_, get_logger()));
      });

    sub_gripper_ = create_subscription<swiftpro::msg::Status>(
      "gripper_topic", 1,
      [this](const swiftpro::msg::Status & msg) {
        LockGuard guard(mutex_);
        event_queue_.push_back(
          std::make_unique<EventGripper>(serial_, msg, mutex_pos_, pos_, get_logger()));
      });

    sub_pump_ = create_subscription<swiftpro::msg::Status>(
      "pump_topic", 1,
      [this](const swiftpro::msg::Status & msg) {
        LockGuard guard(mutex_);
        event_queue_.push_back(
          std::make_unique<EventPump>(serial_, msg, mutex_pos_, pos_, get_logger()));
      });

    // ── Timer (≈ 100 Hz main loop) ──
    timer_ = create_wall_timer(10ms, std::bind(&SwiftproWriteNode::timer_callback, this));
    last_query_ = std::chrono::high_resolution_clock::now();
  }

private:
  void timer_callback()
  {
    auto now = std::chrono::high_resolution_clock::now();
    if ((now - last_query_) > 200ms) {
      LockGuard guard(mutex_);
      event_queue_.push_front(
        std::make_unique<EventGetJoints>(serial_, pub_joints_, mutex_pos_, pos_, *this));
      event_queue_.push_front(
        std::make_unique<EventGetPosition>(serial_, mutex_pos_, pos_));
      event_queue_.push_front(
        std::make_unique<EventGetLimitSwitch>(serial_, mutex_pos_, pos_));
      last_query_ = now;
    }

    {
      LockGuard guard(mutex_);
      while (!event_queue_.empty()) {
        event_queue_.front()->action();
        event_queue_.pop_front();
      }
    }

    {
      LockGuard guard(mutex_pos_);
      pub_state_->publish(pos_);
    }
  }

  // ── Members ──
  SerialPort serial_;
  swiftpro::msg::SwiftproState pos_;
  std::deque<std::unique_ptr<Event>> event_queue_;
  std::mutex mutex_;
  std::mutex mutex_pos_;
  std::chrono::high_resolution_clock::time_point last_query_;

  rclcpp::Publisher<swiftpro::msg::SwiftproState>::SharedPtr pub_state_;
  rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr pub_joints_;
  rclcpp::Subscription<swiftpro::msg::Position>::SharedPtr sub_pos_;
  rclcpp::Subscription<swiftpro::msg::Status>::SharedPtr sub_status_;
  rclcpp::Subscription<swiftpro::msg::Angle4th>::SharedPtr sub_angle4th_;
  rclcpp::Subscription<swiftpro::msg::Status>::SharedPtr sub_gripper_;
  rclcpp::Subscription<swiftpro::msg::Status>::SharedPtr sub_pump_;
  rclcpp::TimerBase::SharedPtr timer_;
};


// ═══════════════════════════════════════════════════════════════════
int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<SwiftproWriteNode>());
  rclcpp::shutdown();
  return 0;
}
