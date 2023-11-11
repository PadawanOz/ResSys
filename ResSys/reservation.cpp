#include "reservation.h"
//ease of access values
#define passengerValue	5
#define BackValue		3
#define SideValue		2
#define MiddleValue		1
#define passenger		0
#define windowLeft		1
#define windowRight		2
#define middle			3
#define Cars			3

Reservation::Reservation()
{
	FileIn(ResFile, pickups, compacts, sedans, passengers);
}

int Reservation::Create()//returns pin number
{
	string seatChoice;
	string tempColor;
	string tempCar;
	string tempSeat;
	string FirstName;

	int temp = 0;//whatever I need it to be for short periods of time
	int cred = 0;
	int tempcol=-1;

	int ReturnPIN=0;

	//--------------Digits for the Pin--------------------//
	//init to 0 for value checking

	int CarPin = 0;//1=truck,2=compact,3=sedan
	int PosPin = 0;//1=Car1,2=Car2,3=Car3 (found by color/car's position in the vehicle vector + 1)
	int seatPos = 0;//1=frontSeat,2=windowLeft,3=windowRight,4=middle (corrisponds to the position in the vehicle vector + 1)
	int PersonPos = 0;//Where person is in vector

	cout << "First name: ";
	cin >> FirstName;
	FirstName = makeLower(FirstName);

	for (int i = 0; i < passengers.size(); i++)
	{
		if (makeLower(passengers.at(i).GetFirstName()) == FirstName)//if person exists
		{
			if (passengers.at(i).GetCreds() > 0)//if person has more than 0 credits
			{
				cout << FirstName << " has " << passengers.at(i).GetCreds() << " credits" << endl;
				PersonPos = i;
				cred = passengers.at(i).GetCreds();//store their credits for a bit
				break;
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
	cout << "please enter a seat catagory: " << "Specific, Passenger, Back Seat, Side Window, or Middle" << endl;
	//cout << " Or a specific seat following the format of 'color car seattype'" << endl;
	
	cin >> seatChoice;
	seatChoice = makeLower(seatChoice);

	if (seatChoice=="passenger")//seat 0
	{
		//check for first available passenger seat (any car)-------------------------------------
		if (cred < passengerValue)
		{
			cout << "Not enough credits for this seat. You need at least " << passengerValue << " credits. You have " << cred << " credits." << endl;
			//error start over.
		}
		
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
	else if (seatChoice == "back seat")//seat 1 and 2
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
		cout << "What type of car would you like to reserve? (pickup, compact, sedan) \n>>";//get car type
		cin >> tempCar;
		cout << "What color of car? \n>>";//get car color
		cin >> tempColor;
		cout << "Which seat? (Passenger, Window, or Middle)";//get seat type
		cin >> tempSeat;

		//Strings to lowercase
		tempCar = makeLower(tempCar);
		tempColor = makeLower(tempColor);
		tempSeat = makeLower(tempSeat);

		//-------------------------------------check if available-------------------------------------

		
		//-----------color to int and set CarPin-----------
		if (tempCar == "pickup")
		{
			CarPin = 1;
			for (int i = 0; i < pickups.size(); i++)
			{
				if (pickups.at(i).getColor() == tempColor)
				{
					tempcol = i;
					PosPin = i + 1;
				}
			}
			if (tempcol == -1)
			{
				//error
				cout << "No car mathcing your description was found." << endl;
			}
		}
		if (tempCar == "compact")
		{
			CarPin = 2;
			for (int i = 0; i < compacts.size(); i++)
			{
				if (compacts.at(i).getColor() == tempColor)
				{
					tempcol = i;
					PosPin = i + 1;
				}
			}
			if (tempcol == -1)
			{
				//error
				cout << "No car mathcing your description was found." << endl;
			}
		}
		if (tempCar == "sedan")
		{
			CarPin = 3;
			for (int i = 0; i < sedans.size(); i++)
			{
				if (sedans.at(i).getColor() == tempColor)
				{
					tempcol = i;
					PosPin = i + 1;
				}
			}
			if (tempcol == -1)
			{
				//error
				cout << "No car mathcing your description was found." << endl;
			}
		}
		//-----------Seat to int-----------
		if (tempSeat == "passenger")//1
		{
			seatPos = 1;
		}
		else if (tempSeat == "window")// 2 or 3
		{
			//check which seat available then choose one.

			if (CarPin == 2)//if for compacts
			{
				if (compacts.at(PosPin - 1).getSeat(1))
				{
					seatPos = 2;//left window
				}
				else if (compacts.at(PosPin - 1).getSeat(2))
				{
					seatPos = 3;//right window
				}
			}
			if (CarPin == 3)//if for sedans
			{
				if (sedans.at(PosPin - 1).getSeat(1))
				{
					seatPos = 2;//left window
				}
				else if (sedans.at(PosPin - 1).getSeat(2))
				{
					seatPos = 3;//right window
				}
			}
		}
		else if (tempSeat == "middle")// 4
		{
			seatPos = 4;
		}
		else
		{
			//error
			cout << "Not a valid seat option. Returning 0.";
			return 0;
		}

		//-----------Check Availability and Reserve-----------//need to check if seat valid (no window on pickups), middle only on sedan
		if (CarPin == 1 && seatPos==1)
		{
			if (pickups.at(tempcol).getSeat() == 1)
			{
				//seat available. make reservation
				pickups.at(tempcol).setSeat(passenger,0);//seatnum (0 is passenger),availability (0 is full)
				ReturnPIN = makePIN(CarPin,PosPin,seatPos,PersonPos);//makepin
				cout << "Reservation Made, Returning Reservation Pin" << endl;
			}
			else
			{
				//seat not available. Error/Retry.
				cout << "Seat already reserved. Please make another reservation." << endl;
			}
		}
		else if (CarPin == 2 && seatPos != 4)
		{
			if (compacts.at(tempcol).getSeat(seatPos) == 1)
			{
				//seat available. make reservation
				compacts.at(tempcol).setSeat(seatPos - 1, 0);//seatpos-1 
				ReturnPIN = makePIN(CarPin, PosPin, seatPos, PersonPos);
				cout << "Reservation Made, Returning Reservation Pin" << endl;
			}
			else
			{
				//seat not available. Error/Retry.
				cout << "Seat already reserved. Please make another reservation." << endl;
			}
		}
		else if (CarPin == 3)
		{
			if (sedans.at(tempcol).getSeat(seatPos) == 1)
			{
				//seat available. make reservation
				sedans.at(tempcol).setSeat(seatPos - 1, 0);//seatpos-1 
				ReturnPIN = makePIN(CarPin, PosPin, seatPos, PersonPos);//7 digit pin
				cout << "Reservation Made, Returning Reservation Pin" << endl;
			}
			else
			{
				//seat not available. Error/Retry.
				cout << "Seat already reserved. Please make another reservation." << endl;
			}
		}
	}
	else
	{
		//Error try again
		cout << "Invalid seat. Please try again." << endl;//returns to main screen
		return 0;
	}

	if (ReturnPIN > 0)
	{
		PINS.push_back(ReturnPIN);
	}
	return ReturnPIN;//return the PIN.
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

int Reservation::makePIN(int car, int color, int seat, int person)//returns unique value for pin that hold information plus three random digits.
{
	int temp;
	int randomNum = makeRand(3);
	string tempNum = to_string(car) + to_string(color) + to_string(seat) + to_string(person) + to_string(PINS.size()) + to_string(randomNum);
	temp = chartoint(tempNum);
	return temp;
}

 