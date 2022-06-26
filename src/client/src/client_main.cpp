//
// Created by kevin on 6/25/22.
//

#include <ctime>

#include <ros/ros.h>
#include <client/current_time.h>

int main(int argc, char **argv) {
    ros::init(argc, argv, "ros_learn_client");
    ros::NodeHandle client_node_handle;

    client::current_time publishing_msg;
    ros::Publisher client_publisher = client_node_handle.advertise<client::current_time>("client_pub_current_time", 1);
    ros::Rate loop_rate(1.0);

    time_t nowtime;
    struct tm* p;

    while (ros::ok()) {
        time(&nowtime);
        p = localtime(&nowtime);

        publishing_msg.name = "Time_broadcaster_1";
        publishing_msg.year = p->tm_year + 1900;
        publishing_msg.month = p->tm_mon + 1;
        publishing_msg.day = p->tm_mday;
        publishing_msg.hour = p->tm_hour;
        publishing_msg.minute = p->tm_min;
        publishing_msg.second = p->tm_sec;

        client_publisher.publish(publishing_msg);
        loop_rate.sleep();
    }

    return 0;
}