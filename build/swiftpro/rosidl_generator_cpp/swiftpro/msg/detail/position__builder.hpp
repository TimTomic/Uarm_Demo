// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from swiftpro:msg/Position.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "swiftpro/msg/position.hpp"


#ifndef SWIFTPRO__MSG__DETAIL__POSITION__BUILDER_HPP_
#define SWIFTPRO__MSG__DETAIL__POSITION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "swiftpro/msg/detail/position__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace swiftpro
{

namespace msg
{

namespace builder
{

class Init_Position_z
{
public:
  explicit Init_Position_z(::swiftpro::msg::Position & msg)
  : msg_(msg)
  {}
  ::swiftpro::msg::Position z(::swiftpro::msg::Position::_z_type arg)
  {
    msg_.z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::swiftpro::msg::Position msg_;
};

class Init_Position_y
{
public:
  explicit Init_Position_y(::swiftpro::msg::Position & msg)
  : msg_(msg)
  {}
  Init_Position_z y(::swiftpro::msg::Position::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_Position_z(msg_);
  }

private:
  ::swiftpro::msg::Position msg_;
};

class Init_Position_x
{
public:
  Init_Position_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Position_y x(::swiftpro::msg::Position::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_Position_y(msg_);
  }

private:
  ::swiftpro::msg::Position msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::swiftpro::msg::Position>()
{
  return swiftpro::msg::builder::Init_Position_x();
}

}  // namespace swiftpro

#endif  // SWIFTPRO__MSG__DETAIL__POSITION__BUILDER_HPP_
