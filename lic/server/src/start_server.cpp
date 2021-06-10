#include <ros/ros.h>
#include "client/name.h"

void nameInfoCallback(const client::name::ConstPtr& msg){
	
	ROS_INFO("Subcriber Info: name:%s", 
			msg->name.c_str());
}

int main(int argc, char **argv){
	
	ros::init(argc, argv, "start_server");

	ros::NodeHandle n;

	ros::Subscriber name_info_sub = n.subscribe("/name_info", 10, nameInfoCallback);

	ros::spin();

	return 0;
}
