/*
* main.cpp
* gavin mcintosh and shaun ryan
* cpet 321
*
* main file for class main. main is intentionally kept minimal.
*/

#include "includes.h"
#include "Vehicle.h"
#include "Pickup.h"
#include "reservation.h"
#include "functions.h"

//definitions for seat numbers for visual help.
#define passenger	 0
#define windowLeft	 1
#define windowRight	 2
#define middle		 3


using namespace std;

void main()//assuming noone makes more than one reservation.
{
	srand(time(NULL));//set seed based off time so pins should be random with every run. (got code for time useage from a google search)
	Reservation reserve;

	for (int i = 0; i < 10; i++)
	{
		reserve.Menu();
	}
	//reserve.Modify();
	//reserve.Display();
	//reserve.Delete(); 
	//reserve.Display();
	//reserve.Print();

	//reserve.Reservations();

	//--------------TESTING Code--------------//
	// 
	//reserve.Display();
	//cout<<reserve.makePIN(1,3,5,7);

	/*
	for (int i = 0; i < 5; i++)
	{
		cout << makeRand(3) << endl;
	}//*/

	/*
	for (int i = 0; i < reserve.pickups.size(); i++)//debug for correct file reading
	{
		reserve.pickups.at(i).DisplayForTest();
	}//*/
}