// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from robo_cleaner_interfaces:msg/BatteryStatus.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "robo_cleaner_interfaces/msg/detail/battery_status__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace robo_cleaner_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void BatteryStatus_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) robo_cleaner_interfaces::msg::BatteryStatus(_init);
}

void BatteryStatus_fini_function(void * message_memory)
{
  auto typed_message = static_cast<robo_cleaner_interfaces::msg::BatteryStatus *>(message_memory);
  typed_message->~BatteryStatus();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember BatteryStatus_message_member_array[2] = {
  {
    "max_moves_on_full_energy",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robo_cleaner_interfaces::msg::BatteryStatus, max_moves_on_full_energy),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "moves_left",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robo_cleaner_interfaces::msg::BatteryStatus, moves_left),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers BatteryStatus_message_members = {
  "robo_cleaner_interfaces::msg",  // message namespace
  "BatteryStatus",  // message name
  2,  // number of fields
  sizeof(robo_cleaner_interfaces::msg::BatteryStatus),
  BatteryStatus_message_member_array,  // message members
  BatteryStatus_init_function,  // function to initialize message memory (memory has to be allocated)
  BatteryStatus_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t BatteryStatus_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &BatteryStatus_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace robo_cleaner_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<robo_cleaner_interfaces::msg::BatteryStatus>()
{
  return &::robo_cleaner_interfaces::msg::rosidl_typesupport_introspection_cpp::BatteryStatus_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, robo_cleaner_interfaces, msg, BatteryStatus)() {
  return &::robo_cleaner_interfaces::msg::rosidl_typesupport_introspection_cpp::BatteryStatus_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
