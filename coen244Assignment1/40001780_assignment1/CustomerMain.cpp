//============================================================================
// Name        : coen244Assignment1.cpp
// Author      : Valentin Puyfourcat
// Version     :
// Copyright   : School Stuff
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include "Customer.h"
using namespace std;

int main() {
	Customer *test = new Customer();
	string sInput;
	int day,month,year;

	cout<<"Here is an unitialized customer:\n"<<*test
		<<"\nPlease enter the customer's name:";
	getline(cin, sInput);
	cin.clear();
	test->setName(sInput);

	cout<<"Please enter the customer's address:";
	getline(cin, sInput);
	cin.clear();
	test->setAddress(sInput);

	cout<<"Please enter the customer's telephone:";
	getline(cin, sInput);
	cin.clear();
	test->setTel(sInput);

	cout<<"Please enter the customer's date of birth:\nday:";
	cin >>day;
	cout<<"month: ";
	cin>>month;
	cout<<"year: ";
	cin >>year;

	test->setDate(day,month,year);
	cout<<"\nHere is your updated customer:\n"<<*test;

	return 0;
}
