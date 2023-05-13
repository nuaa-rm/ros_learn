#include <ros/ros.h>
#include <client/client_message.h>
#include <client/client_login.h>
#include <client/status_code.h>
#include <csignal>

#define PUBLISHER_SIZE 10
#define LOGOUT_TRY_TIMES 3

void signal_handler(int signal){
    ROS_INFO("logout");
    ros::NodeHandle node_handle = ros::NodeHandle("~");

    ros::ServiceClient client_login =
        node_handle.serviceClient<client::client_login>("/client_login");

    client::client_login login_service;
    ros::Rate loop(1.0);
    login_service.request.name = ros::this_node::getName();
    login_service.request.require_code = LOGOUT;
    int try_times;
    for(try_times = 0; try_times < LOGOUT_TRY_TIMES; try_times++){
        if(client_login.call(login_service)){
            if(login_service.response.answer_code == SUCCESS){
                ROS_INFO("logout success");
                break;
            }
            else{
                ROS_INFO("logout failed");
                break;
            }
        }
        ROS_INFO("logout failed, try again");
        loop.sleep();
    }
    if(try_times == LOGOUT_TRY_TIMES){
        ROS_INFO("lose connection with server");
    }
    ros::shutdown();
}

int main(int argc, char ** argv){
    ros::init(argc, argv, "client", ros::init_options::AnonymousName);
    ros::NodeHandle node_handle = ros::NodeHandle("~");

    ros::Publisher client_pub =
        node_handle.advertise<client::client_message>(
            "",
            PUBLISHER_SIZE
            );

    ros::ServiceClient client_login =
        node_handle.serviceClient<client::client_login>("/client_login");

    client::client_login login_service;
    client::client_message message;
    ros::Rate loop(1.0);

    login_service.request.name = ros::this_node::getName();
    login_service.request.require_code = LOGIN;
    while(true){
        if(client_login.call(login_service)){
            if(login_service.response.answer_code == SUCCESS){
                break;
            }
        }
        if(!ros::ok()){
            return 1;
        }
        ROS_INFO("login failed, try again");
        loop.sleep();
    }
    ROS_INFO("login success");

    signal(SIGINT, signal_handler);
    message.name = ros::this_node::getName();
    while(ros::ok()){
        message.current_time = ros::Time::now();
        client_pub.publish(message);
        loop.sleep();
    }

    return 0;
}
