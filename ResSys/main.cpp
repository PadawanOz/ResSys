#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "Vehicle.h"
#include "Pickup.h"
//#include "reservation.h"

using namespace std;

int main() {

	int counter = 0; //to keep track of vector position
	string color_init[9] = { "purple", "green", "black", "red", "blue", "yellow", "blue", "black", "green" };

	//read the dodgeball file
	fstream file;
	file.open("dodgeball_team.txt");
	if (!file.is_open())
	{
		cout << "Couldn't find file" << endl;
		exit(0);
	}
	else {
		//categorize everything correctly
		//first three names are pickups, then compacts, then sedans
		for (int x = 0; x < 3; x++) {
			string fname;
			string lname;
			getline(file, fname, ' ');
			getline(file, lname);
			//Pickup(fname, lname, color_init[counter]);
			cout << fname << " " << lname << " " << color_init[counter] << endl;
			counter++;
		}
		for (int x = 0; x < 3; x++) {
			string fname;
			string lname;
			getline(file, fname, ' ');
			getline(file, lname);
			//Compact(fname, lname, color_init[counter]);
			cout << fname << " " << lname << " " << color_init[counter] << endl;
			counter++;
		}
		for (int x = 0; x < 3; x++) {
			string fname;
			string lname;
			getline(file, fname, ' ');
			getline(file, lname);
			//Sedan(fname, lname, color_init[counter]);
			cout << fname << " " << lname << " " << color_init[counter] << endl;
			counter++;
		}
		// put the rest into a vector of type Person
		for (int x = 0; x <= 24; x++) {
			string fname;
			string lname;
			string creds;
			getline(file, fname, ' ');
			getline(file, lname, ' ');
			getline(file, creds);

			//Person(fname,lname, creds);
			cout << fname << " " << lname << " " << creds << endl;
		}

		while (true) {
			cout << "><><><><><><RESERVATION SYSTEM><><><><><><" << endl;
			cout << "[C]reate a reservation!" << endl;
			cout << "[M]odify a reservation!" << endl;
			cout << "[D]elete a reservation!" << endl;
			cout << "[S]how seat diagram!" << endl;
			cout << "[P]rint vehicle data!" << endl;
			cout << "[R]eservations print! (admin only)" << endl;
			cout << "[E]xit reservation system!" << endl;
			cout << "Select an option: ";

			char choice;
			cin >> choice;
			string password = "opensesame";
			string attempt;

			switch (choice) {
			case 'C':
				cout << "Create Function Here!" << endl;
				break;
			case 'M':
				cout << "Modify Function Here!" << endl;
				break;
			case 'D':
				cout << "Delete Function Here!" << endl;
				break;
			case 'S':
				cout << "Seat Diagram Here!" << endl;
				break;
			case 'P':
				cout << "Print function Here!" << endl;
				break;
			case 'R':

				cout << "This function is protected, please enter password." << endl;
				cout << "> ";
				cin >> attempt;
				if (attempt == password) {
					cout << "Welcome, admin!" << endl;
					cout << "Reserve print here!" << endl;
				}
				else {
					cout << "Nope! That's not it!" << endl;
				}
				break;
			case 'E':
				cout << "Bye!" << endl;
				exit(0);

			}
		}



		//run the menu
		//create
		//modify
		//delete
		//display
		//print
		//reservations(pass locked)
	}
}