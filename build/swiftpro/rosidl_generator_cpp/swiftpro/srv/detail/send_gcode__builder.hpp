// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from swiftpro:srv/SendGcode.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "swiftpro/srv/send_gcode.hpp"


#ifndef SWIFTPRO__SRV__DETAIL__SEND_GCODE__BUILDER_HPP_
#define SWIFTPRO__SRV__DETAIL__SEND_GCODE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "swiftpro/srv/detail/send_gcode__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace swiftpro
{

namespace srv
{

namespace builder
{

class Init_SendGcode_Request_command
{
public:
  Init_SendGcode_Request_command()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::swiftpro::srv::SendGcode_Request command(::swiftpro::srv::SendGcode_Request::_command_type arg)
  {
    msg_.command = std::move(arg);
    return std::move(msg_);
  }

private:
  ::swiftpro::srv::SendGcode_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::swiftpro::srv::SendGcode_Request>()
{
  return swiftpro::srv::builder::Init_SendGcode_Request_command();
}

}  // namespace swiftpro


namespace swiftpro
{

namespace srv
{

namespace builder
{

class Init_SendGcode_Response_message
{
public:
  explicit Init_SendGcode_Response_message(::swiftpro::srv::SendGcode_Response & msg)
  : msg_(msg)
  {}
  ::swiftpro::srv::SendGcode_Response message(::swiftpro::srv::SendGcode_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::swiftpro::srv::SendGcode_Response msg_;
};

class Init_SendGcode_Response_success
{
public:
  Init_SendGcode_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SendGcode_Response_message success(::swiftpro::srv::SendGcode_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_SendGcode_Response_message(msg_);
  }

private:
  ::swiftpro::srv::SendGcode_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::swiftpro::srv::SendGcode_Response>()
{
  return swiftpro::srv::builder::Init_SendGcode_Response_success();
}

}  // namespace swiftpro


namespace swiftpro
{

namespace srv
{

namespace builder
{

class Init_SendGcode_Event_response
{
public:
  explicit Init_SendGcode_Event_response(::swiftpro::srv::SendGcode_Event & msg)
  : msg_(msg)
  {}
  ::swiftpro::srv::SendGcode_Event response(::swiftpro::srv::SendGcode_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::swiftpro::srv::SendGcode_Event msg_;
};

class Init_SendGcode_Event_request
{
public:
  explicit Init_SendGcode_Event_request(::swiftpro::srv::SendGcode_Event & msg)
  : msg_(msg)
  {}
  Init_SendGcode_Event_response request(::swiftpro::srv::SendGcode_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_SendGcode_Event_response(msg_);
  }

private:
  ::swiftpro::srv::SendGcode_Event msg_;
};

class Init_SendGcode_Event_info
{
public:
  Init_SendGcode_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SendGcode_Event_request info(::swiftpro::srv::SendGcode_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_SendGcode_Event_request(msg_);
  }

private:
  ::swiftpro::srv::SendGcode_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::swiftpro::srv::SendGcode_Event>()
{
  return swiftpro::srv::builder::Init_SendGcode_Event_info();
}

}  // namespace swiftpro

#endif  // SWIFTPRO__SRV__DETAIL__SEND_GCODE__BUILDER_HPP_
