// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from motive_streamer:msg/MotiveRigidBodyList.idl
// generated code does not contain a copyright notice

#ifndef MOTIVE_STREAMER__MSG__DETAIL__MOTIVE_RIGID_BODY_LIST__STRUCT_H_
#define MOTIVE_STREAMER__MSG__DETAIL__MOTIVE_RIGID_BODY_LIST__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'rigid_bodies'
#include "motive_streamer/msg/detail/motive_rigid_body__struct.h"

/// Struct defined in msg/MotiveRigidBodyList in the package motive_streamer.
typedef struct motive_streamer__msg__MotiveRigidBodyList
{
  std_msgs__msg__Header header;
  motive_streamer__msg__MotiveRigidBody__Sequence rigid_bodies;
} motive_streamer__msg__MotiveRigidBodyList;

// Struct for a sequence of motive_streamer__msg__MotiveRigidBodyList.
typedef struct motive_streamer__msg__MotiveRigidBodyList__Sequence
{
  motive_streamer__msg__MotiveRigidBodyList * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} motive_streamer__msg__MotiveRigidBodyList__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MOTIVE_STREAMER__MSG__DETAIL__MOTIVE_RIGID_BODY_LIST__STRUCT_H_
