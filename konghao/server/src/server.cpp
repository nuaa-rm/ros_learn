//
// Created by andykong on 22-6-23.
//
#include "ros/ros.h"
#include "std_msgs/Header.h"
#include <client/Num.h>
#include <client/Print.h>

void chatterCallback(const client::print::Request &req,
                     const client::print::Response &res)
{
    ros::NodeHandle n;
    ROS_INFO("name:%s", req.name.c_str());
    res.result = "OK";
    ros::Subscriber client_topic_pub = n.subscribe<std_msgs::Header>("head", 10, show_data);
}


void print(const std_msgs::Header::ConstPtr& msg) {
    ROS_INFO("name:%s,time:%d", msg->frame_id.c_str(), msg->stamp.sec);
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "server");
    ros::NodeHandle n;
    ros::ServiceServer server = n.advertiseService("server", chatterCallback);
    ros::Subscriber sub = n.subscribe("chatter", 1000, print);
    ros::spin();

    return 0;
}