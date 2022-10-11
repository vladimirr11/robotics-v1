// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from robo_miner_interfaces:msg/UserAuthenticate.idl
// generated code does not contain a copyright notice
#include "robo_miner_interfaces/msg/detail/user_authenticate__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `user`
// Member `repository`
// Member `commit_sha`
#include "rosidl_runtime_c/string_functions.h"

bool
robo_miner_interfaces__msg__UserAuthenticate__init(robo_miner_interfaces__msg__UserAuthenticate * msg)
{
  if (!msg) {
    return false;
  }
  // user
  if (!rosidl_runtime_c__String__init(&msg->user)) {
    robo_miner_interfaces__msg__UserAuthenticate__fini(msg);
    return false;
  }
  // repository
  if (!rosidl_runtime_c__String__init(&msg->repository)) {
    robo_miner_interfaces__msg__UserAuthenticate__fini(msg);
    return false;
  }
  // commit_sha
  if (!rosidl_runtime_c__String__init(&msg->commit_sha)) {
    robo_miner_interfaces__msg__UserAuthenticate__fini(msg);
    return false;
  }
  return true;
}

void
robo_miner_interfaces__msg__UserAuthenticate__fini(robo_miner_interfaces__msg__UserAuthenticate * msg)
{
  if (!msg) {
    return;
  }
  // user
  rosidl_runtime_c__String__fini(&msg->user);
  // repository
  rosidl_runtime_c__String__fini(&msg->repository);
  // commit_sha
  rosidl_runtime_c__String__fini(&msg->commit_sha);
}

bool
robo_miner_interfaces__msg__UserAuthenticate__are_equal(const robo_miner_interfaces__msg__UserAuthenticate * lhs, const robo_miner_interfaces__msg__UserAuthenticate * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // user
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->user), &(rhs->user)))
  {
    return false;
  }
  // repository
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->repository), &(rhs->repository)))
  {
    return false;
  }
  // commit_sha
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->commit_sha), &(rhs->commit_sha)))
  {
    return false;
  }
  return true;
}

bool
robo_miner_interfaces__msg__UserAuthenticate__copy(
  const robo_miner_interfaces__msg__UserAuthenticate * input,
  robo_miner_interfaces__msg__UserAuthenticate * output)
{
  if (!input || !output) {
    return false;
  }
  // user
  if (!rosidl_runtime_c__String__copy(
      &(input->user), &(output->user)))
  {
    return false;
  }
  // repository
  if (!rosidl_runtime_c__String__copy(
      &(input->repository), &(output->repository)))
  {
    return false;
  }
  // commit_sha
  if (!rosidl_runtime_c__String__copy(
      &(input->commit_sha), &(output->commit_sha)))
  {
    return false;
  }
  return true;
}

robo_miner_interfaces__msg__UserAuthenticate *
robo_miner_interfaces__msg__UserAuthenticate__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robo_miner_interfaces__msg__UserAuthenticate * msg = (robo_miner_interfaces__msg__UserAuthenticate *)allocator.allocate(sizeof(robo_miner_interfaces__msg__UserAuthenticate), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robo_miner_interfaces__msg__UserAuthenticate));
  bool success = robo_miner_interfaces__msg__UserAuthenticate__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robo_miner_interfaces__msg__UserAuthenticate__destroy(robo_miner_interfaces__msg__UserAuthenticate * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robo_miner_interfaces__msg__UserAuthenticate__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robo_miner_interfaces__msg__UserAuthenticate__Sequence__init(robo_miner_interfaces__msg__UserAuthenticate__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robo_miner_interfaces__msg__UserAuthenticate * data = NULL;

  if (size) {
    data = (robo_miner_interfaces__msg__UserAuthenticate *)allocator.zero_allocate(size, sizeof(robo_miner_interfaces__msg__UserAuthenticate), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robo_miner_interfaces__msg__UserAuthenticate__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robo_miner_interfaces__msg__UserAuthenticate__fini(&data[i - 1]);
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
robo_miner_interfaces__msg__UserAuthenticate__Sequence__fini(robo_miner_interfaces__msg__UserAuthenticate__Sequence * array)
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
      robo_miner_interfaces__msg__UserAuthenticate__fini(&array->data[i]);
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

robo_miner_interfaces__msg__UserAuthenticate__Sequence *
robo_miner_interfaces__msg__UserAuthenticate__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robo_miner_interfaces__msg__UserAuthenticate__Sequence * array = (robo_miner_interfaces__msg__UserAuthenticate__Sequence *)allocator.allocate(sizeof(robo_miner_interfaces__msg__UserAuthenticate__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robo_miner_interfaces__msg__UserAuthenticate__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robo_miner_interfaces__msg__UserAuthenticate__Sequence__destroy(robo_miner_interfaces__msg__UserAuthenticate__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robo_miner_interfaces__msg__UserAuthenticate__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robo_miner_interfaces__msg__UserAuthenticate__Sequence__are_equal(const robo_miner_interfaces__msg__UserAuthenticate__Sequence * lhs, const robo_miner_interfaces__msg__UserAuthenticate__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robo_miner_interfaces__msg__UserAuthenticate__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robo_miner_interfaces__msg__UserAuthenticate__Sequence__copy(
  const robo_miner_interfaces__msg__UserAuthenticate__Sequence * input,
  robo_miner_interfaces__msg__UserAuthenticate__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(robo_miner_interfaces__msg__UserAuthenticate);
    robo_miner_interfaces__msg__UserAuthenticate * data =
      (robo_miner_interfaces__msg__UserAuthenticate *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robo_miner_interfaces__msg__UserAuthenticate__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          robo_miner_interfaces__msg__UserAuthenticate__fini(&data[i]);
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
    if (!robo_miner_interfaces__msg__UserAuthenticate__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
