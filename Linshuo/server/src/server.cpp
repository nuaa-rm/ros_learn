#include <ros/ros.h>
#include <client/time.h>
#include <client/show.h>

#include <vector>
#include <iostream>

using namespace std;

client::show srv;
vector<ros::Subscriber> server_subscribers;
vector<ros::Subscriber>::iterator it;
ros::ServiceServer service_server;

void time_callback(const client::time::ConstPtr& time)
{
    // 将接收到的消息打印出来
    ROS_INFO("client_name:%s   time:%s", time->name.c_str(), time->timer.c_str());
}

// service回调函数，输入参数request，输出参数response
bool show_callback(client::show::Request &request, client::show::Response &response)
{
    if(request.request == 1) 
    {
        ROS_INFO("A client: %s has logged in!", request.node_name.c_str());
        response.response = 10;
        ros::NodeHandle n;
        server_subscribers.push_back(n.subscribe(request.node_name, 10, time_callback));
    }
    else
    {
        ROS_INFO("A client: %s has logged out!", request.node_name.c_str());

        for(it = server_subscribers.begin(); it!=server_subscribers.end(); it++)
        {
            string assist_sig = "/";
            if(assist_sig + request.node_name.c_str() == it->getTopic())
            it->shutdown();
            server_subscribers.erase(it);
        }
//        for(auto &each_subscriber : server_subscribers)
//        {
//        }
//        server_subscribers.pop_back();

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
    
    // 1.创建一个名为/show_info的server，注册回调函数show_Callback
    // 2.创建一个Subscriber，订阅名为client_topic的topic，注册回调函数time_Callback
    
    service_server = n.advertiseService("/show_info", show_callback);

    // 循环等待回调函数
    ROS_INFO("Ready to show informtion.");
    ros::spin();

    return 0;
}


