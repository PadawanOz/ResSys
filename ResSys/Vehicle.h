#pragma once
#include <string>
#include <vector>
using namespace std;

class Vehicle
{
protected:
	string driverFirst;// first name
	string driverLast;// last name
	string color;// vehicle color
	vector<int> seatCost;
	vector<bool> openSeats;
	int seats;//besides driver
public:
	Vehicle();
	void setSeatNumber(int seatnums);
	void setDriver(string fn, string ln);
	void setColor(string colour);
};