// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from swiftpro:msg/Angle4th.idl
// generated code does not contain a copyright notice

#include "swiftpro/msg/detail/angle4th__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_swiftpro
const rosidl_type_hash_t *
swiftpro__msg__Angle4th__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x44, 0x73, 0x40, 0x29, 0x7d, 0x97, 0x82, 0x58,
      0x43, 0xa3, 0xb7, 0x84, 0xff, 0xbe, 0x2f, 0x51,
      0xbd, 0xb3, 0x86, 0xd2, 0xef, 0x70, 0x9e, 0x22,
      0x5d, 0x7e, 0xc9, 0xe0, 0x83, 0x9b, 0x8f, 0x5b,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char swiftpro__msg__Angle4th__TYPE_NAME[] = "swiftpro/msg/Angle4th";

// Define type names, field names, and default values
static char swiftpro__msg__Angle4th__FIELD_NAME__angle4th[] = "angle4th";

static rosidl_runtime_c__type_description__Field swiftpro__msg__Angle4th__FIELDS[] = {
  {
    {swiftpro__msg__Angle4th__FIELD_NAME__angle4th, 8, 8},
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
swiftpro__msg__Angle4th__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {swiftpro__msg__Angle4th__TYPE_NAME, 21, 21},
      {swiftpro__msg__Angle4th__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "float64 angle4th";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
swiftpro__msg__Angle4th__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {swiftpro__msg__Angle4th__TYPE_NAME, 21, 21},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 17, 17},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
swiftpro__msg__Angle4th__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *swiftpro__msg__Angle4th__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
