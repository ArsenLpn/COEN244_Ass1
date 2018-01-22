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

	Hotel *test = new Hotel("Trump Tower","1234 rue Sainte Catherine West","012 345-6789");
	//test->addReservation(1,1,1,1,true);
	cout<<*test;
	delete test;
	return 0;
}

