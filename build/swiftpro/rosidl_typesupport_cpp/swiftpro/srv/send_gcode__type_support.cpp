// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from swiftpro:srv/SendGcode.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "swiftpro/srv/detail/send_gcode__functions.h"
#include "swiftpro/srv/detail/send_gcode__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace swiftpro
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _SendGcode_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SendGcode_Request_type_support_ids_t;

static const _SendGcode_Request_type_support_ids_t _SendGcode_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _SendGcode_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SendGcode_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SendGcode_Request_type_support_symbol_names_t _SendGcode_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, swiftpro, srv, SendGcode_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, swiftpro, srv, SendGcode_Request)),
  }
};

typedef struct _SendGcode_Request_type_support_data_t
{
  void * data[2];
} _SendGcode_Request_type_support_data_t;

static _SendGcode_Request_type_support_data_t _SendGcode_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SendGcode_Request_message_typesupport_map = {
  2,
  "swiftpro",
  &_SendGcode_Request_message_typesupport_ids.typesupport_identifier[0],
  &_SendGcode_Request_message_typesupport_symbol_names.symbol_name[0],
  &_SendGcode_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t SendGcode_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SendGcode_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &swiftpro__srv__SendGcode_Request__get_type_hash,
  &swiftpro__srv__SendGcode_Request__get_type_description,
  &swiftpro__srv__SendGcode_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace swiftpro

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<swiftpro::srv::SendGcode_Request>()
{
  return &::swiftpro::srv::rosidl_typesupport_cpp::SendGcode_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, swiftpro, srv, SendGcode_Request)() {
  return get_message_type_support_handle<swiftpro::srv::SendGcode_Request>();
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
// #include "swiftpro/srv/detail/send_gcode__functions.h"
// already included above
// #include "swiftpro/srv/detail/send_gcode__struct.hpp"
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

namespace swiftpro
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _SendGcode_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SendGcode_Response_type_support_ids_t;

static const _SendGcode_Response_type_support_ids_t _SendGcode_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _SendGcode_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SendGcode_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SendGcode_Response_type_support_symbol_names_t _SendGcode_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, swiftpro, srv, SendGcode_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, swiftpro, srv, SendGcode_Response)),
  }
};

typedef struct _SendGcode_Response_type_support_data_t
{
  void * data[2];
} _SendGcode_Response_type_support_data_t;

static _SendGcode_Response_type_support_data_t _SendGcode_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SendGcode_Response_message_typesupport_map = {
  2,
  "swiftpro",
  &_SendGcode_Response_message_typesupport_ids.typesupport_identifier[0],
  &_SendGcode_Response_message_typesupport_symbol_names.symbol_name[0],
  &_SendGcode_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t SendGcode_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SendGcode_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &swiftpro__srv__SendGcode_Response__get_type_hash,
  &swiftpro__srv__SendGcode_Response__get_type_description,
  &swiftpro__srv__SendGcode_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace swiftpro

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<swiftpro::srv::SendGcode_Response>()
{
  return &::swiftpro::srv::rosidl_typesupport_cpp::SendGcode_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, swiftpro, srv, SendGcode_Response)() {
  return get_message_type_support_handle<swiftpro::srv::SendGcode_Response>();
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
// #include "swiftpro/srv/detail/send_gcode__functions.h"
// already included above
// #include "swiftpro/srv/detail/send_gcode__struct.hpp"
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

namespace swiftpro
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _SendGcode_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SendGcode_Event_type_support_ids_t;

static const _SendGcode_Event_type_support_ids_t _SendGcode_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _SendGcode_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SendGcode_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SendGcode_Event_type_support_symbol_names_t _SendGcode_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, swiftpro, srv, SendGcode_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, swiftpro, srv, SendGcode_Event)),
  }
};

typedef struct _SendGcode_Event_type_support_data_t
{
  void * data[2];
} _SendGcode_Event_type_support_data_t;

static _SendGcode_Event_type_support_data_t _SendGcode_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SendGcode_Event_message_typesupport_map = {
  2,
  "swiftpro",
  &_SendGcode_Event_message_typesupport_ids.typesupport_identifier[0],
  &_SendGcode_Event_message_typesupport_symbol_names.symbol_name[0],
  &_SendGcode_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t SendGcode_Event_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SendGcode_Event_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &swiftpro__srv__SendGcode_Event__get_type_hash,
  &swiftpro__srv__SendGcode_Event__get_type_description,
  &swiftpro__srv__SendGcode_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace swiftpro

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<swiftpro::srv::SendGcode_Event>()
{
  return &::swiftpro::srv::rosidl_typesupport_cpp::SendGcode_Event_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, swiftpro, srv, SendGcode_Event)() {
  return get_message_type_support_handle<swiftpro::srv::SendGcode_Event>();
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
// #include "swiftpro/srv/detail/send_gcode__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace swiftpro
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _SendGcode_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SendGcode_type_support_ids_t;

static const _SendGcode_type_support_ids_t _SendGcode_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _SendGcode_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SendGcode_type_support_symbol_names_t;
#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SendGcode_type_support_symbol_names_t _SendGcode_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, swiftpro, srv, SendGcode)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, swiftpro, srv, SendGcode)),
  }
};

typedef struct _SendGcode_type_support_data_t
{
  void * data[2];
} _SendGcode_type_support_data_t;

static _SendGcode_type_support_data_t _SendGcode_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SendGcode_service_typesupport_map = {
  2,
  "swiftpro",
  &_SendGcode_service_typesupport_ids.typesupport_identifier[0],
  &_SendGcode_service_typesupport_symbol_names.symbol_name[0],
  &_SendGcode_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t SendGcode_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SendGcode_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
  ::rosidl_typesupport_cpp::get_message_type_support_handle<swiftpro::srv::SendGcode_Request>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<swiftpro::srv::SendGcode_Response>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<swiftpro::srv::SendGcode_Event>(),
  &::rosidl_typesupport_cpp::service_create_event_message<swiftpro::srv::SendGcode>,
  &::rosidl_typesupport_cpp::service_destroy_event_message<swiftpro::srv::SendGcode>,
  &swiftpro__srv__SendGcode__get_type_hash,
  &swiftpro__srv__SendGcode__get_type_description,
  &swiftpro__srv__SendGcode__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace swiftpro

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<swiftpro::srv::SendGcode>()
{
  return &::swiftpro::srv::rosidl_typesupport_cpp::SendGcode_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, swiftpro, srv, SendGcode)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<swiftpro::srv::SendGcode>();
}

#ifdef __cplusplus
}
#endif
