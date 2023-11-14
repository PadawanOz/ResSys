/*
* reservation.h
* gavin mcintosh and shaun ryan
* cpet 321
*
* header file for class reservation.
*/

#pragma once
#include "includes.h"
#include "functions.h"

#define PINlength 4						//constant definitions
#define ResFile "dodgeball_team.txt"
#define PASSWORD "501st"

using namespace std;

class Reservation//only need to have one class instance
{
private:		//private members are vectors of pins, pickups, compacts, sedans, and persons. also two private functions, an accessor and a mutator.

	//Pins will have pointers to where the seat is as well as a number to make them unique(linked to vector length)
	vector<int> PINS;
	//PIN has to be digits long. reservation info now stored in person object. Pin format: seatNum - Random Num

	vector<Pickup> pickups;//carPinVal=1
	vector<Compact> compacts;//carPinVal=2
	vector<Sedan> sedans;//carPinVal=3
	vector<Person> passengers;

	int getPassengerInfo(int& position, int& credits, string FirstName,bool textOn);//dont need to access these from outside.
	void CarInfo(string car, string color, int& carPos, int& carpin, int& colorpin);

	

public:
					//function prototypes
	Reservation();

	int Create();//takes firstname returns int with reservation pin
	int makePIN(int person);

	void Delete();
	void Print();
	void Display();
	void Modify();
	void Unreserve(int carType, int carCol, int seatPos);
	void Reserve(int carType, int carCol, int seatPos, int personPos, int PIN);
	void Reservations();
	void Menu();
};

//Constructor
//Create Reservation: returns pin number YES
//Modify Reservation YES
//Delete Reservation YES
//Display YES
//Print Vehicles YES
//Print Reservations YES
//Menu MAYBE