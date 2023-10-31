#pragma once
#include "Vehicle.h"

class Compact : public Vehicle
{
private:
	//int seatNums = 3;
public:
	Compact();
	void setSeat(bool claim, int seatNum);//1 is open 0 is filled
	bool getSeat();
	int getSeatVal();
};
