# ros_learn
入队培训ROS学习练习  
练习内容：  
完成一个ros程序，分为client和server两个pack  
client发布一个topic（名称同name），每1s发送一次当前时间和name  
server提供一个服务，供client注册，client启动后调用该服务发送自己topic的名称，server订阅该topic，并将收到的数据显示出来（需要显示消息内容和来自的客户端名称）  
client如果要退出，则应该在退出前再次调用server的服务，但此次为注销客户端（使用不同的req区分），server收到注销请求后应该销毁对应的subscriber并不再从该topic接收消息
