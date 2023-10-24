#include "Pickup.h"

Pickup::Pickup()
{
	openSeat = 0;//0 means seat is open
}

void Pickup::setSeat(bool claim)
{
	openSeat = claim;
	seatCost = 5;
}

bool Pickup::getSeat()
{
	return openSeat;
}

int Pickup::getSeatVal()
{
	return 5;
}
