#include "ros/ros.h"
#include <client/current_time.h>
#include <client/login.h>
#include <vector>

#include <iostream>

ros::NodeHandle *server_node_handle_pointer = nullptr;
ros::ServiceServer service_server;
std::vector<ros::Subscriber> server_subscribers;

void time_callback(const client::current_time::ConstPtr &msg) {
    ROS_INFO("Name: %s , Time:%d/%d/%d-%d:%d:%d ."
    , (msg->name).c_str()
    , msg->year
    , msg->month
    , msg->day
    , msg->hour
    , msg->minute
    , msg->second
    );
}

bool login_handle(client::login::Request &req, client::login::Response &ack) {
    if(req.req_code == 1) {
        ROS_INFO("Logged in!", req.node_name.c_str());
        ack.ack_code = 10;
        server_subscribers.push_back(
                (*server_node_handle_pointer).subscribe(
                        req.node_name, 1, time_callback));
    }else{
        ROS_INFO("Logged out!",
                 req.node_name.c_str());
        for(auto &each_subscriber : server_subscribers){
            std::string assist_sig = "/";
            if(assist_sig + req.node_name ==
               each_subscriber.getTopic()){
                each_subscriber.shutdown();
            }
        }
        ack.ack_code = 20;
    }
    return true;
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "ser_server");
    ros::NodeHandle server_node_handle;
    server_node_handle_pointer = & server_node_handle;
    server_subscribers.push_back(
            server_node_handle.subscribe(
                    "client_pub_current_time", 1, time_callback));
    service_server =server_node_handle.advertiseService(
            "login_service", login_handle);
    ROS_INFO("Server started!");
    ros::spin();
    return 0;
}
