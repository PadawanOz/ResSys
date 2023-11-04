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

string Person::GetFirstName() {
	return first_name;
}

int Person::GetPin()
{
	return pin;
}
