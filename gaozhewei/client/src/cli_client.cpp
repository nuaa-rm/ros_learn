#include <ros/ros.h>
#include <client/current_time.h>
#include <client/login.h>
#include <csignal>

ros::ServiceClient service_client;
client::login service_msg;

void interrupt_handler(int i);
bool flag = true;

int main(int argc, char **argv) {
    std::string main_name;
    bool logged = false;
    std::cin>>main_name;
    ros::init(argc, argv, main_name);
    ros::NodeHandle client_node_handle;
    client::current_time publishing_msg;
    ros::Publisher client_publisher =
            client_node_handle.advertise<client::current_time>(main_name, 1);
    service_client =
            client_node_handle.serviceClient<client::login>(
                    "login_service");
    service_msg.request.req_code=1;
    service_msg.request.node_name=main_name;
    service_msg.response.ack_code = 0;
    ros::Rate loop_rate(1.0);
    while(!logged) {
        ROS_INFO("Not logged in, trying again!");
        logged = service_client.call(service_msg);
        if(service_msg.response.ack_code != 10){
            logged = false;
        }
        loop_rate.sleep();
    }
    ROS_INFO("Logged in, publishing the topic!");
    signal(SIGINT, interrupt_handler);
    time_t time_seconds = time(nullptr);
    struct tm now_time{};
    while (ros::ok() && flag) {
        time(&time_seconds);
        localtime_r(&time_seconds, &now_time);
        publishing_msg.name = main_name;
        publishing_msg.year = now_time.tm_year + 1900;
        publishing_msg.month = now_time.tm_mon + 1;
        publishing_msg.day = now_time.tm_mday;
        publishing_msg.hour = now_time.tm_hour;
        publishing_msg.minute = now_time.tm_min;
        publishing_msg.second = now_time.tm_sec;
        client_publisher.publish(publishing_msg);
        loop_rate.sleep();
    }
    return 0;
}
void interrupt_handler(int i) {
    service_msg.request.req_code=10;
    service_client.call(service_msg);
    ROS_INFO("Quit!");
    flag = false;
}
