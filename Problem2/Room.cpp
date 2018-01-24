#include "stdafx.h"
#include "Room.h"

using namespace std;
Room::Room(int Number=0,bool Available=1,bool Style=0)
{
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
	cout<<"\nRoom information:"<<"\n\tNumber: "<<this->Number<<"\n\tType: "<<(this->Style)?""
}
