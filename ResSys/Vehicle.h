#pragma once
#include <string>
using namespace std;

class Vehicle
{
protected:
	string driver;
	string color;
public:
	Vehicle();
	void setDriver(string name);
	void setColor(string colour);
};

