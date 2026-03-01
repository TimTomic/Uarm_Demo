// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from swiftpro:msg/Angle4th.idl
// generated code does not contain a copyright notice
#include "swiftpro/msg/detail/angle4th__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
swiftpro__msg__Angle4th__init(swiftpro__msg__Angle4th * msg)
{
  if (!msg) {
    return false;
  }
  // angle4th
  return true;
}

void
swiftpro__msg__Angle4th__fini(swiftpro__msg__Angle4th * msg)
{
  if (!msg) {
    return;
  }
  // angle4th
}

bool
swiftpro__msg__Angle4th__are_equal(const swiftpro__msg__Angle4th * lhs, const swiftpro__msg__Angle4th * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // angle4th
  if (lhs->angle4th != rhs->angle4th) {
    return false;
  }
  return true;
}

bool
swiftpro__msg__Angle4th__copy(
  const swiftpro__msg__Angle4th * input,
  swiftpro__msg__Angle4th * output)
{
  if (!input || !output) {
    return false;
  }
  // angle4th
  output->angle4th = input->angle4th;
  return true;
}

swiftpro__msg__Angle4th *
swiftpro__msg__Angle4th__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  swiftpro__msg__Angle4th * msg = (swiftpro__msg__Angle4th *)allocator.allocate(sizeof(swiftpro__msg__Angle4th), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(swiftpro__msg__Angle4th));
  bool success = swiftpro__msg__Angle4th__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
swiftpro__msg__Angle4th__destroy(swiftpro__msg__Angle4th * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    swiftpro__msg__Angle4th__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
swiftpro__msg__Angle4th__Sequence__init(swiftpro__msg__Angle4th__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  swiftpro__msg__Angle4th * data = NULL;

  if (size) {
    data = (swiftpro__msg__Angle4th *)allocator.zero_allocate(size, sizeof(swiftpro__msg__Angle4th), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = swiftpro__msg__Angle4th__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        swiftpro__msg__Angle4th__fini(&data[i - 1]);
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
swiftpro__msg__Angle4th__Sequence__fini(swiftpro__msg__Angle4th__Sequence * array)
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
      swiftpro__msg__Angle4th__fini(&array->data[i]);
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

swiftpro__msg__Angle4th__Sequence *
swiftpro__msg__Angle4th__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  swiftpro__msg__Angle4th__Sequence * array = (swiftpro__msg__Angle4th__Sequence *)allocator.allocate(sizeof(swiftpro__msg__Angle4th__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = swiftpro__msg__Angle4th__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
swiftpro__msg__Angle4th__Sequence__destroy(swiftpro__msg__Angle4th__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    swiftpro__msg__Angle4th__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
swiftpro__msg__Angle4th__Sequence__are_equal(const swiftpro__msg__Angle4th__Sequence * lhs, const swiftpro__msg__Angle4th__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!swiftpro__msg__Angle4th__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
swiftpro__msg__Angle4th__Sequence__copy(
  const swiftpro__msg__Angle4th__Sequence * input,
  swiftpro__msg__Angle4th__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(swiftpro__msg__Angle4th);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    swiftpro__msg__Angle4th * data =
      (swiftpro__msg__Angle4th *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!swiftpro__msg__Angle4th__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          swiftpro__msg__Angle4th__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!swiftpro__msg__Angle4th__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
