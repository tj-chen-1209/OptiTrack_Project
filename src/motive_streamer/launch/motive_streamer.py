from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch.actions import IncludeLaunchDescription
from launch_ros.substitutions import FindPackageShare
from launch.substitutions import PathJoinSubstitution
def generate_launch_description():
    return LaunchDescription([
    DeclareLaunchArgument('motive_topic_name', default_value='motive_rigid_body_list'),
    DeclareLaunchArgument('local_address', default_value='192.168.50.208'),
    DeclareLaunchArgument('motive_address', default_value='192.168.50.203'),
    DeclareLaunchArgument("pose_pub_topic",default_value="vision_pose/pose"),
    DeclareLaunchArgument("rigid_name", default_value="uav1"),

    Node(
        package='motive_streamer',
        executable='motive_streamer_node',
        name='motive_streamer',
        parameters=[
            {
                "motive_topic_name":LaunchConfiguration("motive_topic_name"),
                "local_address":LaunchConfiguration('local_address'),
                "motive_address":LaunchConfiguration('motive_address'),
                "namespace": LaunchConfiguration("rigid_name"),
                "pose_pub_topic":LaunchConfiguration("pose_pub_topic"),
                "rigid_name":LaunchConfiguration("rigid_name"),
            }
        ]
    ),
    # IncludeLaunchDescription(
    #         PathJoinSubstitution([FindPackageShare("mavros"),'launch','px4.launch']),
    #         launch_arguments={'namespace': LaunchConfiguration("rigid_name")}.items()
    #     ),
    
    
    ])
