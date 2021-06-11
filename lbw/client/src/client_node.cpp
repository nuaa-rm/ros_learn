#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <iostream>
#include <time.h>

using namespace std;
int main()
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
        ros::Publisher turtle_vel_pub = n.advertise<geometry_msgs::Time>("client_topic", 10);
	// 设置循环的频率
	ros::Rate loop_rate(1);
        while(ros::ok())
        {
        //初始化time
        geometry_msgs::Time time;
        //发布消息
        client_topic.publish(time);
    	// 按照循环频率延时
	loop_rate.sleep();    
        }
}
