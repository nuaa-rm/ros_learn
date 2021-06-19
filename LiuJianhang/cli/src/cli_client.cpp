#include<ros/ros.h>
#include<ser/name.h>
#include<ser/tim.h>
long comYearSecond = 31536000;
long loopYearSecond = 31622400;
bool loopYear(int y)
{
	if(y % 100 == 0)
	{
		if(y % 400 == 0)return 1;
		else return 0;
	}
	else if(y % 4 == 0)return 1;
	else return 0;
}
int TimeYear(double& t)
{
	int count = 1970;
	for(;t > (loopYear(count)?loopYearSecond:comYearSecond);count++ )
	{
		t -= (loopYear(count)?loopYearSecond:comYearSecond);
	}
	return count;
}
int TimeMonth(double& t, int year)
{
	int day;
	day = t / 86400;
	int Feb;
	Feb = (loopYear(year)?29:28);
	if(day <= 31)
	{
		return 1;
	}
	else if(day <= Feb + 31)
	{
		t -= 31 * 86400;
		return 2;
	}
	else if(day <= Feb + 31 + 31)
	{
		t -= (31 + Feb) * 86400;
		return 3;
	}
	else if(day <= Feb + 31 + 31 + 30)
	{
		t -= (31 + Feb + 31) * 86400;
		return 4;
	}
	else if(day <= Feb + 31 + 31 + 30 + 31)
	{
		t -= (31 + Feb + 31 + 30) * 86400;
		return 5;
	}
	else if(day <= Feb + 31 + 31 + 30 + 31 + 30)
	{
		t -= (31 + Feb + 31 + 30 + 31) * 86400;
		return 6;
	}
	else if(day <= Feb + 31 + 31 + 30 + 31 + 30 + 31)
	{
		t -= (31 + Feb + 31 + 30 + 31 + 30) * 86400;
		return 7;
	}
	else if(day <= Feb + 31 + 31 + 30 + 31 + 30 + 31 + 31)
	{
		t -= (31 + Feb + 31 + 30 + 31 + 30 + 31) * 86400;
		return 8;
	}
	else if(day <= Feb + 31 + 31 + 30 + 31 + 30 + 31 + 31 + 30)
	{
		t -= (31 + Feb + 31 + 30 + 31 + 30 + 31 + 31) * 86400;
		return 9;
	}
	else if(day <= Feb + 31 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31)
	{
		t -= (31 + Feb + 31 + 30 + 31 + 30 + 31 + 31 + 30) * 86400;
		return 10;
	}
	else if(day <= Feb + 31 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30)
	{
		t -= (31 + Feb + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31) * 86400;
		return 11;
	}
	else
	{
		 t -= (31 + Feb + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30) * 86400;
		 return 12;
	}
		
}
int TimeDay(double& t)
{
	int d = t / 86400;
	t -= (d * 86400);
	return d;
}
int TimeHour(double& t)
{
	int h = t / 3600;
	t -= (h * 3600);
	return h;
}
int TimeMinute(double& t)
{
	int m = t / 60;
	t -= (m * 60);
	return m;
}
int main(int argc, char** argv)
{
	ros::init(argc, argv, "cli_client");
	ros::NodeHandle n;
	ros::service::waitForService("my_time_server");
	ros::Publisher time_info_pub = n.advertise<cli::tim>("time_info",10);
	ros::Rate loop_rate(1);
	ros::ServiceClient cli_client = n.serviceClient<ser::name>("my_time_server");
	ser::name srv;
	srv.request.topic_name = "topic_name";
	ROS_INFO("Call service");
	cli_client.call(srv);
	ROS_INFO("Result:%s", srv.response.result.c_str());
	while(ros::ok())
	{
		cli::tim time_msg;
		ros::Time t1 = ros::Time::now();
		double t_cur = t1.toSec();
		time_msg.year = TimeYear(t_cur);
		time_msg.month = TimeMonth(t_cur, time_msg.year);
		time_msg.day = TimeDay(t_cur);
		time_msg.hour = TimeHour(t_cur);
		time_msg.minute = TimeMinute(t_cur);
		time_msg.second = t_cur;
		time_msg.myName = "topic_name";
	       	time_info_pub.publish(time_msg);
		loop_rate.sleep();

	}
	return 0;
}
