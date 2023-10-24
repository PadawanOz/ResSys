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
public:
	Vehicle();
	void setDriver(string fn, string ln);
	void setColor(string colour);
};