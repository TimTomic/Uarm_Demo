// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from swiftpro:msg/SwiftproState.idl
// generated code does not contain a copyright notice
#include "swiftpro/msg/detail/swiftpro_state__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "swiftpro/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "swiftpro/msg/detail/swiftpro_state__struct.h"
#include "swiftpro/msg/detail/swiftpro_state__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _SwiftproState__ros_msg_type = swiftpro__msg__SwiftproState;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_swiftpro
bool cdr_serialize_swiftpro__msg__SwiftproState(
  const swiftpro__msg__SwiftproState * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: motor_angle1
  {
    cdr << ros_message->motor_angle1;
  }

  // Field name: motor_angle2
  {
    cdr << ros_message->motor_angle2;
  }

  // Field name: motor_angle3
  {
    cdr << ros_message->motor_angle3;
  }

  // Field name: motor_angle4
  {
    cdr << ros_message->motor_angle4;
  }

  // Field name: x
  {
    cdr << ros_message->x;
  }

  // Field name: y
  {
    cdr << ros_message->y;
  }

  // Field name: z
  {
    cdr << ros_message->z;
  }

  // Field name: pump
  {
    cdr << ros_message->pump;
  }

  // Field name: swiftpro_status
  {
    cdr << ros_message->swiftpro_status;
  }

  // Field name: gripper
  {
    cdr << ros_message->gripper;
  }

  // Field name: limit_switch
  {
    cdr << ros_message->limit_switch;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_swiftpro
bool cdr_deserialize_swiftpro__msg__SwiftproState(
  eprosima::fastcdr::Cdr & cdr,
  swiftpro__msg__SwiftproState * ros_message)
{
  // Field name: motor_angle1
  {
    cdr >> ros_message->motor_angle1;
  }

  // Field name: motor_angle2
  {
    cdr >> ros_message->motor_angle2;
  }

  // Field name: motor_angle3
  {
    cdr >> ros_message->motor_angle3;
  }

  // Field name: motor_angle4
  {
    cdr >> ros_message->motor_angle4;
  }

  // Field name: x
  {
    cdr >> ros_message->x;
  }

  // Field name: y
  {
    cdr >> ros_message->y;
  }

  // Field name: z
  {
    cdr >> ros_message->z;
  }

  // Field name: pump
  {
    cdr >> ros_message->pump;
  }

  // Field name: swiftpro_status
  {
    cdr >> ros_message->swiftpro_status;
  }

  // Field name: gripper
  {
    cdr >> ros_message->gripper;
  }

  // Field name: limit_switch
  {
    cdr >> ros_message->limit_switch;
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_swiftpro
size_t get_serialized_size_swiftpro__msg__SwiftproState(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _SwiftproState__ros_msg_type * ros_message = static_cast<const _SwiftproState__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: motor_angle1
  {
    size_t item_size = sizeof(ros_message->motor_angle1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: motor_angle2
  {
    size_t item_size = sizeof(ros_message->motor_angle2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: motor_angle3
  {
    size_t item_size = sizeof(ros_message->motor_angle3);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: motor_angle4
  {
    size_t item_size = sizeof(ros_message->motor_angle4);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: x
  {
    size_t item_size = sizeof(ros_message->x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: y
  {
    size_t item_size = sizeof(ros_message->y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: z
  {
    size_t item_size = sizeof(ros_message->z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: pump
  {
    size_t item_size = sizeof(ros_message->pump);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: swiftpro_status
  {
    size_t item_size = sizeof(ros_message->swiftpro_status);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: gripper
  {
    size_t item_size = sizeof(ros_message->gripper);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: limit_switch
  {
    size_t item_size = sizeof(ros_message->limit_switch);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_swiftpro
size_t max_serialized_size_swiftpro__msg__SwiftproState(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Field name: motor_angle1
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: motor_angle2
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: motor_angle3
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: motor_angle4
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: z
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: pump
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: swiftpro_status
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: gripper
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: limit_switch
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = swiftpro__msg__SwiftproState;
    is_plain =
      (
      offsetof(DataType, limit_switch) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_swiftpro
bool cdr_serialize_key_swiftpro__msg__SwiftproState(
  const swiftpro__msg__SwiftproState * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: motor_angle1
  {
    cdr << ros_message->motor_angle1;
  }

  // Field name: motor_angle2
  {
    cdr << ros_message->motor_angle2;
  }

  // Field name: motor_angle3
  {
    cdr << ros_message->motor_angle3;
  }

  // Field name: motor_angle4
  {
    cdr << ros_message->motor_angle4;
  }

  // Field name: x
  {
    cdr << ros_message->x;
  }

  // Field name: y
  {
    cdr << ros_message->y;
  }

  // Field name: z
  {
    cdr << ros_message->z;
  }

  // Field name: pump
  {
    cdr << ros_message->pump;
  }

  // Field name: swiftpro_status
  {
    cdr << ros_message->swiftpro_status;
  }

  // Field name: gripper
  {
    cdr << ros_message->gripper;
  }

  // Field name: limit_switch
  {
    cdr << ros_message->limit_switch;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_swiftpro
size_t get_serialized_size_key_swiftpro__msg__SwiftproState(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _SwiftproState__ros_msg_type * ros_message = static_cast<const _SwiftproState__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: motor_angle1
  {
    size_t item_size = sizeof(ros_message->motor_angle1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: motor_angle2
  {
    size_t item_size = sizeof(ros_message->motor_angle2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: motor_angle3
  {
    size_t item_size = sizeof(ros_message->motor_angle3);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: motor_angle4
  {
    size_t item_size = sizeof(ros_message->motor_angle4);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: x
  {
    size_t item_size = sizeof(ros_message->x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: y
  {
    size_t item_size = sizeof(ros_message->y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: z
  {
    size_t item_size = sizeof(ros_message->z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: pump
  {
    size_t item_size = sizeof(ros_message->pump);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: swiftpro_status
  {
    size_t item_size = sizeof(ros_message->swiftpro_status);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: gripper
  {
    size_t item_size = sizeof(ros_message->gripper);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: limit_switch
  {
    size_t item_size = sizeof(ros_message->limit_switch);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_swiftpro
size_t max_serialized_size_key_swiftpro__msg__SwiftproState(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;
  // Field name: motor_angle1
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: motor_angle2
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: motor_angle3
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: motor_angle4
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: z
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: pump
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: swiftpro_status
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: gripper
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: limit_switch
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = swiftpro__msg__SwiftproState;
    is_plain =
      (
      offsetof(DataType, limit_switch) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _SwiftproState__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const swiftpro__msg__SwiftproState * ros_message = static_cast<const swiftpro__msg__SwiftproState *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_swiftpro__msg__SwiftproState(ros_message, cdr);
}

static bool _SwiftproState__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  swiftpro__msg__SwiftproState * ros_message = static_cast<swiftpro__msg__SwiftproState *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_swiftpro__msg__SwiftproState(cdr, ros_message);
}

static uint32_t _SwiftproState__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_swiftpro__msg__SwiftproState(
      untyped_ros_message, 0));
}

static size_t _SwiftproState__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_swiftpro__msg__SwiftproState(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_SwiftproState = {
  "swiftpro::msg",
  "SwiftproState",
  _SwiftproState__cdr_serialize,
  _SwiftproState__cdr_deserialize,
  _SwiftproState__get_serialized_size,
  _SwiftproState__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _SwiftproState__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_SwiftproState,
  get_message_typesupport_handle_function,
  &swiftpro__msg__SwiftproState__get_type_hash,
  &swiftpro__msg__SwiftproState__get_type_description,
  &swiftpro__msg__SwiftproState__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, swiftpro, msg, SwiftproState)() {
  return &_SwiftproState__type_support;
}

#if defined(__cplusplus)
}
#endif
