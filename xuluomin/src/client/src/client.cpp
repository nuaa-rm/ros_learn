
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <ros/time.h>
#include <client/time.h>
#include <client/show.h>
#include <signal.h>
#include <unistd.h>
#include <iostream>
void interrupt_handler(int x);
bool flag_ros = 1;
ros::ServiceClient service_client;
client::show srv;
int main(int argc, char **argv){
    std::string name;
    //input the name
    std::cin>>name;
    // 初始化ROS节点
    ros::init(argc, argv, name);
    // 创建节点句柄
    ros::NodeHandle n;

    // 初始化client::show的请求数据
    srv.request.request = 1;
    srv.request.name = name;
    srv.response.response = 0;
    
    // 发现/show_info服务后，创建一个服务客户端，连接名为/show_info的service
    ros::service::waitForService("/show_info");
    service_client = n.serviceClient<client::show>("/show_info");

    // 设置循环的频率
    ros::Rate loop_rate(1);

    // 请求服务调用
    service_client.call(srv);
    // 显示服务调用结果
    ROS_INFO("Logged successfully, now send the topic.");

    // 创建一个Publisher，发布名为/client_topic的topic，消息类型为client::time，队列长度10
    ros::Publisher time_topic_pub = n.advertise<client::time>(name, 10);

    // 检测是否退出
    signal(SIGINT, interrupt_handler);

    while (ros::ok()&&flag_ros)
    {
// 初始化client::time类型的消息
        ros::Time now = ros::Time::now();

        client::time msg;

        msg.second = now.toSec();
        msg.name = name;

// 发布消息
        time_topic_pub.publish(msg);

// 按照循环频率延时
        loop_rate.sleep();
    }
    return 0;
}
void interrupt_handler(int x)
{
    srv.request.request=10;
    service_client.call(srv);
    ROS_INFO("Had quited this subscriber.");
    flag_ros = 0;
}



