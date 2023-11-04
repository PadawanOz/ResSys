#include "reservation.h"
#define passenger	 0
#define windowLeft	 1
#define windowRight	 2
#define middle		 3

Reservation::Reservation()
{
	FileIn(ResFile, pickups, compacts, sedans, passengers);
}

int Reservation::Create(string FirstName)
{
	int temp = 0;//whatever I need it to be for short periods of time

	for (int i = 0; i < passengers.size(); i++)
	{
		if (passengers.at(i).GetFirstName() == FirstName)//if person exists
		{
			if (passengers.at(i).GetCreds() > 0)//if person has more than 0 credits
			{
				cout << FirstName << " has " << passengers.at(i).GetCreds() << " credits" << endl;
				temp = passengers.at(i).GetCreds();//store their credits for a bit
			}
			else// if person has 0 credits
			{
				cout << FirstName << " has " << passengers.at(i).GetCreds() << " credits and must provide their own transportation." << endl;//error and return
				return 0;
			}
		}
		else// if person doesnt exist
		{
			cout << FirstName << " was not found. Check spelling and try again." << endl;
			return 0;
		}
	}

	//Display Diagram//////////////////////////////////////
	Display();

}

void Reservation::Display()//display all seat availability and costs
{
	int temp = 0;
	
	cout << setw(10) << "Trucks" << setw(11) << "Compact" << setw(10) << "Sedan" << endl;//title peice
	cout << setw(10) << "------" << setw(11) << "-------" << setw(11) << "-------" << endl;

	//car format:
	//0 - 3 - 6
	//1 - 4 - 7
	//2 - 5 - 8


	// setw( ( 11 - (7 - compacts.at(i).getColor().length()) ) ) could be used to center text.
	for (int i = 0; i < 3; i++)
	{
		//display vehicle colors
		cout << setw(10) << pickups.at(i).getColor();
		cout << setw(11) << compacts.at(i).getColor();
		cout << setw(10) << sedans.at(i).getColor();
		cout << endl;

		//First row of seats (Driver and Passenger)
		cout << setw(7) << "(-)" << "(" << pickups.at(i).dispSeat() << ')';
		cout << setw(8) << "(-) " << '(' << compacts.at(i).dispSeat(passenger) << ')';
		cout << setw(9) << "(-)   " << '(' << sedans.at(i).dispSeat(passenger) << ')';
		cout << endl;

		/*--------------no second row for picuptrucks--------------*/
		cout << setw(15) << '(' << compacts.at(i).dispSeat(windowRight) << ')' << " (" << compacts.at(i).dispSeat(windowLeft) << ')';
		cout << setw(4) << '(' << sedans.at(i).dispSeat(windowRight) << ')' << '(' << sedans.at(i).dispSeat(middle) << ')' << '(' << sedans.at(i).dispSeat(windowLeft) << ')';
		cout << endl << endl;

	}
	
}
