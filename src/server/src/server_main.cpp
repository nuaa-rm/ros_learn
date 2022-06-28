//
// Created by kevin on 6/25/22.
//
#include <ros/ros.h>
#include <client/current_time.h>
#include <client/login.h>
#include <vector>

ros::NodeHandle *server_node_handle_pointer = NULL;
ros::ServiceServer service_server;
std::vector<ros::Subscriber> server_subscribers;

void time_callback(const client::current_time::ConstPtr &msg) {
    ROS_INFO("Topic received from : %s , Whose time is %d/%d/%d-%d:%d:%d ."
            , (msg->name).c_str()
            , msg->year
            , msg->month
            , msg->day
            , msg->hour
            , msg->minute
            , msg->second
    ); //Output
}

bool login_handle(client::login::Request &req, client::login::Response &ack) {
    if(req.req_code == 1) {
        ROS_INFO("A client: %s has logged in!", req.node_name.c_str());
        ack.ack_code = 10;
        server_subscribers.push_back(
                (*server_node_handle_pointer).subscribe(
                        req.node_name, 1, time_callback));
    }else{
        ROS_INFO("A client: %s has logged out!", req.node_name.c_str());
        for(auto &each_subscriber : server_subscribers)
            if(each_subscriber.getTopic() == req.node_name){
                each_subscriber.shutdown();
            }
        ack.ack_code = 20;
    }
    return true;
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "ros_learn_server");
    ros::NodeHandle server_node_handle;
    server_node_handle_pointer = & server_node_handle;

    server_subscribers.push_back(
            server_node_handle.subscribe(
                    "client_pub_current_time", 1, time_callback));

    service_server =server_node_handle.advertiseService(
            "ros_learn_login_service", login_handle);

    ROS_INFO("Server started!");
    ros::spin();
    return 0;
}
/*
 * Request code description:
 *  1:login
 *  2:logout
 * */
