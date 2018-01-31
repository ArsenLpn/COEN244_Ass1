#pragma once
#include "stdafx.h"
#include "../Problem1/Date.h"				//Second attempt to include classes. first one in stdafx.h
#include "../Problem1/Customer.h"
#include "../Problem2/Room.h"


class Reservations
{
public:
	Reservations();
	void AssignRoom(Room*);
	int GetRoomNb();
	string GetCustomerName();
	void PrintInfo();
	~Reservations();

private:
	int reservation;
	Customer *customer;
	Room *room;
	int durration;
	//int static resefvationsCount;

};

