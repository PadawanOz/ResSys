#pragma once
#include "includes.h"
//#include <string>
//#include <vector>
//#include <fstream>
//#include <iostream>

using namespace std;

class Person {
	private:
		string first_name;
		string last_name;
		int credits;
		int pin;

	public:
		Person();//constructors
		Person(string fname, string lname, int creds);
		
		string GetFirstName();
		int GetCreds();
		int GetPin();
		
		void SetCreds(int creds_to_set);
		void SetFirstName(string name);
		void SetLastName(string name);
		void SetPin(int pinnum);

};
