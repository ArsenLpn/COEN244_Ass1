#include "stdafx.h"
#include "Room.h"

using namespace std;
Room::Room(int Number,bool Available,bool Style)
{
	//Style: 0 = regular, 1 = suit
	this->Number = Number;
	this->Available = Available;
	this->Style = Style;
}


Room::~Room()
{
}


bool Room::ReturnAvailability()
{
	return Available;
}


bool Room::ReturnCategory()
{
	return Style;
}


void Room::PrintInfo()
{
	cout << "\nRoom information:"
		<<"\n\tNumber: " <<this->Number 
		<<"\n\tType: " <<(this->Style ? "Regular" : "Suit") 
		<<(this->Available ? "Available" : "Occupied");
}

int Room::GetNumber()
{
	return this->Number;
}
