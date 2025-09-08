cmake_minimum_required(VERSION 3.20)
project(relative_pose_node)

# 设置编译器警告选项
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# 查找依赖
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(tf2 REQUIRED)  # 查找 tf2 库
find_package(tf2_geometry_msgs REQUIRED)  # 查找 tf2_geometry_msgs 库

find_package(moveit_ros_planning_interface REQUIRED)

# 添加可执行文件
add_executable(relative_pose_node src/relative_pose_node.cpp)
add_executable(test_node src/moveit2_test.cpp)
add_executable(sub_node src/test.cpp)

# 链接依赖库
ament_target_dependencies(relative_pose_node rclcpp geometry_msgs tf2 tf2_geometry_msgs)
ament_target_dependencies(test_node rclcpp geometry_msgs tf2 tf2_geometry_msgs moveit_ros_planning_interface)
ament_target_dependencies(sub_node rclcpp geometry_msgs tf2 tf2_geometry_msgs moveit_ros_planning_interface)


# 安装目标
install(TARGETS
  relative_pose_node
  DESTINATION lib/${PROJECT_NAME}
)

install(TARGETS
  test_node
  DESTINATION lib/${PROJECT_NAME}
)

install(TARGETS
  sub_node
  DESTINATION lib/${PROJECT_NAME}
)


# 安装 launch 文件
install(DIRECTORY launch/
        DESTINATION share/${PROJECT_NAME}/launch)


# 如果启用了测试构建
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # 以下行跳过检查文件版权问题
  # 如果添加了版权和许可证，可以取消注释
  set(ament_cmake_copyright_FOUND TRUE)
  # 以下行跳过 cpplint（仅在 Git 仓库中有效）
  # 如果你在 Git 仓库中且已经添加了版权和许可证，可以取消注释
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
