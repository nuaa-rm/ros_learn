#include <ros/ros.h>
#include "client/name.h"
#include "client/topic_name.h"
/**/
int flag=0;
bool topicCallback(client::topic_name::Request  &req,client::topic_name::Response &res)
{
    ROS_INFO("Topic: name:%s  ", req.name.c_str());
    res.result = "OK";
    return true;
}
int main(int argc, char **argv){
	
	ros::init(argc, argv, "start_server");

	ros::NodeHandle n;
	ros::ServiceServer client_name = n.advertiseService("/show_topic", topicCallback);
	
	ros::Publisher name_info_pub = n.advertise<client::name>("/name_info", 10);

	ros::Rate loop_rate(1);
	int count = 0;
	while(ros::ok()){
		
			client::name name_msg;
			name_msg.name="/name_info";
			name_info_pub.publish(name_msg);
			ROS_INFO("Publish Name Info: namperson_msge:%s ", name_msg.name.c_str());
			loop_rate.sleep();
	}
	ros::spin();
	return 0;
}
