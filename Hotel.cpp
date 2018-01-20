/*
 * Hotel.cpp
 *
 *  Created on: Jan 17, 2018
 *      Author: vpuyf
 */

#include "Room.h"
#include "Date.h"
#include "Customer.h"
#include "Reservation.h"
#include "Hotel.h"
#include <iostream>


ostream& operator<<(ostream &out, const Hotel &T){

	out<<"\n\n still have to do this\n\n";
	return out;
}
void Hotel::initRooms(bool printInfo){

	for(int i=0;i<nbOfRoom;++i){
		rooms[i] = *new Room(i+1,i%2==0,true);
		if(printInfo)cout<<"Rooms initialized like so:\n"<<rooms[i];
	}
}
Hotel::Hotel(string name, string address, string tel){

	this->name = name;
	this->address=address;
	this->tel=tel;
	rooms = new Room[this->nbOfRoom]();
	initRooms(true);
}
Hotel::~Hotel(){
	delete[] rooms;
}
void Hotel::setHotelName(string name){
	this->name=name;
}
void Hotel::setHotelAddress(string address){
	this->address = address;
}
void Hotel::setHotelTel(string tel){
	this->tel=tel;
}
/*void Hotel::setNbOfRoom(int n){

}*/
string Hotel::getHotelName()const{
	return this->name;
}
string Hotel::getHotelAddress()const{
	return this->address;
}
int Hotel::getNbOfRooms()const{
	return this->nbOfRoom;
}
void Hotel::printRoomsAvailability(int day, int month, int year)const{
	Date *temp =new Date(day, month, year);




	delete temp;
}
void Hotel::addReservation(int day, int month, int year , int duration, bool isSuite){
	/*
	 * first look through the list at the specified date and look for available rooms
	 *
	 * then if requested type of room is available
	 *
	 * look if requested duration is available
	 * */

	unsigned int roomsAvailable=0;
	Date *arrivalRequest = new Date(day, month, year);
	rList.push_back(*new Reservation());
	for(list<Reservation>::iterator iterator = rList.begin(),end = rList.end();iterator != end; ++iterator){//checking for available room at date entered

		Date *temp = new Date(iterator->getArrivalDate());

		//check if  a room is available at requested arrival date
		if(temp->compareDates(*arrivalRequest)==1)
			//-1 means the caller happens before
			//1 means the caller happens after
			//0 means same day
		{
			temp->addDays(iterator->getStayDuration());//adding the stayDuration to the requested date arrival
			arrivalRequest->addDays(duration);//adding da
			if(temp->compareDates(*arrivalRequest) )
			++roomsAvailable;
		}
	}


	delete arrivalRequest;
}












