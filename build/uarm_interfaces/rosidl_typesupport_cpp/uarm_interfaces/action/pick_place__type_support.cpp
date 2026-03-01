// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from uarm_interfaces:action/PickPlace.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "uarm_interfaces/action/detail/pick_place__functions.h"
#include "uarm_interfaces/action/detail/pick_place__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace uarm_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _PickPlace_Goal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PickPlace_Goal_type_support_ids_t;

static const _PickPlace_Goal_type_support_ids_t _PickPlace_Goal_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _PickPlace_Goal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PickPlace_Goal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PickPlace_Goal_type_support_symbol_names_t _PickPlace_Goal_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, uarm_interfaces, action, PickPlace_Goal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, uarm_interfaces, action, PickPlace_Goal)),
  }
};

typedef struct _PickPlace_Goal_type_support_data_t
{
  void * data[2];
} _PickPlace_Goal_type_support_data_t;

static _PickPlace_Goal_type_support_data_t _PickPlace_Goal_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PickPlace_Goal_message_typesupport_map = {
  2,
  "uarm_interfaces",
  &_PickPlace_Goal_message_typesupport_ids.typesupport_identifier[0],
  &_PickPlace_Goal_message_typesupport_symbol_names.symbol_name[0],
  &_PickPlace_Goal_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PickPlace_Goal_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PickPlace_Goal_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &uarm_interfaces__action__PickPlace_Goal__get_type_hash,
  &uarm_interfaces__action__PickPlace_Goal__get_type_description,
  &uarm_interfaces__action__PickPlace_Goal__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace uarm_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<uarm_interfaces::action::PickPlace_Goal>()
{
  return &::uarm_interfaces::action::rosidl_typesupport_cpp::PickPlace_Goal_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, uarm_interfaces, action, PickPlace_Goal)() {
  return get_message_type_support_handle<uarm_interfaces::action::PickPlace_Goal>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "uarm_interfaces/action/detail/pick_place__functions.h"
// already included above
// #include "uarm_interfaces/action/detail/pick_place__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace uarm_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _PickPlace_Result_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PickPlace_Result_type_support_ids_t;

static const _PickPlace_Result_type_support_ids_t _PickPlace_Result_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _PickPlace_Result_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PickPlace_Result_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PickPlace_Result_type_support_symbol_names_t _PickPlace_Result_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, uarm_interfaces, action, PickPlace_Result)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, uarm_interfaces, action, PickPlace_Result)),
  }
};

typedef struct _PickPlace_Result_type_support_data_t
{
  void * data[2];
} _PickPlace_Result_type_support_data_t;

static _PickPlace_Result_type_support_data_t _PickPlace_Result_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PickPlace_Result_message_typesupport_map = {
  2,
  "uarm_interfaces",
  &_PickPlace_Result_message_typesupport_ids.typesupport_identifier[0],
  &_PickPlace_Result_message_typesupport_symbol_names.symbol_name[0],
  &_PickPlace_Result_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PickPlace_Result_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PickPlace_Result_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &uarm_interfaces__action__PickPlace_Result__get_type_hash,
  &uarm_interfaces__action__PickPlace_Result__get_type_description,
  &uarm_interfaces__action__PickPlace_Result__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace uarm_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<uarm_interfaces::action::PickPlace_Result>()
{
  return &::uarm_interfaces::action::rosidl_typesupport_cpp::PickPlace_Result_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, uarm_interfaces, action, PickPlace_Result)() {
  return get_message_type_support_handle<uarm_interfaces::action::PickPlace_Result>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "uarm_interfaces/action/detail/pick_place__functions.h"
// already included above
// #include "uarm_interfaces/action/detail/pick_place__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace uarm_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _PickPlace_Feedback_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PickPlace_Feedback_type_support_ids_t;

static const _PickPlace_Feedback_type_support_ids_t _PickPlace_Feedback_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _PickPlace_Feedback_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PickPlace_Feedback_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PickPlace_Feedback_type_support_symbol_names_t _PickPlace_Feedback_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, uarm_interfaces, action, PickPlace_Feedback)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, uarm_interfaces, action, PickPlace_Feedback)),
  }
};

typedef struct _PickPlace_Feedback_type_support_data_t
{
  void * data[2];
} _PickPlace_Feedback_type_support_data_t;

static _PickPlace_Feedback_type_support_data_t _PickPlace_Feedback_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PickPlace_Feedback_message_typesupport_map = {
  2,
  "uarm_interfaces",
  &_PickPlace_Feedback_message_typesupport_ids.typesupport_identifier[0],
  &_PickPlace_Feedback_message_typesupport_symbol_names.symbol_name[0],
  &_PickPlace_Feedback_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PickPlace_Feedback_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PickPlace_Feedback_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &uarm_interfaces__action__PickPlace_Feedback__get_type_hash,
  &uarm_interfaces__action__PickPlace_Feedback__get_type_description,
  &uarm_interfaces__action__PickPlace_Feedback__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace uarm_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<uarm_interfaces::action::PickPlace_Feedback>()
{
  return &::uarm_interfaces::action::rosidl_typesupport_cpp::PickPlace_Feedback_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, uarm_interfaces, action, PickPlace_Feedback)() {
  return get_message_type_support_handle<uarm_interfaces::action::PickPlace_Feedback>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "uarm_interfaces/action/detail/pick_place__functions.h"
// already included above
// #include "uarm_interfaces/action/detail/pick_place__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace uarm_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _PickPlace_SendGoal_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PickPlace_SendGoal_Request_type_support_ids_t;

static const _PickPlace_SendGoal_Request_type_support_ids_t _PickPlace_SendGoal_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _PickPlace_SendGoal_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PickPlace_SendGoal_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PickPlace_SendGoal_Request_type_support_symbol_names_t _PickPlace_SendGoal_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, uarm_interfaces, action, PickPlace_SendGoal_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, uarm_interfaces, action, PickPlace_SendGoal_Request)),
  }
};

typedef struct _PickPlace_SendGoal_Request_type_support_data_t
{
  void * data[2];
} _PickPlace_SendGoal_Request_type_support_data_t;

static _PickPlace_SendGoal_Request_type_support_data_t _PickPlace_SendGoal_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PickPlace_SendGoal_Request_message_typesupport_map = {
  2,
  "uarm_interfaces",
  &_PickPlace_SendGoal_Request_message_typesupport_ids.typesupport_identifier[0],
  &_PickPlace_SendGoal_Request_message_typesupport_symbol_names.symbol_name[0],
  &_PickPlace_SendGoal_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PickPlace_SendGoal_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PickPlace_SendGoal_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &uarm_interfaces__action__PickPlace_SendGoal_Request__get_type_hash,
  &uarm_interfaces__action__PickPlace_SendGoal_Request__get_type_description,
  &uarm_interfaces__action__PickPlace_SendGoal_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace uarm_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<uarm_interfaces::action::PickPlace_SendGoal_Request>()
{
  return &::uarm_interfaces::action::rosidl_typesupport_cpp::PickPlace_SendGoal_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, uarm_interfaces, action, PickPlace_SendGoal_Request)() {
  return get_message_type_support_handle<uarm_interfaces::action::PickPlace_SendGoal_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "uarm_interfaces/action/detail/pick_place__functions.h"
// already included above
// #include "uarm_interfaces/action/detail/pick_place__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace uarm_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _PickPlace_SendGoal_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PickPlace_SendGoal_Response_type_support_ids_t;

static const _PickPlace_SendGoal_Response_type_support_ids_t _PickPlace_SendGoal_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _PickPlace_SendGoal_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PickPlace_SendGoal_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PickPlace_SendGoal_Response_type_support_symbol_names_t _PickPlace_SendGoal_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, uarm_interfaces, action, PickPlace_SendGoal_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, uarm_interfaces, action, PickPlace_SendGoal_Response)),
  }
};

typedef struct _PickPlace_SendGoal_Response_type_support_data_t
{
  void * data[2];
} _PickPlace_SendGoal_Response_type_support_data_t;

static _PickPlace_SendGoal_Response_type_support_data_t _PickPlace_SendGoal_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PickPlace_SendGoal_Response_message_typesupport_map = {
  2,
  "uarm_interfaces",
  &_PickPlace_SendGoal_Response_message_typesupport_ids.typesupport_identifier[0],
  &_PickPlace_SendGoal_Response_message_typesupport_symbol_names.symbol_name[0],
  &_PickPlace_SendGoal_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PickPlace_SendGoal_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PickPlace_SendGoal_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &uarm_interfaces__action__PickPlace_SendGoal_Response__get_type_hash,
  &uarm_interfaces__action__PickPlace_SendGoal_Response__get_type_description,
  &uarm_interfaces__action__PickPlace_SendGoal_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace uarm_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<uarm_interfaces::action::PickPlace_SendGoal_Response>()
{
  return &::uarm_interfaces::action::rosidl_typesupport_cpp::PickPlace_SendGoal_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, uarm_interfaces, action, PickPlace_SendGoal_Response)() {
  return get_message_type_support_handle<uarm_interfaces::action::PickPlace_SendGoal_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "uarm_interfaces/action/detail/pick_place__functions.h"
// already included above
// #include "uarm_interfaces/action/detail/pick_place__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace uarm_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _PickPlace_SendGoal_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PickPlace_SendGoal_Event_type_support_ids_t;

static const _PickPlace_SendGoal_Event_type_support_ids_t _PickPlace_SendGoal_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _PickPlace_SendGoal_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PickPlace_SendGoal_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PickPlace_SendGoal_Event_type_support_symbol_names_t _PickPlace_SendGoal_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, uarm_interfaces, action, PickPlace_SendGoal_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, uarm_interfaces, action, PickPlace_SendGoal_Event)),
  }
};

typedef struct _PickPlace_SendGoal_Event_type_support_data_t
{
  void * data[2];
} _PickPlace_SendGoal_Event_type_support_data_t;

static _PickPlace_SendGoal_Event_type_support_data_t _PickPlace_SendGoal_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PickPlace_SendGoal_Event_message_typesupport_map = {
  2,
  "uarm_interfaces",
  &_PickPlace_SendGoal_Event_message_typesupport_ids.typesupport_identifier[0],
  &_PickPlace_SendGoal_Event_message_typesupport_symbol_names.symbol_name[0],
  &_PickPlace_SendGoal_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PickPlace_SendGoal_Event_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PickPlace_SendGoal_Event_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &uarm_interfaces__action__PickPlace_SendGoal_Event__get_type_hash,
  &uarm_interfaces__action__PickPlace_SendGoal_Event__get_type_description,
  &uarm_interfaces__action__PickPlace_SendGoal_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace uarm_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<uarm_interfaces::action::PickPlace_SendGoal_Event>()
{
  return &::uarm_interfaces::action::rosidl_typesupport_cpp::PickPlace_SendGoal_Event_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, uarm_interfaces, action, PickPlace_SendGoal_Event)() {
  return get_message_type_support_handle<uarm_interfaces::action::PickPlace_SendGoal_Event>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "uarm_interfaces/action/detail/pick_place__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace uarm_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _PickPlace_SendGoal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PickPlace_SendGoal_type_support_ids_t;

static const _PickPlace_SendGoal_type_support_ids_t _PickPlace_SendGoal_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _PickPlace_SendGoal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PickPlace_SendGoal_type_support_symbol_names_t;
#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PickPlace_SendGoal_type_support_symbol_names_t _PickPlace_SendGoal_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, uarm_interfaces, action, PickPlace_SendGoal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, uarm_interfaces, action, PickPlace_SendGoal)),
  }
};

typedef struct _PickPlace_SendGoal_type_support_data_t
{
  void * data[2];
} _PickPlace_SendGoal_type_support_data_t;

static _PickPlace_SendGoal_type_support_data_t _PickPlace_SendGoal_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PickPlace_SendGoal_service_typesupport_map = {
  2,
  "uarm_interfaces",
  &_PickPlace_SendGoal_service_typesupport_ids.typesupport_identifier[0],
  &_PickPlace_SendGoal_service_typesupport_symbol_names.symbol_name[0],
  &_PickPlace_SendGoal_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t PickPlace_SendGoal_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PickPlace_SendGoal_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
  ::rosidl_typesupport_cpp::get_message_type_support_handle<uarm_interfaces::action::PickPlace_SendGoal_Request>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<uarm_interfaces::action::PickPlace_SendGoal_Response>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<uarm_interfaces::action::PickPlace_SendGoal_Event>(),
  &::rosidl_typesupport_cpp::service_create_event_message<uarm_interfaces::action::PickPlace_SendGoal>,
  &::rosidl_typesupport_cpp::service_destroy_event_message<uarm_interfaces::action::PickPlace_SendGoal>,
  &uarm_interfaces__action__PickPlace_SendGoal__get_type_hash,
  &uarm_interfaces__action__PickPlace_SendGoal__get_type_description,
  &uarm_interfaces__action__PickPlace_SendGoal__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace uarm_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<uarm_interfaces::action::PickPlace_SendGoal>()
{
  return &::uarm_interfaces::action::rosidl_typesupport_cpp::PickPlace_SendGoal_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, uarm_interfaces, action, PickPlace_SendGoal)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<uarm_interfaces::action::PickPlace_SendGoal>();
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "uarm_interfaces/action/detail/pick_place__functions.h"
// already included above
// #include "uarm_interfaces/action/detail/pick_place__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace uarm_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _PickPlace_GetResult_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PickPlace_GetResult_Request_type_support_ids_t;

static const _PickPlace_GetResult_Request_type_support_ids_t _PickPlace_GetResult_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _PickPlace_GetResult_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PickPlace_GetResult_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PickPlace_GetResult_Request_type_support_symbol_names_t _PickPlace_GetResult_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, uarm_interfaces, action, PickPlace_GetResult_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, uarm_interfaces, action, PickPlace_GetResult_Request)),
  }
};

typedef struct _PickPlace_GetResult_Request_type_support_data_t
{
  void * data[2];
} _PickPlace_GetResult_Request_type_support_data_t;

static _PickPlace_GetResult_Request_type_support_data_t _PickPlace_GetResult_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PickPlace_GetResult_Request_message_typesupport_map = {
  2,
  "uarm_interfaces",
  &_PickPlace_GetResult_Request_message_typesupport_ids.typesupport_identifier[0],
  &_PickPlace_GetResult_Request_message_typesupport_symbol_names.symbol_name[0],
  &_PickPlace_GetResult_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PickPlace_GetResult_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PickPlace_GetResult_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &uarm_interfaces__action__PickPlace_GetResult_Request__get_type_hash,
  &uarm_interfaces__action__PickPlace_GetResult_Request__get_type_description,
  &uarm_interfaces__action__PickPlace_GetResult_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace uarm_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<uarm_interfaces::action::PickPlace_GetResult_Request>()
{
  return &::uarm_interfaces::action::rosidl_typesupport_cpp::PickPlace_GetResult_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, uarm_interfaces, action, PickPlace_GetResult_Request)() {
  return get_message_type_support_handle<uarm_interfaces::action::PickPlace_GetResult_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "uarm_interfaces/action/detail/pick_place__functions.h"
// already included above
// #include "uarm_interfaces/action/detail/pick_place__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace uarm_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _PickPlace_GetResult_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PickPlace_GetResult_Response_type_support_ids_t;

static const _PickPlace_GetResult_Response_type_support_ids_t _PickPlace_GetResult_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _PickPlace_GetResult_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PickPlace_GetResult_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PickPlace_GetResult_Response_type_support_symbol_names_t _PickPlace_GetResult_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, uarm_interfaces, action, PickPlace_GetResult_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, uarm_interfaces, action, PickPlace_GetResult_Response)),
  }
};

typedef struct _PickPlace_GetResult_Response_type_support_data_t
{
  void * data[2];
} _PickPlace_GetResult_Response_type_support_data_t;

static _PickPlace_GetResult_Response_type_support_data_t _PickPlace_GetResult_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PickPlace_GetResult_Response_message_typesupport_map = {
  2,
  "uarm_interfaces",
  &_PickPlace_GetResult_Response_message_typesupport_ids.typesupport_identifier[0],
  &_PickPlace_GetResult_Response_message_typesupport_symbol_names.symbol_name[0],
  &_PickPlace_GetResult_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PickPlace_GetResult_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PickPlace_GetResult_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &uarm_interfaces__action__PickPlace_GetResult_Response__get_type_hash,
  &uarm_interfaces__action__PickPlace_GetResult_Response__get_type_description,
  &uarm_interfaces__action__PickPlace_GetResult_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace uarm_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<uarm_interfaces::action::PickPlace_GetResult_Response>()
{
  return &::uarm_interfaces::action::rosidl_typesupport_cpp::PickPlace_GetResult_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, uarm_interfaces, action, PickPlace_GetResult_Response)() {
  return get_message_type_support_handle<uarm_interfaces::action::PickPlace_GetResult_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "uarm_interfaces/action/detail/pick_place__functions.h"
// already included above
// #include "uarm_interfaces/action/detail/pick_place__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace uarm_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _PickPlace_GetResult_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PickPlace_GetResult_Event_type_support_ids_t;

static const _PickPlace_GetResult_Event_type_support_ids_t _PickPlace_GetResult_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _PickPlace_GetResult_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PickPlace_GetResult_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PickPlace_GetResult_Event_type_support_symbol_names_t _PickPlace_GetResult_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, uarm_interfaces, action, PickPlace_GetResult_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, uarm_interfaces, action, PickPlace_GetResult_Event)),
  }
};

typedef struct _PickPlace_GetResult_Event_type_support_data_t
{
  void * data[2];
} _PickPlace_GetResult_Event_type_support_data_t;

static _PickPlace_GetResult_Event_type_support_data_t _PickPlace_GetResult_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PickPlace_GetResult_Event_message_typesupport_map = {
  2,
  "uarm_interfaces",
  &_PickPlace_GetResult_Event_message_typesupport_ids.typesupport_identifier[0],
  &_PickPlace_GetResult_Event_message_typesupport_symbol_names.symbol_name[0],
  &_PickPlace_GetResult_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PickPlace_GetResult_Event_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PickPlace_GetResult_Event_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &uarm_interfaces__action__PickPlace_GetResult_Event__get_type_hash,
  &uarm_interfaces__action__PickPlace_GetResult_Event__get_type_description,
  &uarm_interfaces__action__PickPlace_GetResult_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace uarm_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<uarm_interfaces::action::PickPlace_GetResult_Event>()
{
  return &::uarm_interfaces::action::rosidl_typesupport_cpp::PickPlace_GetResult_Event_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, uarm_interfaces, action, PickPlace_GetResult_Event)() {
  return get_message_type_support_handle<uarm_interfaces::action::PickPlace_GetResult_Event>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "uarm_interfaces/action/detail/pick_place__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace uarm_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _PickPlace_GetResult_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PickPlace_GetResult_type_support_ids_t;

static const _PickPlace_GetResult_type_support_ids_t _PickPlace_GetResult_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _PickPlace_GetResult_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PickPlace_GetResult_type_support_symbol_names_t;
#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PickPlace_GetResult_type_support_symbol_names_t _PickPlace_GetResult_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, uarm_interfaces, action, PickPlace_GetResult)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, uarm_interfaces, action, PickPlace_GetResult)),
  }
};

typedef struct _PickPlace_GetResult_type_support_data_t
{
  void * data[2];
} _PickPlace_GetResult_type_support_data_t;

static _PickPlace_GetResult_type_support_data_t _PickPlace_GetResult_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PickPlace_GetResult_service_typesupport_map = {
  2,
  "uarm_interfaces",
  &_PickPlace_GetResult_service_typesupport_ids.typesupport_identifier[0],
  &_PickPlace_GetResult_service_typesupport_symbol_names.symbol_name[0],
  &_PickPlace_GetResult_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t PickPlace_GetResult_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PickPlace_GetResult_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
  ::rosidl_typesupport_cpp::get_message_type_support_handle<uarm_interfaces::action::PickPlace_GetResult_Request>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<uarm_interfaces::action::PickPlace_GetResult_Response>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<uarm_interfaces::action::PickPlace_GetResult_Event>(),
  &::rosidl_typesupport_cpp::service_create_event_message<uarm_interfaces::action::PickPlace_GetResult>,
  &::rosidl_typesupport_cpp::service_destroy_event_message<uarm_interfaces::action::PickPlace_GetResult>,
  &uarm_interfaces__action__PickPlace_GetResult__get_type_hash,
  &uarm_interfaces__action__PickPlace_GetResult__get_type_description,
  &uarm_interfaces__action__PickPlace_GetResult__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace uarm_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<uarm_interfaces::action::PickPlace_GetResult>()
{
  return &::uarm_interfaces::action::rosidl_typesupport_cpp::PickPlace_GetResult_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, uarm_interfaces, action, PickPlace_GetResult)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<uarm_interfaces::action::PickPlace_GetResult>();
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "uarm_interfaces/action/detail/pick_place__functions.h"
// already included above
// #include "uarm_interfaces/action/detail/pick_place__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace uarm_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _PickPlace_FeedbackMessage_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PickPlace_FeedbackMessage_type_support_ids_t;

static const _PickPlace_FeedbackMessage_type_support_ids_t _PickPlace_FeedbackMessage_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _PickPlace_FeedbackMessage_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PickPlace_FeedbackMessage_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PickPlace_FeedbackMessage_type_support_symbol_names_t _PickPlace_FeedbackMessage_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, uarm_interfaces, action, PickPlace_FeedbackMessage)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, uarm_interfaces, action, PickPlace_FeedbackMessage)),
  }
};

typedef struct _PickPlace_FeedbackMessage_type_support_data_t
{
  void * data[2];
} _PickPlace_FeedbackMessage_type_support_data_t;

static _PickPlace_FeedbackMessage_type_support_data_t _PickPlace_FeedbackMessage_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PickPlace_FeedbackMessage_message_typesupport_map = {
  2,
  "uarm_interfaces",
  &_PickPlace_FeedbackMessage_message_typesupport_ids.typesupport_identifier[0],
  &_PickPlace_FeedbackMessage_message_typesupport_symbol_names.symbol_name[0],
  &_PickPlace_FeedbackMessage_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PickPlace_FeedbackMessage_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PickPlace_FeedbackMessage_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &uarm_interfaces__action__PickPlace_FeedbackMessage__get_type_hash,
  &uarm_interfaces__action__PickPlace_FeedbackMessage__get_type_description,
  &uarm_interfaces__action__PickPlace_FeedbackMessage__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace uarm_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<uarm_interfaces::action::PickPlace_FeedbackMessage>()
{
  return &::uarm_interfaces::action::rosidl_typesupport_cpp::PickPlace_FeedbackMessage_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, uarm_interfaces, action, PickPlace_FeedbackMessage)() {
  return get_message_type_support_handle<uarm_interfaces::action::PickPlace_FeedbackMessage>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

#include "action_msgs/msg/goal_status_array.hpp"
#include "action_msgs/srv/cancel_goal.hpp"
// already included above
// #include "uarm_interfaces/action/detail/pick_place__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_runtime_c/action_type_support_struct.h"
#include "rosidl_typesupport_cpp/action_type_support.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_cpp/service_type_support.hpp"

namespace uarm_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

static rosidl_action_type_support_t PickPlace_action_type_support_handle = {
  NULL, NULL, NULL, NULL, NULL,
  &uarm_interfaces__action__PickPlace__get_type_hash,
  &uarm_interfaces__action__PickPlace__get_type_description,
  &uarm_interfaces__action__PickPlace__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace uarm_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_action_type_support_t *
get_action_type_support_handle<uarm_interfaces::action::PickPlace>()
{
  using ::uarm_interfaces::action::rosidl_typesupport_cpp::PickPlace_action_type_support_handle;
  // Thread-safe by always writing the same values to the static struct
  PickPlace_action_type_support_handle.goal_service_type_support = get_service_type_support_handle<::uarm_interfaces::action::PickPlace::Impl::SendGoalService>();
  PickPlace_action_type_support_handle.result_service_type_support = get_service_type_support_handle<::uarm_interfaces::action::PickPlace::Impl::GetResultService>();
  PickPlace_action_type_support_handle.cancel_service_type_support = get_service_type_support_handle<::uarm_interfaces::action::PickPlace::Impl::CancelGoalService>();
  PickPlace_action_type_support_handle.feedback_message_type_support = get_message_type_support_handle<::uarm_interfaces::action::PickPlace::Impl::FeedbackMessage>();
  PickPlace_action_type_support_handle.status_message_type_support = get_message_type_support_handle<::uarm_interfaces::action::PickPlace::Impl::GoalStatusMessage>();
  return &PickPlace_action_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_action_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__ACTION_SYMBOL_NAME(rosidl_typesupport_cpp, uarm_interfaces, action, PickPlace)() {
  return ::rosidl_typesupport_cpp::get_action_type_support_handle<uarm_interfaces::action::PickPlace>();
}

#ifdef __cplusplus
}
#endif
