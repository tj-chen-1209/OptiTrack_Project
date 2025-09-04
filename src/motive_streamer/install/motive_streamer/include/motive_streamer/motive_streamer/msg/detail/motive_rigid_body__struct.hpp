// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from motive_streamer:msg/MotiveRigidBody.idl
// generated code does not contain a copyright notice

#ifndef MOTIVE_STREAMER__MSG__DETAIL__MOTIVE_RIGID_BODY__STRUCT_HPP_
#define MOTIVE_STREAMER__MSG__DETAIL__MOTIVE_RIGID_BODY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__motive_streamer__msg__MotiveRigidBody __attribute__((deprecated))
#else
# define DEPRECATED__motive_streamer__msg__MotiveRigidBody __declspec(deprecated)
#endif

namespace motive_streamer
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MotiveRigidBody_
{
  using Type = MotiveRigidBody_<ContainerAllocator>;

  explicit MotiveRigidBody_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pose(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0l;
      this->valid = false;
    }
  }

  explicit MotiveRigidBody_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pose(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0l;
      this->valid = false;
    }
  }

  // field types and members
  using _id_type =
    int32_t;
  _id_type id;
  using _valid_type =
    bool;
  _valid_type valid;
  using _pose_type =
    geometry_msgs::msg::Pose_<ContainerAllocator>;
  _pose_type pose;

  // setters for named parameter idiom
  Type & set__id(
    const int32_t & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__valid(
    const bool & _arg)
  {
    this->valid = _arg;
    return *this;
  }
  Type & set__pose(
    const geometry_msgs::msg::Pose_<ContainerAllocator> & _arg)
  {
    this->pose = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    motive_streamer::msg::MotiveRigidBody_<ContainerAllocator> *;
  using ConstRawPtr =
    const motive_streamer::msg::MotiveRigidBody_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<motive_streamer::msg::MotiveRigidBody_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<motive_streamer::msg::MotiveRigidBody_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      motive_streamer::msg::MotiveRigidBody_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<motive_streamer::msg::MotiveRigidBody_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      motive_streamer::msg::MotiveRigidBody_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<motive_streamer::msg::MotiveRigidBody_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<motive_streamer::msg::MotiveRigidBody_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<motive_streamer::msg::MotiveRigidBody_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__motive_streamer__msg__MotiveRigidBody
    std::shared_ptr<motive_streamer::msg::MotiveRigidBody_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__motive_streamer__msg__MotiveRigidBody
    std::shared_ptr<motive_streamer::msg::MotiveRigidBody_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MotiveRigidBody_ & other) const
  {
    if (this->id != other.id) {
      return false;
    }
    if (this->valid != other.valid) {
      return false;
    }
    if (this->pose != other.pose) {
      return false;
    }
    return true;
  }
  bool operator!=(const MotiveRigidBody_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MotiveRigidBody_

// alias to use template instance with default allocator
using MotiveRigidBody =
  motive_streamer::msg::MotiveRigidBody_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace motive_streamer

#endif  // MOTIVE_STREAMER__MSG__DETAIL__MOTIVE_RIGID_BODY__STRUCT_HPP_
