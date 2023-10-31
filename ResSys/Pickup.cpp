#include "Pickup.h"

Pickup::Pickup()
{
	openSeat = 0;//0 means seat is open
	seatCost.push_back(5);
}

void Pickup::setSeat(bool claim)
{
	openSeat = claim;
	//seatCost = 5;
}

bool Pickup::getSeat()
{
	return openSeat;
}

int Pickup::getSeatVal()
{
	return 5;
}
