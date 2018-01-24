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

	Hotel *test = new Hotel("Trump Tower");
	test->addReservation(1,1,1,1,true);
	cout<<*test<<"a";

	delete test;
	return 0;
}

