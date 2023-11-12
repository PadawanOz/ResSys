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

//think it works, test more?
int Reservation::Create()//returns 3 digit pin number
{
	string seatChoice;
	string tempColor;
	string tempCar;
	string tempSeat;
	string FirstName;
	string nameEntered;//for display

	int temp = 0;//whatever I need it to be for short periods of time
	int cred = 0;
	int updatedCred = 0;
	int tempcol=-1;

	int soq = 0;
	bool startover = 1;

	int ReturnPIN=0;

	//--------------Digits for the Pin--------------------//
	//init to 0 for value checking

	int CarPin = 0;//1=truck,2=compact,3=sedan
	int PosPin = 0;//1=Car1,2=Car2,3=Car3 (found by color/car's position in the vehicle vector + 1)
	int seatPos = 0;//1=frontSeat,2=windowLeft,3=windowRight,4=middle (corrisponds to the position in the vehicle vector + 1)
	int PersonPos = 0;//Where person is in vector

	cout << "First name: ";
	cin >> FirstName;
	nameEntered = FirstName;
	FirstName = makeLower(FirstName);

	soq=getPassengerInfo(PersonPos, cred, FirstName, nameEntered);// moved to different function for testing and visual reasons

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

	while (startover == 0)//repeat til name is correct
	{
		cout << "First name: ";
		cin >> FirstName;
		nameEntered = FirstName;
		FirstName = makeLower(FirstName);
		startover = getPassengerInfo(PersonPos, cred, FirstName, nameEntered);// moved to different function for testing and visual reasons
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
						passengers.at(PersonPos).setResInfo(CarPin - 1, PosPin, seatPos - 1);
						passengers.at(PersonPos).spendCred(passengerValue);
						pickups.at(i).setSeat(0, 0);//set seat as full
						ReturnPIN = makePIN(seatPos);
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
							compacts.at(i).setSeat(0, 0);//set seat as full
							passengers.at(PersonPos).setResInfo(CarPin - 1, PosPin, seatPos - 1);
							passengers.at(PersonPos).spendCred(passengerValue);
							ReturnPIN = makePIN(seatPos);
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
							passengers.at(PersonPos).setResInfo(CarPin - 1, PosPin, seatPos - 1);
							passengers.at(PersonPos).spendCred(passengerValue);
							sedans.at(i).setSeat(0, 0);//set seat as full
							ReturnPIN = makePIN(seatPos);
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
					passengers.at(PersonPos).setResInfo(CarPin - 1, PosPin, seatPos - 1);
					passengers.at(PersonPos).spendCred(BackValue);
					compacts.at(i).setSeat(1, 0);//set seat as full
					ReturnPIN = makePIN(seatPos);
					cout << "Reservation Made, Your Reservation Pin is: ";
					break;
				}
				else if (compacts.at(i).getSeat(2) == 1)
				{
					CarPin = 2;
					PosPin = i;
					seatPos = 3;
					passengers.at(PersonPos).setResInfo(CarPin - 1, PosPin, seatPos - 1);
					passengers.at(PersonPos).spendCred(BackValue);
					compacts.at(i).setSeat(2, 0);//set seat as full
					ReturnPIN = makePIN(seatPos);
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
					passengers.at(PersonPos).setResInfo(CarPin - 1, PosPin, seatPos - 1);
					passengers.at(PersonPos).spendCred(SideValue);
					sedans.at(i).setSeat(1, 0);//set seat as full
					ReturnPIN = makePIN(seatPos);
					cout << "Reservation Made, Your Reservation Pin is: ";
					break;
				}
				else if (sedans.at(i).getSeat(2) == 1)
				{
					CarPin = 3;
					PosPin = i;
					seatPos = 3;
					passengers.at(PersonPos).setResInfo(CarPin - 1, PosPin, seatPos - 1);
					passengers.at(PersonPos).spendCred(SideValue);
					sedans.at(i).setSeat(2, 0);//set seat as full
					ReturnPIN = makePIN(seatPos);
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
					passengers.at(PersonPos).setResInfo(CarPin - 1, PosPin, seatPos - 1);
					passengers.at(PersonPos).spendCred(MiddleValue);
					sedans.at(i).setSeat(3, 0);//set seat as full
					ReturnPIN = makePIN(seatPos);
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
					passengers.at(PersonPos).setResInfo(CarPin - 1, PosPin, seatPos - 1);
					passengers.at(PersonPos).spendCred(passengerValue);
					ReturnPIN = makePIN(seatPos);//makepin
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
				else if (compacts.at(tempcol).getSeat(seatPos-1) == 1)
				{
					//seat available. make reservation
					compacts.at(tempcol).setSeat(seatPos - 1, 0);//seatpos-1 
					passengers.at(PersonPos).setResInfo(CarPin - 1, PosPin, seatPos - 1);
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
				else if (sedans.at(tempcol).getSeat(seatPos-1) == 1)
				{
					//seat available. make reservation
					sedans.at(tempcol).setSeat(seatPos - 1, 0);//seatpos-1 
					passengers.at(PersonPos).setResInfo(CarPin - 1, PosPin, seatPos - 1);
					passengers.at(PersonPos).spendCred(sedans.at(tempcol).getSeatVal(seatPos));
					ReturnPIN = makePIN(seatPos);//7 digit pin
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

int Reservation::makePIN(int saet)//returns unique value for pin that hold information plus random digit plus pinlength.
{
	//HAS TO BE THREE DIGITS! :(
	//moved pin stored info to person class

	int temp;
	int randomNum = makeRand(1);//get 1 random digits
	string tempNum = to_string(saet +1) +to_string(randomNum) + to_string(PINS.size());//dont need to store person data since name always given.
	temp = chartoint(tempNum);//make integers
	return temp;//return pin (seat location+1 + 2 random digits)
}

void Reservation::Modify()
{
	string name;
	int pinNum;
	int personLoc=-1;
	int pinLoc=-1;
	int cred;
	int potCred = 0;

	int carPos=-1;//which color car
	int carPin=-1;//which Car
	int ColorPin=-1;

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


	cout << "Reservation Found." << endl;
	Display();
	cout << "Please select a new car and seat." << endl << "Car Type: ";
	cin >> NewCarType;
	cout << "Car Color: ";
	cin >> NewCarCol;
	cout << "Which seat? (Passenger, Window, or Middle)" << endl;//get seat type
	cin >> NewSeat;

	CarInfo(NewCarType,NewCarCol,carPos,carPin,ColorPin);

	//Here is template.
	if (carPin == 1)//if truck selected
	{
		if((cred+potCred)<pickups.at(carPos).getSeatVal(0));
		{
			//reserve selected seat
		}
	}
	else if (carPin == 2)//if compact selected
	{
		if ((cred + potCred) < compacts.at(carPos).getSeatVal(0));
		{
			//reserve selected seat
		}
	}
	else if (carPin == 3)//if sedan selected
	{
		if ((cred + potCred) < sedans.at(carPos).getSeatVal(0));
		{
			//reserve selected seat
		}
	}
	else//else error
	{

	}
}

int Reservation::getPassengerInfo(int& position, int& credits, string FirstName, string entered)//int so know if person wasnt found
{
	int temp = 0;
	//string NameTemp;
	for (int i = 0; i < passengers.size(); i++)//--------------------------------------------------------------get passenger Info--------------------------------------------------------------//
	{
		if (makeLower(passengers.at(i).GetFirstName()) == FirstName)//if person exists
		{
			if (passengers.at(i).GetCreds() > 0)//if person has more than 0 credits
			{
				cout << entered << " has " << passengers.at(i).GetCreds() << " credits" << endl;
				position = i;
				credits = passengers.at(i).GetCreds();//store their credits for later
				temp = 1;
				break;
			}
			else// if person has 0 credits
			{
				cout << entered << " has " << passengers.at(i).GetCreds() << " credits and must provide their own transportation." << endl;//error and return
				return 2;
			}
		}
	}//----------------------------------------------------------------------------------------------------------------------------//
	if (temp == 0)
	{
		cout << entered << " was not found. Check spelling and try again." << endl;
		return 0;
	}
	return 1;
}

void Reservation::CarInfo(string car, string color, int& carPos, int& carpin, int& colorpin)//might need better name
{
	//carpin is vehicle type
	//carPos is which car/car color
	//colorpin is carpos+1?
	if (car == "pickup")
	{
		carpin = 1;
		for (int i = 0; i < pickups.size(); i++)
		{
			if (makeLower(pickups.at(i).getColor()) == color)
			{
				carPos = i;
				colorpin = i + 1;
				break;//stop loop so it doesnt go unessearily long
			}
		}
		if (carPos == -1)
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
				carPos = i;
				colorpin = i + 1;
				break;
			}
		}
		if (carPos == -1)
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
				carPos = i;
				colorpin = i + 1;
				break;
			}
		}
		if (carPos == -1)
		{
			//error
			cout << "No car mathcing your description was found." << endl;
		}
	}
}
