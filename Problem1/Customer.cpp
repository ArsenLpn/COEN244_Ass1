#include "Customer.h"
#include <iostream>
#include <string>

using namespace std;
Customer::Customer()
{
	string dateOfBirth, tempStr;

	cout << "\nEnter new customer's name: ";
	cin >> Name;
	cout << "\nEnter customer's address:  ";
	cin >> Address;
	cout << "\nEnter customer's phone number: ";
	cin >> Tel;
	cout << "\nEnter customer's date of birth (format: DD/MM/YYYY): ";
	cin >> dateOfBirth;

	//Convert string to Date obj.
	int newDay, newMonth, newYear;
	size_t length = 2;
	tempStr = dateOfBirth.substr(2);
	newDay = stoi(tempStr, &length);
	tempStr = dateOfBirth.substr(3, 2);
	newMonth = stoi(tempStr, &length);
	tempStr = dateOfBirth.substr(6, 4);
	length = 4;
	newYear = stoi(tempStr, &length);

}


Customer::~Customer()
{
}


void Customer::ChangeAddress(string newAddress)
{
}


void Customer::ChangeTelephone(string newTelephone)
{
}


void Customer::ChangeDateOfBirth(Date* newDate)
{
}


void Customer::PrintInfo()
{
}
