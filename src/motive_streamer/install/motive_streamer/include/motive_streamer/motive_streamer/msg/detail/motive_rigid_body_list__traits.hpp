// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from motive_streamer:msg/MotiveRigidBodyList.idl
// generated code does not contain a copyright notice

#ifndef MOTIVE_STREAMER__MSG__DETAIL__MOTIVE_RIGID_BODY_LIST__TRAITS_HPP_
#define MOTIVE_STREAMER__MSG__DETAIL__MOTIVE_RIGID_BODY_LIST__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "motive_streamer/msg/detail/motive_rigid_body_list__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'rigid_bodies'
#include "motive_streamer/msg/detail/motive_rigid_body__traits.hpp"

namespace motive_streamer
{

namespace msg
{

inline void to_flow_style_yaml(
  const MotiveRigidBodyList & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: rigid_bodies
  {
    if (msg.rigid_bodies.size() == 0) {
      out << "rigid_bodies: []";
    } else {
      out << "rigid_bodies: [";
      size_t pending_items = msg.rigid_bodies.size();
      for (auto item : msg.rigid_bodies) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MotiveRigidBodyList & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: rigid_bodies
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.rigid_bodies.size() == 0) {
      out << "rigid_bodies: []\n";
    } else {
      out << "rigid_bodies:\n";
      for (auto item : msg.rigid_bodies) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MotiveRigidBodyList & msg, bool use_flow_style = false)
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
  const motive_streamer::msg::MotiveRigidBodyList & msg,
  std::ostream & out, size_t indentation = 0)
{
  motive_streamer::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use motive_streamer::msg::to_yaml() instead")]]
inline std::string to_yaml(const motive_streamer::msg::MotiveRigidBodyList & msg)
{
  return motive_streamer::msg::to_yaml(msg);
}

template<>
inline const char * data_type<motive_streamer::msg::MotiveRigidBodyList>()
{
  return "motive_streamer::msg::MotiveRigidBodyList";
}

template<>
inline const char * name<motive_streamer::msg::MotiveRigidBodyList>()
{
  return "motive_streamer/msg/MotiveRigidBodyList";
}

template<>
struct has_fixed_size<motive_streamer::msg::MotiveRigidBodyList>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<motive_streamer::msg::MotiveRigidBodyList>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<motive_streamer::msg::MotiveRigidBodyList>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MOTIVE_STREAMER__MSG__DETAIL__MOTIVE_RIGID_BODY_LIST__TRAITS_HPP_
