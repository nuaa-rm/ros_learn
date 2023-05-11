#include <signal.h>
#include <string>
#include "ros/ros.h"
#include "client/message.h"
#include "server/service.h"

void MySigintHandler(int sig)
{
    ROS_INFO("shutting down!");
    ros::NodeHandle nh;
    ros::ServiceClient client = nh.serviceClient<server::service>("service");
    server::service srv2;
    srv2.request.name = "wenhao";
    srv2.request.status = 0;
    client.call(srv2);
    ros::shutdown();
}

int main(int argc, char **argv){
    ros::init(argc, argv, "client");
    ros::NodeHandle n;
    ros::ServiceClient client = n.serviceClient<server::service>("service");
    ros::Rate loop_rate(1);
    signal(SIGINT, MySigintHandler);
    server::service srv1;
    srv1.request.name = "wenhao";
    srv1.request.status = 1;
    client.call(srv1);
    ros::Publisher chatter_pub = n.advertise<client::message>("wenhao", 1000);
    while(ros::ok){
        client::message msg;
        msg.name = "wenhao";
        msg.time = ros::Time::now();
        chatter_pub.publish(msg);
        ROS_INFO("%d", msg.time.sec);
        ros::spinOnce();
        loop_rate.sleep();
    }


    return 0;
}