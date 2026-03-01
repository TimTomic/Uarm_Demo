// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from swiftpro:msg/Angle4th.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "swiftpro/msg/detail/angle4th__functions.h"
#include "swiftpro/msg/detail/angle4th__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace swiftpro
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void Angle4th_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) swiftpro::msg::Angle4th(_init);
}

void Angle4th_fini_function(void * message_memory)
{
  auto typed_message = static_cast<swiftpro::msg::Angle4th *>(message_memory);
  typed_message->~Angle4th();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Angle4th_message_member_array[1] = {
  {
    "angle4th",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(swiftpro::msg::Angle4th, angle4th),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Angle4th_message_members = {
  "swiftpro::msg",  // message namespace
  "Angle4th",  // message name
  1,  // number of fields
  sizeof(swiftpro::msg::Angle4th),
  false,  // has_any_key_member_
  Angle4th_message_member_array,  // message members
  Angle4th_init_function,  // function to initialize message memory (memory has to be allocated)
  Angle4th_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Angle4th_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Angle4th_message_members,
  get_message_typesupport_handle_function,
  &swiftpro__msg__Angle4th__get_type_hash,
  &swiftpro__msg__Angle4th__get_type_description,
  &swiftpro__msg__Angle4th__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace swiftpro


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<swiftpro::msg::Angle4th>()
{
  return &::swiftpro::msg::rosidl_typesupport_introspection_cpp::Angle4th_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, swiftpro, msg, Angle4th)() {
  return &::swiftpro::msg::rosidl_typesupport_introspection_cpp::Angle4th_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
