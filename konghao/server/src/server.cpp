#include <ros/ros.h>
#include <server/time.h>
#include <server/show.h>

#include <vector>
#include <iostream>

server::show srv;
ros::NodeHandle *n_pointer = NULL;
std::vector<ros::Subscriber> server_subscribers;
ros::ServiceServer service_server;

void time_callback(const server::time::ConstPtr& time) 
{
    ROS_INFO("name:%s   time:%s ", time->name.c_str(), time->sec.c_str());
}

// service回调函数，输入参数request，输出参数response
bool show_callback(server::show::Request &request, server::show::Response &response)
{
    if(request.request == 1) 
    {
        ROS_INFO("A client has logged in!");
        response.response = 10;
        server_subscribers.push_back(n_pointer->subscribe(request.node_name, 10, time_callback));
    }
    else
    {
        ROS_INFO("A client has logged out!");

        for(auto &each_subscriber : server_subscribers)
        {
            std::string assist_sig = "/";

            if(assist_sig + request.node_name.c_str() == each_subscriber.getTopic())
            {
                each_subscriber.shutdown();
            }
        }
        response.response = 20;
    }
    return true;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "server");
    ros::NodeHandle n;
    n_pointer = &n;
    ROS_INFO("Server initialized!");

    service_server = n.advertiseService("/show_info", show_callback);

    ros::spin();
    return 0;
}


