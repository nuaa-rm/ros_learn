#include "ros/ros.h"
#include "ser/OfferAService"
use namespace std;
bool tim(ser::OfferAService::Reauest &req, ser::OfferAService::Response &res)
{
	
	return true;
}
int main(int argc, char **argv)
{
	ros::init(argc, argv, "offer_a_service_server");
	ros::NodeHandle n;
	ros::ServiceServer service = n.advertiseService("offer_a_service", tim);
	ros::spin();
	return 0;
}
