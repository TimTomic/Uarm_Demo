// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from swiftpro:msg/SwiftproState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "swiftpro/msg/swiftpro_state.hpp"


#ifndef SWIFTPRO__MSG__DETAIL__SWIFTPRO_STATE__STRUCT_HPP_
#define SWIFTPRO__MSG__DETAIL__SWIFTPRO_STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__swiftpro__msg__SwiftproState __attribute__((deprecated))
#else
# define DEPRECATED__swiftpro__msg__SwiftproState __declspec(deprecated)
#endif

namespace swiftpro
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SwiftproState_
{
  using Type = SwiftproState_<ContainerAllocator>;

  explicit SwiftproState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->motor_angle1 = 0.0;
      this->motor_angle2 = 0.0;
      this->motor_angle3 = 0.0;
      this->motor_angle4 = 0.0;
      this->x = 0.0;
      this->y = 0.0;
      this->z = 0.0;
      this->pump = 0;
      this->swiftpro_status = 0;
      this->gripper = 0;
      this->limit_switch = 0;
    }
  }

  explicit SwiftproState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->motor_angle1 = 0.0;
      this->motor_angle2 = 0.0;
      this->motor_angle3 = 0.0;
      this->motor_angle4 = 0.0;
      this->x = 0.0;
      this->y = 0.0;
      this->z = 0.0;
      this->pump = 0;
      this->swiftpro_status = 0;
      this->gripper = 0;
      this->limit_switch = 0;
    }
  }

  // field types and members
  using _motor_angle1_type =
    double;
  _motor_angle1_type motor_angle1;
  using _motor_angle2_type =
    double;
  _motor_angle2_type motor_angle2;
  using _motor_angle3_type =
    double;
  _motor_angle3_type motor_angle3;
  using _motor_angle4_type =
    double;
  _motor_angle4_type motor_angle4;
  using _x_type =
    double;
  _x_type x;
  using _y_type =
    double;
  _y_type y;
  using _z_type =
    double;
  _z_type z;
  using _pump_type =
    uint8_t;
  _pump_type pump;
  using _swiftpro_status_type =
    uint8_t;
  _swiftpro_status_type swiftpro_status;
  using _gripper_type =
    uint8_t;
  _gripper_type gripper;
  using _limit_switch_type =
    uint8_t;
  _limit_switch_type limit_switch;

  // setters for named parameter idiom
  Type & set__motor_angle1(
    const double & _arg)
  {
    this->motor_angle1 = _arg;
    return *this;
  }
  Type & set__motor_angle2(
    const double & _arg)
  {
    this->motor_angle2 = _arg;
    return *this;
  }
  Type & set__motor_angle3(
    const double & _arg)
  {
    this->motor_angle3 = _arg;
    return *this;
  }
  Type & set__motor_angle4(
    const double & _arg)
  {
    this->motor_angle4 = _arg;
    return *this;
  }
  Type & set__x(
    const double & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const double & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__z(
    const double & _arg)
  {
    this->z = _arg;
    return *this;
  }
  Type & set__pump(
    const uint8_t & _arg)
  {
    this->pump = _arg;
    return *this;
  }
  Type & set__swiftpro_status(
    const uint8_t & _arg)
  {
    this->swiftpro_status = _arg;
    return *this;
  }
  Type & set__gripper(
    const uint8_t & _arg)
  {
    this->gripper = _arg;
    return *this;
  }
  Type & set__limit_switch(
    const uint8_t & _arg)
  {
    this->limit_switch = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    swiftpro::msg::SwiftproState_<ContainerAllocator> *;
  using ConstRawPtr =
    const swiftpro::msg::SwiftproState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<swiftpro::msg::SwiftproState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<swiftpro::msg::SwiftproState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      swiftpro::msg::SwiftproState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<swiftpro::msg::SwiftproState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      swiftpro::msg::SwiftproState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<swiftpro::msg::SwiftproState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<swiftpro::msg::SwiftproState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<swiftpro::msg::SwiftproState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__swiftpro__msg__SwiftproState
    std::shared_ptr<swiftpro::msg::SwiftproState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__swiftpro__msg__SwiftproState
    std::shared_ptr<swiftpro::msg::SwiftproState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SwiftproState_ & other) const
  {
    if (this->motor_angle1 != other.motor_angle1) {
      return false;
    }
    if (this->motor_angle2 != other.motor_angle2) {
      return false;
    }
    if (this->motor_angle3 != other.motor_angle3) {
      return false;
    }
    if (this->motor_angle4 != other.motor_angle4) {
      return false;
    }
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->z != other.z) {
      return false;
    }
    if (this->pump != other.pump) {
      return false;
    }
    if (this->swiftpro_status != other.swiftpro_status) {
      return false;
    }
    if (this->gripper != other.gripper) {
      return false;
    }
    if (this->limit_switch != other.limit_switch) {
      return false;
    }
    return true;
  }
  bool operator!=(const SwiftproState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SwiftproState_

// alias to use template instance with default allocator
using SwiftproState =
  swiftpro::msg::SwiftproState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace swiftpro

#endif  // SWIFTPRO__MSG__DETAIL__SWIFTPRO_STATE__STRUCT_HPP_
