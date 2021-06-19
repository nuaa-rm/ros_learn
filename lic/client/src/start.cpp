//Copyright 2021 Lic
#include <ros/ros.h>
#include "client/name.h"
#include "client/topic_name.h"

void nameInfoCallback(const client::name::ConstPtr& msg) {
    ROS_INFO("Subcriber Info: name:%s", msg->name.c_str());
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "start");
    ros::NodeHandle n;
    ros::service::waitForService("/show_topic");
    ros::ServiceClient client_name = 
    n.serviceClient<client::topic_name>("/show_topic");
    client::topic_name srv;
    srv.request.name = "client0";
    ROS_INFO("Call service : %s", srv.request.name.c_str());
    client_name.call(srv);
    ROS_INFO("Result : %s", srv.response.result.c_str());
    ROS_INFO("Info:%s ", srv.response.result.c_str());
    ros::Publisher name_info_pub = 
    n.advertise<client::name>(srv.response.result.c_str(), 10);
    ros::Rate loop_rate(1);
    while (ros::ok()) {
    	client::name name_msg;
	name_msg.name = "client0";
	name_msg.tim = ros::Time::now();
	name_info_pub.publish(name_msg);
	ROS_INFO("Publish Name Info:%s", name_msg.name.c_str());
	loop_rate.sleep();
    }
    return 0;
}

