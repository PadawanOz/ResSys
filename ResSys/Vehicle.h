/*
* Vehicle.h
* gavin mcintosh and shaun ryan
* cpet 321
* 11/13/23
* header file for class Vehicle.
*/
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
	vector<int> pinsResd;//first digit is person location for different class, second is random, last digit is which seat

	int seats;//besides driver

public:
	Vehicle();//constructor

	void setSeatNumber(int seatnums);//functions for manually setting variables
	void setDriver(string fn, string ln);
	void setColor(string colour);
	void setSeat(int seat, bool avail);//0 for full, 1 for taken
	void DisplayForTest();//function for making sure vehicle data is being imported correctly.

	string GetDriverFirst();
	string GetDriverLast();

	int getSeatVal(int seatnumMO);
	int getNumSeats();

	string getColor();//return color


};