// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from swiftpro:msg/SwiftproState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "swiftpro/msg/swiftpro_state.hpp"


#ifndef SWIFTPRO__MSG__DETAIL__SWIFTPRO_STATE__BUILDER_HPP_
#define SWIFTPRO__MSG__DETAIL__SWIFTPRO_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "swiftpro/msg/detail/swiftpro_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace swiftpro
{

namespace msg
{

namespace builder
{

class Init_SwiftproState_limit_switch
{
public:
  explicit Init_SwiftproState_limit_switch(::swiftpro::msg::SwiftproState & msg)
  : msg_(msg)
  {}
  ::swiftpro::msg::SwiftproState limit_switch(::swiftpro::msg::SwiftproState::_limit_switch_type arg)
  {
    msg_.limit_switch = std::move(arg);
    return std::move(msg_);
  }

private:
  ::swiftpro::msg::SwiftproState msg_;
};

class Init_SwiftproState_gripper
{
public:
  explicit Init_SwiftproState_gripper(::swiftpro::msg::SwiftproState & msg)
  : msg_(msg)
  {}
  Init_SwiftproState_limit_switch gripper(::swiftpro::msg::SwiftproState::_gripper_type arg)
  {
    msg_.gripper = std::move(arg);
    return Init_SwiftproState_limit_switch(msg_);
  }

private:
  ::swiftpro::msg::SwiftproState msg_;
};

class Init_SwiftproState_swiftpro_status
{
public:
  explicit Init_SwiftproState_swiftpro_status(::swiftpro::msg::SwiftproState & msg)
  : msg_(msg)
  {}
  Init_SwiftproState_gripper swiftpro_status(::swiftpro::msg::SwiftproState::_swiftpro_status_type arg)
  {
    msg_.swiftpro_status = std::move(arg);
    return Init_SwiftproState_gripper(msg_);
  }

private:
  ::swiftpro::msg::SwiftproState msg_;
};

class Init_SwiftproState_pump
{
public:
  explicit Init_SwiftproState_pump(::swiftpro::msg::SwiftproState & msg)
  : msg_(msg)
  {}
  Init_SwiftproState_swiftpro_status pump(::swiftpro::msg::SwiftproState::_pump_type arg)
  {
    msg_.pump = std::move(arg);
    return Init_SwiftproState_swiftpro_status(msg_);
  }

private:
  ::swiftpro::msg::SwiftproState msg_;
};

class Init_SwiftproState_z
{
public:
  explicit Init_SwiftproState_z(::swiftpro::msg::SwiftproState & msg)
  : msg_(msg)
  {}
  Init_SwiftproState_pump z(::swiftpro::msg::SwiftproState::_z_type arg)
  {
    msg_.z = std::move(arg);
    return Init_SwiftproState_pump(msg_);
  }

private:
  ::swiftpro::msg::SwiftproState msg_;
};

class Init_SwiftproState_y
{
public:
  explicit Init_SwiftproState_y(::swiftpro::msg::SwiftproState & msg)
  : msg_(msg)
  {}
  Init_SwiftproState_z y(::swiftpro::msg::SwiftproState::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_SwiftproState_z(msg_);
  }

private:
  ::swiftpro::msg::SwiftproState msg_;
};

class Init_SwiftproState_x
{
public:
  explicit Init_SwiftproState_x(::swiftpro::msg::SwiftproState & msg)
  : msg_(msg)
  {}
  Init_SwiftproState_y x(::swiftpro::msg::SwiftproState::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_SwiftproState_y(msg_);
  }

private:
  ::swiftpro::msg::SwiftproState msg_;
};

class Init_SwiftproState_motor_angle4
{
public:
  explicit Init_SwiftproState_motor_angle4(::swiftpro::msg::SwiftproState & msg)
  : msg_(msg)
  {}
  Init_SwiftproState_x motor_angle4(::swiftpro::msg::SwiftproState::_motor_angle4_type arg)
  {
    msg_.motor_angle4 = std::move(arg);
    return Init_SwiftproState_x(msg_);
  }

private:
  ::swiftpro::msg::SwiftproState msg_;
};

class Init_SwiftproState_motor_angle3
{
public:
  explicit Init_SwiftproState_motor_angle3(::swiftpro::msg::SwiftproState & msg)
  : msg_(msg)
  {}
  Init_SwiftproState_motor_angle4 motor_angle3(::swiftpro::msg::SwiftproState::_motor_angle3_type arg)
  {
    msg_.motor_angle3 = std::move(arg);
    return Init_SwiftproState_motor_angle4(msg_);
  }

private:
  ::swiftpro::msg::SwiftproState msg_;
};

class Init_SwiftproState_motor_angle2
{
public:
  explicit Init_SwiftproState_motor_angle2(::swiftpro::msg::SwiftproState & msg)
  : msg_(msg)
  {}
  Init_SwiftproState_motor_angle3 motor_angle2(::swiftpro::msg::SwiftproState::_motor_angle2_type arg)
  {
    msg_.motor_angle2 = std::move(arg);
    return Init_SwiftproState_motor_angle3(msg_);
  }

private:
  ::swiftpro::msg::SwiftproState msg_;
};

class Init_SwiftproState_motor_angle1
{
public:
  Init_SwiftproState_motor_angle1()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SwiftproState_motor_angle2 motor_angle1(::swiftpro::msg::SwiftproState::_motor_angle1_type arg)
  {
    msg_.motor_angle1 = std::move(arg);
    return Init_SwiftproState_motor_angle2(msg_);
  }

private:
  ::swiftpro::msg::SwiftproState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::swiftpro::msg::SwiftproState>()
{
  return swiftpro::msg::builder::Init_SwiftproState_motor_angle1();
}

}  // namespace swiftpro

#endif  // SWIFTPRO__MSG__DETAIL__SWIFTPRO_STATE__BUILDER_HPP_
