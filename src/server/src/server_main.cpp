//
// Created by kevin on 6/25/22.
//
#include <ros/ros.h>
#include <client/current_time.h>
#include <client/login.h>

ros::NodeHandle *server_node_handle_pointer = NULL;
ros::Subscriber server_subscriber;
ros::ServiceServer service_server;

void time_callback(const client::current_time::ConstPtr &msg) {
    ROS_INFO("Topic received from : %s , Whose time is %d/%d/%d-%d:%d:%d ."
            , (msg->name).c_str()
            , msg->year
            , msg->month
            , msg->day
            , msg->hour
            , msg->minute
            , msg->second
    ); //���
}

bool login_handle(client::login::Request &req, client::login::Response &ack) {
    if(req.req_code == 1) {
        ROS_INFO("A client: %s has logged in!", req.node_name.c_str());
        ack.ack_code = 10;
        server_subscriber = (*server_node_handle_pointer).subscribe(req.node_name, 1, time_callback);
    }else{
        ROS_INFO("A client: %s has logged out!", req.node_name.c_str());
        server_subscriber.shutdown();
        ack.ack_code = 20;
    }
    //��ʾ������Ϣ
    //ROS_INFO(��Request from %s with age %d��, req.req_code.c_str(), req.age);
    //��������,���д��response
    //res.feedback = ��Hi �� + req.name + ��. I��m server!��;
    //����true,��ȷ����������
    return true;
}



int main(int argc, char **argv) {
    ros::init(argc, argv, "ros_learn_server");
    ros::NodeHandle server_node_handle;
    server_node_handle_pointer = & server_node_handle;
    server_subscriber = server_node_handle.subscribe("client_pub_current_time", 1, time_callback);
    service_server = server_node_handle.advertiseService("ros_learn_login_service", login_handle);
    ROS_INFO("Server started!", req.node_name.c_str());
    //���ûص�����gpsCallback
    ros::spin();
    //ros::spin()���ڵ������пɴ����Ļص�����,������ѭ��,���᷵��,��������ѭ���ﷴ������spinOnce(),��ros::spinOnce()ֻ��ȥ����һ��
    return 0;
}
/*
 * equest code descrtption:
 *  1:login
 *  2:logout
 * */
