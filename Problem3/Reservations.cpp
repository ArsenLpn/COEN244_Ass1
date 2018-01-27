#include "stdafx.h"
#include "Reservations.h"


Reservations::Reservations()							//Cunstructor ...dome
{
	customer = new Customer();
	room = new Room();
	reservation = 0;
	durration = 0;

}


Reservations::~Reservations()
{

}
