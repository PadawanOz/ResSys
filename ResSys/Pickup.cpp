#include "Pickup.h"

Pickup::Pickup()
{
	driverFirst = "FirstName";
	driverLast = "LastName";
	color = "Colour";

	openSeats.push_back(1); //1 means seat is open
	seatCost.push_back(5);
	setSeatNumber(1);
}

Pickup::Pickup(string first, string last, string colour)
{
	driverFirst = first;
	driverLast = last;
	color = colour;

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

bool Pickup::getSeat()//return 0 if full 1 is available
{
		return openSeats.at(0);
}

int Pickup::getSeatVal()//doesnt need to be complex since there is one seat.
{
	return seatCost.at(0);
}

char Pickup::dispSeat()
{
	if (openSeats.at(0)==0)
	{
		return('X');
	}
	else
	{
		return (seatCost.at(0))+'0';
	}
}
