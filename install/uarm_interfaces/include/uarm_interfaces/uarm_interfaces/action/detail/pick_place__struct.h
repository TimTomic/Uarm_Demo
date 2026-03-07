// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from uarm_interfaces:action/PickPlace.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "uarm_interfaces/action/pick_place.h"


#ifndef UARM_INTERFACES__ACTION__DETAIL__PICK_PLACE__STRUCT_H_
#define UARM_INTERFACES__ACTION__DETAIL__PICK_PLACE__STRUCT_H_

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

/// Struct defined in action/PickPlace in the package uarm_interfaces.
typedef struct uarm_interfaces__action__PickPlace_Goal
{
  rosidl_runtime_c__String command;
} uarm_interfaces__action__PickPlace_Goal;

// Struct for a sequence of uarm_interfaces__action__PickPlace_Goal.
typedef struct uarm_interfaces__action__PickPlace_Goal__Sequence
{
  uarm_interfaces__action__PickPlace_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} uarm_interfaces__action__PickPlace_Goal__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'message'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in action/PickPlace in the package uarm_interfaces.
typedef struct uarm_interfaces__action__PickPlace_Result
{
  bool success;
  rosidl_runtime_c__String message;
} uarm_interfaces__action__PickPlace_Result;

// Struct for a sequence of uarm_interfaces__action__PickPlace_Result.
typedef struct uarm_interfaces__action__PickPlace_Result__Sequence
{
  uarm_interfaces__action__PickPlace_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} uarm_interfaces__action__PickPlace_Result__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'current_state'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in action/PickPlace in the package uarm_interfaces.
typedef struct uarm_interfaces__action__PickPlace_Feedback
{
  rosidl_runtime_c__String current_state;
} uarm_interfaces__action__PickPlace_Feedback;

// Struct for a sequence of uarm_interfaces__action__PickPlace_Feedback.
typedef struct uarm_interfaces__action__PickPlace_Feedback__Sequence
{
  uarm_interfaces__action__PickPlace_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} uarm_interfaces__action__PickPlace_Feedback__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "uarm_interfaces/action/detail/pick_place__struct.h"

/// Struct defined in action/PickPlace in the package uarm_interfaces.
typedef struct uarm_interfaces__action__PickPlace_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  uarm_interfaces__action__PickPlace_Goal goal;
} uarm_interfaces__action__PickPlace_SendGoal_Request;

// Struct for a sequence of uarm_interfaces__action__PickPlace_SendGoal_Request.
typedef struct uarm_interfaces__action__PickPlace_SendGoal_Request__Sequence
{
  uarm_interfaces__action__PickPlace_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} uarm_interfaces__action__PickPlace_SendGoal_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/PickPlace in the package uarm_interfaces.
typedef struct uarm_interfaces__action__PickPlace_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} uarm_interfaces__action__PickPlace_SendGoal_Response;

// Struct for a sequence of uarm_interfaces__action__PickPlace_SendGoal_Response.
typedef struct uarm_interfaces__action__PickPlace_SendGoal_Response__Sequence
{
  uarm_interfaces__action__PickPlace_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} uarm_interfaces__action__PickPlace_SendGoal_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  uarm_interfaces__action__PickPlace_SendGoal_Event__request__MAX_SIZE = 1
};
// response
enum
{
  uarm_interfaces__action__PickPlace_SendGoal_Event__response__MAX_SIZE = 1
};

/// Struct defined in action/PickPlace in the package uarm_interfaces.
typedef struct uarm_interfaces__action__PickPlace_SendGoal_Event
{
  service_msgs__msg__ServiceEventInfo info;
  uarm_interfaces__action__PickPlace_SendGoal_Request__Sequence request;
  uarm_interfaces__action__PickPlace_SendGoal_Response__Sequence response;
} uarm_interfaces__action__PickPlace_SendGoal_Event;

// Struct for a sequence of uarm_interfaces__action__PickPlace_SendGoal_Event.
typedef struct uarm_interfaces__action__PickPlace_SendGoal_Event__Sequence
{
  uarm_interfaces__action__PickPlace_SendGoal_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} uarm_interfaces__action__PickPlace_SendGoal_Event__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/PickPlace in the package uarm_interfaces.
typedef struct uarm_interfaces__action__PickPlace_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} uarm_interfaces__action__PickPlace_GetResult_Request;

// Struct for a sequence of uarm_interfaces__action__PickPlace_GetResult_Request.
typedef struct uarm_interfaces__action__PickPlace_GetResult_Request__Sequence
{
  uarm_interfaces__action__PickPlace_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} uarm_interfaces__action__PickPlace_GetResult_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "uarm_interfaces/action/detail/pick_place__struct.h"

/// Struct defined in action/PickPlace in the package uarm_interfaces.
typedef struct uarm_interfaces__action__PickPlace_GetResult_Response
{
  int8_t status;
  uarm_interfaces__action__PickPlace_Result result;
} uarm_interfaces__action__PickPlace_GetResult_Response;

// Struct for a sequence of uarm_interfaces__action__PickPlace_GetResult_Response.
typedef struct uarm_interfaces__action__PickPlace_GetResult_Response__Sequence
{
  uarm_interfaces__action__PickPlace_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} uarm_interfaces__action__PickPlace_GetResult_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
// already included above
// #include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  uarm_interfaces__action__PickPlace_GetResult_Event__request__MAX_SIZE = 1
};
// response
enum
{
  uarm_interfaces__action__PickPlace_GetResult_Event__response__MAX_SIZE = 1
};

/// Struct defined in action/PickPlace in the package uarm_interfaces.
typedef struct uarm_interfaces__action__PickPlace_GetResult_Event
{
  service_msgs__msg__ServiceEventInfo info;
  uarm_interfaces__action__PickPlace_GetResult_Request__Sequence request;
  uarm_interfaces__action__PickPlace_GetResult_Response__Sequence response;
} uarm_interfaces__action__PickPlace_GetResult_Event;

// Struct for a sequence of uarm_interfaces__action__PickPlace_GetResult_Event.
typedef struct uarm_interfaces__action__PickPlace_GetResult_Event__Sequence
{
  uarm_interfaces__action__PickPlace_GetResult_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} uarm_interfaces__action__PickPlace_GetResult_Event__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "uarm_interfaces/action/detail/pick_place__struct.h"

/// Struct defined in action/PickPlace in the package uarm_interfaces.
typedef struct uarm_interfaces__action__PickPlace_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  uarm_interfaces__action__PickPlace_Feedback feedback;
} uarm_interfaces__action__PickPlace_FeedbackMessage;

// Struct for a sequence of uarm_interfaces__action__PickPlace_FeedbackMessage.
typedef struct uarm_interfaces__action__PickPlace_FeedbackMessage__Sequence
{
  uarm_interfaces__action__PickPlace_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} uarm_interfaces__action__PickPlace_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UARM_INTERFACES__ACTION__DETAIL__PICK_PLACE__STRUCT_H_
