
#include <ros/ros.h>
#include <std_msgs/String.h>
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

    ros::service::waitForService("/show_info");
    service_client = n.serviceClient<client::show>("/show_info");
    // 设置循环的频率
    ros::Rate loop_rate(1);
    // 请求服务调用
    service_client.call(srv);

    ROS_INFO("Successfully logged , now send the topic with its time message.");

    ros::Publisher time_topic_pub = n.advertise<client::time>(name, 10);
    // 检测是否退出
    signal(SIGINT, interrupt_handler);
    while (ros::ok()&&flag_ros)
    {
        ros::Time now = ros::Time::now();
        client::time msg;
        msg.second = now.toSec();
        msg.name = name;

        time_topic_pub.publish(msg);

        loop_rate.sleep();
    }
    return 0;
}
void interrupt_handler(int x)
{
    srv.request.request=10;
    service_client.call(srv);
    ROS_INFO("delete the subscriber.");
    flag_ros = 0;
}



