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

    /*if (argc != 2)
    {
        ROS_INFO("usage: add_two_ints_client X Y");
        return 1;
    }*/

    ros::NodeHandle nh;
    ros::ServiceClient client = nh.serviceClient<helifeng::SentName>("sent_name");

    ros::Rate loop_rate(1);

    while (ros::ok())
    {
        helifeng::SentName srv;
        srv.request.name = (std::string)helifeng;
        //srv.request.b = atoll(argv[2]);
        ros::spinOnce();
        loop_rate.sleep();
    }

//    int count = 0;
//    if (client.call(srv))
//    {
//        ROS_INFO("%ld", (int)count++);
//    }
//    else
//    {
//        ROS_ERROR("Failed to call service sent_name");
//        return 1;
//    }

    return 0;
}


/*std_msgs::String msg;

    std::stringstream ss;
    ss << "helifeng" << count;
    msg.data = ss.str();

    //ROS_INFO("%s", msg.data.c_str());
    chatter_pub.publish(msg);*/
