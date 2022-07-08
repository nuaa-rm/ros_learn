#include <ros/ros.h>
#include <ros/time.h>

#include <client/time.h>
#include <client/show.h>

#include <signal.h>
#include <unistd.h>

#include <ctime>
#include <cstring>
#include <iostream>

ros::ServiceClient service_client;
client::show srv;

void interrupt_handler(int x);

int main(int argc, char** argv)
{
    std::string main_name;

    // 初始化ROS节点
    ros::init(argc, argv, "node", ros::init_options::AnonymousName);

    main_name = ros::this_node::getName();

    // 创建节点句柄
    ros::NodeHandle n;

    // 初始化client::show的请求数据
    srv.request.request = 1;
    srv.request.node_name = main_name;
    srv.response.response = 0;

    // 发现/show_info服务后，创建一个服务客户端，连接名为/show_info的service
    ros::service::waitForService("/show_info");
    service_client = n.serviceClient<client::show>("/show_info");

    // 设置循环的频率
    ros::Rate loop_rate(1);

    // 请求服务调用
    service_client.call(srv);

    /*
    while(service_client.call(srv))
    {
    	if(srv.response.response!=10)
	{
	    ROS_INFO("Logging in, please wait...");
	    loop_rate.sleep();	
	}
	else
	{
	    break;
	}
    };
    */

    // 显示服务调用结果
    ROS_INFO("Logged successfully, now send the topic.");

    // 创建一个Publisher，发布名为/client_topic的topic，消息类型为client::time，队列长度10
    ros::Publisher time_topic_pub = n.advertise<client::time>(main_name, 10);

    // 检测是否退出
    signal(SIGINT, interrupt_handler);

    while (ros::ok())
    {
        // 初始化client::time类型的消息
        //ros::Time now = ros::Time::now();
        client::time time_msg;

        time_t time_seconds = time(0);
        struct tm now_time;
        localtime_r(&time_seconds, &now_time);

        //time_msg.sec = now.toSec();
        time_msg.year = now_time.tm_year + 1900;
        time_msg.month = now_time.tm_mon + 1;
        time_msg.day = now_time.tm_mday;
        time_msg.hour = now_time.tm_hour;
        time_msg.minute = now_time.tm_min;
        time_msg.second = now_time.tm_sec;
        time_msg.name = main_name;

        // 发布消息
        time_topic_pub.publish(time_msg);

        // 按照循环频率延时
        loop_rate.sleep();
    }

    return 0;
}


void interrupt_handler(int x) 
{
    srv.request.request=10;
    service_client.call(srv);
    ROS_INFO("Had quited the subscriber.");
    ros::shutdown();
}
.
