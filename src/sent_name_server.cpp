//
// Created by hlf on 5/10/23.
//
// !server.cpp
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "helifeng/SentName.h"

void chatterCallback(const std_msgs::String::ConstPtr &msg) {
    ROS_INFO("name: [%s]", msg->data.c_str());
}

bool show(helifeng::SentName::Request &req,
          helifeng::SentName::Response &res) {
    ROS_INFO("name: %s", (std::string) req.name);
    //ros::init(argc, argv, "listener");
    //ros::NodeHandle listener_nh;
    //ros::Subscriber sub = listener_nh.subscribe("chatter", 100, chatterCallback);
    //res.sum = req.a + req.b;
    //ROS_INFO("name: %s", (std::string)req.name);
    //ROS_INFO("sending back response: [%ld]", (long int)res.sum);
    return true;
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "sent_name_server");
    ros::NodeHandle nh;

    ros::ServiceServer service = nh.advertiseService("sent_name", show);
    ROS_INFO("Ready");
    ros::spin();

    return 0;
}

/*bool add(beginner_tutorials::AddTwoInts::Request  &req,
         beginner_tutorials::AddTwoInts::Response &res)
{
  res.sum = req.a + req.b;
  ROS_INFO("request: x=%ld, y=%ld", (long int)req.a, (long int)req.b);
  ROS_INFO("sending back response: [%ld]", (long int)res.sum);
  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "helifeng_server");
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("helifeng", add);
  ROS_INFO("Ready to be called.");
  ros::spin();

  return 0;
}*/
