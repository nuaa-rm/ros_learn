//
// Created by kevin on 6/25/22.
//
#include <ros/ros.h>
#include <client/current_time.h>

int main(int argc, char **argv) {
    ros::init(argc, argv, "ros_learn_client");
    ros::NodeHandle client_node_handle;

    client::current_time publishing_msg;
    ros::Publisher client_publisher = client_node_handle.advertise<client::current_time>("client_pub_current_time", 1);
    ros::Rate loop_rate(1.0);
    while (ros::ok()) {
        publishing_msg.name = "Hello,This is a topic!";
        publishing_msg.year = 2022;
        publishing_msg.month = 6;
        publishing_msg.day = 25;
        publishing_msg.hour = 8;
        publishing_msg.minute = 42;
        publishing_msg.second = 20;

        client_publisher.publish(publishing_msg);
        loop_rate.sleep();
    }

    return 0;
}