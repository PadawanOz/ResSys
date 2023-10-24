#include "Vehicle.h"

Vehicle::Vehicle()
{
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