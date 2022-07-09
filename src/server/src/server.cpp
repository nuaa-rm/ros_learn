#include <ros/ros.h>
#include <client/time.h>
#include <client/show.h>

#include <vector>
#include <iostream>

client::show srv;
std::vector<ros::Subscriber> server_subscribers;
ros::ServiceServer service_server;

void time_callback(const client::time::ConstPtr& time)
{
    ROS_INFO("name:%s   time:%s ", time->name.c_str(), time->sec.c_str());
}

bool show_callback(client::show::Request &request, client::show::Response &response)
{
    if(request.request == 1) 
    {
        ROS_INFO("A client has logged in!");
        response.response = 10;
        ros::NodeHandle n;
        server_subscribers.push_back(n.subscribe(request.node_name, 10, time_callback));
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

        server_subscribers.clear();
        response.response = 20;
    }
    return true;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "server");
    ros::NodeHandle n;
    ROS_INFO("Server initialized!");

    service_server = n.advertiseService("/show_info", show_callback);

    ros::spin();
    return 0;
}


