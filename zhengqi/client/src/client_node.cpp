// Copyright 2021 zhengqi

#include <ros/ros.h>
#include "client/Crist.h"
#include "std_msgs/Header.h"

int main(int argc, char **argv) {
    int i = 0;
    // 初始化ros节点 
    ros::init(argc, argv, "client_node");
    // 创建节点句柄
    ros::NodeHandle n;
    // 等待服务建立
    ros::service::waitForService("/show_name");
    // 创建一个服务客户端，连接名为/show_name的服务
    ros::ServiceClient name_client =
	    n.serviceClient<client::Crist>("/show_name");
    // 初始化client::Crist的数据内容
    client::Crist srv;
    srv.request.name = "Crist";
    // 调用服务
    if (name_client.call(srv)) {
        ROS_INFO("result: %s",  srv.response.result.c_str());
        ROS_INFO("Succeed in calling service show_name");
    } else {
        ROS_ERROR("Failed to call service show_name");
        return 1;
    }
    // 创建publisher，数据类型为std_msgs::Header,发布名为"head",队列长度10
    ros::Publisher inform_pub = n.advertise<std_msgs::Header>("head", 10);
    // 设置循环频率
    ros::Rate loop_rate(1);
    while (ros::ok()) {
        // 初始化std_msgs::Header的数据
        std_msgs::Header Info;
        Info.frame_id = "crist";
        Info.stamp = ros::Time::now();
        // 发布消息
        inform_pub.publish(Info);
        i++;
        ROS_INFO("information was send %d times", i);
        // 按照循环频率延时
        loop_rate.sleep();
    }
    return 0;
}

