// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from swiftpro:msg/Position.idl
// generated code does not contain a copyright notice

#include "swiftpro/msg/detail/position__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_swiftpro
const rosidl_type_hash_t *
swiftpro__msg__Position__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xdc, 0x42, 0x54, 0xfc, 0xa9, 0xf1, 0x2d, 0xc3,
      0xaf, 0xd4, 0xe7, 0x23, 0x6b, 0x74, 0xb0, 0x7d,
      0xb6, 0x23, 0x52, 0xc4, 0xef, 0x92, 0x81, 0xd7,
      0x3b, 0xda, 0x48, 0xc9, 0x1c, 0x2e, 0x9d, 0x40,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char swiftpro__msg__Position__TYPE_NAME[] = "swiftpro/msg/Position";

// Define type names, field names, and default values
static char swiftpro__msg__Position__FIELD_NAME__x[] = "x";
static char swiftpro__msg__Position__FIELD_NAME__y[] = "y";
static char swiftpro__msg__Position__FIELD_NAME__z[] = "z";

static rosidl_runtime_c__type_description__Field swiftpro__msg__Position__FIELDS[] = {
  {
    {swiftpro__msg__Position__FIELD_NAME__x, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {swiftpro__msg__Position__FIELD_NAME__y, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {swiftpro__msg__Position__FIELD_NAME__z, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
swiftpro__msg__Position__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {swiftpro__msg__Position__TYPE_NAME, 21, 21},
      {swiftpro__msg__Position__FIELDS, 3, 3},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "float64 x\n"
  "float64 y\n"
  "float64 z";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
swiftpro__msg__Position__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {swiftpro__msg__Position__TYPE_NAME, 21, 21},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 30, 30},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
swiftpro__msg__Position__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *swiftpro__msg__Position__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
