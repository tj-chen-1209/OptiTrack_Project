#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "geometry_msgs/msg/pose.hpp"
#include "tf2/LinearMath/Quaternion.hpp"
#include "tf2_geometry_msgs/tf2_geometry_msgs.hpp"
#include "moveit/move_group_interface/move_group_interface.h"

class AbsolutePoseNode : public rclcpp::Node
{
public:
    AbsolutePoseNode()
        : Node("absolute_pose_node"),
          initial_pose_set(false)
    {
        // 订阅相对位姿并映射到绝对位姿
        absolute_pose_subscription_ = this->create_subscription<geometry_msgs::msg::PoseStamped>(
            "/relative_pose", 10,
            std::bind(&AbsolutePoseNode::relative_pose_sub, this, std::placeholders::_1));
    }

private:
    void relative_pose_sub(const geometry_msgs::msg::PoseStamped::SharedPtr msg)
    {
        // 获取相对位姿
        geometry_msgs::msg::Pose relative_pose = msg->pose;
        geometry_msgs::msg::Pose absolute_pose = calculate_absolute_pose(relative_pose);
        RCLCPP_INFO(this->get_logger(), "Absolute Position: [%.2f, %.2f, %.2f]",
                    absolute_pose.position.x, absolute_pose.position.y, absolute_pose.position.z);
    }

    geometry_msgs::msg::Pose calculate_absolute_pose(const geometry_msgs::msg::Pose &relative_pose)
    {
        if (!initial_pose_set)
        {
            initial_pose_set = true;
            initial_pose = relative_pose;
            RCLCPP_INFO(this->get_logger(), "Initial pose set.");
            RCLCPP_INFO(this->get_logger(), "Initial Position: [%.2f, %.2f, %.2f]",
                        initial_pose.position.x, initial_pose.position.y, initial_pose.position.z);
            return initial_pose;
        }
        else
        {
            geometry_msgs::msg::Pose absolute_pose;
            absolute_pose.position.x = initial_pose.position.x + relative_pose.position.x;
            absolute_pose.position.y = initial_pose.position.y + relative_pose.position.y;
            absolute_pose.position.z = initial_pose.position.z + relative_pose.position.z;

            tf2::Quaternion initial_q, relative_q, absolute_q;
            tf2::fromMsg(initial_pose.orientation, initial_q);
            tf2::fromMsg(relative_pose.orientation, relative_q);

            absolute_q = initial_q * relative_q; // 绝对旋转为初始旋转与相对旋转的乘积

            absolute_pose.orientation = tf2::toMsg(absolute_q);

            return absolute_pose;
        }
    }
    rclcpp::Subscription<geometry_msgs::msg::PoseStamped>::SharedPtr absolute_pose_subscription_;
    geometry_msgs::msg::Pose initial_pose;
    bool initial_pose_set;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<AbsolutePoseNode>());
    rclcpp::shutdown();
    return 0;
}