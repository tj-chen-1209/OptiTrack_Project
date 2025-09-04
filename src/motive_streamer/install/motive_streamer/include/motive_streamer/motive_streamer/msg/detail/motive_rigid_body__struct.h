// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from motive_streamer:msg/MotiveRigidBody.idl
// generated code does not contain a copyright notice

#ifndef MOTIVE_STREAMER__MSG__DETAIL__MOTIVE_RIGID_BODY__STRUCT_H_
#define MOTIVE_STREAMER__MSG__DETAIL__MOTIVE_RIGID_BODY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__struct.h"

/// Struct defined in msg/MotiveRigidBody in the package motive_streamer.
typedef struct motive_streamer__msg__MotiveRigidBody
{
  int32_t id;
  bool valid;
  geometry_msgs__msg__Pose pose;
} motive_streamer__msg__MotiveRigidBody;

// Struct for a sequence of motive_streamer__msg__MotiveRigidBody.
typedef struct motive_streamer__msg__MotiveRigidBody__Sequence
{
  motive_streamer__msg__MotiveRigidBody * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} motive_streamer__msg__MotiveRigidBody__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MOTIVE_STREAMER__MSG__DETAIL__MOTIVE_RIGID_BODY__STRUCT_H_
