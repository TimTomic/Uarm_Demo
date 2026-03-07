// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from swiftpro:msg/Status.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "swiftpro/msg/status.h"


#ifndef SWIFTPRO__MSG__DETAIL__STATUS__STRUCT_H_
#define SWIFTPRO__MSG__DETAIL__STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/Status in the package swiftpro.
typedef struct swiftpro__msg__Status
{
  uint8_t status;
} swiftpro__msg__Status;

// Struct for a sequence of swiftpro__msg__Status.
typedef struct swiftpro__msg__Status__Sequence
{
  swiftpro__msg__Status * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} swiftpro__msg__Status__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SWIFTPRO__MSG__DETAIL__STATUS__STRUCT_H_
