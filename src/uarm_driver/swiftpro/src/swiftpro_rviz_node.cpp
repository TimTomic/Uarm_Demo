/*
 * Software License Agreement (BSD License)
 * Copyright (c) 2017, UFactory, Inc.
 * All rights reserved.
 * Author: Roger Cui  <roger@ufactory.cc>
 *
 * ROS2 port: 2026
 */
#include <string>
#include <cmath>
#include <memory>

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>
#include <sensor_msgs/msg/joint_state.hpp>
#include <geometry_msgs/msg/transform_stamped.hpp>
#include <tf2_ros/transform_broadcaster.h>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>

#include "swiftpro/msg/swiftpro_state.hpp"

using namespace std::chrono_literals;

#define MATH_PI             3.141592653589793238463
#define MATH_TRANS          57.2958
#define MATH_L1             106.6
#define MATH_L2             13.2
#define MATH_LOWER_ARM      142.07
#define MATH_UPPER_ARM      158.81
#define MATH_UPPER_LOWER    (MATH_UPPER_ARM / MATH_LOWER_ARM)

#define LOWER_ARM_MAX_ANGLE 135.6
#define LOWER_ARM_MIN_ANGLE 0
#define UPPER_ARM_MAX_ANGLE 100.7
#define UPPER_ARM_MIN_ANGLE 0
#define LOWER_UPPER_MAX_ANGLE 151
#define LOWER_UPPER_MIN_ANGLE 10


class SwiftproRvizNode : public rclcpp::Node
{
public:
  SwiftproRvizNode() : Node("swiftpro_rviz_node")
  {
    sub_ = create_subscription<swiftpro::msg::SwiftproState>(
      "SwiftproState_topic", 1,
      std::bind(&SwiftproRvizNode::state_callback, this, std::placeholders::_1));

    pub_ = create_publisher<sensor_msgs::msg::JointState>("joint_states", 1);
    tf_broadcaster_ = std::make_unique<tf2_ros::TransformBroadcaster>(*this);

    timer_ = create_wall_timer(50ms, std::bind(&SwiftproRvizNode::timer_callback, this));
  }

private:
  // ── Inverse kinematics (unchanged) ──
  static bool swiftpro_ik(const float position[3], float angle[3])
  {
    float x = position[0];
    float y = position[1];
    float z = position[2];
    float xIn, zIn, phi, rightAll, sqrtZX = 0.0f;
    float angleRot, angleLeft, angleRight = 0.0f;

    z += 74.55f;
    zIn = (z - MATH_L1) / MATH_LOWER_ARM;
    if (x < 0.1f) x = 0.1f;

    if (y == 0)
      angleRot = 90;
    else if (y < 0)
      angleRot = -atan(x / y) * MATH_TRANS;
    else
      angleRot = 180 - atan(x / y) * MATH_TRANS;

    xIn     = (x / sin(angleRot / MATH_TRANS) - MATH_L2 - 56.55) / MATH_LOWER_ARM;
    phi     = atan(zIn / xIn) * MATH_TRANS;
    sqrtZX  = sqrt(zIn * zIn + xIn * xIn);
    rightAll = (sqrtZX * sqrtZX + MATH_UPPER_LOWER * MATH_UPPER_LOWER - 1)
               / (2 * MATH_UPPER_LOWER * sqrtZX);
    angleRight = acos(rightAll) * MATH_TRANS;

    rightAll  = (sqrtZX * sqrtZX + 1 - MATH_UPPER_LOWER * MATH_UPPER_LOWER) / (2 * sqrtZX);
    angleLeft = acos(rightAll) * MATH_TRANS;
    angleLeft = angleLeft + phi;
    angleRight = angleRight - phi;

    if (std::isnan(angleRot) || std::isnan(angleLeft) || std::isnan(angleRight))
      return false;

    angle[0] = angleRot;
    angle[1] = angleLeft;
    angle[2] = angleRight;
    return true;
  }

  // ── Forward kinematics for 9 joints (unchanged) ──
  static void all_joints_state(const float angle[3], float joint_angle[9])
  {
    double alpha2 = angle[1];
    double alpha3 = angle[2] - 3.8;

    joint_angle[0] = angle[0] - 90;
    joint_angle[1] = 90 - alpha2;
    joint_angle[5] = alpha3;
    joint_angle[2] = (alpha2 + alpha3) - 176.11 + 90;
    joint_angle[3] = -90 + alpha2;
    joint_angle[4] = joint_angle[1];
    joint_angle[6] = 90 - (alpha2 + alpha3);
    joint_angle[7] = 176.11 - 180 - alpha3;
    joint_angle[8] = 48.39 + alpha3 - 44.55;
  }

  // ── Callbacks ──
  void state_callback(const swiftpro::msg::SwiftproState & msg)
  {
    float position[3] = {
      static_cast<float>(msg.x),
      static_cast<float>(msg.y),
      static_cast<float>(msg.z)
    };
    float angle[3];

    if (swiftpro_ik(position, angle))
      all_joints_state(angle, joint_angle_);
    else
      RCLCPP_ERROR(get_logger(), "Inverse kinematic is wrong");
  }

  void timer_callback()
  {
    // ── Publish joint states ──
    sensor_msgs::msg::JointState joint_state;
    joint_state.header.stamp = now();
    joint_state.name.resize(9);
    joint_state.position.resize(9);

    const char * names[] = {
      "Joint1", "Joint2", "Joint3", "Joint4", "Joint5",
      "Joint6", "Joint7", "Joint8", "Joint9"};

    for (int i = 0; i < 9; i++) {
      joint_state.name[i] = names[i];
      joint_state.position[i] = joint_angle_[i] / 57.2958;
    }
    pub_->publish(joint_state);

    // ── Broadcast odom → Base transform ──
    geometry_msgs::msg::TransformStamped odom_trans;
    odom_trans.header.stamp    = now();
    odom_trans.header.frame_id = "odom";
    odom_trans.child_frame_id  = "Base";
    odom_trans.transform.translation.x = 0.0;
    odom_trans.transform.translation.y = 0.0;
    odom_trans.transform.translation.z = 0.0;

    tf2::Quaternion q;
    q.setRPY(0, 0, 10.0);
    odom_trans.transform.rotation = tf2::toMsg(q);

    tf_broadcaster_->sendTransform(odom_trans);
  }

  // ── Members ──
  float joint_angle_[9] = {0.0f};

  rclcpp::Subscription<swiftpro::msg::SwiftproState>::SharedPtr sub_;
  rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr pub_;
  std::unique_ptr<tf2_ros::TransformBroadcaster> tf_broadcaster_;
  rclcpp::TimerBase::SharedPtr timer_;
};


int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<SwiftproRvizNode>());
  rclcpp::shutdown();
  return 0;
}
