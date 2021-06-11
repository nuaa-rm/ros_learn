#include <ros/ros.h>
#include "client/name.h"
#include "client/topic_name.h"
/*void nameInfoCallback(const client::name::ConstPtr& msg){
	
	ROS_INFO("Subcriber Info: name:%s", 
			msg->name.c_str());
}*/
bool topicCallback(client::topic_name::Request  &req,
         			client::topic_name::Response &res)
{
    ROS_INFO("Topic: name:%s  ", req.name.c_str());
    res.result = "OK";
    return true;
}
int main(int argc, char **argv){
	
	ros::init(argc, argv, "start_server");

	ros::NodeHandle n;

	/*ros::Subscriber name_info_sub = n.subscribe("/name_info", 10, nameInfoCallback);

	*/
	ros::ServiceServer client_name = n.advertiseService("/show_topic", topicCallback);
	ros::spin();
	return 0;
}
