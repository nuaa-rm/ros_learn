#include <ros/ros.h>
#include <client/client_message.h>
#include <client/client_login.h>

#define PUBLISHER_SIZE 10

#define LOGIN 0
#define LOGOUT 1
#define NUL 2
#define SUCCESS 3
#define FAILED 4

int main(int argc, char ** argv){
    ros::init(argc, argv, "client", ros::init_options::AnonymousName);
    ros::NodeHandle client_node_handle;
    ros::Publisher client_pub = client_node_handle.advertise<client::client_message>(ros::this_node::getName(), PUBLISHER_SIZE);
    ros::ServiceClient client_login = client_node_handle.serviceClient<client::client_login>("client_login");
    client::client_login login_service;
    client::client_message message;
    ros::Rate loop(1.0);

    login_service.request.name = ros::this_node::getName();
    login_service.request.require_code = LOGIN;
    login_service.response.answer_code = NUL;
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

    message.name = ros::this_node::getName();
    while(ros::ok()){
        message.current_time = ros::Time::now();
        client_pub.publish(message);
        loop.sleep();
    }

    login_service.request.name = ros::this_node::getName();
    login_service.request.require_code = LOGOUT;
    login_service.response.answer_code = NUL;
    ROS_INFO("logout");

    return 0;
}