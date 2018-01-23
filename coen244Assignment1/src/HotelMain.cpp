/*
 * HotelMain.cpp
 *
 *  Created on: Jan 17, 2018
 *      Author: vpuyf
 */
#include "Hotel.h"
#include "Reservation.h"
#include <iostream>
#include <list>
using namespace std;
int main(){

	int stayDuration = 5;

	Hotel *test = new Hotel("Trump Tower","1234 rue Sainte Catherine West","012 345-6789");
	cout<<"\tHotel Reservation System 1.0\n\n\n"
		<<*test;

	test->printRoomsAvailability(1,1,2018);
	cout<<"Let's now make a reservation\n";
	test->addReservation(30,1,2018,stayDuration,SUITE);
	cout<<"Lets make another reservation\n";
	test->addReservation(26,1,2018,10,REGULAR);
	test->printRoomsAvailability(30,1,2018);
	//cout<<*test;
	test->printCustomerReservation(30,1,2018);
	test->printCustomerSuiteReservation(1,2,2018);
	delete test;
	return 0;
}



