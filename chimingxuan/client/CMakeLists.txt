cmake_minimum_required(VERSION 3.0.2)
project(client)

find_package(catkin REQUIRED COMPONENTS
        roscpp
        rospy
        std_msgs
        message_generation
        server
        )


## Generate messages in the 'msg' folder
#add_message_files(
#        FILES
#        Num.msg
#)

## Generate services in the 'srv' folder
#add_service_files(
#        FILES
#
#)

## Generate actions in the 'action' folder
# add_action_files(
#   FILES
#   Action1.action
#   Action2.action
# )

## Generate added messages and services with any dependencies listed here
generate_messages(
        DEPENDENCIES
        std_msgs
)

catkin_package(
        #  INCLUDE_DIRS include
        #  LIBRARIES beginner_tutorials
        #  CATKIN_DEPENDS roscpp rospy std_msgs
        CATKIN_DEPENDS message_runtime
        #  DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
        include
        ${catkin_INCLUDE_DIRS}
)

add_executable(client src/client.cpp)
target_link_libraries(client ${catkin_LIBRARIES})
add_dependencies(client client_generate_messages_cpp)
add_dependencies(client client_gencpp)
