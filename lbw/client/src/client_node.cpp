#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <iostream>
#include <time.h>
#include <client/Time.h>
using namespace std;
int main(int argc, char **argv)
{
        time_t tt;
        time( &tt );
        tt = tt + 8*3600;  // transform the time zone
        tm* t= gmtime( &tt );
        cout <<t->tm_hour<<t->tm_min<< t->tm_sec;

        // ROS节点初始化
	ros::init(argc, argv, "client");
        // 创建节点句柄
	ros::NodeHandle n;
	// 创建一个Publisher，发布名为client_topic的topic，消息类型为time，队列长度10
        ros::Publisher client_topic_pub = n.advertise<client::Time>("client_topic", 10);
	// 设置循环的频率
	ros::Rate loop_rate(1);
        while(ros::ok())
        {
        //初始化time
        client::Time time;
        time.hour =t->tm_hour;
        time.min  =t->tm_min; 
        time.name ="client";
        //发布消息
        client_topic_pub.publish(time);
    	// 按照循环频率延时
	loop_rate.sleep();    
        }
        return 0;
}
