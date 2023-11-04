#pragma once
#include"includes.h"
#include"Pickup.h"
#include"Compact.h"
#include"Sedan.h"
#include"Person.h"

using namespace std;

int chartoint(string numIn);
void FileIn(string fileName, vector<Pickup>&, vector<Compact>&, vector<Sedan>&, vector<Person>&);
int makeRand(int length);