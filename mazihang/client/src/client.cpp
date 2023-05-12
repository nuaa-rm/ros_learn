#include "ros/ros.h"
#include "client/time.h"

#include "time.h"
#include <iostream>

int main(int argc, char** argv)
{
    struct tm *local;
    time_t t;
    t=time(NULL);
    local=localtime(&t);

    ros::init(argc,argv,"client");

    ros::NodeHandle n;

    ros::Publisher pub=n.advertise<client::time>("client",1000);

    client::time time0;
    time0.name="client";
    time0.year=local->tm_year+1900;
    time0.month=local->tm_mon+1;
    time0.day=local->tm_mday;
    time0.hour=local->tm_hour;
    time0.minute=local->tm_min;
    time0.second=local->tm_sec;

    ros::Rate rate(1);

    while(ros::ok()){
        pub.publish(time0);
        rate.sleep();
        ros::spin();
    }

    return 0;
}