#include <ros/ros.h>
#include <time.h>

#include <server/time.h>
#include <server/show.h>

#include <vector>
#include <iostream>

server::show srv;

ros::NodeHandle *n_pointer;

std::vector<ros::Subscriber> server_subscribers;

ros::ServiceServer service_server;

void time_callback(const server::time::ConstPtr& time)
{
    time_t  cur_t=time->second;
    struct tm *t=localtime(&cur_t);

    int year = t->tm_year + 1900; // years since 1900
    int month = t->tm_mon + 1; // months since January - [0, 11]
    int day = t->tm_mday;

    int hour = t->tm_hour;
    int minute = t->tm_min;
    int second = t->tm_sec;

    ROS_INFO("The name of client:%s   time: %d-%d-%d  %d : %d : %d  ", time->name.c_str(), year, month, day, hour, minute, second);
}

// service回调函数，输入参数request，输出参数response
bool show_callback(server::show::Request &request,
                   server::show::Response &response)
{
    if(request.request == 1)
    {
        ROS_INFO("The name of client: %s logged in",
                 request.name.c_str());
        response.response = 10;
        server_subscribers.push_back(n_pointer->subscribe(request.name, 10, time_callback));
    }
    else
    {
        ROS_INFO("The name of client: %s logged out",
                 request.name.c_str());
        for(auto &subscriber : server_subscribers)
        {
            std::string the_string = "/";
            if(the_string + request.name.c_str() == subscriber.getTopic())
                subscriber.shutdown();
        }
        response.response = 20;
    }
    return true;
}

int main(int argc, char **argv)
{
    // ROS节点初始化
    ros::init(argc, argv, "server");

    // 创建节点句柄
    ros::NodeHandle n;
    n_pointer = &n;

    service_server = n.advertiseService("/show_info", show_callback);

    // 循环等待回调函数
    ROS_INFO("show the information.");
    ros::spin();

    return 0;
}

