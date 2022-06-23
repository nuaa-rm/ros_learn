//
// Created by andykong on 22-6-23.
//
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <client/num.h>
#include <client/print.h>
#include <sstream>

#include <ros/time.h>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "client");
    ros::NodeHandle n;
    ros::ServiceClient sclient = n.serviceClient<client::show>("show_name");
    client::print srv;
    srv.request.name ="print";
    ros::Rate loop_rate(1);

    if (sclient.call(srv)) {
        ROS_INFO("result: %s",  srv.response.result.c_str());
        ROS_INFO("Succeed");
    } else {
        ROS_ERROR("Failed");
        return 1;
    }
    ros::Publisher inform_pub = n.advertise<std_msgs::Header>("head", 10);
    int count = 0;
    while (ros::ok())
    {

        std_msgs::String msg;
        std::stringstream ss;
        std_msgs::Header time_now;
        time_now.frame_id = "print";
        time_now.stamp = ros::Time::now();
        inform_pub.publish(Info_message);
    }


    return 0;
}