//
// Created by kevin on 6/25/22.
//
#include <ros/ros.h>
#include <client/current_time.h>
//#include <std_msgs/Uint16.h>

void time_callback(const client::current_time::ConstPtr &msg) {
    ROS_INFO("Topic received from : %s , Whose time is %d/%d/%d-%d:%d:%d .", (msg->name).c_str(), msg->year, msg->month,
             msg->day, msg->hour, msg->minute, msg->second
    ); //���
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "Ros_learn_server");
    ros::NodeHandle server_node_handle;
    ros::Subscriber sub = server_node_handle.subscribe("client_pub_current_time", 1, time_callback);
    //���ûص�����gpsCallback
    ros::spin();
    //ros::spin()���ڵ������пɴ����Ļص�����,������ѭ��,���᷵��,��������ѭ���ﷴ������spinOnce(),��ros::spinOnce()ֻ��ȥ����һ��
    return 0;
}