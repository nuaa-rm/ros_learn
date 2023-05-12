#include <ros/ros.h>
#include <time.h>
#include <client/client_message.h>
#include <client/client_login.h>
#include <vector>

#define SUBSCRIBER_SIZE 10

#define LOGIN 0
#define LOGOUT 1
#define NUL 2
#define SUCCESS 3
#define FAILED 4

typedef struct{
    ros::Subscriber client_sub;
    std::string client_name;
}Client_info;

ros::NodeHandle * server_node_handle_ptr = nullptr;
std::vector<Client_info> client_storage;

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
    if(req.require_code == LOGIN){
        ROS_INFO("login request from %s", req.name.c_str());
        Client_info info;

        info.client_sub =
            (*server_node_handle_ptr).subscribe(
                req.name,
                SUBSCRIBER_SIZE,
                client_message_callback
                );

        info.client_name = req.name;
        client_storage.push_back(info);
        res.answer_code = SUCCESS;
    }
    else{
        ROS_INFO("logout request from %s", req.name.c_str());
        for(auto it = client_storage.begin(); it < client_storage.end(); it++){
            if(it -> client_name == req.name){
                it -> client_sub.shutdown();
                client_storage.erase(it);
                break;
            }
        }
        res.answer_code = SUCCESS;
    }
    return true;
}

int main(int argc, char ** argv){
    ros::init(argc, argv, "server");
    ros::NodeHandle server_node_handle;
    server_node_handle_ptr = &server_node_handle;
    ros::ServiceServer server_login =
        server_node_handle.advertiseService("client_login", client_login);
    ROS_INFO("server started");
    ros::spin();
    return 0;
}
