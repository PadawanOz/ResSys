/*
* TITLE: main.cpp
* AUTHORS: Gavin McIntosh and Shaun Ryan
* COURSE: cpet 321
* DATE: 11/13/23
* DESCRIPTION: file for class main. main is intentionally kept minimal. Loop Calls Menu Function.
*/

#include "includes.h"
#include "Vehicle.h"
#include "Pickup.h"
#include "reservation.h"
#include "functions.h"

using namespace std;

void main()
{
	srand(time(NULL));//set seed based off time so pins should be random with every run. (got code for time useage from a google search)
	Reservation reserve;

	while (true)//all the main we need. Mostly. Just Loop Menu.
	{
		reserve.Menu();//has way to break loop
	}
}