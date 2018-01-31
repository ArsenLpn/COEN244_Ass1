#include "stdafx.h"
#include "Hotel.h"

using namespace std;
Hotel::Hotel()
{
	int nbRoomsTemp = 0;
	//RoomsAmount = 0;
	cout << "\nEnter name of the Hotel: ";
	cin >> this->name;
	cout << "\nEnter the address: ";
	cin >> this->address;
	cout << "\nEnter the phone number: ";
	cin >> this->tel;
	cout << "\nEnter number of rooms to be assigned to this hotel: ";
	cin >> nbRoomsTemp;

	for (size_t i = 0; i < nbRoomsTemp; i++)					//create few rooms set by nbRoomsTemp
	{
		Room*tRoom = new Room(i + 1, 1, ((i < nbRoomsTemp / 2) ? 0 : 1));
		roomsList.push_back(*tRoom);
	}
	this->roomsAmount = roomsList.size();
	roomIter = roomsList.begin();

	cout << "\nCreate default set of reservations?";
	for (size_t i = 0; i < 3; i++)								//create 3 reservations
	{
		Reservations*reservPtr = new Reservations(i + 1, 2 * i, new Date((3*i+1), 1, 2000),*roomIter);
		reservationsList.push_back(*reservPtr);
		roomIter++;
	}
	resIter = reservationsList.begin();
}


Hotel::~Hotel()
{
}


void Hotel::RoomGet(Date *date)
{
	cout << "\nRooms reserved on the given date are:";
	resIter = reservationsList.begin();
	while (resIter!=reservationsList.end())
	{
		Date *tDate = new Date(resIter->GetDate());
		if (tDate->GetYear() == date->GetYear())
		{
			if (tDate->GetMonth()==date->GetMonth())
			{
				if (tDate->GetDay() == date->GetDay())
					cout << resIter->GetRoomNb() << endl;
			}
		}
		++resIter;
	}
	cout << "\nNo more rooms.";
}


void Hotel::CustomersGet(Date *nDate)
{
	cout << "\nCustomers reserved on the given date are:";
	resIter = reservationsList.begin();
	while (resIter != reservationsList.end())
	{
		Date *tDate = new Date(resIter->GetDate());
		if (tDate->GetYear() == nDate->GetYear())
		{
			if (tDate->GetMonth() == nDate->GetMonth())
			{
				if (tDate->GetDay() == nDate->GetDay())
					cout << resIter->GetCustomerName() << endl;
			}
		}
		++resIter;
	}
	cout << "\nNo more customers.";
}


void Hotel::CustomersGet(Date*sDate, Date*eDate, bool rStyle)
{
	/*list all the reservations flaged against startDate and every next date until endDate;
	print customers from flaged list*/
	//1 get customers from the range of dates
	//2,3 get customers from the type of room
}


void Hotel::CustomersGet(int stayDuration)
{
	/*print every customer from reservations that matches the duration*/
}


bool Hotel::HotelFull(Date gDate)
{
	/*test list of reservations for given date; return true if all the rooms in the list are reserved*/
	return false;
}


void Hotel::PrintInfo()									//Info about hotel
{
	cout << "The hotel named " << this->name << "has the following information";
	cout << "\nAddress: " << this->address;
	cout << "\nPhone: " << this->tel;
	cout << "\nWith total number of rooms: " << this->roomsAmount;
}
