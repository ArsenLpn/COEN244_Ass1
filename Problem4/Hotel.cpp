#include "stdafx.h"
#include "Hotel.h"

using namespace std;
Hotel::Hotel()
{
	int nbRoomsTemp = 0;
	char tChar;
	//RoomsAmount = 0;
	cout << "\nEnter name of the Hotel: ";
	cin >> this->name;
	cout << "\nEnter the address: ";
	cin >> this->address;
	cout << "\nEnter the phone number: ";
	cin >> this->tel;
	cout << "\nEnter number of rooms to be assigned to this hotel: ";
	cin >> nbRoomsTemp;

	for (size_t i = 0; i < nbRoomsTemp; i++)
	{
		//TODO: populate the list of rooms...test
		Room*tRoom = new Room(i + 1, 1, ((i < nbRoomsTemp / 2) ? 0 : 1));
		roomsList.push_back(*tRoom);
	}
	this->roomsAmount = roomsList.size();
	roomIter = roomsList.begin();
	cout << "\nCreate default set of reservations?(y/n)";
	cin >> tChar;
	if (tChar == 'y' || tChar == 'Y')
	{
		reservationsList.push_back();
	}
}


Hotel::~Hotel()
{
}


void Hotel::RoomGet(Date *Date)
{

}


void Hotel::CustomersGet(Date *nDate)
{
}


void Hotel::CustomersGet(Date*sDate, Date*eDate, bool rStyle)
{
}


void Hotel::CustomersGet(int stayDuration)
{
}


bool Hotel::HotelFull()
{
	return false;
}


void Hotel::PrintInfo()
{
}
