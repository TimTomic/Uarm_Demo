// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from swiftpro:msg/Angle4th.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "swiftpro/msg/angle4th.hpp"


#ifndef SWIFTPRO__MSG__DETAIL__ANGLE4TH__STRUCT_HPP_
#define SWIFTPRO__MSG__DETAIL__ANGLE4TH__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__swiftpro__msg__Angle4th __attribute__((deprecated))
#else
# define DEPRECATED__swiftpro__msg__Angle4th __declspec(deprecated)
#endif

namespace swiftpro
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Angle4th_
{
  using Type = Angle4th_<ContainerAllocator>;

  explicit Angle4th_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->angle4th = 0.0;
    }
  }

  explicit Angle4th_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->angle4th = 0.0;
    }
  }

  // field types and members
  using _angle4th_type =
    double;
  _angle4th_type angle4th;

  // setters for named parameter idiom
  Type & set__angle4th(
    const double & _arg)
  {
    this->angle4th = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    swiftpro::msg::Angle4th_<ContainerAllocator> *;
  using ConstRawPtr =
    const swiftpro::msg::Angle4th_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<swiftpro::msg::Angle4th_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<swiftpro::msg::Angle4th_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      swiftpro::msg::Angle4th_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<swiftpro::msg::Angle4th_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      swiftpro::msg::Angle4th_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<swiftpro::msg::Angle4th_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<swiftpro::msg::Angle4th_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<swiftpro::msg::Angle4th_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__swiftpro__msg__Angle4th
    std::shared_ptr<swiftpro::msg::Angle4th_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__swiftpro__msg__Angle4th
    std::shared_ptr<swiftpro::msg::Angle4th_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Angle4th_ & other) const
  {
    if (this->angle4th != other.angle4th) {
      return false;
    }
    return true;
  }
  bool operator!=(const Angle4th_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Angle4th_

// alias to use template instance with default allocator
using Angle4th =
  swiftpro::msg::Angle4th_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace swiftpro

#endif  // SWIFTPRO__MSG__DETAIL__ANGLE4TH__STRUCT_HPP_
