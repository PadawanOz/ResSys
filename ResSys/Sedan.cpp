#include "Sedan.h"

Sedan::Sedan()
{
	setSeatNumber(4);//number of passender seats
	
	//seat availablility defaults
	openSeats.push_back(1);//fromnt passenger
	openSeats.push_back(1);//leftWindo
	openSeats.push_back(1);//rightwindow
	openSeats.push_back(1);//middleseat
	
	//seat prices
	seatCost.push_back(5);//front passenger
	seatCost.push_back(2);//leftWindo
	seatCost.push_back(2);//rightwindow
	seatCost.push_back(1);//middleseat
}

void Sedan::setSeat(bool claim, int seatNum)
{
	if (seatNum >= 0 && seatNum < seats)
	{
		openSeats.at(seatNum) = claim;
	}
	else
	{
		cout << "Invalid Seat. No Changes Made." << endl;
	}
}

bool Sedan::getSeat(int seatNum)
{
	if (seatNum >= 0 && seatNum < seats)
	{
		return openSeats.at(seatNum);
	}
	else
	{
		cout << "Invalid Seat. Returning False." << endl;
		return(0);
	}
}

int Sedan::getSeatVal(int seatNum)
{
	if (seatNum >= 0 && seatNum < seats)
	{
		return seatCost.at(seatNum);
	}
	else
	{
		cout << "Invalid Seat. Returning 0." << endl;
		return(0);
	}
}
