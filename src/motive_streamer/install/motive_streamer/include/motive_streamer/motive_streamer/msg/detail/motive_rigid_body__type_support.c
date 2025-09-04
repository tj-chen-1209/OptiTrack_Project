// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from motive_streamer:msg/MotiveRigidBody.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "motive_streamer/msg/detail/motive_rigid_body__rosidl_typesupport_introspection_c.h"
#include "motive_streamer/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "motive_streamer/msg/detail/motive_rigid_body__functions.h"
#include "motive_streamer/msg/detail/motive_rigid_body__struct.h"


// Include directives for member types
// Member `pose`
#include "geometry_msgs/msg/pose.h"
// Member `pose`
#include "geometry_msgs/msg/detail/pose__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void motive_streamer__msg__MotiveRigidBody__rosidl_typesupport_introspection_c__MotiveRigidBody_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  motive_streamer__msg__MotiveRigidBody__init(message_memory);
}

void motive_streamer__msg__MotiveRigidBody__rosidl_typesupport_introspection_c__MotiveRigidBody_fini_function(void * message_memory)
{
  motive_streamer__msg__MotiveRigidBody__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember motive_streamer__msg__MotiveRigidBody__rosidl_typesupport_introspection_c__MotiveRigidBody_message_member_array[3] = {
  {
    "id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(motive_streamer__msg__MotiveRigidBody, id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "valid",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(motive_streamer__msg__MotiveRigidBody, valid),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pose",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(motive_streamer__msg__MotiveRigidBody, pose),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers motive_streamer__msg__MotiveRigidBody__rosidl_typesupport_introspection_c__MotiveRigidBody_message_members = {
  "motive_streamer__msg",  // message namespace
  "MotiveRigidBody",  // message name
  3,  // number of fields
  sizeof(motive_streamer__msg__MotiveRigidBody),
  motive_streamer__msg__MotiveRigidBody__rosidl_typesupport_introspection_c__MotiveRigidBody_message_member_array,  // message members
  motive_streamer__msg__MotiveRigidBody__rosidl_typesupport_introspection_c__MotiveRigidBody_init_function,  // function to initialize message memory (memory has to be allocated)
  motive_streamer__msg__MotiveRigidBody__rosidl_typesupport_introspection_c__MotiveRigidBody_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t motive_streamer__msg__MotiveRigidBody__rosidl_typesupport_introspection_c__MotiveRigidBody_message_type_support_handle = {
  0,
  &motive_streamer__msg__MotiveRigidBody__rosidl_typesupport_introspection_c__MotiveRigidBody_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_motive_streamer
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, motive_streamer, msg, MotiveRigidBody)() {
  motive_streamer__msg__MotiveRigidBody__rosidl_typesupport_introspection_c__MotiveRigidBody_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Pose)();
  if (!motive_streamer__msg__MotiveRigidBody__rosidl_typesupport_introspection_c__MotiveRigidBody_message_type_support_handle.typesupport_identifier) {
    motive_streamer__msg__MotiveRigidBody__rosidl_typesupport_introspection_c__MotiveRigidBody_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &motive_streamer__msg__MotiveRigidBody__rosidl_typesupport_introspection_c__MotiveRigidBody_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
