#pragma once
#include "stdafx.h"

class Hotel
{
public:
	Hotel();

	~Hotel();
private:
	std::string name;
	std::string address;
	std::string tel;
	int roomsAmount;
	std::list<Room>roomsList;
public:
	void RoomGet(Date Date);
	void CustomersGet(Date nDate);
	void CustomersGet(Date sDate, Date eDate, bool rStyle);
	void CustomersGet(int stayDuration);
	bool HotelFull();
	void PrintInfo();
};
