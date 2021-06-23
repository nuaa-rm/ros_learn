// Copyright 2021 DoveJH

#include<ros/ros.h>
#include<ser/name.h>
#include<ser/tim.h>
/*
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
int TimeYear(long long& t)
{
	int count = 1970;
	for(;t > (loopYear(count)?loopYearSecond:comYearSecond);count++ )
	{
		t -= (loopYear(count)?loopYearSecond:comYearSecond);
	}
	return count;
}
int TimeMonth(long long& t, int year)
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
int TimeDay(long long& t)
{
	int d = t / 86400;
	t -= (d * 86400);
	return d + 1;
}
int TimeHour(long long& t, int year)
{
	int loop = 0, com = 0;
	for(int i = 1970; i < year; i ++)
	{
		if(loopYear(i))loop++;
		else com ++;
	}
	t -= (com * comYearSecond + loop * loopYearSecond);
	t = t -((long long)(t/86400)) * 86400;
	int h = t / 3600;
	t -= (h * 3600);
	return h + 1;
}
int TimeMinute(long long& t)
{
	int m = t / 60;
	t -= (m * 60);
	return m + 1;
}*/
int main(int argc, char** argv) {
    ros::init(argc, argv, "cli_client");
    ros::NodeHandle n;
    ros::Time t1 = ros::Time::now();
    int t11 = t1.toSec();
    ros::service::waitForService("my_time_server");
    ros::Publisher time_info_pub = n.advertise<ser::tim>("time_info", 10);
    ros::Rate loop_rate(1);
    ros::ServiceClient cli_client =
        n.serviceClient<ser::name>("my_time_server");
    ser::name srv;
    srv.request.topic_name = "time_info";
    ROS_INFO("Call service");
    cli_client.call(srv);
    ROS_INFO("Result:%s", srv.response.result.c_str());
    while (ros::ok()) {
        ser::tim time_msg;
/*ros::Time t1 = ros::Time::now();
double t_cur = t1.toSec();
long long t2 = t_cur;
		long long t3 = t_cur;
		time_msg.year = TimeYear(t2);
		time_msg.month = TimeMonth(t2, time_msg.year);
		time_msg.day = TimeDay(t2);
		time_msg.hour = TimeHour(t3, time_msg.year);
		time_msg.minute = TimeMinute(t3);
		time_msg.second = t3;*/
        ros::Time t2 = ros::Time::now();
        int t22 = t2.toSec();
        time_msg.tim = t22 - t11;
        time_msg.myName = "time_info";
        time_info_pub.publish(time_msg);
        loop_rate.sleep();
    }
    return 0;
}

