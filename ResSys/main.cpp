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

void main()//assuming noone tries to make more than one reservation. (But assuming I forget things ill make a case for it anyway.)
{
	srand(time(NULL));//set seed based off time so pins should be random with every run. (got code for time useage from a google search)
	Reservation reserve;

	while (true)//all the main we need. Mostly.
	{
		reserve.Menu();
	}
}