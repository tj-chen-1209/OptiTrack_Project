// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from motive_streamer:msg/MotiveRigidBodyList.idl
// generated code does not contain a copyright notice

#ifndef MOTIVE_STREAMER__MSG__DETAIL__MOTIVE_RIGID_BODY_LIST__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define MOTIVE_STREAMER__MSG__DETAIL__MOTIVE_RIGID_BODY_LIST__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "motive_streamer/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "motive_streamer/msg/detail/motive_rigid_body_list__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace motive_streamer
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_motive_streamer
cdr_serialize(
  const motive_streamer::msg::MotiveRigidBodyList & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_motive_streamer
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  motive_streamer::msg::MotiveRigidBodyList & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_motive_streamer
get_serialized_size(
  const motive_streamer::msg::MotiveRigidBodyList & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_motive_streamer
max_serialized_size_MotiveRigidBodyList(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace motive_streamer

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_motive_streamer
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, motive_streamer, msg, MotiveRigidBodyList)();

#ifdef __cplusplus
}
#endif

#endif  // MOTIVE_STREAMER__MSG__DETAIL__MOTIVE_RIGID_BODY_LIST__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
