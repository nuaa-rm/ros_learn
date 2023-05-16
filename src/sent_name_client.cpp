//
// Created by hlf on 5/10/23.
//
// !src/client.cpp

#include "ros/ros.h"
#include "helifeng/SentName.h"
#include <cstdlib>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "sent_name_client");

    if (argc != 2)
    {
        ROS_INFO("please enter a topic name to be subscribed");
        return 1;
    }

    ros::NodeHandle nh;
    ros::ServiceClient client = nh.serviceClient<helifeng::SentName>("sent_name");

    helifeng::SentName srv;
    srv.request.topicName = (std::string)"chatter";
    if (client.call(srv))
    {
        ROS_INFO("sent_name_client call SentName service successfully");
    }
    else
    {
        ROS_ERROR("failed to call SentName service");
        return 1;
    }

//    ros::Rate loop_rate(1);
//
//    while (ros::ok())
//    {
//        helifeng::SentName srv;
//        srv.request.name = (std::string)helifeng;
//        //srv.request.b = atoll(argv[2]);
//        ros::spinOnce();
//        loop_rate.sleep();
//    }

    return 0;
}
