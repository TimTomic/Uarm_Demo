// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from swiftpro:msg/Angle4th.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "swiftpro/msg/angle4th.hpp"


#ifndef SWIFTPRO__MSG__DETAIL__ANGLE4TH__BUILDER_HPP_
#define SWIFTPRO__MSG__DETAIL__ANGLE4TH__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "swiftpro/msg/detail/angle4th__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace swiftpro
{

namespace msg
{

namespace builder
{

class Init_Angle4th_angle4th
{
public:
  Init_Angle4th_angle4th()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::swiftpro::msg::Angle4th angle4th(::swiftpro::msg::Angle4th::_angle4th_type arg)
  {
    msg_.angle4th = std::move(arg);
    return std::move(msg_);
  }

private:
  ::swiftpro::msg::Angle4th msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::swiftpro::msg::Angle4th>()
{
  return swiftpro::msg::builder::Init_Angle4th_angle4th();
}

}  // namespace swiftpro

#endif  // SWIFTPRO__MSG__DETAIL__ANGLE4TH__BUILDER_HPP_
