#pragma once
#include "includes.h"
//#include "functions.h"
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
		int carResd;
		int colorResd;
		int seatResd;
		int currSeatCost;

	public:
		Person();//constructors
		Person(string fname, string lname, int creds);
		
		string GetFirstName();
		
		int GetCreds();
		int GetPin();

		void spendCred(int spending);
		void setResInfo(int Car, int Color, int Seat);
		void SetCreds(int creds_to_set);
		void SetFirstName(string name);
		void SetLastName(string name);
		void SetPin(int pinnum);
		void setSpentCred(int spendin);
		int getSpent();

};
