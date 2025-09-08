// TODO : This example is currently not working. It needs to be fixed. get_current_pose() returns a zero pose. 需要修复
#include <memory>
#include <rclcpp/rclcpp.hpp>
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "geometry_msgs/msg/pose.hpp"
#include "tf2/LinearMath/Quaternion.hpp"
#include "tf2_geometry_msgs/tf2_geometry_msgs.hpp"
#include "moveit/move_group_interface/move_group_interface.h"

// int main(int argc, char *argv[])
// {
//     // Initialize ROS and create the Node
//     rclcpp::init(argc, argv);
//     auto const node = std::make_shared<rclcpp::Node>(
//         "hello_moveit",
//         rclcpp::NodeOptions().automatically_declare_parameters_from_overrides(true));

//     // Create a ROS logger
//     auto const logger = rclcpp::get_logger("hello_moveit");

//     // Next step goes here
//     // Create the MoveIt MoveGroup Interface
//     using moveit::planning_interface::MoveGroupInterface;
//     auto move_group_interface = MoveGroupInterface(node, "panda_arm");

//     // Set a target Pose
//     auto const target_pose = []
//     {
//         geometry_msgs::msg::Pose msg;
//         msg.orientation.w = 1.0;
//         msg.position.x = 0.28;
//         msg.position.y = -0.2;
//         msg.position.z = 0.5;
//         return msg;
//     }();
//     move_group_interface.setPoseTarget(target_pose);

//     // Create a plan to that target pose
//     auto const [success, plan] = [&move_group_interface]
//     {
//         moveit::planning_interface::MoveGroupInterface::Plan msg;
//         auto const ok = static_cast<bool>(move_group_interface.plan(msg));
//         return std::make_pair(ok, msg);
//     }();

//     // Execute the plan
//     if (success)
//     {
//         move_group_interface.execute(plan);
//     }
//     else
//     {
//         RCLCPP_ERROR(logger, "Planning failed!");
//     }
//     // Shutdown ROS
//     rclcpp::shutdown();
//     return 0;
// }

class PandaArmController : public rclcpp::Node
{
public:
    PandaArmController() : Node("hello_moveit"),
                           initial_pose_set(false)
    {
        // 构造函数中不使用 shared_from_this()
    }

    void setupMoveGroup()
    {
        // 在成员函数中使用 shared_from_this() 创建 MoveGroup
        move_group_ = std::make_shared<moveit::planning_interface::MoveGroupInterface>(shared_from_this(), "panda_arm");

        // 设置目标位姿
        absolute_pose_subscription_ = this->create_subscription<geometry_msgs::msg::PoseStamped>(
            "/relative_pose", 10,
            std::bind(&PandaArmController::relative_pose_sub, this, std::placeholders::_1));
    }

private:
    moveit::planning_interface::MoveGroupInterface::Plan plan_;
    geometry_msgs::msg::Pose target_pose_;
    std::shared_ptr<moveit::planning_interface::MoveGroupInterface> move_group_;
    rclcpp::Subscription<geometry_msgs::msg::PoseStamped>::SharedPtr absolute_pose_subscription_;
    geometry_msgs::msg::Pose initial_pose;
    bool initial_pose_set;

    void relative_pose_sub(const geometry_msgs::msg::PoseStamped::SharedPtr msg)
    {
        // 获取相对位姿
        geometry_msgs::msg::Pose relative_pose = msg->pose;
        geometry_msgs::msg::Pose absolute_pose = calculate_absolute_pose(relative_pose);
        RCLCPP_INFO(this->get_logger(), "Absolute Position: [%.2f, %.2f, %.2f]",
                    absolute_pose.position.x, absolute_pose.position.y, absolute_pose.position.z);
        move_group_->setPoseTarget(absolute_pose);
        planAndExecute();
    }

    geometry_msgs::msg::Pose calculate_absolute_pose(const geometry_msgs::msg::Pose &relative_pose)
    {
        // Todo: 需要考虑坐标系的转换，目前假设初始位姿和相对位姿在同一坐标系下
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
    // // 创建目标位姿
    // geometry_msgs::msg::Pose createTargetPose()
    // {
    //     geometry_msgs::msg::Pose msg;
    //     msg.orientation.w = 1.0;
    //     msg.position.x = 0.28;
    //     msg.position.y = -0.2;
    //     msg.position.z = 0.5;
    //     return msg;
    // }

    // 规划并执行运动
    void planAndExecute()
    {
        RCLCPP_INFO(this->get_logger(), "Planning to target pose...");

        // 创建规划消息
        moveit::planning_interface::MoveGroupInterface::Plan plan;
        moveit::core::MoveItErrorCode error_code = move_group_->plan(plan);

        // 判断规划是否成功
        if (error_code == moveit::core::MoveItErrorCode::SUCCESS)
        {
            RCLCPP_INFO(this->get_logger(), "Planning successful, executing...");
            move_group_->execute(plan);
        }
        else
        {
            RCLCPP_ERROR(this->get_logger(), "Planning failed with error code: %d", error_code.val);
        }
    }
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<PandaArmController>();
    node->setupMoveGroup(); // 在节点初始化后，调用 setupMoveGroup() 来设置 MoveGroup
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}