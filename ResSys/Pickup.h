#pragma once
#include "Vehicle.h"

class Pickup : public Vehicle
{
public:
	Pickup();//constructors
	Pickup(string first,string last,string colour);//should use this one

	//void setSeat(bool claim);//1 is open 0 is filled

	bool getSeat();//get seat availability
	//int getSeatVal();//get cost of seat
	char dispSeat();
};