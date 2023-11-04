#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

class Person {
	private:
		string first_name;
		string last_name;
		int credits;
	public:
		Person();
		Person(string fname, string lname, int creds);
		int GetCreds();
		void SetCreds(int creds_to_set);
		string GetFirstName();

};
