// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from swiftpro:msg/SwiftproState.idl
// generated code does not contain a copyright notice

#include "swiftpro/msg/detail/swiftpro_state__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_swiftpro
const rosidl_type_hash_t *
swiftpro__msg__SwiftproState__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xe6, 0xf4, 0x9b, 0x09, 0xcb, 0x1f, 0x80, 0xd9,
      0xfa, 0xa3, 0xf5, 0x16, 0xe6, 0x07, 0x4e, 0x8c,
      0x5c, 0x9d, 0x1f, 0xf7, 0xff, 0xed, 0xb1, 0xce,
      0x5d, 0xca, 0xbb, 0xd5, 0x43, 0x83, 0xc2, 0x86,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char swiftpro__msg__SwiftproState__TYPE_NAME[] = "swiftpro/msg/SwiftproState";

// Define type names, field names, and default values
static char swiftpro__msg__SwiftproState__FIELD_NAME__motor_angle1[] = "motor_angle1";
static char swiftpro__msg__SwiftproState__FIELD_NAME__motor_angle2[] = "motor_angle2";
static char swiftpro__msg__SwiftproState__FIELD_NAME__motor_angle3[] = "motor_angle3";
static char swiftpro__msg__SwiftproState__FIELD_NAME__motor_angle4[] = "motor_angle4";
static char swiftpro__msg__SwiftproState__FIELD_NAME__x[] = "x";
static char swiftpro__msg__SwiftproState__FIELD_NAME__y[] = "y";
static char swiftpro__msg__SwiftproState__FIELD_NAME__z[] = "z";
static char swiftpro__msg__SwiftproState__FIELD_NAME__pump[] = "pump";
static char swiftpro__msg__SwiftproState__FIELD_NAME__swiftpro_status[] = "swiftpro_status";
static char swiftpro__msg__SwiftproState__FIELD_NAME__gripper[] = "gripper";
static char swiftpro__msg__SwiftproState__FIELD_NAME__limit_switch[] = "limit_switch";

static rosidl_runtime_c__type_description__Field swiftpro__msg__SwiftproState__FIELDS[] = {
  {
    {swiftpro__msg__SwiftproState__FIELD_NAME__motor_angle1, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {swiftpro__msg__SwiftproState__FIELD_NAME__motor_angle2, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {swiftpro__msg__SwiftproState__FIELD_NAME__motor_angle3, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {swiftpro__msg__SwiftproState__FIELD_NAME__motor_angle4, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {swiftpro__msg__SwiftproState__FIELD_NAME__x, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {swiftpro__msg__SwiftproState__FIELD_NAME__y, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {swiftpro__msg__SwiftproState__FIELD_NAME__z, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {swiftpro__msg__SwiftproState__FIELD_NAME__pump, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {swiftpro__msg__SwiftproState__FIELD_NAME__swiftpro_status, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {swiftpro__msg__SwiftproState__FIELD_NAME__gripper, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {swiftpro__msg__SwiftproState__FIELD_NAME__limit_switch, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
swiftpro__msg__SwiftproState__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {swiftpro__msg__SwiftproState__TYPE_NAME, 26, 26},
      {swiftpro__msg__SwiftproState__FIELDS, 11, 11},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "float64 motor_angle1\n"
  "float64 motor_angle2\n"
  "float64 motor_angle3\n"
  "float64 motor_angle4\n"
  "float64 x\n"
  "float64 y\n"
  "float64 z\n"
  "uint8 \\tpump\n"
  "uint8 \\tswiftpro_status\n"
  "uint8 \\tgripper\n"
  "uint8   limit_switch";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
swiftpro__msg__SwiftproState__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {swiftpro__msg__SwiftproState__TYPE_NAME, 26, 26},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 185, 185},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
swiftpro__msg__SwiftproState__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *swiftpro__msg__SwiftproState__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
