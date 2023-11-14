/*
* reservation.cpp
* gavin mcintosh and shaun ryan
* cpet 321
*
* main file for class reservation. stores the primary functions needed to perform reservations.
*/

#include "reservation.h"

//ease of access value definitions
#define passengerValue	5
#define BackValue		3
#define SideValue		2
#define MiddleValue		1
#define passenger		0
#define windowLeft		1
#define windowRight		2
#define middle			3
#define Cars			3

Reservation::Reservation()	//constructor, reads in people to vectors defined in reservation
{
	FileIn(ResFile, pickups, compacts, sedans, passengers);
}

int Reservation::Create() //creates reservation, returns 3 digit pin number
{
	//variable definitions, many to act as temp vars.
	string seatChoice;
	string tempColor;
	string tempCar;
	string tempSeat;
	string FirstName;
	//string nameEntered; //for display

	int temp = 0; //temporary variable to be assigned periodically
	int cred = 0;
	int updatedCred = 0;
	int tempcol = -1;

	int soq = 0;
	bool startover = 1;

	int ReturnPIN = 0;

	//--------------Digits for the Pin--------------------//
	//init to 0 for value checking

	int CarPin = 0;//1=truck,2=compact,3=sedan
	int PosPin = 0;//1=Car1,2=Car2,3=Car3 (found by color/car's position in the vehicle vector + 1)
	int seatPos = 0;//1=frontSeat,2=windowLeft,3=windowRight,4=middle (corrisponds to the position in the vehicle vector + 1)
	int PersonPos = 0;//Where person is in vector

	cout << "First name: ";
	cin >> FirstName;
	//nameEntered = FirstName;
	FirstName = makeLower(FirstName);

	soq = getPassengerInfo(PersonPos, cred, FirstName,true);// moved to different function for testing and visual reasons

	if (soq == 0)//if person doesnt exist
	{
		startover = 0;
	}
	else if (soq == 1)//if person exists
	{
		startover = 1;
	}
	else//if person has 0 credits
	{
		return 0;
	}

	if (passengers.at(PersonPos).GetPin() > 0)
	{
		cout << "You already have a Reservation.";// prevent overbooking as it will break someThing
		cout << " Your Pin is: " << passengers.at(PersonPos).GetPin();// For security reasons this should be removed. For testing only.
		cout << endl;
		return 0;
	}

	while (startover == 0)//repeat til name is correct
	{
		cout << "First name: ";
		cin >> FirstName;
		//nameEntered = FirstName;
		FirstName = makeLower(FirstName);
		startover = getPassengerInfo(PersonPos, cred, FirstName,true);// moved to different function for testing and visual reasons
	}


	//startover = 1;
	while (startover)//start over with name and credits still loaded.
	{
		startover = 0;//wont restart unless told to (no get stuck in loop)

		//Display Diagram//
		cout << endl;
		Display();

		//--------------------------------------------------------------get seat Info--------------------------------------------------------------//
		cout << "Choose a seat to reserve or cancel action," << endl;
		cout << "please enter a seat catagory: " << "Specific, Passenger, Back Seat, Side Window, Middle, or Exit: " << endl;

		getline(cin, seatChoice);
		if (seatChoice == "")// kept just grabbing nothing? simple fix, not ideal.
		{
			getline(cin, seatChoice);
		}
		cout << endl;

		seatChoice = makeLower(seatChoice);
		//----------------------------------------------------------------------------------------------------------------------------//

		if (seatChoice == "exit")
		{
			return 0;//exit function with pin of 0
		}

		//--------------------------------------------------------------Set Passenger seat Info--------------------------------------------------------------//
		if (seatChoice == "passenger")//seat 0
		{
			//check for first available passenger seat (any car)-------------------------------------
			if (cred < passengerValue)
			{
				cout << "Not enough credits for this seat. You need at least " << passengerValue << " credits, but you have " << cred << " credits." << endl << endl;
				//error start over. ****
				startover = true;
				//break;				
			}
			if (startover == false)
			{
				for (int i = 0; startover == false && i < Cars; i++)//using Cars as size of the vehicle vectors. could make it modular with pickups.length() but no need.
				{
					if (pickups.at(i).getSeat() == 1)//if seat open
					{
						CarPin = 1;
						PosPin = i;
						seatPos = 1;
						ReturnPIN = makePIN(seatPos);
						passengers.at(PersonPos).setResInfo(CarPin, PosPin, seatPos-1, ReturnPIN);
						passengers.at(PersonPos).spendCred(passengerValue);
						pickups.at(i).setSeat(0, 0);//set seat as full
						cout << "Reservation Made, Your Reservation Pin is: ";
						break;
					}
				}

				if (CarPin == 0)//check if car was already found
				{
					for (int i = 0; i < Cars; i++)
					{
						if (compacts.at(i).getSeat(0) == 1)//if is open
						{
							CarPin = 2;
							PosPin = i;
							seatPos = 1;
							ReturnPIN = makePIN(seatPos);
							compacts.at(i).setSeat(0, 0);//set seat as full
							passengers.at(PersonPos).setResInfo(CarPin, PosPin, seatPos-1, ReturnPIN);
							passengers.at(PersonPos).spendCred(passengerValue);
							break;
						}
					}
				}

				if (CarPin == 0)//check if car was already found
				{
					for (int i = 0; i < Cars; i++)
					{
						if (sedans.at(i).getSeat(0) == 1)//if is available
						{
							CarPin = 3;
							PosPin = i;
							seatPos = 1;
							ReturnPIN = makePIN(seatPos);
							passengers.at(PersonPos).setResInfo(CarPin, PosPin, seatPos-1, ReturnPIN);
							passengers.at(PersonPos).spendCred(passengerValue);
							sedans.at(i).setSeat(0, 0);//set seat as full
							break;
						}
					}
				}
			}

		}
		//----------------------------------------------------------------------------------------------------------------------------//

		//--------------------------------------------------------------Set Back Seat Info--------------------------------------------------------------//
		else if (seatChoice == "back seat")//seat 1 and 2
		{
			if (cred < BackValue)
			{
				cout << "Not enough credits for this seat. You need at least " << passengerValue << " credits. You have " << cred << " credits." << endl << endl;
				//error start over. ****
				startover = true;
				//break;
			}

			//check for first avaiable window seat (compact), only need to check compact's seats 1 and 2
			for (int i = 0; i < Cars; i++)
			{
				if (compacts.at(i).getSeat(1) == 1)//if is open
				{
					CarPin = 2;
					PosPin = i;
					seatPos = 2;
					ReturnPIN = makePIN(seatPos);
					passengers.at(PersonPos).setResInfo(CarPin, PosPin, seatPos-1,ReturnPIN);
					passengers.at(PersonPos).spendCred(BackValue);
					compacts.at(i).setSeat(1, 0);//set seat as full
					cout << "Reservation Made, Your Reservation Pin is: ";
					break;
				}
				else if (compacts.at(i).getSeat(2) == 1)
				{
					CarPin = 2;
					PosPin = i;
					seatPos = 3;
					ReturnPIN = makePIN(seatPos);
					passengers.at(PersonPos).setResInfo(CarPin, PosPin, seatPos - 1,ReturnPIN);
					passengers.at(PersonPos).spendCred(BackValue);
					compacts.at(i).setSeat(2, 0);//set seat as full
					cout << "Reservation Made, Your Reservation Pin is: ";
					break;
				}
			}

		}
		//----------------------------------------------------------------------------------------------------------------------------//

		//--------------------------------------------------------------set window seat Info--------------------------------------------------------------//
		else if (seatChoice == "side window")//seat 1 and 2
		{
			if (cred < SideValue)
			{
				cout << "Not enough credits for this seat. You need at least " << passengerValue << " credits. You have " << cred << " credits." << endl << endl;
				//error start over. ****
				startover = true;
				//break;
			}

			//only need to check sedans's seats 1 and 2
			for (int i = 0; i < Cars; i++)
			{
				if (sedans.at(i).getSeat(1) == 1)//if is open
				{
					CarPin = 3;
					PosPin = i;
					seatPos = 2;
					ReturnPIN = makePIN(seatPos);
					passengers.at(PersonPos).setResInfo(CarPin, PosPin, seatPos - 1,ReturnPIN);
					passengers.at(PersonPos).spendCred(SideValue);
					sedans.at(i).setSeat(1, 0);//set seat as full
					cout << "Reservation Made, Your Reservation Pin is: ";
					break;
				}
				else if (sedans.at(i).getSeat(2) == 1)
				{
					CarPin = 3;
					PosPin = i;
					seatPos = 3;
					ReturnPIN = makePIN(seatPos);
					passengers.at(PersonPos).setResInfo(CarPin, PosPin, seatPos - 1,ReturnPIN);
					passengers.at(PersonPos).spendCred(SideValue);
					sedans.at(i).setSeat(2, 0);//set seat as full
					cout << "Reservation Made, Your Reservation Pin is: ";
					break;
				}
			}
		}
		//----------------------------------------------------------------------------------------------------------------------------//

		//--------------------------------------------------------------set middle seat Info--------------------------------------------------------------//
		else if (seatChoice == "middle")//seat 3
		{
			if (cred < MiddleValue)
			{
				cout << "Not enough credits for this seat. You need at least " << passengerValue << " credits. You have " << cred << " credits." << endl << endl;
				//error start over. ****
				startover = true;
				//break;
			}
			//only need to check sedans's seat 3
			for (int i = 0; i < Cars; i++)
			{
				if (sedans.at(i).getSeat(3) == 1)//if is open
				{
					CarPin = 3;
					PosPin = i;
					seatPos = 4;
					ReturnPIN = makePIN(seatPos);
					passengers.at(PersonPos).setResInfo(CarPin, PosPin, seatPos - 1, ReturnPIN);
					passengers.at(PersonPos).spendCred(MiddleValue);
					sedans.at(i).setSeat(3, 0);//set seat as full
					cout << "Reservation Made, Your Reservation Pin is: ";
					break;
				}
			}
		}
		//----------------------------------------------------------------------------------------------------------------------------//

		//--------------------------------------------------------------Get Specific seat Info--------------------------------------------------------------//
		else if (seatChoice == "specific")
		{
			//get color, model, and seat type
			cout << "What type of car would you like to reserve? (pickup, compact, sedan) \n>>";//get car type
			cin >> tempCar;
			cout << "What color of car? \n>>";//get car color
			cin >> tempColor;
			cout << "Which seat? (Passenger, Window, or Middle)" << endl;//get seat type
			cin >> tempSeat;

			//----Strings to lowercase----
			tempCar = makeLower(tempCar);
			tempColor = makeLower(tempColor);
			tempSeat = makeLower(tempSeat);

			//-------------------------------------|checking if available|-------------------------------------\\


			//-----------color to int and set CarPin-----------
			tempcol = -1;
			CarInfo(tempCar, tempColor, tempcol, CarPin, PosPin);

			if (tempcol == -1)
			{
				//error start over. ****
				startover = true;
				//break;
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
				cout << "Not a valid seat option. Try again.";
				//error start over. ****
				startover = true;
				//break;
			}

			//-----------Check Availability and Reserve-----------//need to check if seat valid (no window on pickups), middle only on sedan

			if (CarPin == 1 && seatPos == 1)//truck && passenger
			{
				if (cred < passengerValue)
				{
					cout << "Not enough credits for this seat. You need at least " << passengerValue << " credits, but you have " << cred << " credits." << endl << endl;
					//error start over. ****
					startover = true;
				}
				else if (pickups.at(tempcol).getSeat() == 1)
				{
					//seat available. make reservation
					pickups.at(tempcol).setSeat(passenger, 0);//seatnum (0 is passenger),availability (0 is full)
					//pickups.at(tempcol).setSeat(2, 0);//set seat as full
					ReturnPIN = makePIN(seatPos);//makepin
					passengers.at(PersonPos).setResInfo(CarPin, PosPin-1, seatPos - 1,ReturnPIN);
					passengers.at(PersonPos).spendCred(passengerValue);
					cout << "Reservation Made, Your Reservation Pin is: ";
				}
				else
				{
					//seat not available. Error/Retry.
					cout << "Seat already reserved. Please make another reservation." << endl;
					//error start over. ****
					startover = true;
				}
			}
			else if (CarPin == 2 && seatPos != 4)//compacts && not middle
			{
				if (cred < compacts.at(tempcol).getSeatVal(seatPos))
				{
					cout << "Not enough credits for this seat. You need at least " << compacts.at(tempcol).getSeatVal(seatPos) << " credits, but you have " << cred << " credits." << endl << endl;
					//error start over. ****
					startover = true;
				}
				else if (compacts.at(tempcol).getSeat(seatPos - 1) == 1)
				{
					//seat available. make reservation
					compacts.at(tempcol).setSeat(seatPos - 1, 0);//seatpos-1 
					ReturnPIN = makePIN(seatPos);
					passengers.at(PersonPos).setResInfo(CarPin, PosPin-1, seatPos - 1,ReturnPIN);
					passengers.at(PersonPos).spendCred(compacts.at(tempcol).getSeatVal(seatPos));
					ReturnPIN = makePIN(seatPos);
					cout << "Reservation Made, Your Reservation Pin is: ";
				}
				else
				{
					//seat not available. Error/Retry.
					cout << "Seat already reserved. Please make another reservation." << endl;
					//error start over. ****
					startover = true;
				}
			}
			else if (CarPin == 3)//sedan && anyseat
			{
				if (cred < sedans.at(tempcol).getSeatVal(seatPos))
				{
					cout << "Not enough credits for this seat. You need at least " << sedans.at(tempcol).getSeatVal(seatPos) << " credits, but you have " << cred << " credits." << endl << endl;
					//error start over. ****
					startover = true;
				}
				else if (sedans.at(tempcol).getSeat(seatPos - 1) == 1)
				{
					//seat available. make reservation
					sedans.at(tempcol).setSeat(seatPos - 1, 0);//seatpos-1 
					ReturnPIN = makePIN(seatPos);//3 digit pin
					passengers.at(PersonPos).setResInfo(CarPin, PosPin-1, seatPos - 1,ReturnPIN);
					passengers.at(PersonPos).spendCred(sedans.at(tempcol).getSeatVal(seatPos));
					cout << "Reservation Made, Your Reservation Pin is: ";
				}
				else
				{
					//seat not available. Error/Retry.
					cout << "Seat already reserved. Please make another reservation." << endl;
					//error start over. ****
					startover = true;
					//break;
				}
			}
			else//not a car
			{
				cout << "Car/Seat not found. Please try again." << endl;
				startover = true;
			}
		}
		else
		{
			cout << "Invalid seat. Please try again." << endl;
			//error start over. ****
			startover = true;
			//break;
		}
	}

	if (ReturnPIN > 0)//save and return PIN
	{
		PINS.push_back(ReturnPIN);
		return ReturnPIN;//return the PIN.
	}

	cout << "reached end of function. Something went wrong. returning 0." << endl;
	return 0;// code shouldnt get here but just in case.
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

int Reservation::makePIN(int saet)//returns unique-ish value for pin that holds some information plus random digit plus pinlength.
{

	int temp;
	int randomNum = makeRand(2);//get 1 random digit
	string tempNum = /*to_string(saet + 1) +*/ to_string(randomNum) + to_string(PINS.size());//making pin a little more random while still being fairly unique
	temp = chartoint(tempNum);//make integers
	return temp;//return pin (seat location+1 + 2 random digits)
}

void Reservation::Modify()//light testing worked
{
	string name;
	int pinNum;
	int personLoc = -1;
	int pinLoc = -1;
	int cred;
	int potCred = 0;

	int carPos = -1;//which color car
	int carPin = -1;//which Car
	int seatPos = -1;
	int ColorPin = -1;//doesnt get used.
	bool foundChange = 0;

	int oldCarPos = 0;
	int oldCarCol = 0;
	int oldCarSeat = 0;

	string NewCarType;
	string NewCarCol;
	string NewSeat;

	cout << "First Name: ";
	cin >> name;
	cout << endl << "Pin Number: ";
	cin >> pinNum;
	cout << endl;

	for (int i = 0; i < PINS.size(); i++)
	{
		if (pinNum == PINS.at(i))
		{
			pinLoc = i;
			break;
		}
	}
	for (int i = 0; i < passengers.size(); i++)
	{
		if (makeLower(passengers.at(i).GetFirstName()) == makeLower(name))
		{
			personLoc = i;
			break;
		}
	}
	if (pinLoc == -1 || personLoc == -1)
	{
		cout << "Name or Pin Number incorrect. Returning to main menu." << endl;
		exit;
	}

	cred = passengers.at(personLoc).GetCreds();
	potCred = passengers.at(personLoc).getSpent();

	oldCarPos = passengers.at(personLoc).GetCar();
	oldCarCol = passengers.at(personLoc).GetColor();
	oldCarSeat = passengers.at(personLoc).GetSeat();


	cout << "Reservation Found. " << "You have " << cred+potCred << " credits to use." << endl << endl;
	Display();
	cout << "Please select a new car and seat." << endl << "Car Type: ";
	cin >> NewCarType;
	cout << "Car Color: ";
	cin >> NewCarCol;
	cout << "Which seat? (Passenger, Window, or Middle)" << endl;//get seat type
	cin >> NewSeat;

	NewCarType = makeLower(NewCarType);
	NewCarCol = makeLower(NewCarCol);

	CarInfo(NewCarType, NewCarCol, carPos, carPin, ColorPin);//carPos is color.

	NewSeat = makeLower(NewSeat);
	if (NewSeat == "passenger")
	{
		if (carPin == 1)
		{
			if (pickups.at(carPos).getSeat() == 1)
			{
				seatPos = 0;
				foundChange = 1;
			}
		}
		else if (carPin == 2)
		{
			if (compacts.at(carPos).getSeat(0) == 1)
			{
				seatPos = 0;
				foundChange = true;
			}
		}
		else if (sedans.at(carPos).getSeat(0) == 1)
		{
			seatPos = 0;
			foundChange = 1;
		}
	}
	else if (NewSeat == "window")
	{
		if (carPin == 2)
		{
			if (compacts.at(carPos).getSeat(1) == 1)//check left window
			{
				seatPos = 1;
				foundChange = true;
			}
			else if (compacts.at(carPos).getSeat(2) == 1)
			{
				seatPos = 2;
				foundChange = true;
			}
			else
			{
				cout << "Seat is already full." << endl;
				exit;
				//error back to main menu
			}
		}
		else if (carPin == 3)
		{
			if (sedans.at(carPos).getSeat(1) == 1)//check left window
			{
				seatPos = 1;
				foundChange = true;
			}
			else if (sedans.at(carPos).getSeat(2) == 1)
			{
				seatPos = 2;
				foundChange = true;
			}
			else
			{
				cout << "Seat is already full." << endl;
				exit;
				//error back to main menu
			}
		}
		else
		{
			cout << "seat does not exist." << endl;
			exit;
			//error back to menu
		}
	}
	else if (NewSeat == "middle")
	{
		if (sedans.at(carPos).getSeat(3) == 1)
		{
			seatPos = 3;
			foundChange = true;
		}
		else
		{
			cout << "seat already full." << endl;
			exit;
			//error and exit to menu
		}
	}

	if (foundChange)
	{
		cout << "Making revervation changes... Thank You." << endl;
		//unreserve first seat
		Unreserve(oldCarPos, oldCarCol, oldCarSeat);

		//reserve selected seat
		Reserve(carPin, carPos, seatPos, personLoc,pinNum);
	}
}
	
void Reservation::Unreserve(int carType, int carCol, int seatPos)
{
	if (carType == 1)//unreserve pickup
	{
		pickups.at(carCol).setSeat(seatPos, 1);
	}
	else if (carType == 2)//unreserve compact
	{
		compacts.at(carCol).setSeat(seatPos, 1);
	}
	else if (carType == 3)
	{
		sedans.at(carCol).setSeat(seatPos, 1);
	}
	else
	{
		//error somehow
		cout << "Error in input. No changes made."<<endl;
	}
}

void Reservation::Reserve(int carType, int carCol, int seatPos, int personPos, int PIN)//reserves in res and person classes.
{
	//was made after Create function so is not used in there.
	if (carType == 1)//unreserve pickup
	{
		pickups.at(carCol).setSeat(seatPos, 0);
		passengers.at(personPos).setResInfo(carType, carCol, seatPos,PIN);
	}
	else if (carType == 2)//unreserve compact
	{
		compacts.at(carCol).setSeat(seatPos, 0);
		passengers.at(personPos).setResInfo(carType, carCol, seatPos,PIN);
	}
	else if (carType == 3)
	{
		sedans.at(carCol).setSeat(seatPos, 0);
		passengers.at(personPos).setResInfo(carType, carCol, seatPos,PIN);
	}
	else
	{
		//error somehow
		cout << "Error in input. No changes made.";
	}
}

int Reservation::getPassengerInfo(int& position, int& credits, string FirstName,bool textOn)//int so know if person wasnt found
{
	//assume FirstName is all lowercase already.
	int temp = 0;
	//string NameTemp;
	for (int i = 0; i < passengers.size(); i++)//--------------------------------------------------------------get passenger Info--------------------------------------------------------------//
	{
		if (makeLower(passengers.at(i).GetFirstName()) == FirstName)//if person exists
		{
			if (passengers.at(i).GetCreds() > 0)//if person has more than 0 credits
			{
				position = i;
				if (textOn)
				{
					cout << passengers.at(position).GetFirstName() << " has " << passengers.at(i).GetCreds() << " credits" << endl;
				}
				credits = passengers.at(position).GetCreds();//store their credits for later
				temp = 1;
				break;
			}
			else// if person has 0 credits
			{
				if (textOn)
				{
					cout << passengers.at(i).GetFirstName() << " has " << passengers.at(i).GetCreds() << " credits and must provide their own transportation." << endl;//error and return
				}
				return 2;
			}
		}
	}//----------------------------------------------------------------------------------------------------------------------------//
	if (temp == 0)
	{
		cout << passengers.at(position).GetFirstName() << " was not found. Check spelling and try again." << endl;
		return 0;
	}
	return 1;
}

void Reservation::CarInfo(string car, string color, int& COlPos, int& carpin, int& colorpin)//might need better names
{
	//carpin is vehicle type
	//COlPos is which car/car color
	//colorpin is carpos+1?
	if (car == "pickup")
	{
		carpin = 1;
		for (int i = 0; i < pickups.size(); i++)
		{
			if (makeLower(pickups.at(i).getColor()) == color)
			{
				COlPos = i;
				colorpin = i + 1;
				break;//stop loop so it doesnt go unessearily long
			}
		}
		if (COlPos == -1)
		{
			//error
			cout << "No car mathcing your description was found." << endl;
		}
	}
	if (car == "compact")
	{
		carpin = 2;
		for (int i = 0; i < compacts.size(); i++)
		{
			if (makeLower(compacts.at(i).getColor()) == color)
			{
				COlPos = i;
				colorpin = i + 1;
				break;
			}
		}
		if (COlPos == -1)
		{
			//error
			cout << "No car mathcing your description was found." << endl;
		}
	}
	if (car == "sedan")
	{
		carpin = 3;
		for (int i = 0; i < sedans.size(); i++)
		{
			if (makeLower(sedans.at(i).getColor()) == color)
			{
				COlPos = i;
				colorpin = i + 1;
				break;
			}
		}
		if (COlPos == -1)
		{
			//error
			cout << "No car mathcing your description was found." << endl;
		}
	}
}

void Reservation::Delete()
{
	//delete pin from person, pin vector in reservation, reset the reserve seat, color, and type to 0, restore points spent, set seat in car to true
	string first_name_in;
	int pin_in;
	int personPos=-1;
	int cred;
	int error = 0;
	int pinLoc;

	int tempCar;
	int tempColl;
	int tempSeat;

	cout << "Enter first name of person of reservation to delete\n>>";
	cin >> first_name_in;
	cout << "Enter pin of reservation to delete\n>>";
	cin >> pin_in;
	string first_name = makeLower(first_name_in);	//grab first name, lower for processing

	//---------------Error Check----------------//
	error=getPassengerInfo(personPos,cred,first_name,false);
	for (int i = 0; i < PINS.size(); i++)
	{
		if (PINS.at(i) == pin_in)
		{
			pinLoc = i;
			break;
		}
	}
	if (error = 0)//check error in name
	{
		exit;
		//couldnt find person. exit.
	}
	if (pin_in == passengers.at(personPos).GetPin())//check mismatched pins
	{
		error = 0;
	}
	if (error = 0)
	{
		exit;
		//couldnt find person. exit.
	}
	//------------------------------------------------//
	
	tempCar = passengers.at(personPos).GetCar();
	tempColl = passengers.at(personPos).GetColor();
	tempSeat = passengers.at(personPos).GetSeat();

	Unreserve(tempCar, tempColl, tempSeat);
	PINS.erase(PINS.begin() + pinLoc);
	passengers.at(personPos).SetPin(-1);//remove pin stored at person
	passengers.at(personPos).setResInfo(-1, -1, -1, pin_in);//set info to default impossible number.
}

void Reservation::Print()//not looking at all seats?
//needs to print the entire manifest of one car
{
	string type_car_in;
	string color_car_in;

	vector<Person> people_in_car;

	int car;//car identifier num
	int color;//car index position

	cout << "What type of car\n>>";
	cin >> type_car_in;
	cout << "What color of car\n>>";
	cin >> color_car_in;

	string type_car = makeLower(type_car_in);
	string color_car = makeLower(color_car_in);


	//colors are fixed. not going to change.
	if (type_car == "pickup")
	{
		car = 1;
		if (color_car == "purple")
		{
			color = 0;
		}
		else if (color_car == "green")
		{
			color = 1;
		}
		else if (color_car == "black")
		{
			color = 2;
		}
		else
		{
			//cant find car, error
			cout << "A pickup of that color was not found. Returning to menu." << endl;
			exit;
		}
	}
	else if (type_car == "compact")
	{
		car = 2;
		if (color_car == "red") {
			color = 0;
		}
		else if (color_car == "blue") {
			color = 1;
		}
		else if (color_car == "yellow")
		{
			color = 2;
		}
		else
		{
			//cant find car, error
			cout << "A compact of that color was not found. Returning to menu." << endl;
			exit;
		}
	}
	else if (type_car == "sedan")
	{
		car = 3;
		if (color_car == "blue") {
			color = 0;
		}
		else if (color_car == "black") {
			color = 1;
		}
		else if (color_car == "green")
		{
			color = 2;
		}
		else
		{
			//cant find car, error
			cout << "A sedan of that color was not found. Returning to menu." << endl;
			exit;
		}

	}
	else
	{
		//vehicle type not spelled write.
		cout << "Couldnt find that Vehicle. Returning to menu." << endl;
		exit;
	}

	for (int i = 0; i < passengers.size(); i++)
	{
		//cout << car << ' ' << color << endl;//Here for Testing
		//cout << passengers.at(i).GetCar() << ' ' << passengers.at(i).GetColor() << endl << endl;//Here for Testing
		if (passengers.at(i).GetCar() == car && passengers.at(i).GetColor() == color)
		{
			people_in_car.push_back(passengers.at(i));
		}
	}

	string fileName = color_car + '_' + type_car + ".txt";
	cout << "file name: " << fileName << endl;
	ofstream OutFile(fileName);

	if (!OutFile.is_open())
	{
		cout << "File Error. Unable to make File." << endl;
		//exit;//exit? not sure what to do here. Probably no problems right?
	}

	OutFile.clear();//empty file to make sure its fresh

	cout << "The people riding in the " << color_car_in << ' ' << type_car_in << " are: " << endl; 
	OutFile<< "The people riding in the " << color_car_in << ' ' << type_car_in << " are: " << endl;


	if (people_in_car.size() > 0)
	{
		for (int i = 0; i < people_in_car.size(); i++)
		{
			cout << people_in_car.at(i).GetFirstName()<<endl;
			OutFile << people_in_car.at(i).GetFirstName() << endl;
		}
	}
	else
	{
		cout << "Nobody! :(" << endl;
		OutFile << "No one is scheduled to travel in this " << type_car << '.' << endl;
	}

	OutFile.close();
	/*
	for (Person p : passengers) 
	{
		if (p.GetCar() == car && p.GetColor() = color) {
			people_in_car.push_back(p);
		}
	}//*/

}

void Reservation::Reservations()
{
	string passkey;
	
	cout << "Password is case sensitive." << endl;
	cout << "Password: ";
	cin >> passkey;

	if (passkey == PASSWORD)
	{
		//make new file and print all vehicle regestrations to it.
		ofstream OutFile("all_reservations.txt");
		if (!OutFile.is_open())
		{
			cout << "could'nt open output File." << endl;
			//error?
		}
		OutFile.clear();

		for (int v = 0; v < 3; v++)
		{
			if (v == 0)
			{
				OutFile << "----------PICKUPS----------" << endl;
			}
			else if (v == 1)
			{
				OutFile << "----------COMPACTS----------" << endl;
			}
			else if (v == 2)
			{
				OutFile << "----------SEDANS----------" << endl;
			}
			for (int i = 0; i < 3; i++)
			{
				if (v == 0)//-----------------------pickups-----------------------//
				{
					OutFile << pickups.at(i).getColor() << " pickup driven by " << pickups.at(i).GetDriverFirst() << ' ' << pickups.at(i).GetDriverLast() << ": " << endl;
					
					OutFile << "Passenger: ";//--------------------------------////--------------------------------////--------------------------------//
					if (pickups.at(i).getSeat())
					{
						OutFile << "Unassigned" << endl;
					}
					else
					{
						for (int j = 0; j < passengers.size(); j++)
						{
							if (passengers.at(j).GetCar() == v+1 && passengers.at(j).GetColor() == i)
							{
								OutFile << passengers.at(j).GetFirstName() << ' ' << passengers.at(j).Getlastname() <<endl;
								break;//dont need to stay here. we found our guy.
							}
						}
					}
					OutFile << endl;
				}
				else if (v == 1)//-----------------------compacts-----------------------//
				{
					OutFile << compacts.at(i).getColor() << " compact driven by " << compacts.at(i).GetDriverFirst() << ' ' << compacts.at(i).GetDriverLast() << ": " << endl;

					OutFile << "Passenger: ";//--------------------------------////--------------------------------////--------------------------------//
					if (compacts.at(i).getSeat(0))//remeber give it seat index not seat associator
					{
						OutFile << "Unassigned" << endl;
					}
					else
					{
						for (int j = 0; j < passengers.size(); j++)
						{
							if (passengers.at(j).GetCar() == v+1 && passengers.at(j).GetColor() == i && passengers.at(j).GetSeat()==0)
							{
								OutFile << passengers.at(j).GetFirstName() << ' ' << passengers.at(j).Getlastname() << endl;
								break;//dont need to stay here. we found our guy.
							}
						}
					}

					OutFile << "Back Windows: ";//--------------------------------////--------------------------------////--------------------------------//
					if (compacts.at(i).getSeat(1) == 1)
					{
						OutFile << "Unasigned";//no endl because there is second window seat.
					}
					else
					{
						for (int j = 0; j < passengers.size(); j++)
						{
							if (passengers.at(j).GetCar() == v + 1 && passengers.at(j).GetColor() == i && passengers.at(j).GetSeat() == 1)
							{
								OutFile << passengers.at(j).GetFirstName() << ' ' << passengers.at(j).Getlastname();//no endl.theres another person after.
								break;//dont need to stay here. we found our guy.
							}
						}
					}
					OutFile << " and ";
					if (compacts.at(i).getSeat(2) == 1)
					{
						OutFile << "Unasigned"<<endl;
					}
					else
					{
						for (int j = 0; j < passengers.size(); j++)
						{
							if (passengers.at(j).GetCar() == v + 1 && passengers.at(j).GetColor() == i && passengers.at(j).GetSeat() == 2)
							{
								OutFile << passengers.at(j).GetFirstName() << ' ' << passengers.at(j).Getlastname() << endl;
								break;//dont need to stay here. we found our guy.
							}
						}
					}
					OutFile << endl;
				}
				else if (v == 2)//-----------------------Sedans-----------------------//
				{
					OutFile << sedans.at(i).getColor() << " sedan driven by " << sedans.at(i).GetDriverFirst() << ' ' << sedans.at(i).GetDriverLast() << ": " << endl;

					OutFile << "Passenger: ";//--------------------------------////--------------------------------////--------------------------------//
					if (sedans.at(i).getSeat(0))//remeber give it seat index not seat associator
					{
						OutFile << "Unassigned" << endl;
					}
					else
					{
						for (int j = 0; j < passengers.size(); j++)
						{
							if (passengers.at(j).GetCar() == v + 1 && passengers.at(j).GetColor() == i && passengers.at(j).GetSeat() == 0)
							{
								OutFile << passengers.at(j).GetFirstName() << ' ' << passengers.at(j).Getlastname() << endl;
								break;//dont need to stay here. we found our guy.
							}
						}
					}

					OutFile << "Side Windows: ";//--------------------------------////--------------------------------////--------------------------------//
					if (sedans.at(i).getSeat(1) == 1)
					{
						OutFile << "Unasigned";//no endl because there is second window seat.
					}
					else
					{
						for (int j = 0; j < passengers.size(); j++)
						{
							if (passengers.at(j).GetCar() == v + 1 && passengers.at(j).GetColor() == i && passengers.at(j).GetSeat() == 1)
							{
								OutFile << passengers.at(j).GetFirstName() << ' ' << passengers.at(j).Getlastname();//no endl. there is another
								break;//dont need to stay here. we found our guy.
							}
						}
					}
					OutFile << " and ";
					if (sedans.at(i).getSeat(1) == 1)
					{
						OutFile << "Unasigned" << endl;
					}
					else
					{
						for (int j = 0; j < passengers.size(); j++)
						{
							if (passengers.at(j).GetCar() == v + 1 && passengers.at(j).GetColor() == i && passengers.at(j).GetSeat() == 2)
							{
								OutFile << passengers.at(j).GetFirstName() << ' ' << passengers.at(j).Getlastname() << endl;
								break;//dont need to stay here. we found our guy.
							}
						}
					}

					OutFile << "Middle Seat: ";//--------------------------------////--------------------------------////--------------------------------//
					if (sedans.at(i).getSeat(3))
					{
						OutFile << "Unassigned" << endl;
					}
					else
					{
						for (int j = 0; j < passengers.size(); j++)
						{
							if (passengers.at(j).GetCar() == v + 1 && passengers.at(j).GetColor() == i && passengers.at(j).GetSeat() == 3)
							{
								OutFile << passengers.at(j).GetFirstName() << ' ' << passengers.at(j).Getlastname() << endl;
								break;//dont need to stay here. We found our guy.
							}
						}
					}
					OutFile << endl;

				}
				
			}
		}

	}
	else
	{
		cout << "Password Incorrect." << endl;
		exit;
	}
}

void Reservation::Menu()
{
	while (true) {
		string choice;
		int tempPin=0;
		cout << "================RESERVATION SYSTEM==================" << endl;
		cout << "[C]reate a reservation!" << endl;
		cout << "[M]odify a reservation!" << endl;
		cout << "[D]elete a reservation!" << endl;
		cout << "[S]eating Chart(Display)" << endl;
		cout << "[P]rint a car's reservations!" << endl;
		cout << "[R]eservations print (locked to admin)" << endl;
		cout << "[E]xit!                          " << endl;
		cout << "====================================================" << endl;
		cout << ">>";
		cin >> choice;
		string real_choice = makeLower(choice);

		if (real_choice == "c" || real_choice == "create") {
			tempPin=Create();
			if (tempPin > 0)
			{
				cout << tempPin << endl << endl;
			}
			else
			{
				//output nothing
			}
		}
		else if (real_choice == "m" || real_choice == "modify") {
			Modify();
		}
		else if (real_choice == "d" || real_choice == "delete") {
			Delete();
		}
		else if (real_choice == "p" || real_choice == "print") {
			Print();
		}
		else if (real_choice == "s" || real_choice == "seating") {
			Display();
		}
		else if (real_choice == "r" || real_choice == "reservations print") {
			Reservations();
		}
		else if (real_choice == "e" || real_choice == "exit") {
			exit(0);
		}
		else {
			cout << "Invalid choice, pick again!" << endl;
			cout << "\n\n\n\n\n\n\n\n\n\n\n";
		}
	}
}
//ofstream outfile(fileName);