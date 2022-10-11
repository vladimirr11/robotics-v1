// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from robo_cleaner_interfaces:action/RobotMove.idl
// generated code does not contain a copyright notice
#include "robo_cleaner_interfaces/action/detail/robot_move__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `robot_move_type`
#include "robo_cleaner_interfaces/msg/detail/robot_move_type__functions.h"

bool
robo_cleaner_interfaces__action__RobotMove_Goal__init(robo_cleaner_interfaces__action__RobotMove_Goal * msg)
{
  if (!msg) {
    return false;
  }
  // robot_move_type
  if (!robo_cleaner_interfaces__msg__RobotMoveType__init(&msg->robot_move_type)) {
    robo_cleaner_interfaces__action__RobotMove_Goal__fini(msg);
    return false;
  }
  return true;
}

void
robo_cleaner_interfaces__action__RobotMove_Goal__fini(robo_cleaner_interfaces__action__RobotMove_Goal * msg)
{
  if (!msg) {
    return;
  }
  // robot_move_type
  robo_cleaner_interfaces__msg__RobotMoveType__fini(&msg->robot_move_type);
}

bool
robo_cleaner_interfaces__action__RobotMove_Goal__are_equal(const robo_cleaner_interfaces__action__RobotMove_Goal * lhs, const robo_cleaner_interfaces__action__RobotMove_Goal * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // robot_move_type
  if (!robo_cleaner_interfaces__msg__RobotMoveType__are_equal(
      &(lhs->robot_move_type), &(rhs->robot_move_type)))
  {
    return false;
  }
  return true;
}

bool
robo_cleaner_interfaces__action__RobotMove_Goal__copy(
  const robo_cleaner_interfaces__action__RobotMove_Goal * input,
  robo_cleaner_interfaces__action__RobotMove_Goal * output)
{
  if (!input || !output) {
    return false;
  }
  // robot_move_type
  if (!robo_cleaner_interfaces__msg__RobotMoveType__copy(
      &(input->robot_move_type), &(output->robot_move_type)))
  {
    return false;
  }
  return true;
}

robo_cleaner_interfaces__action__RobotMove_Goal *
robo_cleaner_interfaces__action__RobotMove_Goal__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robo_cleaner_interfaces__action__RobotMove_Goal * msg = (robo_cleaner_interfaces__action__RobotMove_Goal *)allocator.allocate(sizeof(robo_cleaner_interfaces__action__RobotMove_Goal), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robo_cleaner_interfaces__action__RobotMove_Goal));
  bool success = robo_cleaner_interfaces__action__RobotMove_Goal__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robo_cleaner_interfaces__action__RobotMove_Goal__destroy(robo_cleaner_interfaces__action__RobotMove_Goal * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robo_cleaner_interfaces__action__RobotMove_Goal__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robo_cleaner_interfaces__action__RobotMove_Goal__Sequence__init(robo_cleaner_interfaces__action__RobotMove_Goal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robo_cleaner_interfaces__action__RobotMove_Goal * data = NULL;

  if (size) {
    data = (robo_cleaner_interfaces__action__RobotMove_Goal *)allocator.zero_allocate(size, sizeof(robo_cleaner_interfaces__action__RobotMove_Goal), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robo_cleaner_interfaces__action__RobotMove_Goal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robo_cleaner_interfaces__action__RobotMove_Goal__fini(&data[i - 1]);
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
robo_cleaner_interfaces__action__RobotMove_Goal__Sequence__fini(robo_cleaner_interfaces__action__RobotMove_Goal__Sequence * array)
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
      robo_cleaner_interfaces__action__RobotMove_Goal__fini(&array->data[i]);
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

robo_cleaner_interfaces__action__RobotMove_Goal__Sequence *
robo_cleaner_interfaces__action__RobotMove_Goal__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robo_cleaner_interfaces__action__RobotMove_Goal__Sequence * array = (robo_cleaner_interfaces__action__RobotMove_Goal__Sequence *)allocator.allocate(sizeof(robo_cleaner_interfaces__action__RobotMove_Goal__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robo_cleaner_interfaces__action__RobotMove_Goal__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robo_cleaner_interfaces__action__RobotMove_Goal__Sequence__destroy(robo_cleaner_interfaces__action__RobotMove_Goal__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robo_cleaner_interfaces__action__RobotMove_Goal__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robo_cleaner_interfaces__action__RobotMove_Goal__Sequence__are_equal(const robo_cleaner_interfaces__action__RobotMove_Goal__Sequence * lhs, const robo_cleaner_interfaces__action__RobotMove_Goal__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robo_cleaner_interfaces__action__RobotMove_Goal__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robo_cleaner_interfaces__action__RobotMove_Goal__Sequence__copy(
  const robo_cleaner_interfaces__action__RobotMove_Goal__Sequence * input,
  robo_cleaner_interfaces__action__RobotMove_Goal__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(robo_cleaner_interfaces__action__RobotMove_Goal);
    robo_cleaner_interfaces__action__RobotMove_Goal * data =
      (robo_cleaner_interfaces__action__RobotMove_Goal *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robo_cleaner_interfaces__action__RobotMove_Goal__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          robo_cleaner_interfaces__action__RobotMove_Goal__fini(&data[i]);
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
    if (!robo_cleaner_interfaces__action__RobotMove_Goal__copy(
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
robo_cleaner_interfaces__action__RobotMove_Result__init(robo_cleaner_interfaces__action__RobotMove_Result * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // error_reason
  if (!rosidl_runtime_c__String__init(&msg->error_reason)) {
    robo_cleaner_interfaces__action__RobotMove_Result__fini(msg);
    return false;
  }
  // processed_field_marker
  return true;
}

void
robo_cleaner_interfaces__action__RobotMove_Result__fini(robo_cleaner_interfaces__action__RobotMove_Result * msg)
{
  if (!msg) {
    return;
  }
  // success
  // error_reason
  rosidl_runtime_c__String__fini(&msg->error_reason);
  // processed_field_marker
}

bool
robo_cleaner_interfaces__action__RobotMove_Result__are_equal(const robo_cleaner_interfaces__action__RobotMove_Result * lhs, const robo_cleaner_interfaces__action__RobotMove_Result * rhs)
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
  // processed_field_marker
  if (lhs->processed_field_marker != rhs->processed_field_marker) {
    return false;
  }
  return true;
}

bool
robo_cleaner_interfaces__action__RobotMove_Result__copy(
  const robo_cleaner_interfaces__action__RobotMove_Result * input,
  robo_cleaner_interfaces__action__RobotMove_Result * output)
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
  // processed_field_marker
  output->processed_field_marker = input->processed_field_marker;
  return true;
}

robo_cleaner_interfaces__action__RobotMove_Result *
robo_cleaner_interfaces__action__RobotMove_Result__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robo_cleaner_interfaces__action__RobotMove_Result * msg = (robo_cleaner_interfaces__action__RobotMove_Result *)allocator.allocate(sizeof(robo_cleaner_interfaces__action__RobotMove_Result), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robo_cleaner_interfaces__action__RobotMove_Result));
  bool success = robo_cleaner_interfaces__action__RobotMove_Result__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robo_cleaner_interfaces__action__RobotMove_Result__destroy(robo_cleaner_interfaces__action__RobotMove_Result * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robo_cleaner_interfaces__action__RobotMove_Result__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robo_cleaner_interfaces__action__RobotMove_Result__Sequence__init(robo_cleaner_interfaces__action__RobotMove_Result__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robo_cleaner_interfaces__action__RobotMove_Result * data = NULL;

  if (size) {
    data = (robo_cleaner_interfaces__action__RobotMove_Result *)allocator.zero_allocate(size, sizeof(robo_cleaner_interfaces__action__RobotMove_Result), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robo_cleaner_interfaces__action__RobotMove_Result__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robo_cleaner_interfaces__action__RobotMove_Result__fini(&data[i - 1]);
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
robo_cleaner_interfaces__action__RobotMove_Result__Sequence__fini(robo_cleaner_interfaces__action__RobotMove_Result__Sequence * array)
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
      robo_cleaner_interfaces__action__RobotMove_Result__fini(&array->data[i]);
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

robo_cleaner_interfaces__action__RobotMove_Result__Sequence *
robo_cleaner_interfaces__action__RobotMove_Result__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robo_cleaner_interfaces__action__RobotMove_Result__Sequence * array = (robo_cleaner_interfaces__action__RobotMove_Result__Sequence *)allocator.allocate(sizeof(robo_cleaner_interfaces__action__RobotMove_Result__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robo_cleaner_interfaces__action__RobotMove_Result__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robo_cleaner_interfaces__action__RobotMove_Result__Sequence__destroy(robo_cleaner_interfaces__action__RobotMove_Result__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robo_cleaner_interfaces__action__RobotMove_Result__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robo_cleaner_interfaces__action__RobotMove_Result__Sequence__are_equal(const robo_cleaner_interfaces__action__RobotMove_Result__Sequence * lhs, const robo_cleaner_interfaces__action__RobotMove_Result__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robo_cleaner_interfaces__action__RobotMove_Result__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robo_cleaner_interfaces__action__RobotMove_Result__Sequence__copy(
  const robo_cleaner_interfaces__action__RobotMove_Result__Sequence * input,
  robo_cleaner_interfaces__action__RobotMove_Result__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(robo_cleaner_interfaces__action__RobotMove_Result);
    robo_cleaner_interfaces__action__RobotMove_Result * data =
      (robo_cleaner_interfaces__action__RobotMove_Result *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robo_cleaner_interfaces__action__RobotMove_Result__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          robo_cleaner_interfaces__action__RobotMove_Result__fini(&data[i]);
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
    if (!robo_cleaner_interfaces__action__RobotMove_Result__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
robo_cleaner_interfaces__action__RobotMove_Feedback__init(robo_cleaner_interfaces__action__RobotMove_Feedback * msg)
{
  if (!msg) {
    return false;
  }
  // approaching_field_marker
  // progress_percent
  return true;
}

void
robo_cleaner_interfaces__action__RobotMove_Feedback__fini(robo_cleaner_interfaces__action__RobotMove_Feedback * msg)
{
  if (!msg) {
    return;
  }
  // approaching_field_marker
  // progress_percent
}

bool
robo_cleaner_interfaces__action__RobotMove_Feedback__are_equal(const robo_cleaner_interfaces__action__RobotMove_Feedback * lhs, const robo_cleaner_interfaces__action__RobotMove_Feedback * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // approaching_field_marker
  if (lhs->approaching_field_marker != rhs->approaching_field_marker) {
    return false;
  }
  // progress_percent
  if (lhs->progress_percent != rhs->progress_percent) {
    return false;
  }
  return true;
}

bool
robo_cleaner_interfaces__action__RobotMove_Feedback__copy(
  const robo_cleaner_interfaces__action__RobotMove_Feedback * input,
  robo_cleaner_interfaces__action__RobotMove_Feedback * output)
{
  if (!input || !output) {
    return false;
  }
  // approaching_field_marker
  output->approaching_field_marker = input->approaching_field_marker;
  // progress_percent
  output->progress_percent = input->progress_percent;
  return true;
}

robo_cleaner_interfaces__action__RobotMove_Feedback *
robo_cleaner_interfaces__action__RobotMove_Feedback__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robo_cleaner_interfaces__action__RobotMove_Feedback * msg = (robo_cleaner_interfaces__action__RobotMove_Feedback *)allocator.allocate(sizeof(robo_cleaner_interfaces__action__RobotMove_Feedback), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robo_cleaner_interfaces__action__RobotMove_Feedback));
  bool success = robo_cleaner_interfaces__action__RobotMove_Feedback__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robo_cleaner_interfaces__action__RobotMove_Feedback__destroy(robo_cleaner_interfaces__action__RobotMove_Feedback * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robo_cleaner_interfaces__action__RobotMove_Feedback__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robo_cleaner_interfaces__action__RobotMove_Feedback__Sequence__init(robo_cleaner_interfaces__action__RobotMove_Feedback__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robo_cleaner_interfaces__action__RobotMove_Feedback * data = NULL;

  if (size) {
    data = (robo_cleaner_interfaces__action__RobotMove_Feedback *)allocator.zero_allocate(size, sizeof(robo_cleaner_interfaces__action__RobotMove_Feedback), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robo_cleaner_interfaces__action__RobotMove_Feedback__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robo_cleaner_interfaces__action__RobotMove_Feedback__fini(&data[i - 1]);
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
robo_cleaner_interfaces__action__RobotMove_Feedback__Sequence__fini(robo_cleaner_interfaces__action__RobotMove_Feedback__Sequence * array)
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
      robo_cleaner_interfaces__action__RobotMove_Feedback__fini(&array->data[i]);
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

robo_cleaner_interfaces__action__RobotMove_Feedback__Sequence *
robo_cleaner_interfaces__action__RobotMove_Feedback__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robo_cleaner_interfaces__action__RobotMove_Feedback__Sequence * array = (robo_cleaner_interfaces__action__RobotMove_Feedback__Sequence *)allocator.allocate(sizeof(robo_cleaner_interfaces__action__RobotMove_Feedback__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robo_cleaner_interfaces__action__RobotMove_Feedback__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robo_cleaner_interfaces__action__RobotMove_Feedback__Sequence__destroy(robo_cleaner_interfaces__action__RobotMove_Feedback__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robo_cleaner_interfaces__action__RobotMove_Feedback__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robo_cleaner_interfaces__action__RobotMove_Feedback__Sequence__are_equal(const robo_cleaner_interfaces__action__RobotMove_Feedback__Sequence * lhs, const robo_cleaner_interfaces__action__RobotMove_Feedback__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robo_cleaner_interfaces__action__RobotMove_Feedback__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robo_cleaner_interfaces__action__RobotMove_Feedback__Sequence__copy(
  const robo_cleaner_interfaces__action__RobotMove_Feedback__Sequence * input,
  robo_cleaner_interfaces__action__RobotMove_Feedback__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(robo_cleaner_interfaces__action__RobotMove_Feedback);
    robo_cleaner_interfaces__action__RobotMove_Feedback * data =
      (robo_cleaner_interfaces__action__RobotMove_Feedback *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robo_cleaner_interfaces__action__RobotMove_Feedback__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          robo_cleaner_interfaces__action__RobotMove_Feedback__fini(&data[i]);
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
    if (!robo_cleaner_interfaces__action__RobotMove_Feedback__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `goal`
// already included above
// #include "robo_cleaner_interfaces/action/detail/robot_move__functions.h"

bool
robo_cleaner_interfaces__action__RobotMove_SendGoal_Request__init(robo_cleaner_interfaces__action__RobotMove_SendGoal_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    robo_cleaner_interfaces__action__RobotMove_SendGoal_Request__fini(msg);
    return false;
  }
  // goal
  if (!robo_cleaner_interfaces__action__RobotMove_Goal__init(&msg->goal)) {
    robo_cleaner_interfaces__action__RobotMove_SendGoal_Request__fini(msg);
    return false;
  }
  return true;
}

void
robo_cleaner_interfaces__action__RobotMove_SendGoal_Request__fini(robo_cleaner_interfaces__action__RobotMove_SendGoal_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // goal
  robo_cleaner_interfaces__action__RobotMove_Goal__fini(&msg->goal);
}

bool
robo_cleaner_interfaces__action__RobotMove_SendGoal_Request__are_equal(const robo_cleaner_interfaces__action__RobotMove_SendGoal_Request * lhs, const robo_cleaner_interfaces__action__RobotMove_SendGoal_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // goal
  if (!robo_cleaner_interfaces__action__RobotMove_Goal__are_equal(
      &(lhs->goal), &(rhs->goal)))
  {
    return false;
  }
  return true;
}

bool
robo_cleaner_interfaces__action__RobotMove_SendGoal_Request__copy(
  const robo_cleaner_interfaces__action__RobotMove_SendGoal_Request * input,
  robo_cleaner_interfaces__action__RobotMove_SendGoal_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // goal
  if (!robo_cleaner_interfaces__action__RobotMove_Goal__copy(
      &(input->goal), &(output->goal)))
  {
    return false;
  }
  return true;
}

robo_cleaner_interfaces__action__RobotMove_SendGoal_Request *
robo_cleaner_interfaces__action__RobotMove_SendGoal_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robo_cleaner_interfaces__action__RobotMove_SendGoal_Request * msg = (robo_cleaner_interfaces__action__RobotMove_SendGoal_Request *)allocator.allocate(sizeof(robo_cleaner_interfaces__action__RobotMove_SendGoal_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robo_cleaner_interfaces__action__RobotMove_SendGoal_Request));
  bool success = robo_cleaner_interfaces__action__RobotMove_SendGoal_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robo_cleaner_interfaces__action__RobotMove_SendGoal_Request__destroy(robo_cleaner_interfaces__action__RobotMove_SendGoal_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robo_cleaner_interfaces__action__RobotMove_SendGoal_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robo_cleaner_interfaces__action__RobotMove_SendGoal_Request__Sequence__init(robo_cleaner_interfaces__action__RobotMove_SendGoal_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robo_cleaner_interfaces__action__RobotMove_SendGoal_Request * data = NULL;

  if (size) {
    data = (robo_cleaner_interfaces__action__RobotMove_SendGoal_Request *)allocator.zero_allocate(size, sizeof(robo_cleaner_interfaces__action__RobotMove_SendGoal_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robo_cleaner_interfaces__action__RobotMove_SendGoal_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robo_cleaner_interfaces__action__RobotMove_SendGoal_Request__fini(&data[i - 1]);
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
robo_cleaner_interfaces__action__RobotMove_SendGoal_Request__Sequence__fini(robo_cleaner_interfaces__action__RobotMove_SendGoal_Request__Sequence * array)
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
      robo_cleaner_interfaces__action__RobotMove_SendGoal_Request__fini(&array->data[i]);
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

robo_cleaner_interfaces__action__RobotMove_SendGoal_Request__Sequence *
robo_cleaner_interfaces__action__RobotMove_SendGoal_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robo_cleaner_interfaces__action__RobotMove_SendGoal_Request__Sequence * array = (robo_cleaner_interfaces__action__RobotMove_SendGoal_Request__Sequence *)allocator.allocate(sizeof(robo_cleaner_interfaces__action__RobotMove_SendGoal_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robo_cleaner_interfaces__action__RobotMove_SendGoal_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robo_cleaner_interfaces__action__RobotMove_SendGoal_Request__Sequence__destroy(robo_cleaner_interfaces__action__RobotMove_SendGoal_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robo_cleaner_interfaces__action__RobotMove_SendGoal_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robo_cleaner_interfaces__action__RobotMove_SendGoal_Request__Sequence__are_equal(const robo_cleaner_interfaces__action__RobotMove_SendGoal_Request__Sequence * lhs, const robo_cleaner_interfaces__action__RobotMove_SendGoal_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robo_cleaner_interfaces__action__RobotMove_SendGoal_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robo_cleaner_interfaces__action__RobotMove_SendGoal_Request__Sequence__copy(
  const robo_cleaner_interfaces__action__RobotMove_SendGoal_Request__Sequence * input,
  robo_cleaner_interfaces__action__RobotMove_SendGoal_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(robo_cleaner_interfaces__action__RobotMove_SendGoal_Request);
    robo_cleaner_interfaces__action__RobotMove_SendGoal_Request * data =
      (robo_cleaner_interfaces__action__RobotMove_SendGoal_Request *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robo_cleaner_interfaces__action__RobotMove_SendGoal_Request__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          robo_cleaner_interfaces__action__RobotMove_SendGoal_Request__fini(&data[i]);
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
    if (!robo_cleaner_interfaces__action__RobotMove_SendGoal_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
robo_cleaner_interfaces__action__RobotMove_SendGoal_Response__init(robo_cleaner_interfaces__action__RobotMove_SendGoal_Response * msg)
{
  if (!msg) {
    return false;
  }
  // accepted
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    robo_cleaner_interfaces__action__RobotMove_SendGoal_Response__fini(msg);
    return false;
  }
  return true;
}

void
robo_cleaner_interfaces__action__RobotMove_SendGoal_Response__fini(robo_cleaner_interfaces__action__RobotMove_SendGoal_Response * msg)
{
  if (!msg) {
    return;
  }
  // accepted
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
}

bool
robo_cleaner_interfaces__action__RobotMove_SendGoal_Response__are_equal(const robo_cleaner_interfaces__action__RobotMove_SendGoal_Response * lhs, const robo_cleaner_interfaces__action__RobotMove_SendGoal_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // accepted
  if (lhs->accepted != rhs->accepted) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->stamp), &(rhs->stamp)))
  {
    return false;
  }
  return true;
}

bool
robo_cleaner_interfaces__action__RobotMove_SendGoal_Response__copy(
  const robo_cleaner_interfaces__action__RobotMove_SendGoal_Response * input,
  robo_cleaner_interfaces__action__RobotMove_SendGoal_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // accepted
  output->accepted = input->accepted;
  // stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  return true;
}

robo_cleaner_interfaces__action__RobotMove_SendGoal_Response *
robo_cleaner_interfaces__action__RobotMove_SendGoal_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robo_cleaner_interfaces__action__RobotMove_SendGoal_Response * msg = (robo_cleaner_interfaces__action__RobotMove_SendGoal_Response *)allocator.allocate(sizeof(robo_cleaner_interfaces__action__RobotMove_SendGoal_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robo_cleaner_interfaces__action__RobotMove_SendGoal_Response));
  bool success = robo_cleaner_interfaces__action__RobotMove_SendGoal_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robo_cleaner_interfaces__action__RobotMove_SendGoal_Response__destroy(robo_cleaner_interfaces__action__RobotMove_SendGoal_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robo_cleaner_interfaces__action__RobotMove_SendGoal_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robo_cleaner_interfaces__action__RobotMove_SendGoal_Response__Sequence__init(robo_cleaner_interfaces__action__RobotMove_SendGoal_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robo_cleaner_interfaces__action__RobotMove_SendGoal_Response * data = NULL;

  if (size) {
    data = (robo_cleaner_interfaces__action__RobotMove_SendGoal_Response *)allocator.zero_allocate(size, sizeof(robo_cleaner_interfaces__action__RobotMove_SendGoal_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robo_cleaner_interfaces__action__RobotMove_SendGoal_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robo_cleaner_interfaces__action__RobotMove_SendGoal_Response__fini(&data[i - 1]);
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
robo_cleaner_interfaces__action__RobotMove_SendGoal_Response__Sequence__fini(robo_cleaner_interfaces__action__RobotMove_SendGoal_Response__Sequence * array)
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
      robo_cleaner_interfaces__action__RobotMove_SendGoal_Response__fini(&array->data[i]);
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

robo_cleaner_interfaces__action__RobotMove_SendGoal_Response__Sequence *
robo_cleaner_interfaces__action__RobotMove_SendGoal_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robo_cleaner_interfaces__action__RobotMove_SendGoal_Response__Sequence * array = (robo_cleaner_interfaces__action__RobotMove_SendGoal_Response__Sequence *)allocator.allocate(sizeof(robo_cleaner_interfaces__action__RobotMove_SendGoal_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robo_cleaner_interfaces__action__RobotMove_SendGoal_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robo_cleaner_interfaces__action__RobotMove_SendGoal_Response__Sequence__destroy(robo_cleaner_interfaces__action__RobotMove_SendGoal_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robo_cleaner_interfaces__action__RobotMove_SendGoal_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robo_cleaner_interfaces__action__RobotMove_SendGoal_Response__Sequence__are_equal(const robo_cleaner_interfaces__action__RobotMove_SendGoal_Response__Sequence * lhs, const robo_cleaner_interfaces__action__RobotMove_SendGoal_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robo_cleaner_interfaces__action__RobotMove_SendGoal_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robo_cleaner_interfaces__action__RobotMove_SendGoal_Response__Sequence__copy(
  const robo_cleaner_interfaces__action__RobotMove_SendGoal_Response__Sequence * input,
  robo_cleaner_interfaces__action__RobotMove_SendGoal_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(robo_cleaner_interfaces__action__RobotMove_SendGoal_Response);
    robo_cleaner_interfaces__action__RobotMove_SendGoal_Response * data =
      (robo_cleaner_interfaces__action__RobotMove_SendGoal_Response *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robo_cleaner_interfaces__action__RobotMove_SendGoal_Response__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          robo_cleaner_interfaces__action__RobotMove_SendGoal_Response__fini(&data[i]);
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
    if (!robo_cleaner_interfaces__action__RobotMove_SendGoal_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"

bool
robo_cleaner_interfaces__action__RobotMove_GetResult_Request__init(robo_cleaner_interfaces__action__RobotMove_GetResult_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    robo_cleaner_interfaces__action__RobotMove_GetResult_Request__fini(msg);
    return false;
  }
  return true;
}

void
robo_cleaner_interfaces__action__RobotMove_GetResult_Request__fini(robo_cleaner_interfaces__action__RobotMove_GetResult_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
}

bool
robo_cleaner_interfaces__action__RobotMove_GetResult_Request__are_equal(const robo_cleaner_interfaces__action__RobotMove_GetResult_Request * lhs, const robo_cleaner_interfaces__action__RobotMove_GetResult_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  return true;
}

bool
robo_cleaner_interfaces__action__RobotMove_GetResult_Request__copy(
  const robo_cleaner_interfaces__action__RobotMove_GetResult_Request * input,
  robo_cleaner_interfaces__action__RobotMove_GetResult_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  return true;
}

robo_cleaner_interfaces__action__RobotMove_GetResult_Request *
robo_cleaner_interfaces__action__RobotMove_GetResult_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robo_cleaner_interfaces__action__RobotMove_GetResult_Request * msg = (robo_cleaner_interfaces__action__RobotMove_GetResult_Request *)allocator.allocate(sizeof(robo_cleaner_interfaces__action__RobotMove_GetResult_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robo_cleaner_interfaces__action__RobotMove_GetResult_Request));
  bool success = robo_cleaner_interfaces__action__RobotMove_GetResult_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robo_cleaner_interfaces__action__RobotMove_GetResult_Request__destroy(robo_cleaner_interfaces__action__RobotMove_GetResult_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robo_cleaner_interfaces__action__RobotMove_GetResult_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robo_cleaner_interfaces__action__RobotMove_GetResult_Request__Sequence__init(robo_cleaner_interfaces__action__RobotMove_GetResult_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robo_cleaner_interfaces__action__RobotMove_GetResult_Request * data = NULL;

  if (size) {
    data = (robo_cleaner_interfaces__action__RobotMove_GetResult_Request *)allocator.zero_allocate(size, sizeof(robo_cleaner_interfaces__action__RobotMove_GetResult_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robo_cleaner_interfaces__action__RobotMove_GetResult_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robo_cleaner_interfaces__action__RobotMove_GetResult_Request__fini(&data[i - 1]);
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
robo_cleaner_interfaces__action__RobotMove_GetResult_Request__Sequence__fini(robo_cleaner_interfaces__action__RobotMove_GetResult_Request__Sequence * array)
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
      robo_cleaner_interfaces__action__RobotMove_GetResult_Request__fini(&array->data[i]);
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

robo_cleaner_interfaces__action__RobotMove_GetResult_Request__Sequence *
robo_cleaner_interfaces__action__RobotMove_GetResult_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robo_cleaner_interfaces__action__RobotMove_GetResult_Request__Sequence * array = (robo_cleaner_interfaces__action__RobotMove_GetResult_Request__Sequence *)allocator.allocate(sizeof(robo_cleaner_interfaces__action__RobotMove_GetResult_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robo_cleaner_interfaces__action__RobotMove_GetResult_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robo_cleaner_interfaces__action__RobotMove_GetResult_Request__Sequence__destroy(robo_cleaner_interfaces__action__RobotMove_GetResult_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robo_cleaner_interfaces__action__RobotMove_GetResult_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robo_cleaner_interfaces__action__RobotMove_GetResult_Request__Sequence__are_equal(const robo_cleaner_interfaces__action__RobotMove_GetResult_Request__Sequence * lhs, const robo_cleaner_interfaces__action__RobotMove_GetResult_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robo_cleaner_interfaces__action__RobotMove_GetResult_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robo_cleaner_interfaces__action__RobotMove_GetResult_Request__Sequence__copy(
  const robo_cleaner_interfaces__action__RobotMove_GetResult_Request__Sequence * input,
  robo_cleaner_interfaces__action__RobotMove_GetResult_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(robo_cleaner_interfaces__action__RobotMove_GetResult_Request);
    robo_cleaner_interfaces__action__RobotMove_GetResult_Request * data =
      (robo_cleaner_interfaces__action__RobotMove_GetResult_Request *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robo_cleaner_interfaces__action__RobotMove_GetResult_Request__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          robo_cleaner_interfaces__action__RobotMove_GetResult_Request__fini(&data[i]);
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
    if (!robo_cleaner_interfaces__action__RobotMove_GetResult_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `result`
// already included above
// #include "robo_cleaner_interfaces/action/detail/robot_move__functions.h"

bool
robo_cleaner_interfaces__action__RobotMove_GetResult_Response__init(robo_cleaner_interfaces__action__RobotMove_GetResult_Response * msg)
{
  if (!msg) {
    return false;
  }
  // status
  // result
  if (!robo_cleaner_interfaces__action__RobotMove_Result__init(&msg->result)) {
    robo_cleaner_interfaces__action__RobotMove_GetResult_Response__fini(msg);
    return false;
  }
  return true;
}

void
robo_cleaner_interfaces__action__RobotMove_GetResult_Response__fini(robo_cleaner_interfaces__action__RobotMove_GetResult_Response * msg)
{
  if (!msg) {
    return;
  }
  // status
  // result
  robo_cleaner_interfaces__action__RobotMove_Result__fini(&msg->result);
}

bool
robo_cleaner_interfaces__action__RobotMove_GetResult_Response__are_equal(const robo_cleaner_interfaces__action__RobotMove_GetResult_Response * lhs, const robo_cleaner_interfaces__action__RobotMove_GetResult_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  // result
  if (!robo_cleaner_interfaces__action__RobotMove_Result__are_equal(
      &(lhs->result), &(rhs->result)))
  {
    return false;
  }
  return true;
}

bool
robo_cleaner_interfaces__action__RobotMove_GetResult_Response__copy(
  const robo_cleaner_interfaces__action__RobotMove_GetResult_Response * input,
  robo_cleaner_interfaces__action__RobotMove_GetResult_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  output->status = input->status;
  // result
  if (!robo_cleaner_interfaces__action__RobotMove_Result__copy(
      &(input->result), &(output->result)))
  {
    return false;
  }
  return true;
}

robo_cleaner_interfaces__action__RobotMove_GetResult_Response *
robo_cleaner_interfaces__action__RobotMove_GetResult_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robo_cleaner_interfaces__action__RobotMove_GetResult_Response * msg = (robo_cleaner_interfaces__action__RobotMove_GetResult_Response *)allocator.allocate(sizeof(robo_cleaner_interfaces__action__RobotMove_GetResult_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robo_cleaner_interfaces__action__RobotMove_GetResult_Response));
  bool success = robo_cleaner_interfaces__action__RobotMove_GetResult_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robo_cleaner_interfaces__action__RobotMove_GetResult_Response__destroy(robo_cleaner_interfaces__action__RobotMove_GetResult_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robo_cleaner_interfaces__action__RobotMove_GetResult_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robo_cleaner_interfaces__action__RobotMove_GetResult_Response__Sequence__init(robo_cleaner_interfaces__action__RobotMove_GetResult_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robo_cleaner_interfaces__action__RobotMove_GetResult_Response * data = NULL;

  if (size) {
    data = (robo_cleaner_interfaces__action__RobotMove_GetResult_Response *)allocator.zero_allocate(size, sizeof(robo_cleaner_interfaces__action__RobotMove_GetResult_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robo_cleaner_interfaces__action__RobotMove_GetResult_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robo_cleaner_interfaces__action__RobotMove_GetResult_Response__fini(&data[i - 1]);
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
robo_cleaner_interfaces__action__RobotMove_GetResult_Response__Sequence__fini(robo_cleaner_interfaces__action__RobotMove_GetResult_Response__Sequence * array)
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
      robo_cleaner_interfaces__action__RobotMove_GetResult_Response__fini(&array->data[i]);
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

robo_cleaner_interfaces__action__RobotMove_GetResult_Response__Sequence *
robo_cleaner_interfaces__action__RobotMove_GetResult_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robo_cleaner_interfaces__action__RobotMove_GetResult_Response__Sequence * array = (robo_cleaner_interfaces__action__RobotMove_GetResult_Response__Sequence *)allocator.allocate(sizeof(robo_cleaner_interfaces__action__RobotMove_GetResult_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robo_cleaner_interfaces__action__RobotMove_GetResult_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robo_cleaner_interfaces__action__RobotMove_GetResult_Response__Sequence__destroy(robo_cleaner_interfaces__action__RobotMove_GetResult_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robo_cleaner_interfaces__action__RobotMove_GetResult_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robo_cleaner_interfaces__action__RobotMove_GetResult_Response__Sequence__are_equal(const robo_cleaner_interfaces__action__RobotMove_GetResult_Response__Sequence * lhs, const robo_cleaner_interfaces__action__RobotMove_GetResult_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robo_cleaner_interfaces__action__RobotMove_GetResult_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robo_cleaner_interfaces__action__RobotMove_GetResult_Response__Sequence__copy(
  const robo_cleaner_interfaces__action__RobotMove_GetResult_Response__Sequence * input,
  robo_cleaner_interfaces__action__RobotMove_GetResult_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(robo_cleaner_interfaces__action__RobotMove_GetResult_Response);
    robo_cleaner_interfaces__action__RobotMove_GetResult_Response * data =
      (robo_cleaner_interfaces__action__RobotMove_GetResult_Response *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robo_cleaner_interfaces__action__RobotMove_GetResult_Response__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          robo_cleaner_interfaces__action__RobotMove_GetResult_Response__fini(&data[i]);
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
    if (!robo_cleaner_interfaces__action__RobotMove_GetResult_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `feedback`
// already included above
// #include "robo_cleaner_interfaces/action/detail/robot_move__functions.h"

bool
robo_cleaner_interfaces__action__RobotMove_FeedbackMessage__init(robo_cleaner_interfaces__action__RobotMove_FeedbackMessage * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    robo_cleaner_interfaces__action__RobotMove_FeedbackMessage__fini(msg);
    return false;
  }
  // feedback
  if (!robo_cleaner_interfaces__action__RobotMove_Feedback__init(&msg->feedback)) {
    robo_cleaner_interfaces__action__RobotMove_FeedbackMessage__fini(msg);
    return false;
  }
  return true;
}

void
robo_cleaner_interfaces__action__RobotMove_FeedbackMessage__fini(robo_cleaner_interfaces__action__RobotMove_FeedbackMessage * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // feedback
  robo_cleaner_interfaces__action__RobotMove_Feedback__fini(&msg->feedback);
}

bool
robo_cleaner_interfaces__action__RobotMove_FeedbackMessage__are_equal(const robo_cleaner_interfaces__action__RobotMove_FeedbackMessage * lhs, const robo_cleaner_interfaces__action__RobotMove_FeedbackMessage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // feedback
  if (!robo_cleaner_interfaces__action__RobotMove_Feedback__are_equal(
      &(lhs->feedback), &(rhs->feedback)))
  {
    return false;
  }
  return true;
}

bool
robo_cleaner_interfaces__action__RobotMove_FeedbackMessage__copy(
  const robo_cleaner_interfaces__action__RobotMove_FeedbackMessage * input,
  robo_cleaner_interfaces__action__RobotMove_FeedbackMessage * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // feedback
  if (!robo_cleaner_interfaces__action__RobotMove_Feedback__copy(
      &(input->feedback), &(output->feedback)))
  {
    return false;
  }
  return true;
}

robo_cleaner_interfaces__action__RobotMove_FeedbackMessage *
robo_cleaner_interfaces__action__RobotMove_FeedbackMessage__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robo_cleaner_interfaces__action__RobotMove_FeedbackMessage * msg = (robo_cleaner_interfaces__action__RobotMove_FeedbackMessage *)allocator.allocate(sizeof(robo_cleaner_interfaces__action__RobotMove_FeedbackMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robo_cleaner_interfaces__action__RobotMove_FeedbackMessage));
  bool success = robo_cleaner_interfaces__action__RobotMove_FeedbackMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robo_cleaner_interfaces__action__RobotMove_FeedbackMessage__destroy(robo_cleaner_interfaces__action__RobotMove_FeedbackMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robo_cleaner_interfaces__action__RobotMove_FeedbackMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robo_cleaner_interfaces__action__RobotMove_FeedbackMessage__Sequence__init(robo_cleaner_interfaces__action__RobotMove_FeedbackMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robo_cleaner_interfaces__action__RobotMove_FeedbackMessage * data = NULL;

  if (size) {
    data = (robo_cleaner_interfaces__action__RobotMove_FeedbackMessage *)allocator.zero_allocate(size, sizeof(robo_cleaner_interfaces__action__RobotMove_FeedbackMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robo_cleaner_interfaces__action__RobotMove_FeedbackMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robo_cleaner_interfaces__action__RobotMove_FeedbackMessage__fini(&data[i - 1]);
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
robo_cleaner_interfaces__action__RobotMove_FeedbackMessage__Sequence__fini(robo_cleaner_interfaces__action__RobotMove_FeedbackMessage__Sequence * array)
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
      robo_cleaner_interfaces__action__RobotMove_FeedbackMessage__fini(&array->data[i]);
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

robo_cleaner_interfaces__action__RobotMove_FeedbackMessage__Sequence *
robo_cleaner_interfaces__action__RobotMove_FeedbackMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robo_cleaner_interfaces__action__RobotMove_FeedbackMessage__Sequence * array = (robo_cleaner_interfaces__action__RobotMove_FeedbackMessage__Sequence *)allocator.allocate(sizeof(robo_cleaner_interfaces__action__RobotMove_FeedbackMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robo_cleaner_interfaces__action__RobotMove_FeedbackMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robo_cleaner_interfaces__action__RobotMove_FeedbackMessage__Sequence__destroy(robo_cleaner_interfaces__action__RobotMove_FeedbackMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robo_cleaner_interfaces__action__RobotMove_FeedbackMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robo_cleaner_interfaces__action__RobotMove_FeedbackMessage__Sequence__are_equal(const robo_cleaner_interfaces__action__RobotMove_FeedbackMessage__Sequence * lhs, const robo_cleaner_interfaces__action__RobotMove_FeedbackMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robo_cleaner_interfaces__action__RobotMove_FeedbackMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robo_cleaner_interfaces__action__RobotMove_FeedbackMessage__Sequence__copy(
  const robo_cleaner_interfaces__action__RobotMove_FeedbackMessage__Sequence * input,
  robo_cleaner_interfaces__action__RobotMove_FeedbackMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(robo_cleaner_interfaces__action__RobotMove_FeedbackMessage);
    robo_cleaner_interfaces__action__RobotMove_FeedbackMessage * data =
      (robo_cleaner_interfaces__action__RobotMove_FeedbackMessage *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robo_cleaner_interfaces__action__RobotMove_FeedbackMessage__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          robo_cleaner_interfaces__action__RobotMove_FeedbackMessage__fini(&data[i]);
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
    if (!robo_cleaner_interfaces__action__RobotMove_FeedbackMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
