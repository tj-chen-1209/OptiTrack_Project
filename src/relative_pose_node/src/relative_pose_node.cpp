#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "geometry_msgs/msg/pose.hpp"
#include "tf2/LinearMath/Quaternion.hpp"
#include "tf2_geometry_msgs/tf2_geometry_msgs.hpp"

#define _TIME_PERIOD_MS 10 // 定时器周期，单位为毫秒

class RelativePoseNode : public rclcpp::Node
{
public:
    RelativePoseNode() : Node("relative_pose_node"), initial_pose_received_(false)
    {
        // 创建订阅者，接收Motive发布的位姿
        pose_subscription_ = this->create_subscription<geometry_msgs::msg::PoseStamped>(
            "arm/joint1/pose", 10,
            std::bind(&RelativePoseNode::pose_callback, this, std::placeholders::_1));

        // 创建发布者，发布相对位姿
        relative_pose_publisher_ = this->create_publisher<geometry_msgs::msg::PoseStamped>(
            "/relative_pose", 10);

        // 创建定时器，每隔指定毫秒获取一次位姿并计算相对位姿
        timer_ = this->create_wall_timer(
            std::chrono::milliseconds(_TIME_PERIOD_MS),
            std::bind(&RelativePoseNode::timer_callback, this));
    }

private:
    // 订阅者回调函数，用于接收位姿消息
    void pose_callback(const geometry_msgs::msg::PoseStamped::SharedPtr msg)
    {
        // 将接收到的位姿保存
        current_pose_ = msg->pose;

        if (!initial_pose_received_)
        {
            // 第一次接收到位姿时设置初始位姿
            initial_pose_ = current_pose_;
            initial_pose_received_ = true;
            RCLCPP_INFO(this->get_logger(), "Initial pose set.");
            RCLCPP_INFO(this->get_logger(), "Initial Position: [%.2f, %.2f, %.2f]", initial_pose_.position.x, initial_pose_.position.y, initial_pose_.position.z);
        }
    }

    // 定时器回调函数，每隔指定时间获取位姿并计算相对位姿
    void timer_callback()
    {
        if (initial_pose_received_)
        {
            // 计算相对位姿
            geometry_msgs::msg::Pose relative_pose = calculate_relative_pose(current_pose_);

            // 构建并发布相对位姿消息
            geometry_msgs::msg::PoseStamped relative_pose_msg;
            relative_pose_msg.header.stamp = this->get_clock()->now();
            relative_pose_msg.header.frame_id = "Relative_pose_link"; // 可以根据需要修改坐标系
            relative_pose_msg.pose = relative_pose;

            relative_pose_publisher_->publish(relative_pose_msg);
        }
        else
        {
            RCLCPP_WARN(this->get_logger(), "Waiting for initial pose...");
        }
    }

    // 计算相对位姿
    geometry_msgs::msg::Pose calculate_relative_pose(const geometry_msgs::msg::Pose &current_pose)
    {
        geometry_msgs::msg::Pose relative_pose;

        // 计算位置差异
        relative_pose.position.x = current_pose.position.x - initial_pose_.position.x;
        relative_pose.position.y = current_pose.position.y - initial_pose_.position.y;
        relative_pose.position.z = current_pose.position.z - initial_pose_.position.z;

        // 计算旋转差异
        tf2::Quaternion initial_q, current_q, relative_q;
        tf2::fromMsg(initial_pose_.orientation, initial_q);
        tf2::fromMsg(current_pose.orientation, current_q);

        // 计算相对旋转
        relative_q = current_q * initial_q.inverse();

        // 转换为消息
        relative_pose.orientation = tf2::toMsg(relative_q);

        return relative_pose;
    }

    // ROS2 订阅者和发布者
    rclcpp::Subscription<geometry_msgs::msg::PoseStamped>::SharedPtr pose_subscription_;
    rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr relative_pose_publisher_;

    // 定时器
    rclcpp::TimerBase::SharedPtr timer_;

    // 初始位姿和当前位姿
    geometry_msgs::msg::Pose initial_pose_;
    geometry_msgs::msg::Pose current_pose_;

    bool initial_pose_received_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<RelativePoseNode>());
    rclcpp::shutdown();
    return 0;
}
