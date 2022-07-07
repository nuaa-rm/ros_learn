#include <ros/ros.h>
#include <client/current_time.h>
#include <client/login.h>
#include <iostream>
#include <ctime>
#include <chrono>
#include <iomanip>

using namespace std;
ros::ServiceClient service_client;
client::login service_msg;
string current_time;

void format_time_point()
{
    auto tp=std::chrono::system_clock::now();
    auto time=std::chrono::system_clock::to_time_t(tp);
    std::stringstream ss;
    ss<<std::put_time(std::localtime(&time),"%Y-%m-%d %H:%M:%S");
    current_time = ss.str();
}

int main(int argc, char **argv) {
    bool logged = false;
    ros::init(argc, argv,"cli_client",ros::init_options::AnonymousName);
    ros::NodeHandle client_node_handle;
    client::current_time publishing_msg;
    ros::Publisher client_publisher =
            client_node_handle.advertise<client::current_time>(ros::this_node::getName(), 1);
    service_client =
            client_node_handle.serviceClient<client::login>(
                    "login_service");
    service_msg.request.req_code = 1;
    service_msg.request.node_name = ros::this_node::getName();
    service_msg.response.ack_code = 0;
    ros::Rate loop_rate(1.0);
    while(!logged) {
        ROS_INFO("Not logged in, trying again!");
        logged = service_client.call(service_msg);
        if(service_msg.response.ack_code != 10){
            logged = false;
        }
        loop_rate.sleep();
    }
    ROS_INFO("Logged in, publishing the topic!");
    while (ros::ok()) {
        format_time_point();
        publishing_msg.name = ros::this_node::getName();
        publishing_msg.current_time = current_time;
        client_publisher.publish(publishing_msg);
        loop_rate.sleep();
    }
    service_msg.request.req_code=10;
    service_client.call(service_msg);
    ROS_INFO("Quit!");
    return 0;
}

