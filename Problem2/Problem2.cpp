// Problem2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Room.h"

using namespace std;
int main()
{
	cout << "\nCreating new Room object";
	Room *RoomPtr = new Room();											//Creating new room with RoomPtr pointer using default values 1,available,regular
	
	cout<< "\n\nRunning ReturnAvailability()" 
	<< "\nAvailability: "
		<<(RoomPtr->ReturnAvailability() ? "Is " : "Not")				//ReturnAvailability()
		<< "Available";
	cout << "\n\nRunning ReturnCategory()";
	cout << "\nAvailability is: " << (RoomPtr->ReturnCategory() ? "Is Available" : "Occupied");		//ReturnCategory()
	cout << "\n\nRunning PrintInfo()";
	RoomPtr->PrintInfo();

	cout << "\nPress Enter to exit";
	cin.get();
    return 0;
}

