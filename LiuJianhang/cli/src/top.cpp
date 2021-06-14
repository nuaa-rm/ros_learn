#include<ros/ros.h>
#include<std_msgs/String.h>
#include<time.h>
int main(int argc, char** argv)
{
	ros::init(argc, argv, "my_time");
	ros::NodeHandle nh;
	ros::Publisher pub = nh.advertise<std_msgs::Float64>("my_time", 10);
	
	ros::Rate loop_rate(1.0);
	while(ros::ok)
	{
		std_msgs::Int32 myTime;
		myTime = ros::Time::now;
		pub.publish(myTime);
		loop_rate.sleep();
	}
	ros::spin();
	return 0;
}
