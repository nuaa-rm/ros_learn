cmake_minimum_required(VERSION 3.0.2)
project(server)

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

add_service_files(
        DIRECTORY srv
        FILES
        service.srv
)

generate_messages(
        DEPENDENCIES
        std_msgs
)

catkin_package(
        CATKIN_DEPENDS
        message_runtime
)

add_executable(server_node src/server_node.cpp)
target_link_libraries(server_node ${catkin_LIBRARIES})