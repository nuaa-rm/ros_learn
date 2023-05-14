//
// Created by wenhao on 23-5-9.
//
#include <string>
#include "ros/ros.h"
#include "server/service.h"
#include "client/message.h"


std::map<std::string, ros::Subscriber> clients;

void chatterCallback(const client::message::ConstPtr &msg){
    ROS_INFO("get time: %d from client: %s", msg->time.sec, msg->name.c_str() );
}

bool SeekTopic(server::service::Request &req,
               server::service::Response &res){
    ros::NodeHandle n;
    if (req.status == 1){
        ROS_INFO("service open");
        ros::Subscriber sub = n.subscribe(req.name, 1000, chatterCallback);
        clients.emplace(req.name, sub);
    } else if (req.status == 0){
        clients[req.name].shutdown();
        clients.erase(req.name);
        ROS_INFO("exit...");
    } else {
        ROS_INFO("something wrong happen");
    }

    return true;
}

int main (int argc, char **argv){
    ros::init(argc, argv, "server");
    ROS_INFO("wait for service request");
    ros::NodeHandle n;
    ros::ServiceServer service = n.advertiseService("service", SeekTopic);
    ros::spin();
    return 0;
}