#pragma once
#include "includes.h"
#include "functions.h"

#define PINlength 4
#define ResFile "dodgeball_team.txt"

using namespace std;

class Reservation//only need to have one class instance
{
private:
	//Pins will have pointers to where the seat is as well as a number to make them unique(linked to vector length)
	vector<int> PINS;
	//PIN=car-colorPos(where in vehicle vector car is)-seatPos-passengerPos-PINLength

	vector<Pickup> pickups;//carPinVal=1
	vector<Compact> compacts;//carPinVal=2
	vector<Sedan> sedans;//carPinVal=3
	vector<Person> passengers;
public:
	
	Reservation();
	int Create();//takes firstname returns int with reservation pin
	void Display();
	int makePIN(int car, int color, int seat, int person);
	

};

//Constructor
//Create Reservation: returns pin number
//Modify Reservation
//Delete Reservation
//Display
//Print Vehicles
//Print Reservations
//Menu