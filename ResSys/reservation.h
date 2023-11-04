#pragma once
#include "includes.h"
#include "functions.h"

#define PINlength 4
#define ResFile "dodgeball_team.txt"

using namespace std;

class Reservation//only need to have one class instance
{
private:
	vector<int> PINS;
	vector<Pickup> pickups;
	vector<Compact> compacts;
	vector<Sedan> sedans;
	vector<Person> passengers;
public:
	
	Reservation();
	int Create(string FirstName);//takes firstname returns int with reservation pin
	void Display();


};

//Constructor
//Create Reservation: returns pin number
//Modify Reservation
//Delete Reservation
//Display
//Print Vehicles
//Print Reservations
//Menu