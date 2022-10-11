// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from robo_miner_interfaces:msg/UInt8MultiArray.idl
// generated code does not contain a copyright notice
#include "robo_miner_interfaces/msg/detail/u_int8_multi_array__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `data`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
robo_miner_interfaces__msg__UInt8MultiArray__init(robo_miner_interfaces__msg__UInt8MultiArray * msg)
{
  if (!msg) {
    return false;
  }
  // rows
  // cols
  // data
  if (!rosidl_runtime_c__uint8__Sequence__init(&msg->data, 0)) {
    robo_miner_interfaces__msg__UInt8MultiArray__fini(msg);
    return false;
  }
  return true;
}

void
robo_miner_interfaces__msg__UInt8MultiArray__fini(robo_miner_interfaces__msg__UInt8MultiArray * msg)
{
  if (!msg) {
    return;
  }
  // rows
  // cols
  // data
  rosidl_runtime_c__uint8__Sequence__fini(&msg->data);
}

bool
robo_miner_interfaces__msg__UInt8MultiArray__are_equal(const robo_miner_interfaces__msg__UInt8MultiArray * lhs, const robo_miner_interfaces__msg__UInt8MultiArray * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // rows
  if (lhs->rows != rhs->rows) {
    return false;
  }
  // cols
  if (lhs->cols != rhs->cols) {
    return false;
  }
  // data
  if (!rosidl_runtime_c__uint8__Sequence__are_equal(
      &(lhs->data), &(rhs->data)))
  {
    return false;
  }
  return true;
}

bool
robo_miner_interfaces__msg__UInt8MultiArray__copy(
  const robo_miner_interfaces__msg__UInt8MultiArray * input,
  robo_miner_interfaces__msg__UInt8MultiArray * output)
{
  if (!input || !output) {
    return false;
  }
  // rows
  output->rows = input->rows;
  // cols
  output->cols = input->cols;
  // data
  if (!rosidl_runtime_c__uint8__Sequence__copy(
      &(input->data), &(output->data)))
  {
    return false;
  }
  return true;
}

robo_miner_interfaces__msg__UInt8MultiArray *
robo_miner_interfaces__msg__UInt8MultiArray__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robo_miner_interfaces__msg__UInt8MultiArray * msg = (robo_miner_interfaces__msg__UInt8MultiArray *)allocator.allocate(sizeof(robo_miner_interfaces__msg__UInt8MultiArray), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robo_miner_interfaces__msg__UInt8MultiArray));
  bool success = robo_miner_interfaces__msg__UInt8MultiArray__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robo_miner_interfaces__msg__UInt8MultiArray__destroy(robo_miner_interfaces__msg__UInt8MultiArray * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robo_miner_interfaces__msg__UInt8MultiArray__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robo_miner_interfaces__msg__UInt8MultiArray__Sequence__init(robo_miner_interfaces__msg__UInt8MultiArray__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robo_miner_interfaces__msg__UInt8MultiArray * data = NULL;

  if (size) {
    data = (robo_miner_interfaces__msg__UInt8MultiArray *)allocator.zero_allocate(size, sizeof(robo_miner_interfaces__msg__UInt8MultiArray), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robo_miner_interfaces__msg__UInt8MultiArray__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robo_miner_interfaces__msg__UInt8MultiArray__fini(&data[i - 1]);
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
robo_miner_interfaces__msg__UInt8MultiArray__Sequence__fini(robo_miner_interfaces__msg__UInt8MultiArray__Sequence * array)
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
      robo_miner_interfaces__msg__UInt8MultiArray__fini(&array->data[i]);
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

robo_miner_interfaces__msg__UInt8MultiArray__Sequence *
robo_miner_interfaces__msg__UInt8MultiArray__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robo_miner_interfaces__msg__UInt8MultiArray__Sequence * array = (robo_miner_interfaces__msg__UInt8MultiArray__Sequence *)allocator.allocate(sizeof(robo_miner_interfaces__msg__UInt8MultiArray__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robo_miner_interfaces__msg__UInt8MultiArray__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robo_miner_interfaces__msg__UInt8MultiArray__Sequence__destroy(robo_miner_interfaces__msg__UInt8MultiArray__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robo_miner_interfaces__msg__UInt8MultiArray__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robo_miner_interfaces__msg__UInt8MultiArray__Sequence__are_equal(const robo_miner_interfaces__msg__UInt8MultiArray__Sequence * lhs, const robo_miner_interfaces__msg__UInt8MultiArray__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robo_miner_interfaces__msg__UInt8MultiArray__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robo_miner_interfaces__msg__UInt8MultiArray__Sequence__copy(
  const robo_miner_interfaces__msg__UInt8MultiArray__Sequence * input,
  robo_miner_interfaces__msg__UInt8MultiArray__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(robo_miner_interfaces__msg__UInt8MultiArray);
    robo_miner_interfaces__msg__UInt8MultiArray * data =
      (robo_miner_interfaces__msg__UInt8MultiArray *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robo_miner_interfaces__msg__UInt8MultiArray__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          robo_miner_interfaces__msg__UInt8MultiArray__fini(&data[i]);
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
    if (!robo_miner_interfaces__msg__UInt8MultiArray__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
