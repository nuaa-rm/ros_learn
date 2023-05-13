#include <ros/ros.h>
#include <time.h>
#include <client/client_message.h>
#include <client/client_login.h>
#include <client/status_code.h>
#include <vector>

#define SUBSCRIBER_SIZE 10

std::map<std::string, ros::Subscriber> client_storage;

void client_message_callback(const client::client_message & client_message){
    char output_tmp[100];
    time_t _time = client_message.current_time.sec;
    strftime(output_tmp, sizeof(output_tmp),
        "%Y-%m-%d %H:%M:%S", localtime(&_time));
    ROS_INFO("name: %s, time: %s", client_message.name.c_str(), output_tmp);
}

bool client_login(
    client::client_login::Request & req,
    client::client_login::Response & res
    )
    {
    ros::NodeHandle node_handle = ros::NodeHandle("~");
    if(req.require_code == LOGIN){
        ROS_INFO("login request from %s", req.name.c_str());
        if(client_storage.find(req.name) != client_storage.end()){
            ROS_INFO("login failed");
            res.answer_code = FAILED;
        }
        else{
            client_storage[req.name] =
            node_handle.subscribe(
                req.name,
                SUBSCRIBER_SIZE,
                client_message_callback
                );
            res.answer_code = SUCCESS;
        }
    }
    else{
        ROS_INFO("logout request from %s", req.name.c_str());
        auto it = client_storage.find(req.name);
        if(it == client_storage.end()){
            ROS_INFO("logout failed");
            res.answer_code = FAILED;
        }
        else{
            client_storage.erase(it);
            res.answer_code = SUCCESS;
        }
    }
    return true;
}

int main(int argc, char ** argv){
    ros::init(argc, argv, "server");
    ros::NodeHandle node_handle;
    ros::ServiceServer server_login =
        node_handle.advertiseService("/client_login", client_login);
    ROS_INFO("server started");
    ros::spin();
    return 0;
}
