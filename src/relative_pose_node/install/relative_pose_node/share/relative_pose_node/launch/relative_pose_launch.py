import launch
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, LogInfo
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription([
        # 声明节点参数（如果需要，可以添加更多的参数）
        DeclareLaunchArgument(
            'pose_topic', default_value='arm/joint1/pose', description='Topic to subscribe for pose messages'
        ),

        # 启动节点
        Node(
            package='relative_pose_node',  # 你的 ROS2 包名
            executable='relative_pose_node',  # 你在 CMake 中定义的可执行文件名
            name='relative_pose_node',  # 给节点起个名字
            output='screen',  # 设置输出到屏幕
            parameters=[{'pose_topic': 'arm/joint1/pose'}],  # 可选的参数传递给节点
            remappings=[('/motive/pose', '/motive/pose')]  # 可以设置话题重命名
        ),

        # 可选：在启动时输出一条日志消息
        LogInfo(
            msg="Starting relative_pose_node with pose topic: arm/joint1/pose"
        ),
    ])
