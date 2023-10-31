#pragma once
#include "Vehicle.h"
#include <iostream>
using namespace std;

class Pickup : public Vehicle
{
private:
	int seatNums = 1;
public:
	Pickup();
	void setSeat(bool claim, int seatNum);//0 is open 1 is filled
	bool getSeat();
	int getSeatVal();
};