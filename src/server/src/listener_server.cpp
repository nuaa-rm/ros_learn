//
// Created by wenhao on 23-5-9.
//
#include "ros/ros.h"
#include "server/service.h"
#include "client/message.h"
#include <string>

ros::Subscriber sub;

void chatterCallback(const client::message::ConstPtr &msg){
    ROS_INFO("%d %s", msg->time.sec, msg->name.c_str() );
}

bool SeekTopic(server::service::Request &req,
               server::service::Response &res){
    ros::NodeHandle n;
    ROS_INFO("service open");
    sub = n.subscribe(req.name, 1000, chatterCallback);

    return true;
}

int main (int argc, char **argv){
    ros::init(argc, argv, "server");
    ros::NodeHandle n;
    ros::ServiceServer service = n.advertiseService("service", SeekTopic);

    ros::spin();

    return 0;
}