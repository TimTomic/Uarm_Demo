// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from swiftpro:msg/SwiftproState.idl
// generated code does not contain a copyright notice
#include "swiftpro/msg/detail/swiftpro_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
swiftpro__msg__SwiftproState__init(swiftpro__msg__SwiftproState * msg)
{
  if (!msg) {
    return false;
  }
  // motor_angle1
  // motor_angle2
  // motor_angle3
  // motor_angle4
  // x
  // y
  // z
  // pump
  // swiftpro_status
  // gripper
  // limit_switch
  return true;
}

void
swiftpro__msg__SwiftproState__fini(swiftpro__msg__SwiftproState * msg)
{
  if (!msg) {
    return;
  }
  // motor_angle1
  // motor_angle2
  // motor_angle3
  // motor_angle4
  // x
  // y
  // z
  // pump
  // swiftpro_status
  // gripper
  // limit_switch
}

bool
swiftpro__msg__SwiftproState__are_equal(const swiftpro__msg__SwiftproState * lhs, const swiftpro__msg__SwiftproState * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // motor_angle1
  if (lhs->motor_angle1 != rhs->motor_angle1) {
    return false;
  }
  // motor_angle2
  if (lhs->motor_angle2 != rhs->motor_angle2) {
    return false;
  }
  // motor_angle3
  if (lhs->motor_angle3 != rhs->motor_angle3) {
    return false;
  }
  // motor_angle4
  if (lhs->motor_angle4 != rhs->motor_angle4) {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  // z
  if (lhs->z != rhs->z) {
    return false;
  }
  // pump
  if (lhs->pump != rhs->pump) {
    return false;
  }
  // swiftpro_status
  if (lhs->swiftpro_status != rhs->swiftpro_status) {
    return false;
  }
  // gripper
  if (lhs->gripper != rhs->gripper) {
    return false;
  }
  // limit_switch
  if (lhs->limit_switch != rhs->limit_switch) {
    return false;
  }
  return true;
}

bool
swiftpro__msg__SwiftproState__copy(
  const swiftpro__msg__SwiftproState * input,
  swiftpro__msg__SwiftproState * output)
{
  if (!input || !output) {
    return false;
  }
  // motor_angle1
  output->motor_angle1 = input->motor_angle1;
  // motor_angle2
  output->motor_angle2 = input->motor_angle2;
  // motor_angle3
  output->motor_angle3 = input->motor_angle3;
  // motor_angle4
  output->motor_angle4 = input->motor_angle4;
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // z
  output->z = input->z;
  // pump
  output->pump = input->pump;
  // swiftpro_status
  output->swiftpro_status = input->swiftpro_status;
  // gripper
  output->gripper = input->gripper;
  // limit_switch
  output->limit_switch = input->limit_switch;
  return true;
}

swiftpro__msg__SwiftproState *
swiftpro__msg__SwiftproState__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  swiftpro__msg__SwiftproState * msg = (swiftpro__msg__SwiftproState *)allocator.allocate(sizeof(swiftpro__msg__SwiftproState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(swiftpro__msg__SwiftproState));
  bool success = swiftpro__msg__SwiftproState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
swiftpro__msg__SwiftproState__destroy(swiftpro__msg__SwiftproState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    swiftpro__msg__SwiftproState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
swiftpro__msg__SwiftproState__Sequence__init(swiftpro__msg__SwiftproState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  swiftpro__msg__SwiftproState * data = NULL;

  if (size) {
    data = (swiftpro__msg__SwiftproState *)allocator.zero_allocate(size, sizeof(swiftpro__msg__SwiftproState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = swiftpro__msg__SwiftproState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        swiftpro__msg__SwiftproState__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
swiftpro__msg__SwiftproState__Sequence__fini(swiftpro__msg__SwiftproState__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      swiftpro__msg__SwiftproState__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

swiftpro__msg__SwiftproState__Sequence *
swiftpro__msg__SwiftproState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  swiftpro__msg__SwiftproState__Sequence * array = (swiftpro__msg__SwiftproState__Sequence *)allocator.allocate(sizeof(swiftpro__msg__SwiftproState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = swiftpro__msg__SwiftproState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
swiftpro__msg__SwiftproState__Sequence__destroy(swiftpro__msg__SwiftproState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    swiftpro__msg__SwiftproState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
swiftpro__msg__SwiftproState__Sequence__are_equal(const swiftpro__msg__SwiftproState__Sequence * lhs, const swiftpro__msg__SwiftproState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!swiftpro__msg__SwiftproState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
swiftpro__msg__SwiftproState__Sequence__copy(
  const swiftpro__msg__SwiftproState__Sequence * input,
  swiftpro__msg__SwiftproState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(swiftpro__msg__SwiftproState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    swiftpro__msg__SwiftproState * data =
      (swiftpro__msg__SwiftproState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!swiftpro__msg__SwiftproState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          swiftpro__msg__SwiftproState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!swiftpro__msg__SwiftproState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
