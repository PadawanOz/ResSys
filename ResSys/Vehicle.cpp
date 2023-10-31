#include "Vehicle.h"

Vehicle::Vehicle()
{
	seats = 0;
}

void Vehicle::setSeatNumber(int seatnums)
{
	seats = seatnums;
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