/*
 * ReservationMain.cpp
 *
 *  Created on: Jan 16, 2018
 *      Author: vpuyf
 */




#include "Reservation.h"
#include <iostream>

int main(){

	Reservation *test = new Reservation(2);
	cout<<*test;

	test->setArrivalDate(30,1,2018);
	test->setRoom(42,true,false);
	test->setCustomerInfo("Valentin Puyfourcat","1234 Main Street",
							"40001780",1,3,1996);

	test->setRoom(99,false, true);
	cout <<*test;

	test->setStayDuration(15);
	cout <<*test;
	delete test;
	return 0;

}
