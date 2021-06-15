#include <ros/ros.h>
#include "client/name.h"
#include "client/topic_name.h"
#include <string>

using namespace std;

int num_of_sub = 0;
string aim_topic;
ros::Subscriber name_info_sub[100];

void nameInfoCallback(const client::name::ConstPtr& msg) {
    ROS_INFO("Subcriber Info: name:%s Time:%lld", msg->name.c_str() ,msg->tim.sec);
}

bool topicCallback(client::topic_name::Request  &req,client::topic_name::Response &res)
{
    ROS_INFO("Topic: name:%s  ", req.name.c_str());
    aim_topic = "/"+req.name;
    res.result = aim_topic;
    ros::NodeHandle n;
    name_info_sub[num_of_sub++] = n.subscribe<client::name>(aim_topic.c_str(), 10, nameInfoCallback);
    return true;
}

int main(int argc, char **argv) {
	ros::init(argc, argv, "start_server");
	ros::NodeHandle n;
	ros::ServiceServer client_name = n.advertiseService("/show_topic", topicCallback);
	//ros::Subscriber name_info_sub = n.subscribe<client::name>("/client0", 10, nameInfoCallback);
	//ros::Subscriber name_info_sub;
	ros::spin();
	return 0;
}

