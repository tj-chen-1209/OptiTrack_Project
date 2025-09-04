// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from motive_streamer:msg/MotiveRigidBodyList.idl
// generated code does not contain a copyright notice
#include "motive_streamer/msg/detail/motive_rigid_body_list__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `rigid_bodies`
#include "motive_streamer/msg/detail/motive_rigid_body__functions.h"

bool
motive_streamer__msg__MotiveRigidBodyList__init(motive_streamer__msg__MotiveRigidBodyList * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    motive_streamer__msg__MotiveRigidBodyList__fini(msg);
    return false;
  }
  // rigid_bodies
  if (!motive_streamer__msg__MotiveRigidBody__Sequence__init(&msg->rigid_bodies, 0)) {
    motive_streamer__msg__MotiveRigidBodyList__fini(msg);
    return false;
  }
  return true;
}

void
motive_streamer__msg__MotiveRigidBodyList__fini(motive_streamer__msg__MotiveRigidBodyList * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // rigid_bodies
  motive_streamer__msg__MotiveRigidBody__Sequence__fini(&msg->rigid_bodies);
}

bool
motive_streamer__msg__MotiveRigidBodyList__are_equal(const motive_streamer__msg__MotiveRigidBodyList * lhs, const motive_streamer__msg__MotiveRigidBodyList * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // rigid_bodies
  if (!motive_streamer__msg__MotiveRigidBody__Sequence__are_equal(
      &(lhs->rigid_bodies), &(rhs->rigid_bodies)))
  {
    return false;
  }
  return true;
}

bool
motive_streamer__msg__MotiveRigidBodyList__copy(
  const motive_streamer__msg__MotiveRigidBodyList * input,
  motive_streamer__msg__MotiveRigidBodyList * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // rigid_bodies
  if (!motive_streamer__msg__MotiveRigidBody__Sequence__copy(
      &(input->rigid_bodies), &(output->rigid_bodies)))
  {
    return false;
  }
  return true;
}

motive_streamer__msg__MotiveRigidBodyList *
motive_streamer__msg__MotiveRigidBodyList__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  motive_streamer__msg__MotiveRigidBodyList * msg = (motive_streamer__msg__MotiveRigidBodyList *)allocator.allocate(sizeof(motive_streamer__msg__MotiveRigidBodyList), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(motive_streamer__msg__MotiveRigidBodyList));
  bool success = motive_streamer__msg__MotiveRigidBodyList__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
motive_streamer__msg__MotiveRigidBodyList__destroy(motive_streamer__msg__MotiveRigidBodyList * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    motive_streamer__msg__MotiveRigidBodyList__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
motive_streamer__msg__MotiveRigidBodyList__Sequence__init(motive_streamer__msg__MotiveRigidBodyList__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  motive_streamer__msg__MotiveRigidBodyList * data = NULL;

  if (size) {
    data = (motive_streamer__msg__MotiveRigidBodyList *)allocator.zero_allocate(size, sizeof(motive_streamer__msg__MotiveRigidBodyList), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = motive_streamer__msg__MotiveRigidBodyList__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        motive_streamer__msg__MotiveRigidBodyList__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
motive_streamer__msg__MotiveRigidBodyList__Sequence__fini(motive_streamer__msg__MotiveRigidBodyList__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      motive_streamer__msg__MotiveRigidBodyList__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

motive_streamer__msg__MotiveRigidBodyList__Sequence *
motive_streamer__msg__MotiveRigidBodyList__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  motive_streamer__msg__MotiveRigidBodyList__Sequence * array = (motive_streamer__msg__MotiveRigidBodyList__Sequence *)allocator.allocate(sizeof(motive_streamer__msg__MotiveRigidBodyList__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = motive_streamer__msg__MotiveRigidBodyList__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
motive_streamer__msg__MotiveRigidBodyList__Sequence__destroy(motive_streamer__msg__MotiveRigidBodyList__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    motive_streamer__msg__MotiveRigidBodyList__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
motive_streamer__msg__MotiveRigidBodyList__Sequence__are_equal(const motive_streamer__msg__MotiveRigidBodyList__Sequence * lhs, const motive_streamer__msg__MotiveRigidBodyList__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!motive_streamer__msg__MotiveRigidBodyList__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
motive_streamer__msg__MotiveRigidBodyList__Sequence__copy(
  const motive_streamer__msg__MotiveRigidBodyList__Sequence * input,
  motive_streamer__msg__MotiveRigidBodyList__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(motive_streamer__msg__MotiveRigidBodyList);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    motive_streamer__msg__MotiveRigidBodyList * data =
      (motive_streamer__msg__MotiveRigidBodyList *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!motive_streamer__msg__MotiveRigidBodyList__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          motive_streamer__msg__MotiveRigidBodyList__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!motive_streamer__msg__MotiveRigidBodyList__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
