/*
* TITLE: functions.h
* AUTHORS: Gavin McIntosh and Shaun Ryan
* COURSE: cpet 321
* DATE: 11/13/23
* DESCRIPTION: header file for class functions.
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