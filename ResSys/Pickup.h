#pragma once
#include "Vehicle.h"

class Pickup : public Vehicle
{
public:
	Pickup();
	void setSeat(bool claim, int seatNum);//1 is open 0 is filled
	bool getSeat();
	int getSeatVal();
};