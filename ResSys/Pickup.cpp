#include "Pickup.h"

Pickup::Pickup()
{
	openSeats.push_back(1); //1 means seat is open
	seatCost.push_back(5);
	setSeatNumber(1);
}

void Pickup::setSeat(bool claim,int seatNum)
{
	if (seatNum == 0)
	{
		openSeats.at(seatNum) = claim;
	}
	else
	{
		cout << "Invalid Seat. No Changes Made" << endl;
		//give ErrorCode
	}
}

bool Pickup::getSeat()//might remove
{
		return openSeats.at(0);
}

int Pickup::getSeatVal()//doesnt need to be complex since there is one seat.
{
	return seatCost.at(0);
}
