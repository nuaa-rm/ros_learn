#include "client/Time.h"
#include "client/show.h"
#include <ros/time.h>
#include <ros/ros.h>
using namespace std;
int main(int argc, char **argv)
{
    // ROS节点初始化
    ros::init(argc, argv, "client_topic");
    // 创建节点句柄
    ros::NodeHandle n;
    // 创建一个Publisher，发布名为client_topic的topic，消息类型为time，队列长度10

    ros::ServiceClient cli = n.serviceClient<client::show>("show_name");

    client::show srv;
    srv.request.req=1;
    cli.call(srv);
    ros::Publisher client_topic_pub = n.advertise<client::Time>(srv.response.rep.c_str(), 10);
    // 设置循环的频率
    ros::Rate loop_rate(1);
    while(ros::ok())
    {
    //初始化time
    ros::Time begin = ros::Time::now();
    client::Time time;
    time.sec = (long unsigned int)begin.toSec();  
    time.name = "client";
    //发布消息
    client_topic_pub.publish(time);
    // 按照循环频率延时
    loop_rate.sleep();    
    }
    return 0;
}
