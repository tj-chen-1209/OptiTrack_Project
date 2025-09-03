# optitrack_pose_node.py
import sys
import time
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped

from NatNetClient import NatNetClient
# import DataDescriptions  # 如需打印刚体名字，可解开并看下方“可选：请求模型描述”


class OptiTrackPoseNode(Node):
    def __init__(self):
        super().__init__('opti_track_pose_node')

        # 参数
        self.declare_parameter('clientAddress', '192.168.50.208')  # 本机网卡IP
        self.declare_parameter(
            'serverAddress', '192.168.50.203')  # Motive所在主机IP
        self.declare_parameter('use_multicast', True)

        client_ip = self.get_parameter('clientAddress').value
        server_ip = self.get_parameter('serverAddress').value
        use_mc = self.get_parameter('use_multicast').value

        # ROS publisher
        self.pub = self.create_publisher(PoseStamped, 'opti_track_pose', 10)

        # NatNet 客户端
        self.nn = NatNetClient()
        self.nn.set_client_address(client_ip)
        self.nn.set_server_address(server_ip)
        self.nn.set_use_multicast(use_mc)

        # 刚体回调：每帧每个刚体都会触发
        # 签名: (id, position, rotation)
        self.nn.rigid_body_listener = self._on_rigid_body

        # 启动数据流（'d' = data+command 两线程）
        ok = self.nn.run('d')
        if not ok:
            self.get_logger().error("Failed to start NatNet client.")
            sys.exit(1)

        # 等待连接就绪（样例中也会 sleep 再检查）
        time.sleep(1.0)
        if not self.nn.connected():
            self.get_logger().error(
                "NatNet not connected. Check Motive streaming, IP/ports, multicast mode.")
            sys.exit(2)

        self.get_logger().info("NatNet streaming started and connected.")

        # 【可选】请求并打印模型描述（刚体名/ID），不修改库，仅发送请求
        # self.nn.send_request(self.nn.command_socket,
        #                      self.nn.NAT_REQUEST_MODELDEF, "",
        #                      (server_ip, self.nn.get_command_port()))
        # time.sleep(0.5)  # 模型描述会由库内部解析并打印（库本身不缓存）

    def _on_rigid_body(self, rb_id, position, rotation):
        """ rb_id: int, position: (x,y,z), rotation: (qx,qy,qz,qw) """
        msg = PoseStamped()
        msg.header.stamp = self.get_clock().now().to_msg()   # 正确时间戳
        # 如需区分可改为 f"optitrack/{rb_id}"
        msg.header.frame_id = "optitrack"
        msg.pose.position.x, msg.pose.position.y, msg.pose.position.z = position
        msg.pose.orientation.x, msg.pose.orientation.y, msg.pose.orientation.z, msg.pose.orientation.w = rotation
        self.pub.publish(msg)
        # 建议：高频场景下不要每帧info日志
        # self.get_logger().debug(f"RB {rb_id} pos={position} rot={rotation}")

    def destroy_node(self):
        # 优雅关闭 NatNet 线程/套接字（不改库，直接用现有API）
        try:
            self.nn.shutdown()
        except Exception as e:
            self.get_logger().warn(f"NatNet shutdown exception: {e}")
        super().destroy_node()


def main():
    rclpy.init()
    node = OptiTrackPoseNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()
