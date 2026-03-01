// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from swiftpro:msg/Status.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "swiftpro/msg/status.hpp"


#ifndef SWIFTPRO__MSG__DETAIL__STATUS__STRUCT_HPP_
#define SWIFTPRO__MSG__DETAIL__STATUS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__swiftpro__msg__Status __attribute__((deprecated))
#else
# define DEPRECATED__swiftpro__msg__Status __declspec(deprecated)
#endif

namespace swiftpro
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Status_
{
  using Type = Status_<ContainerAllocator>;

  explicit Status_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  explicit Status_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  // field types and members
  using _status_type =
    uint8_t;
  _status_type status;

  // setters for named parameter idiom
  Type & set__status(
    const uint8_t & _arg)
  {
    this->status = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    swiftpro::msg::Status_<ContainerAllocator> *;
  using ConstRawPtr =
    const swiftpro::msg::Status_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<swiftpro::msg::Status_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<swiftpro::msg::Status_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      swiftpro::msg::Status_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<swiftpro::msg::Status_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      swiftpro::msg::Status_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<swiftpro::msg::Status_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<swiftpro::msg::Status_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<swiftpro::msg::Status_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__swiftpro__msg__Status
    std::shared_ptr<swiftpro::msg::Status_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__swiftpro__msg__Status
    std::shared_ptr<swiftpro::msg::Status_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Status_ & other) const
  {
    if (this->status != other.status) {
      return false;
    }
    return true;
  }
  bool operator!=(const Status_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Status_

// alias to use template instance with default allocator
using Status =
  swiftpro::msg::Status_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace swiftpro

#endif  // SWIFTPRO__MSG__DETAIL__STATUS__STRUCT_HPP_
