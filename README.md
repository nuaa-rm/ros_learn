# ros_learn
入队培训ROS学习练习  
练习内容：  
完成一个ros程序，分为client和server两个pack  
client发布一个topic（名称同name），每1s发送一次当前时间和name  
server提供一个服务，供client注册，client启动后调用该服务发送自己topic的名称，server订阅该topic，并将收到的数据显示出来  
仓库中目录结构参考：
```
ros工作空间
 - devel
 - build
 - src（此目录为git根目录）
   - cmakelist.txt
   - 以你的名字命名的文件夹（英文）
     - cmakelist.txt
     - client包
     - server包
```
