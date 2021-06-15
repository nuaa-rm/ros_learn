#include <ros/ros.h>
#include "client/name.h"
#include "client/topic_name.h"
#include <string>

using namespace std;

int flag = 0;
string aim_topic;

void nameInfoCallback(const client::name::ConstPtr& msg) {
    ROS_INFO("Subcriber Info: name:%s Time:%lld", msg->name.c_str() ,msg->tim.sec);
}

bool topicCallback(client::topic_name::Request  &req,client::topic_name::Response &res)
{
    ROS_INFO("Topic: name:%s  ", req.name.c_str());
	aim_topic = "/"+req.name;
    res.result = aim_topic;
	flag = 1;
    return true;
}

int main(int argc, char **argv) {
	ros::init(argc, argv, "start_server");
	ros::NodeHandle n;
	ros::ServiceServer client_name = n.advertiseService("/show_topic", topicCallback);
	//ros::Subscriber name_info_sub = n.subscribe<client::name>("/client0", 10, nameInfoCallback);
	ros::Subscriber name_info_sub;
	ros::Rate loop_rate(1);
	while(ros::ok()) {
		ros::spinOnce();
		if(flag == 1) {
			ROS_INFO("aim_topic :%s", aim_topic.c_str());
			name_info_sub = n.subscribe<client::name>(aim_topic.c_str(), 10, nameInfoCallback);
			flag = 0;
		}
		loop_rate.sleep();
	}
	return 0;
}

