#pragma once
#include "Vehicle.h"

class Sedan : public Vehicle
{
public:
	Sedan();//constructors
	Sedan(string first, string last, string colour);//prefered constructor

	void setSeat(bool claim, int seatNum);//1 is open 0 is filled

	bool getSeat(int seatNum);//get seat availability
	int getSeatVal(int seatNum);//get seat cost
	char dispSeat(int seatNum);
};
