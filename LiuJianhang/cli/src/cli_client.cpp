#include<ros/ros.h>
#include<ser/name.h>

int main(int argc, char** argv)
{
	ros::init(argc, argv, "cli_client");
	ros::NodeHandle n;
	ros::service::waitForService("my_time_server");
	ros::ServiceClient cli_client = n.serviceClient<ser::name>("my_time_server");
	ser::name srv;
	srv.request.topic_name = "topic_name";
	ROS_INFO("Call service");
	cli_client.call(srv);
	ROS_INFO("Result:%s", srv.response.result.c_str());
	return 0;
}
