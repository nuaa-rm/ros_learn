cmake_minimum_required(VERSION 3.0.2)
project(client)

find_package(catkin REQUIRED COMPONENTS
        roscpp
        rospy
        std_msgs
        message_generation
        )

include_directories(
        include
        ${catkin_INCLUDE_DIRS}
)

add_message_files(
        DIRECTORY msg
        FILES
        message.msg
)

generate_messages(
        DEPENDENCIES
        std_msgs
)

catkin_package(
        CATKIN_DEPENDS
        message_runtime
)

add_executable(client_node src/client_node.cpp)
target_link_libraries(client_node ${catkin_LIBRARIES})