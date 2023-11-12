#include "Sedan.h"

Sedan::Sedan()
{
	driverFirst = "FirstName";
	driverLast = "LastName";
	color = "Colour";

	setSeatNumber(4);//number of passender seats
	
	//seat availablility defaults
	openSeats.push_back(1);//fromnt passenger	0
	openSeats.push_back(1);//leftWindo			1
	openSeats.push_back(1);//rightwindow		2
	openSeats.push_back(1);//middleseat			3
	
	//seat prices
	seatCost.push_back(5);//front passenger
	seatCost.push_back(2);//leftWindo
	seatCost.push_back(2);//rightwindow
	seatCost.push_back(1);//middleseat
}

Sedan::Sedan(string first, string last, string colour)
{
	driverFirst = first;
	driverLast = last;
	color = colour;

	setSeatNumber(4);//number of passender seats

	//seat availablility defaults
	openSeats.push_back(1);//fromnt passenger
	openSeats.push_back(1);//leftWindo
	openSeats.push_back(1);//rightwindow
	openSeats.push_back(1);//middleseat

	//seat prices
	seatCost.push_back(5);//front passenger
	seatCost.push_back(2);//leftWindo
	seatCost.push_back(2);//rightwindow
	seatCost.push_back(1);//middleseat
}

/*void Sedan::setSeat(bool claim, int seatNum)
{
	if (seatNum >= 0 && seatNum < seats)
	{
		openSeats.at(seatNum) = claim;
	}
	else
	{
		cout << "Invalid Seat. No Changes Made." << endl;
	}
}//*/

bool Sedan::getSeat(int seatNum)
{
	if (seatNum >= 0 && seatNum < seats)
	{
		return openSeats.at(seatNum);
	}
	else
	{
		cout << "Invalid Seat. Returning False." << endl;
		return(0);
	}
}

/*
int Sedan::getSeatVal(int seatNum)
{
	if (seatNum >= 0 && seatNum < seats)
	{
		return seatCost.at(seatNum);
	}
	else
	{
		cout << "Invalid Seat. Returning 0." << endl;
		return(0);
	}
}//*/

char Sedan::dispSeat(int seatNum)
{
	if (openSeats.at(seatNum) == 0)
	{
		return 'X';
	}
	else
	{
		return (seatCost.at(seatNum)) + '0';
	}
}
