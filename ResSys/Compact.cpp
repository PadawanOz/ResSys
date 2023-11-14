/*
* Compact.cpp
* gavin mcintosh and shaun ryan
* cpet 321
* 11/13/23
* main file for class compacts. compacts is a subclass of class vehicle.
*/

#include "Compact.h"

Compact::Compact() //constructor-default
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

Compact::Compact(string first, string last, string colour) //constructor with params
{
	driverFirst = first;
	driverLast = last;
	color = colour;

	setSeatNumber(3);//number of seats

	//seat availablility defaults
	openSeats.push_back(1);//front passenger
	openSeats.push_back(1);//left Window
	openSeats.push_back(1);//righ twindow

	//seat prices
	seatCost.push_back(5);//front passenger
	seatCost.push_back(3);//left Window
	seatCost.push_back(3);//right window
}



bool Compact::getSeat(int seatNum) //accessir for seat, grabs from vehicle
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


char Compact::dispSeat(int seatNum)		//function for display
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