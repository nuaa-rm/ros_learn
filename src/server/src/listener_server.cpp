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
    if (req.status == 1){
        ROS_INFO("service open");
        sub = n.subscribe(req.name, 1000, chatterCallback);
    } else if (req.status == 0){
        sub.shutdown();
        ROS_INFO("exit...");
    } else {
        ROS_INFO("something wrong happen");
    }

    return true;
}

int main (int argc, char **argv){
    ros::init(argc, argv, "server");
    ros::NodeHandle n;
    ros::ServiceServer service = n.advertiseService("service", SeekTopic);
    ROS_INFO("wait for service request")
    ros::spin();

    return 0;
}