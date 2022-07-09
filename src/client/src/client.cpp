#include <ros/ros.h>
#include <ros/time.h>

#include <client/time.h>
#include <client/show.h>

#include <signal.h>
#include <unistd.h>

//#include <chrono>
#include <ctime>
#include <cstring>
#include <iostream>

ros::ServiceClient service_client;
client::show srv;

void interrupt_handler(int x);

int main(int argc, char** argv)
{
    //using namespace std;
    //using namespace std::chrono;
    std::string name;
    ros::init(argc, argv, "auto_node_name", ros::init_options::AnonymousName);

    name = ros::this_node::getName();
    ros::NodeHandle n;
    srv.request.request = 1;
    srv.request.node_name = name;
    srv.response.response = 0;
    ros::service::waitForService("/show_info");
    service_client = n.serviceClient<client::show>("/show_info");
    ros::Rate loop_rate(1);
    service_client.call(srv);
    ROS_INFO("Logged in!");

    ros::Publisher time_topic_pub = n.advertise<client::time>(name, 10);

    signal(SIGINT, interrupt_handler);

    while (ros::ok())
    {
    client::time time_msg;
    //system_clock::time_point now = system_clock::now();
    //time_t tt = system_clock::to_time_t(now);
    using namespace std;
    time_t t = time(0);
    char tmp[32]={NULL};
    strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S",localtime(&t));
    time_msg.sec = tmp;
	time_msg.name = name;

	time_topic_pub.publish(time_msg);

    loop_rate.sleep();
    }

    return 0;
}

void interrupt_handler(int x) 
{
    srv.request.request=10;
    service_client.call(srv);
    ROS_INFO("Logged out!");
    ros::shutdown();
}

