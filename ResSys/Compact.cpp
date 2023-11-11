#include "Compact.h"

Compact::Compact()
{
	driverFirst = "FirstName";
	driverLast = "LastName";
	color = "Colour";

	setSeatNumber(3);//number of seats

	//seat availablility defaults
	openSeats.push_back(1);//fromnt passenger	0
	openSeats.push_back(1);//left Window		1
	openSeats.push_back(1);//righ twindow		2

	//seat prices
	seatCost.push_back(5);//front passenger
	seatCost.push_back(3);//left Window
	seatCost.push_back(3);//right window
}

Compact::Compact(string first, string last, string colour)
{
	driverFirst = first;
	driverLast = last;
	color = colour;

	setSeatNumber(3);//number of seats

	//seat availablility defaults
	openSeats.push_back(1);//fromnt passenger
	openSeats.push_back(1);//left Window
	openSeats.push_back(1);//righ twindow

	//seat prices
	seatCost.push_back(5);//front passenger
	seatCost.push_back(3);//left Window
	seatCost.push_back(3);//right window
}

/*void Compact::setSeat(bool claim, int seatNum)
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

bool Compact::getSeat(int seatNum)
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

int Compact::getSeatVal(int seatNum)
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
}

char Compact::dispSeat(int seatNum)
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
