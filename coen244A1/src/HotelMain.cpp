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

	int stayDuration = 6;
	string yourCustomer;

	cout<<"\tHotel Reservation System 1.0\n\n\n";
	Hotel *test = new Hotel("Trump Tower","1234 rue Saint Catherine West","012 345-6789");

	cout<<*test;

	test->printRoomsAvailability(30,1,2018);

	cout<<"Let's now make a reservation for a Suite.\n";
	test->addReservation(30,1,2018,stayDuration,SUITE);

	cout<<"Lets make another reservation for a Suite\n";
	test->addReservation(26,1,2018,9,SUITE);

	test->printRoomsAvailability(1,2,2018);
	test->printCustomerSuiteReservation(1,2,2018);

	cout<<"Lets now make a reservation for a regular room.\n";
	test->addReservation(28,1,2018,12,REGULAR);

	test->printCustomerReservation(29,1,2018,5,2,2018);
	test->printCustomerRegularReservation(1,2,2018);
	test->printCustomerStayLongerThan(8);
	cout <<*test
			<<"\nNow lets try to cancel a reservation. It is done by searching the name of the customer.\n"
			<<"Please enter the name of one of the customer your entered before: ";

	cin>>yourCustomer;
	test->cancelReservation(yourCustomer);

	test->printCustomerReservation(29,1,2018,5,2,2018);



	delete test;
	return 0;
}



