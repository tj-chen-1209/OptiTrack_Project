# pragma once

#include <map>
#include <string>
#include <vector>
#include <deque>
#include <thread>
#include <mutex>
#include <memory>

#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>
#include <motive_streamer/msg/motive_rigid_body.hpp>
#include <motive_streamer/msg/motive_rigid_body_list.hpp>

#include "NatNetTypes.h"
#include "NatNetRequests.h"
#include "NatNetClient.h"
#include "NatNetCAPI.h"

class MotiveStreamer : public rclcpp::Node
{
public:
    MotiveStreamer();
    ~MotiveStreamer();

    static void NATNET_CALLCONV DataHandler(sFrameOfMocapData* data, void* pUserData);
    static void NATNET_CALLCONV MessageHandler(Verbosity msgType, const char* msg);
    
    int ConnectClient();
    bool UpdateDataDescriptions();
    void UpdateDataToDescriptionMaps(sDataDescriptions* pDataDefs);

    NatNetClient* natnetClient = nullptr;
    sNatNetClientConnectParams connectParams;
    sServerDescription serverDescription;
    std::vector<sNatNetDiscoveredServer> discoveredServers;
    char discoveredMulticastGroupAddr[kNatNetIpv4AddrStrLenMax] = NATNET_DEFAULT_MULTICAST_ADDRESS;
    sDataDescriptions* dataDefs = nullptr;
    std::map<int, int> assetIDtoAssetDescOrder;
    std::map<int, std::string> assetIDtoAssetName;
    std::map<std::string, int> assetNameToAssetID;
    std::string strDefaultLocal = "";
    std::string strDefaultMotive = "";

    sFrameOfMocapData currentFrame;

    bool initOk = false;

    rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr pubRigidPose;
    int32_t rigid_id;
    std::string rigid_name;
};
