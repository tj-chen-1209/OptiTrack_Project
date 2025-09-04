// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from motive_streamer:msg/MotiveRigidBody.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "motive_streamer/msg/detail/motive_rigid_body__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace motive_streamer
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void MotiveRigidBody_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) motive_streamer::msg::MotiveRigidBody(_init);
}

void MotiveRigidBody_fini_function(void * message_memory)
{
  auto typed_message = static_cast<motive_streamer::msg::MotiveRigidBody *>(message_memory);
  typed_message->~MotiveRigidBody();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember MotiveRigidBody_message_member_array[3] = {
  {
    "id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(motive_streamer::msg::MotiveRigidBody, id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "valid",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(motive_streamer::msg::MotiveRigidBody, valid),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "pose",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::Pose>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(motive_streamer::msg::MotiveRigidBody, pose),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers MotiveRigidBody_message_members = {
  "motive_streamer::msg",  // message namespace
  "MotiveRigidBody",  // message name
  3,  // number of fields
  sizeof(motive_streamer::msg::MotiveRigidBody),
  MotiveRigidBody_message_member_array,  // message members
  MotiveRigidBody_init_function,  // function to initialize message memory (memory has to be allocated)
  MotiveRigidBody_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t MotiveRigidBody_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &MotiveRigidBody_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace motive_streamer


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<motive_streamer::msg::MotiveRigidBody>()
{
  return &::motive_streamer::msg::rosidl_typesupport_introspection_cpp::MotiveRigidBody_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, motive_streamer, msg, MotiveRigidBody)() {
  return &::motive_streamer::msg::rosidl_typesupport_introspection_cpp::MotiveRigidBody_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
