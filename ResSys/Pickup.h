/*
* Pickup.h
* AUTHORS: Gavin McIntosh and Shaun Ryan
* cpet 321
* 11/13/23
* header file for class Pickup.
*/

#pragma once
#include "Vehicle.h"

class Pickup : public Vehicle
{
public:
	Pickup();//constructors
	Pickup(string first, string last, string colour);

	//void setSeat(bool claim);//1 is open 0 is filled

	bool getSeat();//get seat availability
	//int getSeatVal();//get cost of seat
	char dispSeat();
};