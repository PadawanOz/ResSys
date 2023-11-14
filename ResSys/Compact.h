/*
* Compact.h
* gavin mcintosh and shaun ryan
* cpet 321
*
* header file for class compact.
*/
#pragma once
#include "Vehicle.h"

class Compact : public Vehicle 
{
public:
	Compact();//constructors
	Compact(string first, string last, string colour); 

	//void setSeat(bool claim, int seatNum);// set to 1 is open 0 is filled

	bool getSeat(int seatNum);//get seat availability
	//int getSeatVal(int seatNum);//get seat values
	char dispSeat(int seatNum);// return either X for full or the cost of the seat.
};