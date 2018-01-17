#include "Customer.h"
#include <iostream>
#include <string>

using namespace std;
Customer::Customer()
{
	string dateOfBirth;

	cout << "\nEnter new customer's name: ";
	cin >> Name;
	cout << "\nEnter customer's address:  ";
	cin >> Address;
	cout << "\nEnter customer's phone number: ";
	cin >> Tel;
	cout << "\nEnter customer's date of birth (format: DD/MM/YYYY): ";
	cin >> dateOfBirth;

	//Convert string to Date obj.


	


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
