// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from swiftpro:srv/SendGcode.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "swiftpro/srv/send_gcode.h"


#ifndef SWIFTPRO__SRV__DETAIL__SEND_GCODE__STRUCT_H_
#define SWIFTPRO__SRV__DETAIL__SEND_GCODE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'command'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/SendGcode in the package swiftpro.
typedef struct swiftpro__srv__SendGcode_Request
{
  rosidl_runtime_c__String command;
} swiftpro__srv__SendGcode_Request;

// Struct for a sequence of swiftpro__srv__SendGcode_Request.
typedef struct swiftpro__srv__SendGcode_Request__Sequence
{
  swiftpro__srv__SendGcode_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} swiftpro__srv__SendGcode_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'message'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/SendGcode in the package swiftpro.
typedef struct swiftpro__srv__SendGcode_Response
{
  bool success;
  rosidl_runtime_c__String message;
} swiftpro__srv__SendGcode_Response;

// Struct for a sequence of swiftpro__srv__SendGcode_Response.
typedef struct swiftpro__srv__SendGcode_Response__Sequence
{
  swiftpro__srv__SendGcode_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} swiftpro__srv__SendGcode_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  swiftpro__srv__SendGcode_Event__request__MAX_SIZE = 1
};
// response
enum
{
  swiftpro__srv__SendGcode_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/SendGcode in the package swiftpro.
typedef struct swiftpro__srv__SendGcode_Event
{
  service_msgs__msg__ServiceEventInfo info;
  swiftpro__srv__SendGcode_Request__Sequence request;
  swiftpro__srv__SendGcode_Response__Sequence response;
} swiftpro__srv__SendGcode_Event;

// Struct for a sequence of swiftpro__srv__SendGcode_Event.
typedef struct swiftpro__srv__SendGcode_Event__Sequence
{
  swiftpro__srv__SendGcode_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} swiftpro__srv__SendGcode_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SWIFTPRO__SRV__DETAIL__SEND_GCODE__STRUCT_H_
