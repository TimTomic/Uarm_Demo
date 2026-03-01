// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from swiftpro:msg/Status.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "swiftpro/msg/detail/status__rosidl_typesupport_introspection_c.h"
#include "swiftpro/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "swiftpro/msg/detail/status__functions.h"
#include "swiftpro/msg/detail/status__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void swiftpro__msg__Status__rosidl_typesupport_introspection_c__Status_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  swiftpro__msg__Status__init(message_memory);
}

void swiftpro__msg__Status__rosidl_typesupport_introspection_c__Status_fini_function(void * message_memory)
{
  swiftpro__msg__Status__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember swiftpro__msg__Status__rosidl_typesupport_introspection_c__Status_message_member_array[1] = {
  {
    "status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(swiftpro__msg__Status, status),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers swiftpro__msg__Status__rosidl_typesupport_introspection_c__Status_message_members = {
  "swiftpro__msg",  // message namespace
  "Status",  // message name
  1,  // number of fields
  sizeof(swiftpro__msg__Status),
  false,  // has_any_key_member_
  swiftpro__msg__Status__rosidl_typesupport_introspection_c__Status_message_member_array,  // message members
  swiftpro__msg__Status__rosidl_typesupport_introspection_c__Status_init_function,  // function to initialize message memory (memory has to be allocated)
  swiftpro__msg__Status__rosidl_typesupport_introspection_c__Status_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t swiftpro__msg__Status__rosidl_typesupport_introspection_c__Status_message_type_support_handle = {
  0,
  &swiftpro__msg__Status__rosidl_typesupport_introspection_c__Status_message_members,
  get_message_typesupport_handle_function,
  &swiftpro__msg__Status__get_type_hash,
  &swiftpro__msg__Status__get_type_description,
  &swiftpro__msg__Status__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_swiftpro
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, swiftpro, msg, Status)() {
  if (!swiftpro__msg__Status__rosidl_typesupport_introspection_c__Status_message_type_support_handle.typesupport_identifier) {
    swiftpro__msg__Status__rosidl_typesupport_introspection_c__Status_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &swiftpro__msg__Status__rosidl_typesupport_introspection_c__Status_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
