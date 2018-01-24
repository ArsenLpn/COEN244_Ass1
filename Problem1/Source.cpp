#include <iostream>
#include <string>
#include <iomanip>

#include "Customer.h"
#include "Date.h"

using namespace std;
int main()
{
	cout << "Creating the customer object with pointer myCustomer\n";
	Customer *myCustomer= new Customer();								//test the constructor
	myCustomer->PrintInfo();

	cout << "\nRunning ChangeAddress(string)";
	myCustomer->ChangeAddress("New Address");							//Address changed to 'new address'
	
	cout << "\nRunning ChangeTelephone(string)";
	myCustomer->ChangeTelephone("New Telephone");							//Telephone changed to "NewTlephone"
	
	cout << "\nRunning ChangeDateOfBirth(Date)";
	Date *newDate = new Date(7, 7, 2000);
	myCustomer->ChangeDateOfBirth(newDate);								//DateOfBirth changed to 7/7/2000
	
	cout << "\nprinting new customer information";
	myCustomer->PrintInfo();											//Printing new info

	system("PAUSE");

}
