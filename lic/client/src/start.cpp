#include <ros/ros.h>
#include "client/name.h"
#include "client/topic_name.h"
void nameInfoCallback(const client::name::ConstPtr& msg){
	
	ROS_INFO("Subcriber Info: name:%s", msg->name.c_str());
}
int main(int argc, char **argv){

	ros::init(argc, argv, "start");

	ros::NodeHandle n;
	ros::Subscriber name_info_sub = n.subscribe("/name_info", 10, nameInfoCallback);
	
	ros::service::waitForService("/show_topic");
	ros::ServiceClient client_name = n.serviceClient<client::topic_name>("/show_topic");
	client::topic_name srv;
	srv.request.name="/name_info";
	
	ROS_INFO("Call service name : %s",srv.request.name.c_str());

	client_name.call(srv);
	
	ROS_INFO("Result : %s", srv.response.result.c_str());

	ros::spin();
	return 0;

}
