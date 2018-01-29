// Problem3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Reservations.h"

int main()
{
	//Declarations
	cout << "Creating objects of Reservations and Room";
	Reservations *myReservationPtr = new Reservations();					//create new reservation
	Room *myRoomPtr = new Room(5,1,false);											//create new room
	/////////////////////////

	//Testing Reservations class
	cout << "\ntesting reservations object:\n";
	myReservationPtr->AssignRoom(myRoomPtr);								//Run AssignRoom() => assign myRoomPtr to myReservationPtr
	cout << "\nRoom number is: " << myReservationPtr->GetRoomNb();			//run GetRoomNb()
	cout << "\nCustomer name: " << myReservationPtr->GetCustomerName();		//Run GetCustomerName()
	myReservationPtr->PrintInfo();											//Run PrintInfo()




    return 0;
}

