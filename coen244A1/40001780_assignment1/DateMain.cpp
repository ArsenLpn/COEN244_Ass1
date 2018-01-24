/*
 * testDate.cpp
 *
 *  Created on: Nov 11, 2017
 *      Author: vpuyf
 */

#include <iostream>
#include <array>
#include "date.h"
using namespace std;
int main(){
	Date *a = new Date(21,1,2018);
	Date *b = new Date(24,1,2018);

	cout<<a->dateDifferential(*b); // +
	cout<< b->dateDifferential(*a);// -
	return 0;
}
