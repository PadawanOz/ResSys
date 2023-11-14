/*
* funstions.h
* gavin mcintosh and shaun ryan
* cpet 321
*
* header file for class functions.
*/

#pragma once
#include"includes.h"
#include"Pickup.h"
#include"Compact.h"
#include"Sedan.h"
#include"Person.h"

using namespace std;
							//function prototypes
int chartoint(string numIn);
int makeRand(int length);
int GetFirstDigit(int num);

void FileIn(string fileName, vector<Pickup>&, vector<Compact>&, vector<Sedan>&, vector<Person>&);

string makeLower(string input);