#pragma once
#include "Vehicle.h"
class Pickup : public Vehicle
{
private:
	bool openSeat;
	int seatCost;
public:
	Pickup();
	void setSeat(bool claim);//0 is open 1 is filled
	bool getSeat();
	int getSeatVal();
};