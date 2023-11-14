/*
* functions.cpp
* gavin mcintosh and shaun ryan
* cpet 321
* 11/13/23
* main file for class functions. holds useful functions for programming efficiency.
*/

#include "functions.h"


int chartoint(string numIn) //converts numerical string to interger
{
	int digits = numIn.size();//gets number of numbers in the string
	int temp;
	int power = digits;
	int finalInt = 0;

	for (int i = 0; i < digits; i++)
	{
		power = digits - (i + 1);
		temp = numIn.at(i) - '0';
		finalInt += (temp * pow(10, power));

	}

	return finalInt;
}


void FileIn(string fileName, vector<Pickup>& pickups, vector<Compact>& compacts, vector<Sedan>& sedans, vector<Person>& people) //Reads in data from file.
{
	vector<string> carColors = { "Purple","Green","Black","Red","Blue","Yellow","Blue","Black","Green" };//list of colors for the cars in the order they show up in the file.

	ifstream infile(fileName);

	string num;//store words and numbers from file
	string FirstName;
	string LastName;
	int Points;

	int state = 1;//should not be 0, will return error if it is. Starts positive for drivers then goes negative for passengers.
	int tempstate = 0;
	int carNum = 0;//0 for truck, 1 for compact, 2 for sedan
	int carstate = 0;


	if (!infile.is_open())
	{
		cout << "File Error. No changes made." << endl;
		exit;
	}

	for (int i = 0; i < 3; i++)//get first 3 pickup Drivers
	{
		infile >> FirstName;
		infile >> LastName;
		pickups.push_back(Pickup(FirstName, LastName, carColors.at(i)));
	}
	for (int i = 0; i < 3; i++)// get second 3 compact drivers
	{
		infile >> FirstName;
		infile >> LastName;
		compacts.push_back(Compact(FirstName, LastName, carColors.at(i + 3)));
	}
	for (int i = 0; i < 3; i++)//get last 3 sedan drivers
	{
		infile >> FirstName;
		infile >> LastName;
		sedans.push_back(Sedan(FirstName, LastName, carColors.at(i + 6)));
	}

	while (!infile.eof())//rest of the file should be passengers
	{
		infile >> FirstName;
		infile >> LastName;
		infile >> num;
		Points = chartoint(num);
		people.push_back(Person(FirstName, LastName, Points));
	}
	infile.close();
}

int makeRand(int length)//makes random number of length. no numbers are 0
{
	int temp = 0;
	int power = 0;

	for (int i = 0; i < length; i++)
	{
		power = length - (i + 1);//start in the highest position
		temp += (((rand() % 9) + 1) * pow(10, power));//random number 1-9 times 10^(i+1)
	}

	return temp;
}

int GetFirstDigit(int num) //gets first digit.
{
	int temp = num;
	while (temp > 10)
	{
		temp /= 10;
	}
	return temp;
}

string makeLower(string input) //converts all letters of a string into lowercase for ease of processing.
{
	string temp;
	for (int i = 0; i < input.length(); i++)
	{
		temp.push_back(tolower(input.at(i)));
	}
	return temp;
}