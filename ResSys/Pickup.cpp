/*
* Pickup.cpp
* gavin mcintosh and shaun ryan
* cpet 321
*
* main file for class Pickup. Pickup is a subclass of Vehicle
*/

#include "Pickup.h"

Pickup::Pickup() //constructor-default
{
	driverFirst = "FirstName";
	driverLast = "LastName";
	color = "Colour";

	openSeats.push_back(1); 
	seatCost.push_back(5);
	setSeatNumber(1);
}

Pickup::Pickup(string first, string last, string colour) //constructor-params
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

bool Pickup::getSeat()// get seat num
{
	return openSeats.at(0);
	
}

/*int Pickup::getSeatVal()//doesnt need to be complex since there is one seat.
{
	return seatCost.at(0);
}//*/

char Pickup::dispSeat() //displays seat
{
	if (openSeats.at(0) == 0)
	{
		return('X');
	}
	else
	{
		return (seatCost.at(0)) + '0';
	}
}