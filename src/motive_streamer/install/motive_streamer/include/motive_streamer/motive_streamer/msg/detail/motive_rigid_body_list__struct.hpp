// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from motive_streamer:msg/MotiveRigidBodyList.idl
// generated code does not contain a copyright notice

#ifndef MOTIVE_STREAMER__MSG__DETAIL__MOTIVE_RIGID_BODY_LIST__STRUCT_HPP_
#define MOTIVE_STREAMER__MSG__DETAIL__MOTIVE_RIGID_BODY_LIST__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'rigid_bodies'
#include "motive_streamer/msg/detail/motive_rigid_body__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__motive_streamer__msg__MotiveRigidBodyList __attribute__((deprecated))
#else
# define DEPRECATED__motive_streamer__msg__MotiveRigidBodyList __declspec(deprecated)
#endif

namespace motive_streamer
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MotiveRigidBodyList_
{
  using Type = MotiveRigidBodyList_<ContainerAllocator>;

  explicit MotiveRigidBodyList_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    (void)_init;
  }

  explicit MotiveRigidBodyList_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _rigid_bodies_type =
    std::vector<motive_streamer::msg::MotiveRigidBody_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<motive_streamer::msg::MotiveRigidBody_<ContainerAllocator>>>;
  _rigid_bodies_type rigid_bodies;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__rigid_bodies(
    const std::vector<motive_streamer::msg::MotiveRigidBody_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<motive_streamer::msg::MotiveRigidBody_<ContainerAllocator>>> & _arg)
  {
    this->rigid_bodies = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    motive_streamer::msg::MotiveRigidBodyList_<ContainerAllocator> *;
  using ConstRawPtr =
    const motive_streamer::msg::MotiveRigidBodyList_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<motive_streamer::msg::MotiveRigidBodyList_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<motive_streamer::msg::MotiveRigidBodyList_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      motive_streamer::msg::MotiveRigidBodyList_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<motive_streamer::msg::MotiveRigidBodyList_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      motive_streamer::msg::MotiveRigidBodyList_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<motive_streamer::msg::MotiveRigidBodyList_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<motive_streamer::msg::MotiveRigidBodyList_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<motive_streamer::msg::MotiveRigidBodyList_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__motive_streamer__msg__MotiveRigidBodyList
    std::shared_ptr<motive_streamer::msg::MotiveRigidBodyList_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__motive_streamer__msg__MotiveRigidBodyList
    std::shared_ptr<motive_streamer::msg::MotiveRigidBodyList_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MotiveRigidBodyList_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->rigid_bodies != other.rigid_bodies) {
      return false;
    }
    return true;
  }
  bool operator!=(const MotiveRigidBodyList_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MotiveRigidBodyList_

// alias to use template instance with default allocator
using MotiveRigidBodyList =
  motive_streamer::msg::MotiveRigidBodyList_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace motive_streamer

#endif  // MOTIVE_STREAMER__MSG__DETAIL__MOTIVE_RIGID_BODY_LIST__STRUCT_HPP_
