#pragma once
#include <string>
#include "Date.h"

using namespace std;
class Customer
{
public:
	Customer();
	void ChangeAddress(string newAddress);
	void ChangeTelephone(string newTelephone);
	void ChangeDateOfBirth(Date* newDate);
	void PrintInfo();
	string GetName();
	~Customer();
private:
	string Name;
	string Address;
	string Tel;
	Date *DateOfBirth;

};

