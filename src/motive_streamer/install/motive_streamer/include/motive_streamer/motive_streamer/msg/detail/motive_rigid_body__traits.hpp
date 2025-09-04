// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from motive_streamer:msg/MotiveRigidBody.idl
// generated code does not contain a copyright notice

#ifndef MOTIVE_STREAMER__MSG__DETAIL__MOTIVE_RIGID_BODY__TRAITS_HPP_
#define MOTIVE_STREAMER__MSG__DETAIL__MOTIVE_RIGID_BODY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "motive_streamer/msg/detail/motive_rigid_body__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__traits.hpp"

namespace motive_streamer
{

namespace msg
{

inline void to_flow_style_yaml(
  const MotiveRigidBody & msg,
  std::ostream & out)
{
  out << "{";
  // member: id
  {
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << ", ";
  }

  // member: valid
  {
    out << "valid: ";
    rosidl_generator_traits::value_to_yaml(msg.valid, out);
    out << ", ";
  }

  // member: pose
  {
    out << "pose: ";
    to_flow_style_yaml(msg.pose, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MotiveRigidBody & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << "\n";
  }

  // member: valid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "valid: ";
    rosidl_generator_traits::value_to_yaml(msg.valid, out);
    out << "\n";
  }

  // member: pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose:\n";
    to_block_style_yaml(msg.pose, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MotiveRigidBody & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace motive_streamer

namespace rosidl_generator_traits
{

[[deprecated("use motive_streamer::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const motive_streamer::msg::MotiveRigidBody & msg,
  std::ostream & out, size_t indentation = 0)
{
  motive_streamer::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use motive_streamer::msg::to_yaml() instead")]]
inline std::string to_yaml(const motive_streamer::msg::MotiveRigidBody & msg)
{
  return motive_streamer::msg::to_yaml(msg);
}

template<>
inline const char * data_type<motive_streamer::msg::MotiveRigidBody>()
{
  return "motive_streamer::msg::MotiveRigidBody";
}

template<>
inline const char * name<motive_streamer::msg::MotiveRigidBody>()
{
  return "motive_streamer/msg/MotiveRigidBody";
}

template<>
struct has_fixed_size<motive_streamer::msg::MotiveRigidBody>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Pose>::value> {};

template<>
struct has_bounded_size<motive_streamer::msg::MotiveRigidBody>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Pose>::value> {};

template<>
struct is_message<motive_streamer::msg::MotiveRigidBody>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MOTIVE_STREAMER__MSG__DETAIL__MOTIVE_RIGID_BODY__TRAITS_HPP_
