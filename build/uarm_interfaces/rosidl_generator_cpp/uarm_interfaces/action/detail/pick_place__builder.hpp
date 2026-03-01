// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from uarm_interfaces:action/PickPlace.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "uarm_interfaces/action/pick_place.hpp"


#ifndef UARM_INTERFACES__ACTION__DETAIL__PICK_PLACE__BUILDER_HPP_
#define UARM_INTERFACES__ACTION__DETAIL__PICK_PLACE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "uarm_interfaces/action/detail/pick_place__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace uarm_interfaces
{

namespace action
{

namespace builder
{

class Init_PickPlace_Goal_command
{
public:
  Init_PickPlace_Goal_command()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::uarm_interfaces::action::PickPlace_Goal command(::uarm_interfaces::action::PickPlace_Goal::_command_type arg)
  {
    msg_.command = std::move(arg);
    return std::move(msg_);
  }

private:
  ::uarm_interfaces::action::PickPlace_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::uarm_interfaces::action::PickPlace_Goal>()
{
  return uarm_interfaces::action::builder::Init_PickPlace_Goal_command();
}

}  // namespace uarm_interfaces


namespace uarm_interfaces
{

namespace action
{

namespace builder
{

class Init_PickPlace_Result_message
{
public:
  explicit Init_PickPlace_Result_message(::uarm_interfaces::action::PickPlace_Result & msg)
  : msg_(msg)
  {}
  ::uarm_interfaces::action::PickPlace_Result message(::uarm_interfaces::action::PickPlace_Result::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::uarm_interfaces::action::PickPlace_Result msg_;
};

class Init_PickPlace_Result_success
{
public:
  Init_PickPlace_Result_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PickPlace_Result_message success(::uarm_interfaces::action::PickPlace_Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_PickPlace_Result_message(msg_);
  }

private:
  ::uarm_interfaces::action::PickPlace_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::uarm_interfaces::action::PickPlace_Result>()
{
  return uarm_interfaces::action::builder::Init_PickPlace_Result_success();
}

}  // namespace uarm_interfaces


namespace uarm_interfaces
{

namespace action
{

namespace builder
{

class Init_PickPlace_Feedback_current_state
{
public:
  Init_PickPlace_Feedback_current_state()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::uarm_interfaces::action::PickPlace_Feedback current_state(::uarm_interfaces::action::PickPlace_Feedback::_current_state_type arg)
  {
    msg_.current_state = std::move(arg);
    return std::move(msg_);
  }

private:
  ::uarm_interfaces::action::PickPlace_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::uarm_interfaces::action::PickPlace_Feedback>()
{
  return uarm_interfaces::action::builder::Init_PickPlace_Feedback_current_state();
}

}  // namespace uarm_interfaces


namespace uarm_interfaces
{

namespace action
{

namespace builder
{

class Init_PickPlace_SendGoal_Request_goal
{
public:
  explicit Init_PickPlace_SendGoal_Request_goal(::uarm_interfaces::action::PickPlace_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::uarm_interfaces::action::PickPlace_SendGoal_Request goal(::uarm_interfaces::action::PickPlace_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::uarm_interfaces::action::PickPlace_SendGoal_Request msg_;
};

class Init_PickPlace_SendGoal_Request_goal_id
{
public:
  Init_PickPlace_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PickPlace_SendGoal_Request_goal goal_id(::uarm_interfaces::action::PickPlace_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_PickPlace_SendGoal_Request_goal(msg_);
  }

private:
  ::uarm_interfaces::action::PickPlace_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::uarm_interfaces::action::PickPlace_SendGoal_Request>()
{
  return uarm_interfaces::action::builder::Init_PickPlace_SendGoal_Request_goal_id();
}

}  // namespace uarm_interfaces


namespace uarm_interfaces
{

namespace action
{

namespace builder
{

class Init_PickPlace_SendGoal_Response_stamp
{
public:
  explicit Init_PickPlace_SendGoal_Response_stamp(::uarm_interfaces::action::PickPlace_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::uarm_interfaces::action::PickPlace_SendGoal_Response stamp(::uarm_interfaces::action::PickPlace_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::uarm_interfaces::action::PickPlace_SendGoal_Response msg_;
};

class Init_PickPlace_SendGoal_Response_accepted
{
public:
  Init_PickPlace_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PickPlace_SendGoal_Response_stamp accepted(::uarm_interfaces::action::PickPlace_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_PickPlace_SendGoal_Response_stamp(msg_);
  }

private:
  ::uarm_interfaces::action::PickPlace_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::uarm_interfaces::action::PickPlace_SendGoal_Response>()
{
  return uarm_interfaces::action::builder::Init_PickPlace_SendGoal_Response_accepted();
}

}  // namespace uarm_interfaces


namespace uarm_interfaces
{

namespace action
{

namespace builder
{

class Init_PickPlace_SendGoal_Event_response
{
public:
  explicit Init_PickPlace_SendGoal_Event_response(::uarm_interfaces::action::PickPlace_SendGoal_Event & msg)
  : msg_(msg)
  {}
  ::uarm_interfaces::action::PickPlace_SendGoal_Event response(::uarm_interfaces::action::PickPlace_SendGoal_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::uarm_interfaces::action::PickPlace_SendGoal_Event msg_;
};

class Init_PickPlace_SendGoal_Event_request
{
public:
  explicit Init_PickPlace_SendGoal_Event_request(::uarm_interfaces::action::PickPlace_SendGoal_Event & msg)
  : msg_(msg)
  {}
  Init_PickPlace_SendGoal_Event_response request(::uarm_interfaces::action::PickPlace_SendGoal_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_PickPlace_SendGoal_Event_response(msg_);
  }

private:
  ::uarm_interfaces::action::PickPlace_SendGoal_Event msg_;
};

class Init_PickPlace_SendGoal_Event_info
{
public:
  Init_PickPlace_SendGoal_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PickPlace_SendGoal_Event_request info(::uarm_interfaces::action::PickPlace_SendGoal_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_PickPlace_SendGoal_Event_request(msg_);
  }

private:
  ::uarm_interfaces::action::PickPlace_SendGoal_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::uarm_interfaces::action::PickPlace_SendGoal_Event>()
{
  return uarm_interfaces::action::builder::Init_PickPlace_SendGoal_Event_info();
}

}  // namespace uarm_interfaces


namespace uarm_interfaces
{

namespace action
{

namespace builder
{

class Init_PickPlace_GetResult_Request_goal_id
{
public:
  Init_PickPlace_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::uarm_interfaces::action::PickPlace_GetResult_Request goal_id(::uarm_interfaces::action::PickPlace_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::uarm_interfaces::action::PickPlace_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::uarm_interfaces::action::PickPlace_GetResult_Request>()
{
  return uarm_interfaces::action::builder::Init_PickPlace_GetResult_Request_goal_id();
}

}  // namespace uarm_interfaces


namespace uarm_interfaces
{

namespace action
{

namespace builder
{

class Init_PickPlace_GetResult_Response_result
{
public:
  explicit Init_PickPlace_GetResult_Response_result(::uarm_interfaces::action::PickPlace_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::uarm_interfaces::action::PickPlace_GetResult_Response result(::uarm_interfaces::action::PickPlace_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::uarm_interfaces::action::PickPlace_GetResult_Response msg_;
};

class Init_PickPlace_GetResult_Response_status
{
public:
  Init_PickPlace_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PickPlace_GetResult_Response_result status(::uarm_interfaces::action::PickPlace_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_PickPlace_GetResult_Response_result(msg_);
  }

private:
  ::uarm_interfaces::action::PickPlace_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::uarm_interfaces::action::PickPlace_GetResult_Response>()
{
  return uarm_interfaces::action::builder::Init_PickPlace_GetResult_Response_status();
}

}  // namespace uarm_interfaces


namespace uarm_interfaces
{

namespace action
{

namespace builder
{

class Init_PickPlace_GetResult_Event_response
{
public:
  explicit Init_PickPlace_GetResult_Event_response(::uarm_interfaces::action::PickPlace_GetResult_Event & msg)
  : msg_(msg)
  {}
  ::uarm_interfaces::action::PickPlace_GetResult_Event response(::uarm_interfaces::action::PickPlace_GetResult_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::uarm_interfaces::action::PickPlace_GetResult_Event msg_;
};

class Init_PickPlace_GetResult_Event_request
{
public:
  explicit Init_PickPlace_GetResult_Event_request(::uarm_interfaces::action::PickPlace_GetResult_Event & msg)
  : msg_(msg)
  {}
  Init_PickPlace_GetResult_Event_response request(::uarm_interfaces::action::PickPlace_GetResult_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_PickPlace_GetResult_Event_response(msg_);
  }

private:
  ::uarm_interfaces::action::PickPlace_GetResult_Event msg_;
};

class Init_PickPlace_GetResult_Event_info
{
public:
  Init_PickPlace_GetResult_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PickPlace_GetResult_Event_request info(::uarm_interfaces::action::PickPlace_GetResult_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_PickPlace_GetResult_Event_request(msg_);
  }

private:
  ::uarm_interfaces::action::PickPlace_GetResult_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::uarm_interfaces::action::PickPlace_GetResult_Event>()
{
  return uarm_interfaces::action::builder::Init_PickPlace_GetResult_Event_info();
}

}  // namespace uarm_interfaces


namespace uarm_interfaces
{

namespace action
{

namespace builder
{

class Init_PickPlace_FeedbackMessage_feedback
{
public:
  explicit Init_PickPlace_FeedbackMessage_feedback(::uarm_interfaces::action::PickPlace_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::uarm_interfaces::action::PickPlace_FeedbackMessage feedback(::uarm_interfaces::action::PickPlace_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::uarm_interfaces::action::PickPlace_FeedbackMessage msg_;
};

class Init_PickPlace_FeedbackMessage_goal_id
{
public:
  Init_PickPlace_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PickPlace_FeedbackMessage_feedback goal_id(::uarm_interfaces::action::PickPlace_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_PickPlace_FeedbackMessage_feedback(msg_);
  }

private:
  ::uarm_interfaces::action::PickPlace_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::uarm_interfaces::action::PickPlace_FeedbackMessage>()
{
  return uarm_interfaces::action::builder::Init_PickPlace_FeedbackMessage_goal_id();
}

}  // namespace uarm_interfaces

#endif  // UARM_INTERFACES__ACTION__DETAIL__PICK_PLACE__BUILDER_HPP_
