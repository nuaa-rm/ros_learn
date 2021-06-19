// Copyright 2021 Lic
#include <ros/ros.h>
#include <string>
#include "client/name.h"
#include "client/topic_name.h"

using namespace string;

int num_of_sub = 0;
ros::Subscriber name_info_sub[100];

void nameInfoCallback(const client::name::ConstPtr& msg) {
    ROS_INFO("Subcriber Info: name:%s Time:%lld",
    msg->name.c_str() , msg->tim.sec);
}

bool topicCallback(const client::topic_name::Request
&req, const client::topic_name::Response &res) {
    string aim_topic;
    ROS_INFO("Topic: name:%s  ", req.name.c_str());
    aim_topic = "/"+req.name;
    res.result = aim_topic;
    ros::NodeHandle n;
    name_info_sub[num_of_sub++] =
    n.subscribe<client::name>(aim_topic.c_str(),
    10, nameInfoCallback);
    return true;
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "start_server");
    ros::NodeHandle n;
    ros::ServiceServer client_name =
    n.advertiseService("/show_topic", topicCallback);
    ros::spin();
    return 0;
}

