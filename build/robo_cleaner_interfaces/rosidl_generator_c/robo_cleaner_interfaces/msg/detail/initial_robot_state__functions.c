// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from robo_cleaner_interfaces:msg/InitialRobotState.idl
// generated code does not contain a copyright notice
#include "robo_cleaner_interfaces/msg/detail/initial_robot_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `battery_status`
#include "robo_cleaner_interfaces/msg/detail/battery_status__functions.h"

bool
robo_cleaner_interfaces__msg__InitialRobotState__init(robo_cleaner_interfaces__msg__InitialRobotState * msg)
{
  if (!msg) {
    return false;
  }
  // battery_status
  if (!robo_cleaner_interfaces__msg__BatteryStatus__init(&msg->battery_status)) {
    robo_cleaner_interfaces__msg__InitialRobotState__fini(msg);
    return false;
  }
  // robot_tile
  // robot_dir
  return true;
}

void
robo_cleaner_interfaces__msg__InitialRobotState__fini(robo_cleaner_interfaces__msg__InitialRobotState * msg)
{
  if (!msg) {
    return;
  }
  // battery_status
  robo_cleaner_interfaces__msg__BatteryStatus__fini(&msg->battery_status);
  // robot_tile
  // robot_dir
}

bool
robo_cleaner_interfaces__msg__InitialRobotState__are_equal(const robo_cleaner_interfaces__msg__InitialRobotState * lhs, const robo_cleaner_interfaces__msg__InitialRobotState * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // battery_status
  if (!robo_cleaner_interfaces__msg__BatteryStatus__are_equal(
      &(lhs->battery_status), &(rhs->battery_status)))
  {
    return false;
  }
  // robot_tile
  if (lhs->robot_tile != rhs->robot_tile) {
    return false;
  }
  // robot_dir
  if (lhs->robot_dir != rhs->robot_dir) {
    return false;
  }
  return true;
}

bool
robo_cleaner_interfaces__msg__InitialRobotState__copy(
  const robo_cleaner_interfaces__msg__InitialRobotState * input,
  robo_cleaner_interfaces__msg__InitialRobotState * output)
{
  if (!input || !output) {
    return false;
  }
  // battery_status
  if (!robo_cleaner_interfaces__msg__BatteryStatus__copy(
      &(input->battery_status), &(output->battery_status)))
  {
    return false;
  }
  // robot_tile
  output->robot_tile = input->robot_tile;
  // robot_dir
  output->robot_dir = input->robot_dir;
  return true;
}

robo_cleaner_interfaces__msg__InitialRobotState *
robo_cleaner_interfaces__msg__InitialRobotState__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robo_cleaner_interfaces__msg__InitialRobotState * msg = (robo_cleaner_interfaces__msg__InitialRobotState *)allocator.allocate(sizeof(robo_cleaner_interfaces__msg__InitialRobotState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robo_cleaner_interfaces__msg__InitialRobotState));
  bool success = robo_cleaner_interfaces__msg__InitialRobotState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robo_cleaner_interfaces__msg__InitialRobotState__destroy(robo_cleaner_interfaces__msg__InitialRobotState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robo_cleaner_interfaces__msg__InitialRobotState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robo_cleaner_interfaces__msg__InitialRobotState__Sequence__init(robo_cleaner_interfaces__msg__InitialRobotState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robo_cleaner_interfaces__msg__InitialRobotState * data = NULL;

  if (size) {
    data = (robo_cleaner_interfaces__msg__InitialRobotState *)allocator.zero_allocate(size, sizeof(robo_cleaner_interfaces__msg__InitialRobotState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robo_cleaner_interfaces__msg__InitialRobotState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robo_cleaner_interfaces__msg__InitialRobotState__fini(&data[i - 1]);
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
robo_cleaner_interfaces__msg__InitialRobotState__Sequence__fini(robo_cleaner_interfaces__msg__InitialRobotState__Sequence * array)
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
      robo_cleaner_interfaces__msg__InitialRobotState__fini(&array->data[i]);
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

robo_cleaner_interfaces__msg__InitialRobotState__Sequence *
robo_cleaner_interfaces__msg__InitialRobotState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robo_cleaner_interfaces__msg__InitialRobotState__Sequence * array = (robo_cleaner_interfaces__msg__InitialRobotState__Sequence *)allocator.allocate(sizeof(robo_cleaner_interfaces__msg__InitialRobotState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robo_cleaner_interfaces__msg__InitialRobotState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robo_cleaner_interfaces__msg__InitialRobotState__Sequence__destroy(robo_cleaner_interfaces__msg__InitialRobotState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robo_cleaner_interfaces__msg__InitialRobotState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robo_cleaner_interfaces__msg__InitialRobotState__Sequence__are_equal(const robo_cleaner_interfaces__msg__InitialRobotState__Sequence * lhs, const robo_cleaner_interfaces__msg__InitialRobotState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robo_cleaner_interfaces__msg__InitialRobotState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robo_cleaner_interfaces__msg__InitialRobotState__Sequence__copy(
  const robo_cleaner_interfaces__msg__InitialRobotState__Sequence * input,
  robo_cleaner_interfaces__msg__InitialRobotState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(robo_cleaner_interfaces__msg__InitialRobotState);
    robo_cleaner_interfaces__msg__InitialRobotState * data =
      (robo_cleaner_interfaces__msg__InitialRobotState *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robo_cleaner_interfaces__msg__InitialRobotState__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          robo_cleaner_interfaces__msg__InitialRobotState__fini(&data[i]);
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
    if (!robo_cleaner_interfaces__msg__InitialRobotState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
