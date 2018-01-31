#pragma once
#include "stdafx.h"
#include "../Problem1/Date.h"				//Second attempt to include classes. first one in stdafx.h
#include "../Problem1/Customer.h"
#include "../Problem2/Room.h"


class Reservations
{
public:
	Reservations();
	Reservations(int reservID, int durration, Date *sDate,Room room);
	void AssignRoom(Room*);
	int GetRoomNb();
	string GetCustomerName();
	void PrintInfo();
	Date GetDate();
	~Reservations();

private:
	int reservation;
	Customer *customer;
	Room *room;
	Date *startDate;
	int durration;
	//int static reservationsCount;

};

