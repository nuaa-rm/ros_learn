#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include "client/Time.h"
#include <iostream>

using namespace std;
void personInfoCallback(const client::Time::ConstPtr& time)
{
    // 将接收到的消息打印出来
    ROS_INFO("Topic_name:%s   time:%d:%d:%d", 
    time->name.c_str(), time->hour, time->min,time->sec);
}

int main(int argc, char **argv)
{
    // 初始化ROS节点
    ros::init(argc, argv, "server");

    // 创建节点句柄
    ros::NodeHandle n;
    // 创建一个Subscriber，订阅名为client_topic的topic，注册回调函数personInfoCallback
    ros::Subscriber client_topic_sub = n.subscribe("/client_topic", 10, personInfoCallback);

    ros::spin();
   
    return 0;
}
