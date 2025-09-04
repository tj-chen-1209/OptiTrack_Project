// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from motive_streamer:msg/MotiveRigidBody.idl
// generated code does not contain a copyright notice

#ifndef MOTIVE_STREAMER__MSG__DETAIL__MOTIVE_RIGID_BODY__BUILDER_HPP_
#define MOTIVE_STREAMER__MSG__DETAIL__MOTIVE_RIGID_BODY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "motive_streamer/msg/detail/motive_rigid_body__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace motive_streamer
{

namespace msg
{

namespace builder
{

class Init_MotiveRigidBody_pose
{
public:
  explicit Init_MotiveRigidBody_pose(::motive_streamer::msg::MotiveRigidBody & msg)
  : msg_(msg)
  {}
  ::motive_streamer::msg::MotiveRigidBody pose(::motive_streamer::msg::MotiveRigidBody::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return std::move(msg_);
  }

private:
  ::motive_streamer::msg::MotiveRigidBody msg_;
};

class Init_MotiveRigidBody_valid
{
public:
  explicit Init_MotiveRigidBody_valid(::motive_streamer::msg::MotiveRigidBody & msg)
  : msg_(msg)
  {}
  Init_MotiveRigidBody_pose valid(::motive_streamer::msg::MotiveRigidBody::_valid_type arg)
  {
    msg_.valid = std::move(arg);
    return Init_MotiveRigidBody_pose(msg_);
  }

private:
  ::motive_streamer::msg::MotiveRigidBody msg_;
};

class Init_MotiveRigidBody_id
{
public:
  Init_MotiveRigidBody_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MotiveRigidBody_valid id(::motive_streamer::msg::MotiveRigidBody::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_MotiveRigidBody_valid(msg_);
  }

private:
  ::motive_streamer::msg::MotiveRigidBody msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::motive_streamer::msg::MotiveRigidBody>()
{
  return motive_streamer::msg::builder::Init_MotiveRigidBody_id();
}

}  // namespace motive_streamer

#endif  // MOTIVE_STREAMER__MSG__DETAIL__MOTIVE_RIGID_BODY__BUILDER_HPP_
