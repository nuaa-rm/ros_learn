#include <ros/ros.h>
#include "client/name.h"

int main(int argc, char **argv){

	ros::init(argc, argv, "start");

	ros::NodeHandle n;

	ros::Publisher name_info_pub = n.advertise<client::name>("/name_info", 10);

	ros::Rate loop_rate(1);

	int count = 0;

	while(ros::ok()){
		
			client::name name_msg;
			name_msg.name="/name_info";

			name_info_pub.publish(name_msg);

			ROS_INFO("Publish Name Info: namperson_msge:%s ",
					name_msg.name.c_str());

			loop_rate.sleep();
	}

	return 0;

}
