//
// Created by mijiao on 23-1-28.
//
#include <csignal>
#include <string>
#include <ros/ros.h>
#include <client/message.h>
#include <server/service.h>


ros::ServiceClient *clientp = nullptr;

void SigintHandler(int sig) {
    if (sig == SIGINT) {
        ROS_INFO("Exiting...");
        server::service srv;
        srv.request.id = 1;
        srv.request.name = ros::this_node::getName();
        clientp->call(srv);
        ros::shutdown();
    }
}

int main(int argc, char **argv) {
    std::cout << "Input client name:";
    std::string name;
    std::cin >> name;
    ros::init(argc, argv, name, ros::init_options::NoSigintHandler);
    ros::NodeHandle nh;
    ros::Rate rate(1);
    signal(SIGINT, SigintHandler);
    ros::Publisher pub = nh.advertise<client::message>(name, 1000);
    ros::ServiceClient client = nh.serviceClient<server::service>("service");
    clientp = &client;
    server::service srv;
    srv.request.id = 0;
    srv.request.name = name;
    ros::service::waitForService("service");
    client.call(srv);
    while (ros::ok()) {
        client::message msg;
        msg.name = ros::this_node::getName();
        msg.time = ros::Time::now();
        pub.publish(msg);
        ROS_INFO("Sending: %s %d.%d", msg.name.c_str(), msg.time.sec, msg.time.nsec);
        ros::spinOnce();
        rate.sleep();
    }
    return 0;
}