#include "ros/ros.h"
#include "client/time.h"
#include "client/client.h"
#include <iostream>
#include <string>

int main(int argc, char** argv)
{
    ros::init(argc , argv , "client", ros::init_options::AnonymousName);

    ros::NodeHandle n;

    ros::Publisher pub=n.advertise<client::time>("client", 1000);
    ros::ServiceClient client= n.serviceClient<client::client>("client");

    client::client name;
    name.request.topicname="client";
    name.request.login=1;

    client::time time;
    time.name="client";
    time.timenow=ros::Time::now();

    ros::Rate loop_rate(1);

    if(client.call(name)){
        ROS_INFO("Find");
    }
    else{
        ROS_INFO("NOT FOUND");
    }

    while(ros::ok()){
        pub.publish(time);
        ros::spinOnce();
        loop_rate.sleep();
    }

    name.request.login=0;
    client.call(name);

    return 0;
}
