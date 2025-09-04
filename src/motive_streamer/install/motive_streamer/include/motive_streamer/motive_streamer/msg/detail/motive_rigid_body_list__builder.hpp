// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from motive_streamer:msg/MotiveRigidBodyList.idl
// generated code does not contain a copyright notice

#ifndef MOTIVE_STREAMER__MSG__DETAIL__MOTIVE_RIGID_BODY_LIST__BUILDER_HPP_
#define MOTIVE_STREAMER__MSG__DETAIL__MOTIVE_RIGID_BODY_LIST__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "motive_streamer/msg/detail/motive_rigid_body_list__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace motive_streamer
{

namespace msg
{

namespace builder
{

class Init_MotiveRigidBodyList_rigid_bodies
{
public:
  explicit Init_MotiveRigidBodyList_rigid_bodies(::motive_streamer::msg::MotiveRigidBodyList & msg)
  : msg_(msg)
  {}
  ::motive_streamer::msg::MotiveRigidBodyList rigid_bodies(::motive_streamer::msg::MotiveRigidBodyList::_rigid_bodies_type arg)
  {
    msg_.rigid_bodies = std::move(arg);
    return std::move(msg_);
  }

private:
  ::motive_streamer::msg::MotiveRigidBodyList msg_;
};

class Init_MotiveRigidBodyList_header
{
public:
  Init_MotiveRigidBodyList_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MotiveRigidBodyList_rigid_bodies header(::motive_streamer::msg::MotiveRigidBodyList::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_MotiveRigidBodyList_rigid_bodies(msg_);
  }

private:
  ::motive_streamer::msg::MotiveRigidBodyList msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::motive_streamer::msg::MotiveRigidBodyList>()
{
  return motive_streamer::msg::builder::Init_MotiveRigidBodyList_header();
}

}  // namespace motive_streamer

#endif  // MOTIVE_STREAMER__MSG__DETAIL__MOTIVE_RIGID_BODY_LIST__BUILDER_HPP_
