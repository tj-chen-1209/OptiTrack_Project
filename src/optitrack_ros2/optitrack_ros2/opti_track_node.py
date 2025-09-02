# TODO： 实现一个ROS2节点，订阅OptiTrack数据并发布到一个话题
import os
import sys
from geometry_msgs.msg import Pose
from rclpy.node import Node
import rclpy
from threading import Thread

# 添加NatNet SDK的路径
current_dir = os.path.dirname(__file__)
relative_path = os.path.join(current_dir, '..', '..', 'NatNet_SDK_4.3_ubuntu', 'samples', 'PythonClient')
sys.path.append(relative_path)

from NatNetClient import NatNetClient  # 假设已经正确导入你的NatNetClient

class OptiTrackNode(Node):
    def __init__(self):
        super().__init__('opti_track_node')
        self.publisher = self.create_publisher(Pose, 'opti_track_pose', 10)

        # 设置NatNet客户端并开始接收数据
        self.client = NatNetClient()
        self.client.set_client_address('127.0.0.1')  # 本地IP地址
        self.client.set_server_address('127.0.0.1')  # 服务器IP地址
        
        self.position_queue = []  # 缓存接收到的数据

        try:
            self.client.rigid_body_listener = self.receive_rigid_body_frame
            self.client_thread = Thread(target=self.client.run, args=(None,))
            self.client_thread.start()
        except Exception as e:
            self.get_logger().error(f"NatNetClient连接失败: {e}")
            rclpy.shutdown()  # 这里使用rclpy.shutdown()来退出

        # 定时器控制发布频率（每100ms发布一次数据）
        self.timer = self.create_timer(0.1, self.timer_callback)

    def receive_rigid_body_frame(self, new_id, position, rotation):
        # 将数据放入队列，供定时器发布
        self.position_queue.append((position, rotation))

    def timer_callback(self):
        if self.position_queue:
            position, rotation = self.position_queue.pop(0)

            # 创建并发布ROS2消息
            pose_msg = Pose()
            pose_msg.position.x = position[0]
            pose_msg.position.y = position[1]
            pose_msg.position.z = position[2]
            pose_msg.orientation.x = rotation[0]
            pose_msg.orientation.y = rotation[1]
            pose_msg.orientation.z = rotation[2]
            pose_msg.orientation.w = rotation[3]

            # 发布到ROS2话题
            self.publisher.publish(pose_msg)
            self.get_logger().info(f"Published Pose: {pose_msg}")

    def destroy_node(self):
        # 确保ROS2节点关闭时也会终止NatNetClient线程
        self.client.stop()
        self.client_thread.join()  # 等待线程结束
        super().destroy_node()

def main():
    rclpy.init()
    node = OptiTrackNode()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()  # 这里使用rclpy.shutdown()来优雅关闭

if __name__ == '__main__':
    main()

