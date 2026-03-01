// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from swiftpro:msg/SwiftproState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "swiftpro/msg/swiftpro_state.hpp"


#ifndef SWIFTPRO__MSG__DETAIL__SWIFTPRO_STATE__TRAITS_HPP_
#define SWIFTPRO__MSG__DETAIL__SWIFTPRO_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "swiftpro/msg/detail/swiftpro_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace swiftpro
{

namespace msg
{

inline void to_flow_style_yaml(
  const SwiftproState & msg,
  std::ostream & out)
{
  out << "{";
  // member: motor_angle1
  {
    out << "motor_angle1: ";
    rosidl_generator_traits::value_to_yaml(msg.motor_angle1, out);
    out << ", ";
  }

  // member: motor_angle2
  {
    out << "motor_angle2: ";
    rosidl_generator_traits::value_to_yaml(msg.motor_angle2, out);
    out << ", ";
  }

  // member: motor_angle3
  {
    out << "motor_angle3: ";
    rosidl_generator_traits::value_to_yaml(msg.motor_angle3, out);
    out << ", ";
  }

  // member: motor_angle4
  {
    out << "motor_angle4: ";
    rosidl_generator_traits::value_to_yaml(msg.motor_angle4, out);
    out << ", ";
  }

  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: z
  {
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
    out << ", ";
  }

  // member: pump
  {
    out << "pump: ";
    rosidl_generator_traits::value_to_yaml(msg.pump, out);
    out << ", ";
  }

  // member: swiftpro_status
  {
    out << "swiftpro_status: ";
    rosidl_generator_traits::value_to_yaml(msg.swiftpro_status, out);
    out << ", ";
  }

  // member: gripper
  {
    out << "gripper: ";
    rosidl_generator_traits::value_to_yaml(msg.gripper, out);
    out << ", ";
  }

  // member: limit_switch
  {
    out << "limit_switch: ";
    rosidl_generator_traits::value_to_yaml(msg.limit_switch, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SwiftproState & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: motor_angle1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "motor_angle1: ";
    rosidl_generator_traits::value_to_yaml(msg.motor_angle1, out);
    out << "\n";
  }

  // member: motor_angle2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "motor_angle2: ";
    rosidl_generator_traits::value_to_yaml(msg.motor_angle2, out);
    out << "\n";
  }

  // member: motor_angle3
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "motor_angle3: ";
    rosidl_generator_traits::value_to_yaml(msg.motor_angle3, out);
    out << "\n";
  }

  // member: motor_angle4
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "motor_angle4: ";
    rosidl_generator_traits::value_to_yaml(msg.motor_angle4, out);
    out << "\n";
  }

  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
    out << "\n";
  }

  // member: pump
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pump: ";
    rosidl_generator_traits::value_to_yaml(msg.pump, out);
    out << "\n";
  }

  // member: swiftpro_status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "swiftpro_status: ";
    rosidl_generator_traits::value_to_yaml(msg.swiftpro_status, out);
    out << "\n";
  }

  // member: gripper
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gripper: ";
    rosidl_generator_traits::value_to_yaml(msg.gripper, out);
    out << "\n";
  }

  // member: limit_switch
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "limit_switch: ";
    rosidl_generator_traits::value_to_yaml(msg.limit_switch, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SwiftproState & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace swiftpro

namespace rosidl_generator_traits
{

[[deprecated("use swiftpro::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const swiftpro::msg::SwiftproState & msg,
  std::ostream & out, size_t indentation = 0)
{
  swiftpro::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use swiftpro::msg::to_yaml() instead")]]
inline std::string to_yaml(const swiftpro::msg::SwiftproState & msg)
{
  return swiftpro::msg::to_yaml(msg);
}

template<>
inline const char * data_type<swiftpro::msg::SwiftproState>()
{
  return "swiftpro::msg::SwiftproState";
}

template<>
inline const char * name<swiftpro::msg::SwiftproState>()
{
  return "swiftpro/msg/SwiftproState";
}

template<>
struct has_fixed_size<swiftpro::msg::SwiftproState>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<swiftpro::msg::SwiftproState>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<swiftpro::msg::SwiftproState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SWIFTPRO__MSG__DETAIL__SWIFTPRO_STATE__TRAITS_HPP_
