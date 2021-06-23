// Coperight 2021 DoveJH

#include "ros/ros.h"
#include "ser/name.h"
#include "ser/tim.h"

bool serCallback(const ser::name::Request &req,
                const ser::name::Response &res) {
    ROS_INFO("Topic:%s", req.topic_name);
    res.result = "OK";
    return true;
}
void timeInfoCallback(const ser::tim::ConstPtr& msg) {
    ROS_INFO("%s %d", msg->myName.c_str(), msg->tim);
}
int main(int argc, char **argv) {
    char *i;
    ros::init(argc, argv, "my_time_server");
    ros::NodeHandle n;
    ros::ServiceServer name_service =
        n.advertiseService("my_time_server", serCallback);
    ros::Subscriber time_info_suc =
        n.subscribe("time_info", 10, timeInfoCallback);
    ROS_INFO("Ready!");
    ros::spin();
    return 0;
}

