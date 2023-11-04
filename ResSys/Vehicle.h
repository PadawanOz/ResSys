#pragma once
#include "includes.h"
using namespace std;

class Vehicle
{
protected:
	string driverFirst;// first name
	string driverLast;// last name
	string color;// vehicle color
	vector<int> seatCost;
	vector<bool> openSeats;//0 for full, 1 for empty
	int seats;//besides driver
public:
	Vehicle();//constructor

	void setSeatNumber(int seatnums);//functions for manually setting variables
	void setDriver(string fn, string ln);
	void setColor(string colour);

	string getColor();//return color

	void DisplayForTest();//function for making sure vehicle data is being imported correctly.
};