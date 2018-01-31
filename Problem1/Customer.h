#pragma once
#include <string>
#include "Date.h"

using namespace std;
class Customer
{
public:
	Customer();
	Customer(string name, string address, string tel, int day, int month, int year);
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

