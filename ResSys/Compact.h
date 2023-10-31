#pragma once
#include "Vehicle.h"

class Compact : public Vehicle
{
public:
	Compact();
	void setSeat(bool claim, int seatNum);//1 is open 0 is filled
	bool getSeat(int seatNum);
	int getSeatVal(int seatNum);
};
