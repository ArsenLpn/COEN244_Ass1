/*
 * RoomMain.cpp
 *
 *  Created on: Jan 16, 2018
 *      Author: vpuyf
 */
#include <iostream>
#include"Room.h"
#include <string>
using namespace std;

int main(){
	Room *r = new Room();
	cout <<*r<<endl;
	r->setRoomNb(10);
	r->setAvailability(true);
	Room *copy =r;
	cout<<*r<<"\nCopied room:\n"<<*copy;

	delete r;
	cout<<copy;
	return 0;
}



