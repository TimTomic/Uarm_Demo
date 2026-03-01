// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from swiftpro:srv/SendGcode.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "swiftpro/srv/send_gcode.hpp"


#ifndef SWIFTPRO__SRV__DETAIL__SEND_GCODE__STRUCT_HPP_
#define SWIFTPRO__SRV__DETAIL__SEND_GCODE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__swiftpro__srv__SendGcode_Request __attribute__((deprecated))
#else
# define DEPRECATED__swiftpro__srv__SendGcode_Request __declspec(deprecated)
#endif

namespace swiftpro
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SendGcode_Request_
{
  using Type = SendGcode_Request_<ContainerAllocator>;

  explicit SendGcode_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->command = "";
    }
  }

  explicit SendGcode_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : command(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->command = "";
    }
  }

  // field types and members
  using _command_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _command_type command;

  // setters for named parameter idiom
  Type & set__command(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->command = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    swiftpro::srv::SendGcode_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const swiftpro::srv::SendGcode_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<swiftpro::srv::SendGcode_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<swiftpro::srv::SendGcode_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      swiftpro::srv::SendGcode_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<swiftpro::srv::SendGcode_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      swiftpro::srv::SendGcode_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<swiftpro::srv::SendGcode_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<swiftpro::srv::SendGcode_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<swiftpro::srv::SendGcode_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__swiftpro__srv__SendGcode_Request
    std::shared_ptr<swiftpro::srv::SendGcode_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__swiftpro__srv__SendGcode_Request
    std::shared_ptr<swiftpro::srv::SendGcode_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SendGcode_Request_ & other) const
  {
    if (this->command != other.command) {
      return false;
    }
    return true;
  }
  bool operator!=(const SendGcode_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SendGcode_Request_

// alias to use template instance with default allocator
using SendGcode_Request =
  swiftpro::srv::SendGcode_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace swiftpro


#ifndef _WIN32
# define DEPRECATED__swiftpro__srv__SendGcode_Response __attribute__((deprecated))
#else
# define DEPRECATED__swiftpro__srv__SendGcode_Response __declspec(deprecated)
#endif

namespace swiftpro
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SendGcode_Response_
{
  using Type = SendGcode_Response_<ContainerAllocator>;

  explicit SendGcode_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  explicit SendGcode_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    swiftpro::srv::SendGcode_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const swiftpro::srv::SendGcode_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<swiftpro::srv::SendGcode_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<swiftpro::srv::SendGcode_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      swiftpro::srv::SendGcode_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<swiftpro::srv::SendGcode_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      swiftpro::srv::SendGcode_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<swiftpro::srv::SendGcode_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<swiftpro::srv::SendGcode_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<swiftpro::srv::SendGcode_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__swiftpro__srv__SendGcode_Response
    std::shared_ptr<swiftpro::srv::SendGcode_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__swiftpro__srv__SendGcode_Response
    std::shared_ptr<swiftpro::srv::SendGcode_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SendGcode_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const SendGcode_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SendGcode_Response_

// alias to use template instance with default allocator
using SendGcode_Response =
  swiftpro::srv::SendGcode_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace swiftpro


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__swiftpro__srv__SendGcode_Event __attribute__((deprecated))
#else
# define DEPRECATED__swiftpro__srv__SendGcode_Event __declspec(deprecated)
#endif

namespace swiftpro
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SendGcode_Event_
{
  using Type = SendGcode_Event_<ContainerAllocator>;

  explicit SendGcode_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit SendGcode_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<swiftpro::srv::SendGcode_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<swiftpro::srv::SendGcode_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<swiftpro::srv::SendGcode_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<swiftpro::srv::SendGcode_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<swiftpro::srv::SendGcode_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<swiftpro::srv::SendGcode_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<swiftpro::srv::SendGcode_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<swiftpro::srv::SendGcode_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    swiftpro::srv::SendGcode_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const swiftpro::srv::SendGcode_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<swiftpro::srv::SendGcode_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<swiftpro::srv::SendGcode_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      swiftpro::srv::SendGcode_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<swiftpro::srv::SendGcode_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      swiftpro::srv::SendGcode_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<swiftpro::srv::SendGcode_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<swiftpro::srv::SendGcode_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<swiftpro::srv::SendGcode_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__swiftpro__srv__SendGcode_Event
    std::shared_ptr<swiftpro::srv::SendGcode_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__swiftpro__srv__SendGcode_Event
    std::shared_ptr<swiftpro::srv::SendGcode_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SendGcode_Event_ & other) const
  {
    if (this->info != other.info) {
      return false;
    }
    if (this->request != other.request) {
      return false;
    }
    if (this->response != other.response) {
      return false;
    }
    return true;
  }
  bool operator!=(const SendGcode_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SendGcode_Event_

// alias to use template instance with default allocator
using SendGcode_Event =
  swiftpro::srv::SendGcode_Event_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace swiftpro

namespace swiftpro
{

namespace srv
{

struct SendGcode
{
  using Request = swiftpro::srv::SendGcode_Request;
  using Response = swiftpro::srv::SendGcode_Response;
  using Event = swiftpro::srv::SendGcode_Event;
};

}  // namespace srv

}  // namespace swiftpro

#endif  // SWIFTPRO__SRV__DETAIL__SEND_GCODE__STRUCT_HPP_
