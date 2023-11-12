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

/*void Pickup::setSeat(bool claim)//0 for taken 
{
		openSeats.at(0) = claim;
}//*/

bool Pickup::getSeat()//return 0 if full 1 is available
{
		return openSeats.at(0);
		//if I wasnt already using it without problems I'd put this function into the vehicle class.
}

/*int Pickup::getSeatVal()//doesnt need to be complex since there is one seat.
{
	return seatCost.at(0);
}//*/

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
