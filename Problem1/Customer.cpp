#include "Customer.h"
#include <iostream>
#include <string>

using namespace std;
Customer::Customer()
{
	this->DateOfBirth = new Date();
	//string dateOfBirth, tempStr;									//For alternative dateOfBirth registration
	int newDay, newMonth, newYear;

	cout << "Enter new customer's name: ";							//Prompt user for Custmer' types
	cin >> Name;
	cout.flush();

	if (this->Name!="default")
	{
		cout << "Enter customer's address:  ";
		cin >> Address;
		cout << "Enter customer's phone number: ";
		cin >> Tel;
		cout << "Enter customer's date of birth: " << endl;
		cout << "\tEnter day: ";
		cin >> newDay;
		cout << "\tEnter month: ";
		cin >> newMonth;
		cout << "\tEnter Year: ";
		cin >> newYear;
		cout << endl;
		this->DateOfBirth->ChangeDate(newDay, newMonth, newYear);
	}
	else
	{
		this->Name = "Jane Dow";
		this->Address = "here";
		this->Tel = "123-4567";
		this->DateOfBirth->ChangeDate(6,6,2000);
	}
	
	
	//Convert string to Date obj.									//Alternative dateOfBirth registration
	/*size_t length = 2;
	tempStr = dateOfBirth.substr(2);
	newDay = stoi(tempStr, &length);
	tempStr = dateOfBirth.substr(3, 2);
	newMonth = stoi(tempStr, &length);
	tempStr = dateOfBirth.substr(6, 4);
	length = 4;
	newYear = stoi(tempStr, &length);
	this->DateOfBirth.ChangeDate(newDay, newMonth, newYear);*/
}


Customer::~Customer()
{
}


void Customer::ChangeAddress(string newAddress)
{
	this->Address = newAddress;
}


void Customer::ChangeTelephone(string newTelephone)
{
	this->Tel = newTelephone;
}


void Customer::ChangeDateOfBirth(Date* newDate)
{
	this->DateOfBirth = newDate;
}


void Customer::PrintInfo()
{
	cout << "\nCustomer' info:";
	cout << "\n\tName: " << this->Name;
	cout << "\n\tAddress: " << this->Address;
	cout << "\n\tTelephone: " << this->Tel;
	cout << "\n\tDate of birth: ";this->DateOfBirth->PrintDate();
	cout << endl;
}
string Customer::GetName()
{
	return this->Name;
}
