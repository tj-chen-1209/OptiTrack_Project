#!/usr/bin/env python3
import sys
import time
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped

from NatNetClient import NatNetClient


class OptiTrackPoseMulticastNode(Node):
    """
    Multicast-only OptiTrack (NatNet) -> ROS2 PoseStamped publisher with lightweight diagnostics.
    Uses ONLY the existing NatNetClient APIs; no source changes required.
    """

    def __init__(self):
        super().__init__('opti_track_pose_multicast_node')

        # ---- Parameters (multicast enforced) ----
        # local NIC IP (this machine)
        self.declare_parameter('clientAddress', '192.168.50.208')
        self.declare_parameter(
            'serverAddress', '192.168.50.203')  # Motive host IP
        # TF frame for PoseStamped
        self.declare_parameter('frame_id', 'optitrack')
        # user asked for multicast; we enforce True
        use_multicast = True

        client_ip = self.get_parameter('clientAddress').value
        server_ip = self.get_parameter('serverAddress').value
        frame_id = self.get_parameter('frame_id').value

        # ---- ROS publisher ----
        self.pub = self.create_publisher(PoseStamped, 'opti_track_pose', 10)

        # ---- NatNet client ----
        self.nn = NatNetClient()
        self.nn.set_client_address(client_ip)
        self.nn.set_server_address(server_ip)
        self.nn.set_use_multicast(use_multicast)

        # Increase verbosity inside NatNet client if method exists (fallback to attribute)
        try:
            # 0=quiet, 1=print modeldefs/frames summary
            self.nn.set_print_level(1)
        except Exception:
            try:
                self.nn.print_level = 1
            except Exception:
                pass

        # Rigid body callback (fires once per rigid body per frame)
        self.nn.rigid_body_listener = self._on_rigid_body

        # Optional: frame callback to confirm data flow health (fires once per frame)
        self._frames_this_tick = 0
        self._rb_msgs_this_tick = 0
        self.nn.new_frame_listener = self._on_new_frame

        # Start command+data threads
        ok = self.nn.run('d')
        if not ok:
            self.get_logger().error("Failed to start NatNet client (threads).")
            sys.exit(1)

        # Wait briefly for SERVERINFO to arrive, then verify connected
        t0 = time.time()
        while time.time() - t0 < 2.0:
            if self.nn.connected():
                break
            time.sleep(0.05)

        if not self.nn.connected():
            self.get_logger().error(
                "NatNet not connected. Ensure Motive Streaming is ON and Multicast matches.")
            sys.exit(2)

        # Request model definitions (library will print them when print_level>0)
        try:
            self.nn.send_request(self.nn.command_socket,
                                 self.nn.NAT_REQUEST_MODELDEF, "",
                                 (server_ip, self.nn.get_command_port()))
            self.get_logger().info("Requested model definitions via NAT_REQUEST_MODELDEF.")
        except Exception as e:
            self.get_logger().warn(f"Requesting model definitions failed: {e}")

        self.get_logger().info(f"NatNet connected (multicast). Publishing PoseStamped on /opti_track_pose "
                               f"[frame_id={frame_id}].")

        # 1 Hz diagnostics
        self._frame_id_base = frame_id
        self._diag_timer = self.create_timer(1.0, self._diag_tick)

    # ---------- NatNet callbacks ----------
    def _on_new_frame(self, data_dict):
        # Count frames per second for diagnostics
        try:
            self._frames_this_tick += 1
        except Exception:
            pass

    def _on_rigid_body(self, rb_id, position, rotation):
        # Publish PoseStamped; write ID into frame_id suffix for easy disambiguation
        msg = PoseStamped()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = f"{self._frame_id_base}/{rb_id}" if self._frame_id_base else str(
            rb_id)
        msg.pose.position.x, msg.pose.position.y, msg.pose.position.z = position
        msg.pose.orientation.x, msg.pose.orientation.y, msg.pose.orientation.z, msg.pose.orientation.w = rotation
        self.pub.publish(msg)

        # diagnostics counter
        try:
            self._rb_msgs_this_tick += 1
        except Exception:
            pass

    # ---------- Diagnostics ----------
    def _diag_tick(self):
        frames = self._frames_this_tick
        rbs = self._rb_msgs_this_tick
        self._frames_this_tick = 0
        self._rb_msgs_this_tick = 0
        # If frames>0 but rbs==0 => streaming works but no rigid body is tracked
        if frames == 0:
            self.get_logger().warn(
                "No mocap frames received in the last second (check network/multicast).")
        elif rbs == 0:
            self.get_logger().warn(
                "Frames received but no rigid bodies tracked (check Motive Rigid Bodies & visibility).")
        else:
            self.get_logger().debug(
                f"frames/s={frames}, rigid_body_msgs/s={rbs}")

    # ---------- Cleanup ----------
    def destroy_node(self):
        try:
            self.nn.shutdown()  # close sockets and join threads
        except Exception as e:
            self.get_logger().warn(f"NatNet shutdown exception: {e}")
        super().destroy_node()


def main():
    rclpy.init()
    node = OptiTrackPoseMulticastNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()
