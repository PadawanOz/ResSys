/*
* person.cpp
* gavin mcintosh and shaun ryan
* cpet 321
* 
* main file for class person. stores much of the reservation info as well.
*/


#include "Person.h"

using namespace std;

Person::Person() {				//constructor-default(applies placeholder values)
	first_name = "NULL";
	last_name = "NULL";
	credits = 0;
	pin = 0;
	carResd = -1;
	colorResd = -1;
	seatResd = -1;
	currSeatCost = 0;
}

Person::Person(string fname, string lname, int creds) { //constructor with name and credit parameters, used in reading file to quickly make people
	first_name = fname;
	last_name = lname;
	credits = creds;
	pin = 0;
	carResd = -1;
	colorResd = -1;
	seatResd = -1;
	currSeatCost = 0;
}

int Person::GetCreds() { //credit accessor
	return credits;
}

void Person::setResInfo(int Car, int Color, int Seat) //reservation mutator, changes the seat, color of car, and type of car
{
	carResd = Car;
	colorResd = Color;
	seatResd = Seat;
}

void Person::SetCreds(int creds_to_set) { //credit mutator
	credits = creds_to_set;
}

void Person::SetFirstName(string name) //first name mutator
{
	first_name = name;
}

void Person::SetLastName(string name) //last name mutator
{
	last_name = name;
}

void Person::SetPin(int pinnum) // PIN mutator
{
	pin = pinnum;
}

void Person::setSpentCred(int spendin) //spent credit mutator
{
	currSeatCost = spendin;
}

int Person::getSpent() // spent credit accessor
{
	return currSeatCost;
}

string Person::GetFirstName()  // first name accessor
{
	return first_name;
}

string Person::Getlastname()
{
	return last_name;
}

void Person::spendCred(int spending) // function for spending credits, used in reservation primarily in create
{
	credits -= spending;
	currSeatCost = spending;
}

int Person::GetPin() // pin accessor
{
	return pin;
}

int Person::GetCar()
{
	return carResd;
}

int Person::GetColor()
{
	return colorResd;
}

int Person::GetSeat()
{
	return seatResd;
}
