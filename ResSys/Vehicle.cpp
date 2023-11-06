#include "Vehicle.h"

Vehicle::Vehicle()
{
	seats = 0;
}

void Vehicle::setSeatNumber(int seatnums)
{
	seats = seatnums;
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

void Vehicle::setDriver(string fn, string ln)
{
	driverFirst = fn;
	driverLast = ln;
}

void Vehicle::setColor(string colour)
{
	color = colour;
}