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

add_executable(talker_client src/talker_client.cpp)
target_link_libraries(talker_client ${catkin_LIBRARIES})
add_dependencies(talker_client client_generate_messages_cpp)
