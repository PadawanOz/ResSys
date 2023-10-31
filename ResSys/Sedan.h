#pragma once
#include "Vehicle.h"

class Sedan : public Vehicle
{
public:
	Sedan();
	void setSeat(bool claim, int seatNum);//1 is open 0 is filled
	bool getSeat(int seatNum);//get seat availability
	int getSeatVal(int seatNum);//get seat cost
};
