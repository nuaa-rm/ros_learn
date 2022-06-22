#include <client/Time.h>
#include <client/show.h>
#include <ros/time.h>
#include <ros/ros.h>
#include "std_msgs/Header.h"
int main(int argc, char **argv) {
    // ROS节点初始化
    ros::init(argc, argv, "client_topic");
    // 创建节点句柄
    ros::NodeHandle n;

    ros::ServiceClient cli = n.serviceClient<client::show>("show_name");
    client::show srv;
    srv.request.name ="show";

    if(cli.call(srv)){
        ROS_INFO("result: %s",  srv.response.res.c_str());
        ROS_INFO("Succeed calling!");
    } else {
        ROS_ERROR("Failed to call");
        return 1;
    }
    ros::Publisher client_topic_pub =
            n.advertise<std_msgs::Header>("head", 10);
    // 循环的频率
    ros::Rate loop_rate(1);
    while (ros::ok()) {
        // 初始化std_msgs::Header的数据
        std_msgs::Header Info_message;
        Info_message.frame_id = "show";
        Info_message.stamp = ros::Time::now();
        // 发布消息
        client_topic_pub.publish(Info_message);

        // 按照循环频率延时
        loop_rate.sleep();
    }
    return 0;
}
