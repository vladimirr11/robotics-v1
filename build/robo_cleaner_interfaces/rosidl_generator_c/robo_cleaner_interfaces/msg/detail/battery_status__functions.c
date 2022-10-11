// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from robo_cleaner_interfaces:msg/BatteryStatus.idl
// generated code does not contain a copyright notice
#include "robo_cleaner_interfaces/msg/detail/battery_status__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
robo_cleaner_interfaces__msg__BatteryStatus__init(robo_cleaner_interfaces__msg__BatteryStatus * msg)
{
  if (!msg) {
    return false;
  }
  // max_moves_on_full_energy
  // moves_left
  return true;
}

void
robo_cleaner_interfaces__msg__BatteryStatus__fini(robo_cleaner_interfaces__msg__BatteryStatus * msg)
{
  if (!msg) {
    return;
  }
  // max_moves_on_full_energy
  // moves_left
}

bool
robo_cleaner_interfaces__msg__BatteryStatus__are_equal(const robo_cleaner_interfaces__msg__BatteryStatus * lhs, const robo_cleaner_interfaces__msg__BatteryStatus * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // max_moves_on_full_energy
  if (lhs->max_moves_on_full_energy != rhs->max_moves_on_full_energy) {
    return false;
  }
  // moves_left
  if (lhs->moves_left != rhs->moves_left) {
    return false;
  }
  return true;
}

bool
robo_cleaner_interfaces__msg__BatteryStatus__copy(
  const robo_cleaner_interfaces__msg__BatteryStatus * input,
  robo_cleaner_interfaces__msg__BatteryStatus * output)
{
  if (!input || !output) {
    return false;
  }
  // max_moves_on_full_energy
  output->max_moves_on_full_energy = input->max_moves_on_full_energy;
  // moves_left
  output->moves_left = input->moves_left;
  return true;
}

robo_cleaner_interfaces__msg__BatteryStatus *
robo_cleaner_interfaces__msg__BatteryStatus__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robo_cleaner_interfaces__msg__BatteryStatus * msg = (robo_cleaner_interfaces__msg__BatteryStatus *)allocator.allocate(sizeof(robo_cleaner_interfaces__msg__BatteryStatus), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robo_cleaner_interfaces__msg__BatteryStatus));
  bool success = robo_cleaner_interfaces__msg__BatteryStatus__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robo_cleaner_interfaces__msg__BatteryStatus__destroy(robo_cleaner_interfaces__msg__BatteryStatus * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robo_cleaner_interfaces__msg__BatteryStatus__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robo_cleaner_interfaces__msg__BatteryStatus__Sequence__init(robo_cleaner_interfaces__msg__BatteryStatus__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robo_cleaner_interfaces__msg__BatteryStatus * data = NULL;

  if (size) {
    data = (robo_cleaner_interfaces__msg__BatteryStatus *)allocator.zero_allocate(size, sizeof(robo_cleaner_interfaces__msg__BatteryStatus), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robo_cleaner_interfaces__msg__BatteryStatus__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robo_cleaner_interfaces__msg__BatteryStatus__fini(&data[i - 1]);
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
robo_cleaner_interfaces__msg__BatteryStatus__Sequence__fini(robo_cleaner_interfaces__msg__BatteryStatus__Sequence * array)
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
      robo_cleaner_interfaces__msg__BatteryStatus__fini(&array->data[i]);
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

robo_cleaner_interfaces__msg__BatteryStatus__Sequence *
robo_cleaner_interfaces__msg__BatteryStatus__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robo_cleaner_interfaces__msg__BatteryStatus__Sequence * array = (robo_cleaner_interfaces__msg__BatteryStatus__Sequence *)allocator.allocate(sizeof(robo_cleaner_interfaces__msg__BatteryStatus__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robo_cleaner_interfaces__msg__BatteryStatus__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robo_cleaner_interfaces__msg__BatteryStatus__Sequence__destroy(robo_cleaner_interfaces__msg__BatteryStatus__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robo_cleaner_interfaces__msg__BatteryStatus__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robo_cleaner_interfaces__msg__BatteryStatus__Sequence__are_equal(const robo_cleaner_interfaces__msg__BatteryStatus__Sequence * lhs, const robo_cleaner_interfaces__msg__BatteryStatus__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robo_cleaner_interfaces__msg__BatteryStatus__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robo_cleaner_interfaces__msg__BatteryStatus__Sequence__copy(
  const robo_cleaner_interfaces__msg__BatteryStatus__Sequence * input,
  robo_cleaner_interfaces__msg__BatteryStatus__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(robo_cleaner_interfaces__msg__BatteryStatus);
    robo_cleaner_interfaces__msg__BatteryStatus * data =
      (robo_cleaner_interfaces__msg__BatteryStatus *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robo_cleaner_interfaces__msg__BatteryStatus__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          robo_cleaner_interfaces__msg__BatteryStatus__fini(&data[i]);
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
    if (!robo_cleaner_interfaces__msg__BatteryStatus__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
