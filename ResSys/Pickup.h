#pragma once
#include "Vehicle.h"
class Pickup : public Vehicle
{
private:
	bool openSeat;
public:
	void setSeat(bool claim);
};