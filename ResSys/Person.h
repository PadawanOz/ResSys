/*
* person.h
* gavin mcintosh and shaun ryan
* cpet 321
*
* header file for class person.
*/

#pragma once
#include "includes.h"


using namespace std;

class Person { 
private:					// private members are full name, credits, current seat cost, seat in car, color of car, type of car, and PIN
	string first_name;
	string last_name;
	int credits;
	int pin;
	int carResd;//which kind Car(pickup = )
	int colorResd;//positon in car vector(index+)
	int seatResd;//which seat (index+)
	int currSeatCost;

public:						//function prototypes, purposes detailed in person.cpp documentation
	Person();
	Person(string fname, string lname, int creds);

	string GetFirstName();
	string Getlastname();

	int GetCreds();
	int GetPin();
	int GetCar();
	int GetColor();
	int GetSeat();
	int getSpent();

	void spendCred(int spending);
	void setResInfo(int Car, int Color, int Seat);
	void SetCreds(int creds_to_set);
	void SetFirstName(string name);
	void SetLastName(string name);
	void SetPin(int pinnum);
	void setSpentCred(int spendin);
};