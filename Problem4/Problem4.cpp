// Problem4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Hotel.h"

int main()
{
	//create new hotel
	cout << "\nCreating new hotel:";
	Hotel*hotelPtr = new Hotel();					//constructor
	Date*testDate = new Date(4, 1, 2000);

	cout << "\n\nRunning RoomGet() to retrieve rooms ocupied on a given date.";
	hotelPtr->RoomGet(testDate);


	cout << "\nPress enter to exit";
	cin.get();
	cin.get();
    return 0;
}

