// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from robo_miner_interfaces:srv/LongestSequenceValidate.idl
// generated code does not contain a copyright notice
#include "robo_miner_interfaces/srv/detail/longest_sequence_validate__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `sequence_points`
#include "robo_miner_interfaces/msg/detail/field_point__functions.h"

bool
robo_miner_interfaces__srv__LongestSequenceValidate_Request__init(robo_miner_interfaces__srv__LongestSequenceValidate_Request * msg)
{
  if (!msg) {
    return false;
  }
  // sequence_points
  if (!robo_miner_interfaces__msg__FieldPoint__Sequence__init(&msg->sequence_points, 0)) {
    robo_miner_interfaces__srv__LongestSequenceValidate_Request__fini(msg);
    return false;
  }
  return true;
}

void
robo_miner_interfaces__srv__LongestSequenceValidate_Request__fini(robo_miner_interfaces__srv__LongestSequenceValidate_Request * msg)
{
  if (!msg) {
    return;
  }
  // sequence_points
  robo_miner_interfaces__msg__FieldPoint__Sequence__fini(&msg->sequence_points);
}

bool
robo_miner_interfaces__srv__LongestSequenceValidate_Request__are_equal(const robo_miner_interfaces__srv__LongestSequenceValidate_Request * lhs, const robo_miner_interfaces__srv__LongestSequenceValidate_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // sequence_points
  if (!robo_miner_interfaces__msg__FieldPoint__Sequence__are_equal(
      &(lhs->sequence_points), &(rhs->sequence_points)))
  {
    return false;
  }
  return true;
}

bool
robo_miner_interfaces__srv__LongestSequenceValidate_Request__copy(
  const robo_miner_interfaces__srv__LongestSequenceValidate_Request * input,
  robo_miner_interfaces__srv__LongestSequenceValidate_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // sequence_points
  if (!robo_miner_interfaces__msg__FieldPoint__Sequence__copy(
      &(input->sequence_points), &(output->sequence_points)))
  {
    return false;
  }
  return true;
}

robo_miner_interfaces__srv__LongestSequenceValidate_Request *
robo_miner_interfaces__srv__LongestSequenceValidate_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robo_miner_interfaces__srv__LongestSequenceValidate_Request * msg = (robo_miner_interfaces__srv__LongestSequenceValidate_Request *)allocator.allocate(sizeof(robo_miner_interfaces__srv__LongestSequenceValidate_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robo_miner_interfaces__srv__LongestSequenceValidate_Request));
  bool success = robo_miner_interfaces__srv__LongestSequenceValidate_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robo_miner_interfaces__srv__LongestSequenceValidate_Request__destroy(robo_miner_interfaces__srv__LongestSequenceValidate_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robo_miner_interfaces__srv__LongestSequenceValidate_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robo_miner_interfaces__srv__LongestSequenceValidate_Request__Sequence__init(robo_miner_interfaces__srv__LongestSequenceValidate_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robo_miner_interfaces__srv__LongestSequenceValidate_Request * data = NULL;

  if (size) {
    data = (robo_miner_interfaces__srv__LongestSequenceValidate_Request *)allocator.zero_allocate(size, sizeof(robo_miner_interfaces__srv__LongestSequenceValidate_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robo_miner_interfaces__srv__LongestSequenceValidate_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robo_miner_interfaces__srv__LongestSequenceValidate_Request__fini(&data[i - 1]);
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
robo_miner_interfaces__srv__LongestSequenceValidate_Request__Sequence__fini(robo_miner_interfaces__srv__LongestSequenceValidate_Request__Sequence * array)
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
      robo_miner_interfaces__srv__LongestSequenceValidate_Request__fini(&array->data[i]);
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

robo_miner_interfaces__srv__LongestSequenceValidate_Request__Sequence *
robo_miner_interfaces__srv__LongestSequenceValidate_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robo_miner_interfaces__srv__LongestSequenceValidate_Request__Sequence * array = (robo_miner_interfaces__srv__LongestSequenceValidate_Request__Sequence *)allocator.allocate(sizeof(robo_miner_interfaces__srv__LongestSequenceValidate_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robo_miner_interfaces__srv__LongestSequenceValidate_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robo_miner_interfaces__srv__LongestSequenceValidate_Request__Sequence__destroy(robo_miner_interfaces__srv__LongestSequenceValidate_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robo_miner_interfaces__srv__LongestSequenceValidate_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robo_miner_interfaces__srv__LongestSequenceValidate_Request__Sequence__are_equal(const robo_miner_interfaces__srv__LongestSequenceValidate_Request__Sequence * lhs, const robo_miner_interfaces__srv__LongestSequenceValidate_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robo_miner_interfaces__srv__LongestSequenceValidate_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robo_miner_interfaces__srv__LongestSequenceValidate_Request__Sequence__copy(
  const robo_miner_interfaces__srv__LongestSequenceValidate_Request__Sequence * input,
  robo_miner_interfaces__srv__LongestSequenceValidate_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(robo_miner_interfaces__srv__LongestSequenceValidate_Request);
    robo_miner_interfaces__srv__LongestSequenceValidate_Request * data =
      (robo_miner_interfaces__srv__LongestSequenceValidate_Request *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robo_miner_interfaces__srv__LongestSequenceValidate_Request__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          robo_miner_interfaces__srv__LongestSequenceValidate_Request__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!robo_miner_interfaces__srv__LongestSequenceValidate_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `error_reason`
#include "rosidl_runtime_c/string_functions.h"

bool
robo_miner_interfaces__srv__LongestSequenceValidate_Response__init(robo_miner_interfaces__srv__LongestSequenceValidate_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // error_reason
  if (!rosidl_runtime_c__String__init(&msg->error_reason)) {
    robo_miner_interfaces__srv__LongestSequenceValidate_Response__fini(msg);
    return false;
  }
  return true;
}

void
robo_miner_interfaces__srv__LongestSequenceValidate_Response__fini(robo_miner_interfaces__srv__LongestSequenceValidate_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
  // error_reason
  rosidl_runtime_c__String__fini(&msg->error_reason);
}

bool
robo_miner_interfaces__srv__LongestSequenceValidate_Response__are_equal(const robo_miner_interfaces__srv__LongestSequenceValidate_Response * lhs, const robo_miner_interfaces__srv__LongestSequenceValidate_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // error_reason
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->error_reason), &(rhs->error_reason)))
  {
    return false;
  }
  return true;
}

bool
robo_miner_interfaces__srv__LongestSequenceValidate_Response__copy(
  const robo_miner_interfaces__srv__LongestSequenceValidate_Response * input,
  robo_miner_interfaces__srv__LongestSequenceValidate_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // error_reason
  if (!rosidl_runtime_c__String__copy(
      &(input->error_reason), &(output->error_reason)))
  {
    return false;
  }
  return true;
}

robo_miner_interfaces__srv__LongestSequenceValidate_Response *
robo_miner_interfaces__srv__LongestSequenceValidate_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robo_miner_interfaces__srv__LongestSequenceValidate_Response * msg = (robo_miner_interfaces__srv__LongestSequenceValidate_Response *)allocator.allocate(sizeof(robo_miner_interfaces__srv__LongestSequenceValidate_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robo_miner_interfaces__srv__LongestSequenceValidate_Response));
  bool success = robo_miner_interfaces__srv__LongestSequenceValidate_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robo_miner_interfaces__srv__LongestSequenceValidate_Response__destroy(robo_miner_interfaces__srv__LongestSequenceValidate_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robo_miner_interfaces__srv__LongestSequenceValidate_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robo_miner_interfaces__srv__LongestSequenceValidate_Response__Sequence__init(robo_miner_interfaces__srv__LongestSequenceValidate_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robo_miner_interfaces__srv__LongestSequenceValidate_Response * data = NULL;

  if (size) {
    data = (robo_miner_interfaces__srv__LongestSequenceValidate_Response *)allocator.zero_allocate(size, sizeof(robo_miner_interfaces__srv__LongestSequenceValidate_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robo_miner_interfaces__srv__LongestSequenceValidate_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robo_miner_interfaces__srv__LongestSequenceValidate_Response__fini(&data[i - 1]);
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
robo_miner_interfaces__srv__LongestSequenceValidate_Response__Sequence__fini(robo_miner_interfaces__srv__LongestSequenceValidate_Response__Sequence * array)
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
      robo_miner_interfaces__srv__LongestSequenceValidate_Response__fini(&array->data[i]);
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

robo_miner_interfaces__srv__LongestSequenceValidate_Response__Sequence *
robo_miner_interfaces__srv__LongestSequenceValidate_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robo_miner_interfaces__srv__LongestSequenceValidate_Response__Sequence * array = (robo_miner_interfaces__srv__LongestSequenceValidate_Response__Sequence *)allocator.allocate(sizeof(robo_miner_interfaces__srv__LongestSequenceValidate_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robo_miner_interfaces__srv__LongestSequenceValidate_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robo_miner_interfaces__srv__LongestSequenceValidate_Response__Sequence__destroy(robo_miner_interfaces__srv__LongestSequenceValidate_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robo_miner_interfaces__srv__LongestSequenceValidate_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robo_miner_interfaces__srv__LongestSequenceValidate_Response__Sequence__are_equal(const robo_miner_interfaces__srv__LongestSequenceValidate_Response__Sequence * lhs, const robo_miner_interfaces__srv__LongestSequenceValidate_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robo_miner_interfaces__srv__LongestSequenceValidate_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robo_miner_interfaces__srv__LongestSequenceValidate_Response__Sequence__copy(
  const robo_miner_interfaces__srv__LongestSequenceValidate_Response__Sequence * input,
  robo_miner_interfaces__srv__LongestSequenceValidate_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(robo_miner_interfaces__srv__LongestSequenceValidate_Response);
    robo_miner_interfaces__srv__LongestSequenceValidate_Response * data =
      (robo_miner_interfaces__srv__LongestSequenceValidate_Response *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robo_miner_interfaces__srv__LongestSequenceValidate_Response__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          robo_miner_interfaces__srv__LongestSequenceValidate_Response__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!robo_miner_interfaces__srv__LongestSequenceValidate_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
