// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from robo_cleaner_interfaces:srv/QueryInitialRobotState.idl
// generated code does not contain a copyright notice
#include "robo_cleaner_interfaces/srv/detail/query_initial_robot_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
robo_cleaner_interfaces__srv__QueryInitialRobotState_Request__init(robo_cleaner_interfaces__srv__QueryInitialRobotState_Request * msg)
{
  if (!msg) {
    return false;
  }
  // structure_needs_at_least_one_member
  return true;
}

void
robo_cleaner_interfaces__srv__QueryInitialRobotState_Request__fini(robo_cleaner_interfaces__srv__QueryInitialRobotState_Request * msg)
{
  if (!msg) {
    return;
  }
  // structure_needs_at_least_one_member
}

bool
robo_cleaner_interfaces__srv__QueryInitialRobotState_Request__are_equal(const robo_cleaner_interfaces__srv__QueryInitialRobotState_Request * lhs, const robo_cleaner_interfaces__srv__QueryInitialRobotState_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // structure_needs_at_least_one_member
  if (lhs->structure_needs_at_least_one_member != rhs->structure_needs_at_least_one_member) {
    return false;
  }
  return true;
}

bool
robo_cleaner_interfaces__srv__QueryInitialRobotState_Request__copy(
  const robo_cleaner_interfaces__srv__QueryInitialRobotState_Request * input,
  robo_cleaner_interfaces__srv__QueryInitialRobotState_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // structure_needs_at_least_one_member
  output->structure_needs_at_least_one_member = input->structure_needs_at_least_one_member;
  return true;
}

robo_cleaner_interfaces__srv__QueryInitialRobotState_Request *
robo_cleaner_interfaces__srv__QueryInitialRobotState_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robo_cleaner_interfaces__srv__QueryInitialRobotState_Request * msg = (robo_cleaner_interfaces__srv__QueryInitialRobotState_Request *)allocator.allocate(sizeof(robo_cleaner_interfaces__srv__QueryInitialRobotState_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robo_cleaner_interfaces__srv__QueryInitialRobotState_Request));
  bool success = robo_cleaner_interfaces__srv__QueryInitialRobotState_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robo_cleaner_interfaces__srv__QueryInitialRobotState_Request__destroy(robo_cleaner_interfaces__srv__QueryInitialRobotState_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robo_cleaner_interfaces__srv__QueryInitialRobotState_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robo_cleaner_interfaces__srv__QueryInitialRobotState_Request__Sequence__init(robo_cleaner_interfaces__srv__QueryInitialRobotState_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robo_cleaner_interfaces__srv__QueryInitialRobotState_Request * data = NULL;

  if (size) {
    data = (robo_cleaner_interfaces__srv__QueryInitialRobotState_Request *)allocator.zero_allocate(size, sizeof(robo_cleaner_interfaces__srv__QueryInitialRobotState_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robo_cleaner_interfaces__srv__QueryInitialRobotState_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robo_cleaner_interfaces__srv__QueryInitialRobotState_Request__fini(&data[i - 1]);
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
robo_cleaner_interfaces__srv__QueryInitialRobotState_Request__Sequence__fini(robo_cleaner_interfaces__srv__QueryInitialRobotState_Request__Sequence * array)
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
      robo_cleaner_interfaces__srv__QueryInitialRobotState_Request__fini(&array->data[i]);
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

robo_cleaner_interfaces__srv__QueryInitialRobotState_Request__Sequence *
robo_cleaner_interfaces__srv__QueryInitialRobotState_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robo_cleaner_interfaces__srv__QueryInitialRobotState_Request__Sequence * array = (robo_cleaner_interfaces__srv__QueryInitialRobotState_Request__Sequence *)allocator.allocate(sizeof(robo_cleaner_interfaces__srv__QueryInitialRobotState_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robo_cleaner_interfaces__srv__QueryInitialRobotState_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robo_cleaner_interfaces__srv__QueryInitialRobotState_Request__Sequence__destroy(robo_cleaner_interfaces__srv__QueryInitialRobotState_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robo_cleaner_interfaces__srv__QueryInitialRobotState_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robo_cleaner_interfaces__srv__QueryInitialRobotState_Request__Sequence__are_equal(const robo_cleaner_interfaces__srv__QueryInitialRobotState_Request__Sequence * lhs, const robo_cleaner_interfaces__srv__QueryInitialRobotState_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robo_cleaner_interfaces__srv__QueryInitialRobotState_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robo_cleaner_interfaces__srv__QueryInitialRobotState_Request__Sequence__copy(
  const robo_cleaner_interfaces__srv__QueryInitialRobotState_Request__Sequence * input,
  robo_cleaner_interfaces__srv__QueryInitialRobotState_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(robo_cleaner_interfaces__srv__QueryInitialRobotState_Request);
    robo_cleaner_interfaces__srv__QueryInitialRobotState_Request * data =
      (robo_cleaner_interfaces__srv__QueryInitialRobotState_Request *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robo_cleaner_interfaces__srv__QueryInitialRobotState_Request__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          robo_cleaner_interfaces__srv__QueryInitialRobotState_Request__fini(&data[i]);
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
    if (!robo_cleaner_interfaces__srv__QueryInitialRobotState_Request__copy(
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
// Member `initial_robot_state`
#include "robo_cleaner_interfaces/msg/detail/initial_robot_state__functions.h"

bool
robo_cleaner_interfaces__srv__QueryInitialRobotState_Response__init(robo_cleaner_interfaces__srv__QueryInitialRobotState_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // error_reason
  if (!rosidl_runtime_c__String__init(&msg->error_reason)) {
    robo_cleaner_interfaces__srv__QueryInitialRobotState_Response__fini(msg);
    return false;
  }
  // initial_robot_state
  if (!robo_cleaner_interfaces__msg__InitialRobotState__init(&msg->initial_robot_state)) {
    robo_cleaner_interfaces__srv__QueryInitialRobotState_Response__fini(msg);
    return false;
  }
  return true;
}

void
robo_cleaner_interfaces__srv__QueryInitialRobotState_Response__fini(robo_cleaner_interfaces__srv__QueryInitialRobotState_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
  // error_reason
  rosidl_runtime_c__String__fini(&msg->error_reason);
  // initial_robot_state
  robo_cleaner_interfaces__msg__InitialRobotState__fini(&msg->initial_robot_state);
}

bool
robo_cleaner_interfaces__srv__QueryInitialRobotState_Response__are_equal(const robo_cleaner_interfaces__srv__QueryInitialRobotState_Response * lhs, const robo_cleaner_interfaces__srv__QueryInitialRobotState_Response * rhs)
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
  // initial_robot_state
  if (!robo_cleaner_interfaces__msg__InitialRobotState__are_equal(
      &(lhs->initial_robot_state), &(rhs->initial_robot_state)))
  {
    return false;
  }
  return true;
}

bool
robo_cleaner_interfaces__srv__QueryInitialRobotState_Response__copy(
  const robo_cleaner_interfaces__srv__QueryInitialRobotState_Response * input,
  robo_cleaner_interfaces__srv__QueryInitialRobotState_Response * output)
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
  // initial_robot_state
  if (!robo_cleaner_interfaces__msg__InitialRobotState__copy(
      &(input->initial_robot_state), &(output->initial_robot_state)))
  {
    return false;
  }
  return true;
}

robo_cleaner_interfaces__srv__QueryInitialRobotState_Response *
robo_cleaner_interfaces__srv__QueryInitialRobotState_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robo_cleaner_interfaces__srv__QueryInitialRobotState_Response * msg = (robo_cleaner_interfaces__srv__QueryInitialRobotState_Response *)allocator.allocate(sizeof(robo_cleaner_interfaces__srv__QueryInitialRobotState_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robo_cleaner_interfaces__srv__QueryInitialRobotState_Response));
  bool success = robo_cleaner_interfaces__srv__QueryInitialRobotState_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robo_cleaner_interfaces__srv__QueryInitialRobotState_Response__destroy(robo_cleaner_interfaces__srv__QueryInitialRobotState_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robo_cleaner_interfaces__srv__QueryInitialRobotState_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robo_cleaner_interfaces__srv__QueryInitialRobotState_Response__Sequence__init(robo_cleaner_interfaces__srv__QueryInitialRobotState_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robo_cleaner_interfaces__srv__QueryInitialRobotState_Response * data = NULL;

  if (size) {
    data = (robo_cleaner_interfaces__srv__QueryInitialRobotState_Response *)allocator.zero_allocate(size, sizeof(robo_cleaner_interfaces__srv__QueryInitialRobotState_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robo_cleaner_interfaces__srv__QueryInitialRobotState_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robo_cleaner_interfaces__srv__QueryInitialRobotState_Response__fini(&data[i - 1]);
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
robo_cleaner_interfaces__srv__QueryInitialRobotState_Response__Sequence__fini(robo_cleaner_interfaces__srv__QueryInitialRobotState_Response__Sequence * array)
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
      robo_cleaner_interfaces__srv__QueryInitialRobotState_Response__fini(&array->data[i]);
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

robo_cleaner_interfaces__srv__QueryInitialRobotState_Response__Sequence *
robo_cleaner_interfaces__srv__QueryInitialRobotState_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robo_cleaner_interfaces__srv__QueryInitialRobotState_Response__Sequence * array = (robo_cleaner_interfaces__srv__QueryInitialRobotState_Response__Sequence *)allocator.allocate(sizeof(robo_cleaner_interfaces__srv__QueryInitialRobotState_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robo_cleaner_interfaces__srv__QueryInitialRobotState_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robo_cleaner_interfaces__srv__QueryInitialRobotState_Response__Sequence__destroy(robo_cleaner_interfaces__srv__QueryInitialRobotState_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robo_cleaner_interfaces__srv__QueryInitialRobotState_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robo_cleaner_interfaces__srv__QueryInitialRobotState_Response__Sequence__are_equal(const robo_cleaner_interfaces__srv__QueryInitialRobotState_Response__Sequence * lhs, const robo_cleaner_interfaces__srv__QueryInitialRobotState_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robo_cleaner_interfaces__srv__QueryInitialRobotState_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robo_cleaner_interfaces__srv__QueryInitialRobotState_Response__Sequence__copy(
  const robo_cleaner_interfaces__srv__QueryInitialRobotState_Response__Sequence * input,
  robo_cleaner_interfaces__srv__QueryInitialRobotState_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(robo_cleaner_interfaces__srv__QueryInitialRobotState_Response);
    robo_cleaner_interfaces__srv__QueryInitialRobotState_Response * data =
      (robo_cleaner_interfaces__srv__QueryInitialRobotState_Response *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robo_cleaner_interfaces__srv__QueryInitialRobotState_Response__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          robo_cleaner_interfaces__srv__QueryInitialRobotState_Response__fini(&data[i]);
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
    if (!robo_cleaner_interfaces__srv__QueryInitialRobotState_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
