#include "ros/ros.h"
#include "ser/name.h"
bool serCallback(ser::name::Request &req,
		ser::name::Response &res)
{
	ROS_INFO("Topic:%s", req.topic_name);
	res.result = "OK";
	return true;
}
int main(int argc, char **argv)
{
	ros::init(argc, argv, "my_time_server");
	ros::NodeHandle n;
	ros::ServiceServer name_service = n.advertiseService("my_time_server", serCallback);
	ROS_INFO("Ready!");
	ros::spin();
	return 0;
}
