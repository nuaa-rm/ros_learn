#include"ros/ros.h"
#include "client/time.h"
#include "client/client.h"
#include <iostream>
#include <string>

void print_message(const client::time::ConstPtr& time){
    ROS_INFO("%s Time:%d", time->name.c_str(), time->timenow.sec);
}

bool log_in(client::client::Request  &req,
            client::client::Response &res)
{
    ros::NodeHandle n;
    if (req.login==1){
    ROS_INFO("%s", req.topicname.c_str());
    res.name=req.topicname;
    }
    else if (req.login==0){
        ROS_INFO("Stop!!!");
    }
    return true;
}

int main(int argc,char** argv)
{
    ros::init(argc, argv, "server");
    std::string* name;

    ros::NodeHandle n;
    ros::ServiceServer service = n.advertiseService("client" , log_in);
    ros::Subscriber sub = n.subscribe("client" , 1000 , print_message);
    ros::spin();

    return 0;
}
