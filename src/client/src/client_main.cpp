//
// Created by kevin on 6/25/22.
//
#include <ros/ros.h>
#include <client/current_time.h>
#include <client/login.h>
#include <ctime>
#include <cstring>
#include <iostream>

ros::ServiceClient service_client;

int main(int argc, char **argv) {
    std::string main_name;
    bool logged = 0;
    std::cin>>main_name;
    ros::init(argc, argv, main_name);
    ros::NodeHandle client_node_handle;

    client::current_time publishing_msg;
    ros::Publisher client_publisher =
            client_node_handle.advertise<client::current_time>(main_name, 1);

    service_client =
            client_node_handle.serviceClient<client::login>(
                    "ros_learn_login_service");
    client::login login_service_message;
    login_service_message.request.req_code=1;
    login_service_message.request.node_name=main_name;

    ros::Rate loop_rate(1.0);
    while(!logged) {
        ROS_INFO("Not logged in, trying again!");
        logged = service_client.call(login_service_message);
        if(login_service_message.response.ack_code != 10){
            logged = 0;
        }
        loop_rate.sleep();
    }
    ROS_INFO("Logged in, now publishing the topic!");
    time_t time_seconds = time(0);
    struct tm now_time;

    while (ros::ok()) {
        //time(&now_time_from_system);
        localtime_r(&time_seconds, &now_time);

        publishing_msg.name = main_name;
        publishing_msg.year = now_time.tm_year + 1900;
        publishing_msg.month = now_time.tm_mon + 1;
        publishing_msg.day = now_time.tm_mday;
        publishing_msg.hour = now_time.tm_hour;
        publishing_msg.minute = now_time.tm_min;
        publishing_msg.second = now_time.tm_sec;

        client_publisher.publish(publishing_msg);
        loop_rate.sleep();
    }
    return 0;
}
