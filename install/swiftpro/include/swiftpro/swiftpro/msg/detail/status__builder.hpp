// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from swiftpro:msg/Status.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "swiftpro/msg/status.hpp"


#ifndef SWIFTPRO__MSG__DETAIL__STATUS__BUILDER_HPP_
#define SWIFTPRO__MSG__DETAIL__STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "swiftpro/msg/detail/status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace swiftpro
{

namespace msg
{

namespace builder
{

class Init_Status_status
{
public:
  Init_Status_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::swiftpro::msg::Status status(::swiftpro::msg::Status::_status_type arg)
  {
    msg_.status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::swiftpro::msg::Status msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::swiftpro::msg::Status>()
{
  return swiftpro::msg::builder::Init_Status_status();
}

}  // namespace swiftpro

#endif  // SWIFTPRO__MSG__DETAIL__STATUS__BUILDER_HPP_
