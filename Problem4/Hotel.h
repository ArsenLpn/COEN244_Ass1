#pragma once
#include "stdafx.h"

using namespace std;
class Hotel
{
public:
	Hotel();
	void RoomGet(Date*Date);
	void CustomersGet(Date*nDate);
	void CustomersGet(Date*sDate, Date*eDate, bool rStyle);				//get the customers in the date range 
	void CustomersGet(int stayDuration);
	bool HotelFull(Date gDate);
	void PrintInfo();

						/************************Getters and Setters********************/
	string GetName() const { return name; };
	void SetName(string newName) { this->name = newName; };
	string GetAddress() const { return this->name; };
	void SetAddress(string newAddress) { this->address = newAddress; };
	string GetTel()const { return this->tel; };
	void SetTel(string newTel) { this->tel = newTel; };
	int GetRoomsAmount()const { return this->roomsAmount; };
	void SetRoomsAmount(int newRoomsAmount) { this->roomsAmount; };
					////////////////////////////////////////////////////////////////

	~Hotel();
private:
	string name;
	string address;
	string tel;
	int roomsAmount;

	list<Room> roomsList;					//rooms list
	list<Room>::iterator roomIter;

	list<Reservations> reservationsList;	//reservations list
	list<Reservations>::iterator resIter;
};

