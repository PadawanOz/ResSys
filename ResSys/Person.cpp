#include "Person.h"

using namespace std;

Person::Person() {
	first_name = "NULL";
	last_name = "NULL";
	credits = 0;
	pin = 0;
}

Person::Person(string fname, string lname, int creds) {
	first_name = fname;
	last_name = lname;
	credits = creds;
	pin = 0;
}

int Person::GetCreds(){
	return credits;
 }

void Person::setResInfo(int Car, int Color, int Seat)
{
	carResd = Car;
	colorResd = Color;
	seatResd = Seat;
}

void Person::SetCreds(int creds_to_set) {
	credits = creds_to_set;
}

void Person::SetFirstName(string name)
{
	first_name = name;
}

void Person::SetLastName(string name)
{
	last_name = name;
}

void Person::SetPin(int pinnum)
{
	pin = pinnum;
}

void Person::setSpentCred(int spendin)
{
	currSeatCost = spendin;
}

int Person::getSpent()
{
	return currSeatCost;
}

string Person::GetFirstName() 
{
	return first_name;
}

void Person::spendCred(int spending)
{
	credits -= spending;
	currSeatCost = spending;
}

int Person::GetPin()
{
	return pin;
}
