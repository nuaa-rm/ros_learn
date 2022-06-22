#include<ros/ros.h>
#include<server/name.h>
#include<server/tim.h>
int main(int argc, char** argv) {
    ros::init(argc, argv, "cli_client");
    ros::NodeHandle node;
    ros::Time time_1 = ros::Time::now();
    int time_1_1 = time_1.toSec();
    ros::service::waitForService("my_time_server");
    ros::Publisher time_info_pub = node.advertise<ser::tim>("time_info", 10);
    ros::Rate loop_rate(1);
    ros::ServiceClient cli_client =
            node.serviceClient<ser::name>("my_time_server");
    server::name srv;
    srv.request.topic_name = "time_info";
    ROS_INFO("Call service");
    cli_client.call(srv);
    ROS_INFO("Result:%s", srv.response.result.c_str());
    while (ros::ok()) {
        ser::tim time_msg;
        ros::Time time_2 = ros::Time::now();
        int time_2_2 = time_2.toSec();
        time_msg.tim = time_2_2 - time_1_1;
        time_msg.myName = "time_info";
        time_info_pub.publish(time_msg);
        loop_rate.sleep();
    }
    return 0;
}
