#include "stdafx.h"
#include "Reservations.h"


Reservations::Reservations()							//Constructor ...dome
{
	customer = new Customer();
	//room = new Room();
	reservation = 0;
	durration = 0;

}
Reservations::Reservations(int reservID, int durration,Date *sDate,Room room)
{
	customer = new Customer("john", "there", "123", 5, 5, 2000);
	this->reservation=reservID;
	this->durration = durration;
	this->startDate = sDate;
	this->room = &room;
}


Reservations::~Reservations()
{

}


void Reservations::AssignRoom(Room*newRoom)						//Assignes a pointer to a room object

{
	this->room = newRoom;
}


int Reservations::GetRoomNb()									//Returns room number associated with the reservation
{

	if (this->room!=NULL)												//Check for pointer validity
	{
		return this->room->GetNumber();
	}
	else
	{
		std::cout << "\nThis reservation doesn't have a room associated with it!\n";
		return 0;
	}
}


string Reservations::GetCustomerName()								//Returns customer name
{
	return this->customer->GetName();
}


void Reservations::PrintInfo()										//Prints information stored in this reservation
{
	cout << "\nReservation number " << this->reservation << ":";
	cout << "\nReserved by:";
	this->customer->PrintInfo();
	cout << endl;
	this->room->PrintInfo();
	cout << "\nFor the amount of " << this->durration << " day" << (this->durration == 1 ? "" : "s");
}

Date Reservations::GetDate()
{
	return *startDate;
}
