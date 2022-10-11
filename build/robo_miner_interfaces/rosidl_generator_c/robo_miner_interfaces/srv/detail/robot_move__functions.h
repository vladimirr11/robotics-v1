// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from robo_miner_interfaces:srv/RobotMove.idl
// generated code does not contain a copyright notice

#ifndef ROBO_MINER_INTERFACES__SRV__DETAIL__ROBOT_MOVE__FUNCTIONS_H_
#define ROBO_MINER_INTERFACES__SRV__DETAIL__ROBOT_MOVE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "robo_miner_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "robo_miner_interfaces/srv/detail/robot_move__struct.h"

/// Initialize srv/RobotMove message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * robo_miner_interfaces__srv__RobotMove_Request
 * )) before or use
 * robo_miner_interfaces__srv__RobotMove_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_robo_miner_interfaces
bool
robo_miner_interfaces__srv__RobotMove_Request__init(robo_miner_interfaces__srv__RobotMove_Request * msg);

/// Finalize srv/RobotMove message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_robo_miner_interfaces
void
robo_miner_interfaces__srv__RobotMove_Request__fini(robo_miner_interfaces__srv__RobotMove_Request * msg);

/// Create srv/RobotMove message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * robo_miner_interfaces__srv__RobotMove_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_robo_miner_interfaces
robo_miner_interfaces__srv__RobotMove_Request *
robo_miner_interfaces__srv__RobotMove_Request__create();

/// Destroy srv/RobotMove message.
/**
 * It calls
 * robo_miner_interfaces__srv__RobotMove_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_robo_miner_interfaces
void
robo_miner_interfaces__srv__RobotMove_Request__destroy(robo_miner_interfaces__srv__RobotMove_Request * msg);

/// Check for srv/RobotMove message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_robo_miner_interfaces
bool
robo_miner_interfaces__srv__RobotMove_Request__are_equal(const robo_miner_interfaces__srv__RobotMove_Request * lhs, const robo_miner_interfaces__srv__RobotMove_Request * rhs);

/// Copy a srv/RobotMove message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_robo_miner_interfaces
bool
robo_miner_interfaces__srv__RobotMove_Request__copy(
  const robo_miner_interfaces__srv__RobotMove_Request * input,
  robo_miner_interfaces__srv__RobotMove_Request * output);

/// Initialize array of srv/RobotMove messages.
/**
 * It allocates the memory for the number of elements and calls
 * robo_miner_interfaces__srv__RobotMove_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_robo_miner_interfaces
bool
robo_miner_interfaces__srv__RobotMove_Request__Sequence__init(robo_miner_interfaces__srv__RobotMove_Request__Sequence * array, size_t size);

/// Finalize array of srv/RobotMove messages.
/**
 * It calls
 * robo_miner_interfaces__srv__RobotMove_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_robo_miner_interfaces
void
robo_miner_interfaces__srv__RobotMove_Request__Sequence__fini(robo_miner_interfaces__srv__RobotMove_Request__Sequence * array);

/// Create array of srv/RobotMove messages.
/**
 * It allocates the memory for the array and calls
 * robo_miner_interfaces__srv__RobotMove_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_robo_miner_interfaces
robo_miner_interfaces__srv__RobotMove_Request__Sequence *
robo_miner_interfaces__srv__RobotMove_Request__Sequence__create(size_t size);

/// Destroy array of srv/RobotMove messages.
/**
 * It calls
 * robo_miner_interfaces__srv__RobotMove_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_robo_miner_interfaces
void
robo_miner_interfaces__srv__RobotMove_Request__Sequence__destroy(robo_miner_interfaces__srv__RobotMove_Request__Sequence * array);

/// Check for srv/RobotMove message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_robo_miner_interfaces
bool
robo_miner_interfaces__srv__RobotMove_Request__Sequence__are_equal(const robo_miner_interfaces__srv__RobotMove_Request__Sequence * lhs, const robo_miner_interfaces__srv__RobotMove_Request__Sequence * rhs);

/// Copy an array of srv/RobotMove messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_robo_miner_interfaces
bool
robo_miner_interfaces__srv__RobotMove_Request__Sequence__copy(
  const robo_miner_interfaces__srv__RobotMove_Request__Sequence * input,
  robo_miner_interfaces__srv__RobotMove_Request__Sequence * output);

/// Initialize srv/RobotMove message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * robo_miner_interfaces__srv__RobotMove_Response
 * )) before or use
 * robo_miner_interfaces__srv__RobotMove_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_robo_miner_interfaces
bool
robo_miner_interfaces__srv__RobotMove_Response__init(robo_miner_interfaces__srv__RobotMove_Response * msg);

/// Finalize srv/RobotMove message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_robo_miner_interfaces
void
robo_miner_interfaces__srv__RobotMove_Response__fini(robo_miner_interfaces__srv__RobotMove_Response * msg);

/// Create srv/RobotMove message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * robo_miner_interfaces__srv__RobotMove_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_robo_miner_interfaces
robo_miner_interfaces__srv__RobotMove_Response *
robo_miner_interfaces__srv__RobotMove_Response__create();

/// Destroy srv/RobotMove message.
/**
 * It calls
 * robo_miner_interfaces__srv__RobotMove_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_robo_miner_interfaces
void
robo_miner_interfaces__srv__RobotMove_Response__destroy(robo_miner_interfaces__srv__RobotMove_Response * msg);

/// Check for srv/RobotMove message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_robo_miner_interfaces
bool
robo_miner_interfaces__srv__RobotMove_Response__are_equal(const robo_miner_interfaces__srv__RobotMove_Response * lhs, const robo_miner_interfaces__srv__RobotMove_Response * rhs);

/// Copy a srv/RobotMove message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_robo_miner_interfaces
bool
robo_miner_interfaces__srv__RobotMove_Response__copy(
  const robo_miner_interfaces__srv__RobotMove_Response * input,
  robo_miner_interfaces__srv__RobotMove_Response * output);

/// Initialize array of srv/RobotMove messages.
/**
 * It allocates the memory for the number of elements and calls
 * robo_miner_interfaces__srv__RobotMove_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_robo_miner_interfaces
bool
robo_miner_interfaces__srv__RobotMove_Response__Sequence__init(robo_miner_interfaces__srv__RobotMove_Response__Sequence * array, size_t size);

/// Finalize array of srv/RobotMove messages.
/**
 * It calls
 * robo_miner_interfaces__srv__RobotMove_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_robo_miner_interfaces
void
robo_miner_interfaces__srv__RobotMove_Response__Sequence__fini(robo_miner_interfaces__srv__RobotMove_Response__Sequence * array);

/// Create array of srv/RobotMove messages.
/**
 * It allocates the memory for the array and calls
 * robo_miner_interfaces__srv__RobotMove_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_robo_miner_interfaces
robo_miner_interfaces__srv__RobotMove_Response__Sequence *
robo_miner_interfaces__srv__RobotMove_Response__Sequence__create(size_t size);

/// Destroy array of srv/RobotMove messages.
/**
 * It calls
 * robo_miner_interfaces__srv__RobotMove_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_robo_miner_interfaces
void
robo_miner_interfaces__srv__RobotMove_Response__Sequence__destroy(robo_miner_interfaces__srv__RobotMove_Response__Sequence * array);

/// Check for srv/RobotMove message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_robo_miner_interfaces
bool
robo_miner_interfaces__srv__RobotMove_Response__Sequence__are_equal(const robo_miner_interfaces__srv__RobotMove_Response__Sequence * lhs, const robo_miner_interfaces__srv__RobotMove_Response__Sequence * rhs);

/// Copy an array of srv/RobotMove messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_robo_miner_interfaces
bool
robo_miner_interfaces__srv__RobotMove_Response__Sequence__copy(
  const robo_miner_interfaces__srv__RobotMove_Response__Sequence * input,
  robo_miner_interfaces__srv__RobotMove_Response__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // ROBO_MINER_INTERFACES__SRV__DETAIL__ROBOT_MOVE__FUNCTIONS_H_
