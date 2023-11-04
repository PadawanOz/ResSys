#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "Person.h"

using namespace std;

Person::Person() {
	first_name = "NULL";
	last_name = "NULL";
	credits = 0;
}

Person::Person(string fname, string lname, int creds) {
	first_name = fname;
	last_name = lname;
	credits = creds;
}

int Person::GetCreds(){
	return credits;
 }

void Person::SetCreds(int creds_to_set) {
	credits = creds_to_set;
}

string Person::GetFirstName() {
	return first_name;
}