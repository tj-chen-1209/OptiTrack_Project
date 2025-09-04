#include "motive_streamer/motive_streamer.hpp"

#include <chrono>

MotiveStreamer::MotiveStreamer()
    : Node("motive_streamer")
{
    unsigned char ver[4];
    NatNet_GetVersion(ver);
    RCLCPP_INFO(get_logger(), "NatNet SDK Version: %d.%d.%d.%d", ver[0], ver[1], ver[2], ver[3]);

    NatNet_SetLogCallback(MessageHandler);

    natnetClient = new NatNetClient();
    natnetClient->SetFrameReceivedCallback(DataHandler, this);

    declare_parameter("motive_topic_name", "motive_rigid_body_list");
    declare_parameter("pose_pub_topic", "pose_pub");
    declare_parameter("rigid_name", "");
    declare_parameter("local_address", "");
    declare_parameter("motive_address", "");
    declare_parameter("namespace", "");

    pubRigidPose = this->create_publisher<geometry_msgs::msg::PoseStamped>("/" + get_parameter("namespace").as_string() + "/" + get_parameter("pose_pub_topic").as_string(), 10);
    strDefaultLocal = get_parameter("local_address").as_string();
    strDefaultMotive = get_parameter("motive_address").as_string();
    rigid_name = get_parameter("rigid_name").as_string();

    connectParams.connectionType = ConnectionType_Multicast;
    connectParams.localAddress = strDefaultLocal.c_str();
    connectParams.serverAddress = strDefaultMotive.c_str();
    connectParams.connectionType = ConnectionType_Multicast;
    connectParams.serverCommandPort = 1510;
    connectParams.serverDataPort = 1511;
    connectParams.multicastAddress = discoveredMulticastGroupAddr;
    int result = ConnectClient();
    if (result != ErrorCode_OK)
    {
        RCLCPP_ERROR(get_logger(), "Error initializing client. See log for details. Exiting.");
        return;
    }
    else
    {
        RCLCPP_INFO(get_logger(), "Client initialized and ready.");
    }

    if (!UpdateDataDescriptions())
    {
        RCLCPP_WARN(get_logger(), "Unable to retrieve Data Descriptions from Motive.");
    }
    RCLCPP_INFO(get_logger(), "Client is connected to server and listening for data...");
    try
    {
        rigid_id = assetNameToAssetID.at(rigid_name);
        RCLCPP_INFO(get_logger(), "rigid_name: %s, rigid_id: %d", rigid_name.c_str(), rigid_id);
    }
    catch (const std::exception &e)
    {
        RCLCPP_ERROR(get_logger(), "No rigid body named %s", rigid_name.c_str());
        throw e;
    }

    initOk = true;
}
MotiveStreamer::~MotiveStreamer()
{
    if (natnetClient)
    {
        natnetClient->Disconnect();
        delete natnetClient;
        natnetClient = nullptr;
    }
    if (dataDefs)
    {
        NatNet_FreeDescriptions(dataDefs);
        dataDefs = nullptr;
    }
}

void NATNET_CALLCONV MotiveStreamer::DataHandler(sFrameOfMocapData *data, void *pUserData)
{
    std::chrono::steady_clock::time_point timepoint1 = std::chrono::steady_clock::now();
    MotiveStreamer *pStreamer = (MotiveStreamer *)pUserData;
    NatNetClient *pClient = pStreamer->natnetClient;
    if (!pStreamer || !pClient)
        return;

    geometry_msgs::msg::PoseStamped poseStampedMsg;
    poseStampedMsg.header.stamp = rclcpp::Clock().now();
    poseStampedMsg.header.frame_id = "base_link";
    for (int i = 0; i < data->nRigidBodies; i++)
    {

        if (data->RigidBodies[i].ID == pStreamer->rigid_id)
        {
            poseStampedMsg.pose.position.x = data->RigidBodies[i].x;
            poseStampedMsg.pose.position.y = data->RigidBodies[i].y;
            poseStampedMsg.pose.position.z = data->RigidBodies[i].z;
            poseStampedMsg.pose.orientation.x = data->RigidBodies[i].qx;
            poseStampedMsg.pose.orientation.y = data->RigidBodies[i].qy;
            poseStampedMsg.pose.orientation.z = data->RigidBodies[i].qz;
            poseStampedMsg.pose.orientation.w = data->RigidBodies[i].qw;
        }
    }

    pStreamer->pubRigidPose->publish(poseStampedMsg);
    std::chrono::steady_clock::time_point timepoint2 = std::chrono::steady_clock::now();
    std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(timepoint2 - timepoint1);
    RCLCPP_INFO(pStreamer->get_logger(), "time_span: %f", time_span.count());
}

void NATNET_CALLCONV MotiveStreamer::MessageHandler(Verbosity msgType, const char *msg)
{
    static auto logger = rclcpp::get_logger("NatNetLib");
    switch (msgType)
    {
    case Verbosity_Debug:
        RCLCPP_DEBUG(logger, "%s", msg);
        break;
    case Verbosity_Info:
        RCLCPP_INFO(logger, "%s", msg);
        break;
    case Verbosity_Warning:
        RCLCPP_WARN(logger, "%s", msg);
        break;
    case Verbosity_Error:
        RCLCPP_ERROR(logger, "%s", msg);
        break;
    default:
        break;
    }
}

int MotiveStreamer::ConnectClient()
{
    natnetClient->Disconnect();
    int ret = natnetClient->Connect(connectParams);
    if (ret != ErrorCode_OK)
    {
        RCLCPP_ERROR(get_logger(), "Unable to connect to server.  Error code: %d. Exiting.", ret);
        return ErrorCode_Internal;
    }
    return ret;
}

bool MotiveStreamer::UpdateDataDescriptions()
{
    if (dataDefs)
    {
        NatNet_FreeDescriptions(dataDefs);
    }
    int ret = natnetClient->GetDataDescriptionList(&dataDefs);
    if (ret != ErrorCode_OK || !dataDefs)
    {
        return false;
    }
    UpdateDataToDescriptionMaps(dataDefs);
    return true;
}

void MotiveStreamer::UpdateDataToDescriptionMaps(sDataDescriptions *pDataDefs)
{
    assetIDtoAssetDescOrder.clear();
    assetIDtoAssetName.clear();
    int assetID = 0;
    std::string assetName = "";
    int index = 0;
    if (pDataDefs == nullptr || pDataDefs->nDataDescriptions <= 0)
        return;

    for (int i = 0; i < pDataDefs->nDataDescriptions; i++)
    {
        assetID = -1;
        assetName = "";
        switch (pDataDefs->arrDataDescriptions[i].type)
        {
        case Descriptor_RigidBody:
        {
            sRigidBodyDescription *pRB = pDataDefs->arrDataDescriptions[i].Data.RigidBodyDescription;
            assetID = pRB->ID;
            assetName = std::string(pRB->szName);
            break;
        }
        case Descriptor_Skeleton:
        {
            sSkeletonDescription *pSK = pDataDefs->arrDataDescriptions[i].Data.SkeletonDescription;
            assetID = pSK->skeletonID;
            assetName = std::string(pSK->szName);
            break;
        }
        case Descriptor_MarkerSet:
        {
            index++;
            continue;
        }
        case Descriptor_ForcePlate:
        {
            sForcePlateDescription *pDesc = pDataDefs->arrDataDescriptions[i].Data.ForcePlateDescription;
            assetID = pDesc->ID;
            assetName = pDesc->strSerialNo;
            break;
        }
        case Descriptor_Device:
        {
            sDeviceDescription *pDesc = pDataDefs->arrDataDescriptions[i].Data.DeviceDescription;
            assetID = pDesc->ID;
            assetName = std::string(pDesc->strName);
            break;
        }
        case Descriptor_Camera:
        {
            continue;
        }
        case Descriptor_Asset:
        {
            sAssetDescription *pDesc = pDataDefs->arrDataDescriptions[i].Data.AssetDescription;
            assetID = pDesc->AssetID;
            assetName = std::string(pDesc->szName);
            break;
        }
        }
        if (assetID == -1)
        {
            RCLCPP_WARN(get_logger(), "Unknown asset type.");
        }
        else
        {
            std::pair<std::map<int, std::string>::iterator, bool> insertResult;
            insertResult = assetIDtoAssetName.insert(std::make_pair(assetID, assetName));
            // update
            assetNameToAssetID.insert(std::make_pair(assetName, assetID));
            if (!insertResult.second)
            {
                RCLCPP_WARN(get_logger(), "Duplicate asset ID detected: %d", assetID);
            }
        }

        if (assetID != -1)
        {
            std::pair<std::map<int, int>::iterator, bool> insertResult;
            insertResult = assetIDtoAssetDescOrder.insert(std::make_pair(assetID, index++));
            if (!insertResult.second)
            {
                RCLCPP_WARN(get_logger(), "Duplicate asset ID detected: %d", assetID);
            }
        }
    }
}
