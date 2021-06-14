#include "ros/ros.h"
#include "ser/OfferAService"

bool tim(ser::OfferAService::Reauest &req, ser::OfferAService::Response &res)
{
	
	return true;
}
int main(int argc, char **argv)
{
	ros::init(argc, argv, "offer_a_service");
	ros::NodeHandle n;
	ros::ServiceServer service = n.advertiseService
}
