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

void main()
{
	Reservation reserve;

	reserve.Display();
	
	/*
	for (int i = 0; i < reserve.pickups.size(); i++)//debug for correct file reading
	{
		reserve.pickups.at(i).DisplayForTest();
	}//*/

}