// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from swiftpro:msg/Status.idl
// generated code does not contain a copyright notice

#include "swiftpro/msg/detail/status__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_swiftpro
const rosidl_type_hash_t *
swiftpro__msg__Status__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xec, 0x9d, 0xb4, 0xb4, 0x0b, 0xf8, 0xe1, 0x6e,
      0x05, 0xd9, 0x83, 0xc7, 0x01, 0x45, 0x5f, 0x16,
      0xfb, 0xc3, 0x86, 0xe6, 0xca, 0xb4, 0x8d, 0xf6,
      0xf8, 0x06, 0xd4, 0x8c, 0x81, 0x8c, 0x3d, 0x33,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char swiftpro__msg__Status__TYPE_NAME[] = "swiftpro/msg/Status";

// Define type names, field names, and default values
static char swiftpro__msg__Status__FIELD_NAME__status[] = "status";

static rosidl_runtime_c__type_description__Field swiftpro__msg__Status__FIELDS[] = {
  {
    {swiftpro__msg__Status__FIELD_NAME__status, 6, 6},
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
swiftpro__msg__Status__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {swiftpro__msg__Status__TYPE_NAME, 19, 19},
      {swiftpro__msg__Status__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "uint8 status";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
swiftpro__msg__Status__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {swiftpro__msg__Status__TYPE_NAME, 19, 19},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 13, 13},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
swiftpro__msg__Status__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *swiftpro__msg__Status__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
