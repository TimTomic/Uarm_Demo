// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from swiftpro:msg/Position.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "swiftpro/msg/position.hpp"


#ifndef SWIFTPRO__MSG__DETAIL__POSITION__TRAITS_HPP_
#define SWIFTPRO__MSG__DETAIL__POSITION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "swiftpro/msg/detail/position__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace swiftpro
{

namespace msg
{

inline void to_flow_style_yaml(
  const Position & msg,
  std::ostream & out)
{
  out << "{";
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
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Position & msg,
  std::ostream & out, size_t indentation = 0)
{
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
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Position & msg, bool use_flow_style = false)
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
  const swiftpro::msg::Position & msg,
  std::ostream & out, size_t indentation = 0)
{
  swiftpro::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use swiftpro::msg::to_yaml() instead")]]
inline std::string to_yaml(const swiftpro::msg::Position & msg)
{
  return swiftpro::msg::to_yaml(msg);
}

template<>
inline const char * data_type<swiftpro::msg::Position>()
{
  return "swiftpro::msg::Position";
}

template<>
inline const char * name<swiftpro::msg::Position>()
{
  return "swiftpro/msg/Position";
}

template<>
struct has_fixed_size<swiftpro::msg::Position>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<swiftpro::msg::Position>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<swiftpro::msg::Position>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SWIFTPRO__MSG__DETAIL__POSITION__TRAITS_HPP_
