#pragma once
/*The additional include directry were included via Visal studio project properties. this allows direct inclusion of files from other project(folders) as follows:*/
#include "Room.h"									//IF PROJECT IS MISSING CLASSES USE #include "../Problem1/Room.h"
#include "Customer.h"								//IF PROJECT IS MISSING CLASSES USE #include "../Problem2/Customer.h"
#include "Date.h"									//../Problem2/Date.h

class Reservations
{
public:
	Reservations();									//since you have static instances as data members, look into initialization list
	~Reservations();
private:
	int reservation;
	Customer *customer;	
	Room *room;	
	int durration;
};

