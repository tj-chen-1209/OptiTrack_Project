// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from motive_streamer:msg/MotiveRigidBody.idl
// generated code does not contain a copyright notice

#ifndef MOTIVE_STREAMER__MSG__DETAIL__MOTIVE_RIGID_BODY__FUNCTIONS_H_
#define MOTIVE_STREAMER__MSG__DETAIL__MOTIVE_RIGID_BODY__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "motive_streamer/msg/rosidl_generator_c__visibility_control.h"

#include "motive_streamer/msg/detail/motive_rigid_body__struct.h"

/// Initialize msg/MotiveRigidBody message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * motive_streamer__msg__MotiveRigidBody
 * )) before or use
 * motive_streamer__msg__MotiveRigidBody__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_motive_streamer
bool
motive_streamer__msg__MotiveRigidBody__init(motive_streamer__msg__MotiveRigidBody * msg);

/// Finalize msg/MotiveRigidBody message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_motive_streamer
void
motive_streamer__msg__MotiveRigidBody__fini(motive_streamer__msg__MotiveRigidBody * msg);

/// Create msg/MotiveRigidBody message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * motive_streamer__msg__MotiveRigidBody__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_motive_streamer
motive_streamer__msg__MotiveRigidBody *
motive_streamer__msg__MotiveRigidBody__create();

/// Destroy msg/MotiveRigidBody message.
/**
 * It calls
 * motive_streamer__msg__MotiveRigidBody__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_motive_streamer
void
motive_streamer__msg__MotiveRigidBody__destroy(motive_streamer__msg__MotiveRigidBody * msg);

/// Check for msg/MotiveRigidBody message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_motive_streamer
bool
motive_streamer__msg__MotiveRigidBody__are_equal(const motive_streamer__msg__MotiveRigidBody * lhs, const motive_streamer__msg__MotiveRigidBody * rhs);

/// Copy a msg/MotiveRigidBody message.
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
ROSIDL_GENERATOR_C_PUBLIC_motive_streamer
bool
motive_streamer__msg__MotiveRigidBody__copy(
  const motive_streamer__msg__MotiveRigidBody * input,
  motive_streamer__msg__MotiveRigidBody * output);

/// Initialize array of msg/MotiveRigidBody messages.
/**
 * It allocates the memory for the number of elements and calls
 * motive_streamer__msg__MotiveRigidBody__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_motive_streamer
bool
motive_streamer__msg__MotiveRigidBody__Sequence__init(motive_streamer__msg__MotiveRigidBody__Sequence * array, size_t size);

/// Finalize array of msg/MotiveRigidBody messages.
/**
 * It calls
 * motive_streamer__msg__MotiveRigidBody__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_motive_streamer
void
motive_streamer__msg__MotiveRigidBody__Sequence__fini(motive_streamer__msg__MotiveRigidBody__Sequence * array);

/// Create array of msg/MotiveRigidBody messages.
/**
 * It allocates the memory for the array and calls
 * motive_streamer__msg__MotiveRigidBody__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_motive_streamer
motive_streamer__msg__MotiveRigidBody__Sequence *
motive_streamer__msg__MotiveRigidBody__Sequence__create(size_t size);

/// Destroy array of msg/MotiveRigidBody messages.
/**
 * It calls
 * motive_streamer__msg__MotiveRigidBody__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_motive_streamer
void
motive_streamer__msg__MotiveRigidBody__Sequence__destroy(motive_streamer__msg__MotiveRigidBody__Sequence * array);

/// Check for msg/MotiveRigidBody message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_motive_streamer
bool
motive_streamer__msg__MotiveRigidBody__Sequence__are_equal(const motive_streamer__msg__MotiveRigidBody__Sequence * lhs, const motive_streamer__msg__MotiveRigidBody__Sequence * rhs);

/// Copy an array of msg/MotiveRigidBody messages.
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
ROSIDL_GENERATOR_C_PUBLIC_motive_streamer
bool
motive_streamer__msg__MotiveRigidBody__Sequence__copy(
  const motive_streamer__msg__MotiveRigidBody__Sequence * input,
  motive_streamer__msg__MotiveRigidBody__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // MOTIVE_STREAMER__MSG__DETAIL__MOTIVE_RIGID_BODY__FUNCTIONS_H_
