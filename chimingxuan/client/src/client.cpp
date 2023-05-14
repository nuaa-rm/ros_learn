#include "ros/ros.h"
#include "std_msgs/String.h"
#include "server/Register.h"
#include "server/Unregister.h"

#include <signal.h>

#include <sstream>
#include <ctime>


void Unregister(int sig){
    ros::NodeHandle n;
    ros::ServiceClient client_unregister =
            n.serviceClient<server::Unregister>("unregister");
    server::Unregister unregister_srv;
    std::string client_name = ros::this_node::getName();
    unregister_srv.request.name = client_name;
    if(client_unregister.call(unregister_srv)) {
        if (unregister_srv.response.success) {
            ROS_INFO("Unregister success");
        } else {
            ROS_INFO("Client %s unregister fail!", client_name.c_str());
        }
    } else {
        ROS_INFO("Failed to call server unregister");
    }

    ros::shutdown();
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "client");
    ros::NodeHandle n;

    std::string client_name = ros::this_node::getName();
    std::string topic = client_name;

    ros::ServiceClient client_register =
            n.serviceClient<server::Register>("register");
    server::Register register_srv;
    register_srv.request.name = topic;

    if(client_register.call(register_srv)){
        if(register_srv.response.success) {
            ROS_INFO("Register success");
        }else{
            ROS_INFO("Client %s already exists!", client_name.c_str());
            return 1;
        }
    }else{
        ROS_ERROR("Failed to register");
        return 1;
    }

    signal(SIGINT, Unregister);

    ros::Publisher chatter_pub = n.advertise<std_msgs::String>(topic,1000);
    ros::Rate loop_rate(1);
    while(ros::ok()){
        std_msgs::String msg;

        std::stringstream ss;

        time_t now = time(nullptr);
        char* curr_time = ctime(&now);
        ss << "current time:" << curr_time << "from client " << client_name;
        msg.data = ss.str();

        chatter_pub.publish(msg);
        ROS_INFO("sending [%s]", msg.data.c_str());

        ros::spinOnce();

        loop_rate.sleep();
    }
    return 0;
}
