// Copyright 2021 zhengqi

#include <ros/ros.h>
#include "client/Crist.h"
#include "std_msgs/Header.h"

bool show_data(const std_msgs::Header::ConstPtr& msg) {
    // 打印接收到的数据
    ROS_INFO("Subsrcibe data name:%s,time:%d", 
                            msg->frame_id.c_str(), msg->stamp.sec);
}

bool Callback(client::Crist::Request & req,
                              client::Crist::Response & res) {   
   ros::NodeHandle n;
   // 显示请求数据
    ROS_INFO("name:%s", req.name.c_str());
    // 设置返回数据
    res.result = "OK";
    // 订阅topic,注册回调函数show_data
    ros::Subscriber inform_sub = n.subscribe<std_msgs::Header>("head",10,show_data);
}

int main(int argc, char **argv) { 
    // 初始化节点
    ros::init(argc, argv, "server_node");
    // 设置节点句柄
    ros::NodeHandle n;
    // 创建名为"/show_name",的server,注册回调函数Callback
    ros::ServiceServer  name_server = n.advertiseService("/show_name",Callback);
    // 等待循环回调函数
    ros::spin();
    return 0;
}