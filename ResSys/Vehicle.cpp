/*
* Vehicle.cpp
* gavin mcintosh and shaun ryan
* cpet 321
*
* main file for class Vehicle.
*/

#include "Vehicle.h"

Vehicle::Vehicle() //constructor -default
{
	seats = 0;
}

void Vehicle::setSeatNumber(int seatnums) //mutator for seats
{
	seats = seatnums;
}

void Vehicle::setSeat(int seat, bool avail) //mutator for seat
{
	if (seat < openSeats.size() && seat >= 0)
	{
		openSeats.at(seat) = avail;
	}
	else
	{
		cout << "invalid seat position. No changes made.";
	}
}

void Vehicle::DisplayForTest() //test function
{
	cout << "Driver " << driverFirst << ' ' << driverLast << " is driving a " << color << " vehicle" << endl;
}

string Vehicle::GetDriverFirst()
{
	return driverFirst;
}

string Vehicle::GetDriverLast()
{
	return driverLast;
}

string Vehicle::getColor() //accessor for color
{
	return color;
}

int Vehicle::getNumSeats() // returns number of open seats
{
	return openSeats.size();
}

int Vehicle::getSeatVal(int seatnumMO) //returns seat position
//assuming you give it seatPos from pin which has a 1 added to it and is never 0
{
	if (seatnumMO < openSeats.size() && seatnumMO >= 0)
	{
		return seatCost.at(seatnumMO - 1);
	}
	else
	{
		cout << "invalid seat position. returning 0.";
		return 0;
	}
}

void Vehicle::setDriver(string fn, string ln) //mutator for driver first and last name
{
	driverFirst = fn;
	driverLast = ln;
}

void Vehicle::setColor(string colour) //mutator for color
{
	color = colour;
}