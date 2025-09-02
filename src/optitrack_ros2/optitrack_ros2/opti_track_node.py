# TODO： 实现一个ROS2节点，订阅OptiTrack数据并发布到一个话题
# from NatNetClient import NatNetClient  # 假设已经正确导入你的NatNetClient
# import os
# import sys
# from geometry_msgs.msg import Pose
# from rclpy.node import Node
# import rclpy
# from threading import Thread

# 添加NatNet SDK的路径
import types
import time
import sys
import os
from geometry_msgs.msg import PoseStamped
from rclpy.node import Node
import rclpy
current_dir = os.path.dirname(__file__)
relative_path = os.path.join(
    current_dir, '..', '..', 'NatNet_SDK_4.3_ubuntu', 'samples', 'PythonClient')
sys.path.append(relative_path)


# class OptiTrackNode(Node):
#     def __init__(self):
#         super().__init__('opti_track_node')
#         self.publisher = self.create_publisher(Pose, 'opti_track_pose', 10)

#         # 设置NatNet客户端并开始接收数据
#         self.client = NatNetClient()
#         self.client.set_client_address('127.0.0.1')  # 本地IP地址
#         self.client.set_server_address('127.0.0.1')  # 服务器IP地址

#         self.position_queue = []  # 缓存接收到的数据

#         try:
#             self.client.rigid_body_listener = self.receive_rigid_body_frame
#             self.client_thread = Thread(target=self.client.run, args=(None,))
#             self.client_thread.start()
#         except Exception as e:
#             self.get_logger().error(f"NatNetClient连接失败: {e}")
#             rclpy.shutdown()  # 这里使用rclpy.shutdown()来退出

#         # 定时器控制发布频率（每100ms发布一次数据）
#         self.timer = self.create_timer(0.1, self.timer_callback)

#     def receive_rigid_body_frame(self, new_id, position, rotation):
#         # 将数据放入队列，供定时器发布
#         self.position_queue.append((position, rotation))

#     def timer_callback(self):
#         if self.position_queue:
#             position, rotation = self.position_queue.pop(0)

#             # 创建并发布ROS2消息
#             pose_msg = Pose()
#             pose_msg.position.x = position[0]
#             pose_msg.position.y = position[1]
#             pose_msg.position.z = position[2]
#             pose_msg.orientation.x = rotation[0]
#             pose_msg.orientation.y = rotation[1]
#             pose_msg.orientation.z = rotation[2]
#             pose_msg.orientation.w = rotation[3]

#             # 发布到ROS2话题
#             self.publisher.publish(pose_msg)
#             self.get_logger().info(f"Published Pose: {pose_msg}")

#     def destroy_node(self):
#         # 确保ROS2节点关闭时也会终止NatNetClient线程
#         self.client.stop()
#         self.client_thread.join()  # 等待线程结束
#         super().destroy_node()


# def main():
#     rclpy.init()
#     node = OptiTrackNode()

#     try:
#         rclpy.spin(node)
#     except KeyboardInterrupt:
#         pass
#     finally:
#         node.destroy_node()
#         rclpy.shutdown()  # 这里使用rclpy.shutdown()来优雅关闭


# if __name__ == '__main__':
#     main()
#!/usr/bin/env python3
# uav1_pose_pub.py
# ROS 2 node: publishes geometry_msgs/PoseStamped for rigid body by NAME (default "uav1").


try:
    from NatNetClient import NatNetClient
except ImportError:
    sys.path.append(os.path.dirname(__file__))
    from NatNetClient import NatNetClient  # type: ignore


class OptiTrackNode(Node):
    def __init__(self):
        super().__init__('opti_track_node')

        # Params
        self.declare_parameter('server_address', '192.168.50.203')
        self.declare_parameter('client_address', '192.168.50.208')
        self.declare_parameter('use_multicast', True)
        self.declare_parameter('rb_name', 'uav1')
        self.declare_parameter('scale', 1.0)   # mm->m: set 0.001 if needed
        self.declare_parameter('frame_id', 'mocap_world')
        self.declare_parameter('topic', 'opti_track_pose')

        self.server_address = self.get_parameter('server_address').value
        self.client_address = self.get_parameter('client_address').value
        self.use_multicast = self.get_parameter('use_multicast').value
        self.rb_name = self.get_parameter('rb_name').value
        self.scale = float(self.get_parameter('scale').value)
        self.frame_id = self.get_parameter('frame_id').value
        topic = self.get_parameter('topic').value

        self.pub = self.create_publisher(PoseStamped, topic, 10)

        # NatNet
        self.nn = NatNetClient()
        self.nn.set_server_address(self.server_address)
        self.nn.set_client_address(self.client_address)
        self.nn.set_use_multicast(self.use_multicast)

        # 捕获 DataDescriptions
        self.nn.last_data_descriptions = None  # type: ignore[attr-defined]
        orig_unpack = getattr(
            self.nn, "_NatNetClient__unpack_data_descriptions")

        def _wrap_unpack(data, packet_size, major, minor):
            offset, dd = orig_unpack(data, packet_size, major, minor)
            self.nn.last_data_descriptions = dd
            return offset, dd
        setattr(self.nn, "_NatNetClient__unpack_data_descriptions",
                types.MethodType(_wrap_unpack, self.nn))

        ok = self.nn.run('d')
        if not ok:
            self.get_logger().error('Failed to start NatNet client.')
            return

        # 请求模型描述并解析名称→ID
        try:
            self.nn.send_request(self.nn.command_socket, self.nn.NAT_REQUEST_MODELDEF, "",
                                 (self.nn.server_ip_address, self.nn.command_port))
        except Exception as e:
            self.get_logger().warn(f'Failed to request model definitions: {e}')

        self.rb_id = None
        t0 = time.time()
        while getattr(self.nn, "last_data_descriptions", None) is None and (time.time() - t0) < 5.0:
            rclpy.spin_once(self, timeout_sec=0.05)

        dd = getattr(self.nn, "last_data_descriptions", None)
        if dd is not None:
            target = self.rb_name.lower()
            for rb_desc in dd.rigid_body_list:
                if getattr(rb_desc, "sz_name", "").lower() == target:
                    self.rb_id = rb_desc.id_num
                    break
        if self.rb_id is None:
            self.get_logger().warn(
                f'Rigid body "{self.rb_name}" not found; will publish the first seen rigid body.')

        def on_rb(new_id, pos, rot):
            if self.rb_id is None:
                self.rb_id = int(new_id)
                self.get_logger().info(
                    f'Using first seen rigid body ID={self.rb_id}')
            if int(new_id) != int(self.rb_id):
                return

            x, y, z = pos
            qx, qy, qz, qw = rot
            x *= self.scale
            y *= self.scale
            z *= self.scale

            msg = PoseStamped()
            msg.header.stamp = self.get_clock().now().to_msg()
            msg.header.frame_id = self.frame_id
            msg.pose.position.x = float(x)
            msg.pose.position.y = float(y)
            msg.pose.position.z = float(z)
            msg.pose.orientation.x = float(qx)
            msg.pose.orientation.y = float(qy)
            msg.pose.orientation.z = float(qz)
            msg.pose.orientation.w = float(qw)
            self.pub.publish(msg)

        self.nn.rigid_body_listener = on_rb
        self.get_logger().info(
            f'Publishing {self.rb_name} pose on "{topic}" (frame_id="{self.frame_id}").')

    def destroy_node(self):
        try:
            self.nn.shutdown()
        except Exception:
            pass
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
        rclpy.shutdown()


if __name__ == "__main__":
    main()
