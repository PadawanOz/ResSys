#include "Vehicle.h"

Vehicle::Vehicle()
{
	seats = 0;
}

void Vehicle::setSeatNumber(int seatnums)
{
	seats = seatnums;
}

void Vehicle::setSeat(int seat, bool avail)
{
	if (seat < openSeats.size() && seat>=0)
	{
		openSeats.at(seat) = avail;
	}
	else
	{
		cout << "invalid seat position. No changes made.";
	}
}

void Vehicle::DisplayForTest()
{
	cout << "Driver " << driverFirst << ' ' << driverLast << " is driving a " << color << " vehicle" << endl;
}

string Vehicle::getColor()
{
	return color;
}

int Vehicle::getNumSeats()
{
	return openSeats.size();
}

int Vehicle::getSeatVal(int seatnumMO)//assuming you give it seatPos from pin which has a 1 added to it and is never 0
{
	if (seatnumMO < openSeats.size() && seatnumMO >= 0)
	{
		return seatCost.at(seatnumMO-1);
	}
	else
	{
		cout << "invalid seat position. returning 0.";
		return 0;
	}
}

void Vehicle::setDriver(string fn, string ln)
{
	driverFirst = fn;
	driverLast = ln;
}

void Vehicle::setColor(string colour)
{
	color = colour;
}