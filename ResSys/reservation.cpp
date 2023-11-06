#include "reservation.h"
#define passenger	 0
#define windowLeft	 1
#define windowRight	 2
#define middle		 3
#define Cars 3

Reservation::Reservation()
{
	FileIn(ResFile, pickups, compacts, sedans, passengers);
}

int Reservation::Create(string FirstName)//returns pin number
{
	string seatChoice;
	string tempColor;
	string tempCar;
	string tempSeat;
	int temp = 0;//whatever I need it to be for short periods of time
	int cred = 0;

	//init to 0
	int CarPin = 0;//1=truck,2=compact,3=sedan
	int PosPin = 0;//1=Car1,2=Car2,3=Car3 (found by color/car's position in the vehicle vector + 1)
	int seatPos = 0;//1=frontSeat,2=windowLeft,3=windowRight,4=middle (corrisponds to the position in the vehicle vector + 1)
	int PinNum = 0;//will be length of pin vector

	for (int i = 0; i < passengers.size(); i++)
	{
		if (passengers.at(i).GetFirstName() == FirstName)//if person exists
		{
			if (passengers.at(i).GetCreds() > 0)//if person has more than 0 credits
			{
				cout << FirstName << " has " << passengers.at(i).GetCreds() << " credits" << endl;
				cred = passengers.at(i).GetCreds();//store their credits for a bit
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

	//Display Diagram//
	Display();

	cout << "Choose a seat to reserve," << endl;
	cout << "please enter a seat catagory: " << "Specific, Passenger, Back Window, Side Window, or Middle" << endl;
	//cout << " Or a specific seat following the format of 'color car seattype'" << endl;
	
	cin >> seatChoice;
	seatChoice = makeLower(seatChoice);

	if (seatChoice=="passenger")//seat 0
	{
		//check for first available passenger seat (any car)-------------------------------------
		for (int i = 0; i < Cars; i++)//using Cars as size of the vehicle vectors. could make it modular with pickups.length() but no need.
		{
			if (pickups.at(i).getSeat() == 1)//if seat open
			{
				CarPin = 1;
				PosPin = i;
				seatPos = 1;
			}
		}
		for (int i = 0; i < Cars; i++)
		{
			if (compacts.at(i).getSeat(0) == 1)//if is open
			{
				CarPin = 2;
				PosPin = i;
				seatPos = 1;
			}
		}
		for (int i = 0; i < Cars; i++)
		{
			if (sedans.at(i).getSeat(0) == 1)//if is available
			{
				CarPin = 3;
				PosPin = i;
				seatPos = 1;
			}
		}

	}
	else if (seatChoice == "back window")//seat 1 and 2
	{
		//check for first avaiable window seat (compact)-------------------------------------

		//only need to check compact's seats 1 and 2
		for (int i = 0; i < Cars; i++)
		{
			if (compacts.at(i).getSeat(1) == 1)//if is open
			{
				CarPin = 2;
				PosPin = i;
				seatPos = 2;
			}
			else if (compacts.at(i).getSeat(2) == 1)
			{
				CarPin = 2;
				PosPin = i;
				seatPos = 3;
			}
		}
	
	}
	else if (seatChoice == "side window")//seat 1 and 2
	{
		//check for first available window seat (sedan)-------------------------------------

		//only need to check sedans's seats 1 and 2
		for (int i = 0; i < Cars; i++)
		{
			if (sedans.at(i).getSeat(1) == 1)//if is open
			{
				CarPin = 3;
				PosPin = i;
				seatPos = 2;
			}
			else if (sedans.at(i).getSeat(2) == 1)
			{
				CarPin = 3;
				PosPin = i;
				seatPos = 3;
			}
		}
	}
	else if(seatChoice=="middle")//seat 3
	{
		//check for first available middle seat (sedan)-------------------------------------

		//only need to check sedans's seat 3
		for (int i = 0; i < Cars; i++)
		{
			if (sedans.at(i).getSeat(3) == 1)//if is open
			{
				CarPin = 3;
				PosPin = i;
				seatPos = 4;
			}
		}
	}
	else if (seatChoice == "specific")
	{
		//get color, model, and seat type
		cout << "What type of car would you like to reserve? (compact, sedan, pickup) \n>>";//forgot to ask about generic seating
		cin >> tempCar;
		cout << "What color of car? \n>>";
		cin >> tempColor;
		cout << "Which seat?";
		cin >> tempSeat;

		//check if available-------------------------------------

	}
	else
	{
		//Error try again
	}
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
