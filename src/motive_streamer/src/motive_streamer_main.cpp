#include <rclcpp/rclcpp.hpp>
#include "motive_streamer/motive_streamer.hpp"

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    // rclcpp::executors::MultiThreadedExecutor exec;

    auto node = std::make_shared<MotiveStreamer>();

    // while (rclcpp::ok() && node->initOk) {
    //     // node->SpinTask();
    //     rclcpp::spin_some(node);
    // }
    rclcpp::spin(node);
    
    // exec.add_node(node);

    rclcpp::shutdown();
    return 0;
}