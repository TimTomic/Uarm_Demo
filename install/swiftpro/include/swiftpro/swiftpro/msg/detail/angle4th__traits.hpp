// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from swiftpro:msg/Angle4th.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "swiftpro/msg/angle4th.hpp"


#ifndef SWIFTPRO__MSG__DETAIL__ANGLE4TH__TRAITS_HPP_
#define SWIFTPRO__MSG__DETAIL__ANGLE4TH__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "swiftpro/msg/detail/angle4th__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace swiftpro
{

namespace msg
{

inline void to_flow_style_yaml(
  const Angle4th & msg,
  std::ostream & out)
{
  out << "{";
  // member: angle4th
  {
    out << "angle4th: ";
    rosidl_generator_traits::value_to_yaml(msg.angle4th, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Angle4th & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: angle4th
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "angle4th: ";
    rosidl_generator_traits::value_to_yaml(msg.angle4th, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Angle4th & msg, bool use_flow_style = false)
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
  const swiftpro::msg::Angle4th & msg,
  std::ostream & out, size_t indentation = 0)
{
  swiftpro::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use swiftpro::msg::to_yaml() instead")]]
inline std::string to_yaml(const swiftpro::msg::Angle4th & msg)
{
  return swiftpro::msg::to_yaml(msg);
}

template<>
inline const char * data_type<swiftpro::msg::Angle4th>()
{
  return "swiftpro::msg::Angle4th";
}

template<>
inline const char * name<swiftpro::msg::Angle4th>()
{
  return "swiftpro/msg/Angle4th";
}

template<>
struct has_fixed_size<swiftpro::msg::Angle4th>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<swiftpro::msg::Angle4th>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<swiftpro::msg::Angle4th>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SWIFTPRO__MSG__DETAIL__ANGLE4TH__TRAITS_HPP_
