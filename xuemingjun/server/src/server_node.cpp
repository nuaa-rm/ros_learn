//
// Created by mijiao on 23-1-28.
//
#include <client/message.h>
#include <server/service.h>
#include <ros/ros.h>
#include <string>
#include <unordered_map>


std::unordered_map<std::string, ros::Subscriber> sublist;

void topicCallBack(const client::message::ConstPtr &msg) {
    ROS_INFO("From %s received: %d.%d", msg->name.c_str(), msg->time.sec,
             msg->time.nsec);
}

bool serviceCallback(server::serviceRequest &req, server::serviceResponse &) {
    ros::NodeHandle nh;
    if (req.id == 0) {
        sublist.emplace(req.name, nh.subscribe(req.name, 1000, topicCallBack));
    } else if (req.id == 1) {
        sublist[req.name].shutdown();
        sublist.erase(req.name);
        ROS_INFO("Client %s exited", req.name.data());
    } else {
        ROS_WARN("From %s received unknown id %d", req.name.c_str(), req.id);
    }
    return true;
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "service");
    ros::NodeHandle nh;
    ros::ServiceServer server = nh.advertiseService("service", serviceCallback);
    ros::spin();
    return 0;
}
