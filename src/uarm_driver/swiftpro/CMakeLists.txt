cmake_minimum_required(VERSION 3.8)
project(swiftpro)

# Default to C++17
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# ── Find dependencies ────────────────────────────────────────────────
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)

# ── Generate messages / services ─────────────────────────────────────
rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/SwiftproState.msg"
  "msg/Position.msg"
  "msg/Angle4th.msg"
  "msg/Status.msg"
  "srv/SendGcode.srv"
  DEPENDENCIES std_msgs sensor_msgs
)

# ── Include directories ──────────────────────────────────────────────
include_directories(include)

# ── Common dependencies list ─────────────────────────────────────────
set(COMMON_DEPS
  rclcpp
  std_msgs
  sensor_msgs
  geometry_msgs
  tf2
  tf2_ros
  tf2_geometry_msgs
)

# ── swiftpro_write_node ──────────────────────────────────────────────
add_executable(swiftpro_write_node src/swiftpro_write_node.cpp)
ament_target_dependencies(swiftpro_write_node ${COMMON_DEPS})
rosidl_get_typesupport_target(write_ts_target ${PROJECT_NAME} rosidl_typesupport_cpp)
target_link_libraries(swiftpro_write_node "${write_ts_target}")

# ── swiftpro_read_node ───────────────────────────────────────────────
add_executable(swiftpro_read_node src/swiftpro_read_node.cpp)
ament_target_dependencies(swiftpro_read_node ${COMMON_DEPS})
rosidl_get_typesupport_target(read_ts_target ${PROJECT_NAME} rosidl_typesupport_cpp)
target_link_libraries(swiftpro_read_node "${read_ts_target}")

# ── swiftpro_rviz_node ───────────────────────────────────────────────
add_executable(swiftpro_rviz_node src/swiftpro_rviz_node.cpp)
ament_target_dependencies(swiftpro_rviz_node ${COMMON_DEPS})
rosidl_get_typesupport_target(rviz_ts_target ${PROJECT_NAME} rosidl_typesupport_cpp)
target_link_libraries(swiftpro_rviz_node "${rviz_ts_target}")

# ── Install ──────────────────────────────────────────────────────────
install(TARGETS
  swiftpro_write_node
  swiftpro_read_node
  swiftpro_rviz_node
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY launch/
  DESTINATION share/${PROJECT_NAME}/launch
  FILES_MATCHING PATTERN "*.py"
)

install(DIRECTORY urdf/
  DESTINATION share/${PROJECT_NAME}/urdf
)

ament_package()
