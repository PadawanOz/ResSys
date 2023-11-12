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
	//PIN has to be digits long. reservation info now stored in person object. Pin format: seatNum - Random Num

	vector<Pickup> pickups;//carPinVal=1
	vector<Compact> compacts;//carPinVal=2
	vector<Sedan> sedans;//carPinVal=3
	vector<Person> passengers;
	
	int getPassengerInfo(int& position, int& credits, string FirstName, string entered);//dont need to access these from outside.
	void CarInfo(string car, string color, int& carPos, int& carpin, int& colorpin);

public:
	
	Reservation();
	int Create();//takes firstname returns int with reservation pin
	void Display();
	int makePIN(int person);
	void Modify();
	

};

//Constructor
//Create Reservation: returns pin number
//Modify Reservation
//Delete Reservation
//Display
//Print Vehicles
//Print Reservations
//Menu