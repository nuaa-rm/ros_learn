#include "ros/ros.h"
#include "std_msgs/String.h"
#include "server/Register.h"
#include "server/Unregister.h"

#include <sstream>
#include <vector>
#include <map>

std::map<std::string, ros::Subscriber> sub_map;

void chatterCallback(const std_msgs::String::ConstPtr& msg){
    ROS_INFO("I heard: [%s]", msg->data.c_str());
}

bool registerClient(server::Register::Request &req,
                    server::Register::Response &res)
{
    std::string client_name = req.name;
    if (sub_map.find(client_name) != sub_map.end()) {
        ROS_INFO("Register Error,Client %s already exists!",
                 client_name.c_str());
        res.success = false;
    } else {
        ros::NodeHandle n;
        std::string topic_name = client_name;

        ros::Subscriber sub =
                n.subscribe<std_msgs::String>(topic_name,
                                              1000,
                                              chatterCallback);
        sub_map[client_name] = sub;
        ROS_INFO("Client %s registered.", client_name.c_str());
        res.success = true;
    }
    return true;
}

bool unregisterClient(server::Unregister::Request &req,
                      server::Unregister::Response &res)
{
    std::string client_name = req.name;
    if (sub_map.find(client_name) != sub_map.end()) {
        sub_map[client_name].shutdown();
        sub_map.erase(client_name);
        ROS_INFO("Client %s unregistered.", client_name.c_str());
        res.success = true;
    } else {
        ROS_INFO("Client %s does not exist!", client_name.c_str());
        res.success = false;
    }
    return true;
}

int main(int argc, char** argv){
    ros::init(argc, argv, "server");
    ros::NodeHandle n;

    ros::ServiceServer register_service =
            n.advertiseService("register", registerClient);
    ros::ServiceServer unregister_service =
            n.advertiseService("unregister", unregisterClient);
    ROS_INFO("Ready to register.");

    ros::spin();

    return 0;
}
