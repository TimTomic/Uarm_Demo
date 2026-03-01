// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from swiftpro:msg/SwiftproState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "swiftpro/msg/swiftpro_state.h"


#ifndef SWIFTPRO__MSG__DETAIL__SWIFTPRO_STATE__STRUCT_H_
#define SWIFTPRO__MSG__DETAIL__SWIFTPRO_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/SwiftproState in the package swiftpro.
typedef struct swiftpro__msg__SwiftproState
{
  double motor_angle1;
  double motor_angle2;
  double motor_angle3;
  double motor_angle4;
  double x;
  double y;
  double z;
  uint8_t pump;
  uint8_t swiftpro_status;
  uint8_t gripper;
  uint8_t limit_switch;
} swiftpro__msg__SwiftproState;

// Struct for a sequence of swiftpro__msg__SwiftproState.
typedef struct swiftpro__msg__SwiftproState__Sequence
{
  swiftpro__msg__SwiftproState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} swiftpro__msg__SwiftproState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SWIFTPRO__MSG__DETAIL__SWIFTPRO_STATE__STRUCT_H_
