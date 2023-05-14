
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

add_executable(listener_server src/listener_server.cpp)
target_link_libraries(listener_server ${catkin_LIBRARIES})
add_dependencies(listener_server server_gencpp)
