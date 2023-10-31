#include "Pickup.h"

Pickup::Pickup()
{
	openSeats->at(0) = 1; //1 means seat is open
	seatCost.push_back(5);
}

void Pickup::setSeat(bool claim,int seatNum)
{
	if (seatNum == 0)
	{
		openSeats->at(seatNum) = claim;
	}
	else
	{
		cout << "Invalid Seat. No changes made" << endl;
		//give ErrorCode
	}
}

bool Pickup::getSeat()
{
	return openSeats;
}

int Pickup::getSeatVal()
{
	return 5;
}
