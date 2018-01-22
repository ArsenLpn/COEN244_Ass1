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
#include<iomanip>


ostream& operator<<(ostream &out, const Hotel &T){

	out <<"####################################################\n"
		<<"\tHere is everything about your Hotel:\n\n"
		<<"####################################################\n"
		<<"\nHotel's Name: "<<setw(T.name.length()+5)<<T.name
		<<".\nHotel's Address: "<<setw(T.address.length()+2)<<T.address
		<<".\nHotel's Telephone: "<<T.tel
		<<".\n\nThere are "<<T.nbOfRoom<<" rooms."
		<<"\nThere ";
		T.rList.size()>1? out<<"are ":out<<"is ";
	    out<<"currently "<<T.rList.size();
		T.rList.size()>1? out<<" reservations.":out<<" reservation.";


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
	initRooms(false);
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

		/*TO DO*/


	delete temp;
}
/*void Hotel::addReservation(int day, int month, int year , int duration, bool isSuite){

	//* first look through the list at the specified date and look for available rooms
	//*
	//* then if requested type of room is available
	//*
	//* look if requested duration is available


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
}*/
int Hotel::isFull(bool roomType){
//return -1 if full, else return the index of first available room
	int i;
	for(i=0;i<nbOfRoom;++i)
		if(rooms[i].isAvailable())
			break;
	return (i<nbOfRoom? i:-1);
}
void Hotel::addReservation(int day, int month, int year, int stayDuration, bool wantSuite){
	string name, address, tel;
	int custDay, custMonth, custYear;
	int roomAvailable = this->isFull(wantSuite);
	if(roomAvailable==-1){
		cout<<"Cannot make the reservation. All rooms are booked!\n";
		return;
	}
	//checking if right type of room is available
	rooms[roomAvailable].setAvailability(false);
	rList.push_back(*new Reservation());//adding a new reservation to the list
	rList.back().setArrivalDate(day,month,year);

	cout<<"Please enter the Customer's name:";
	getline(cin,name);
	cin.clear();

	cout<<"Please enter the customer's address:";
	getline(cin,address);
	cin.clear();

	cout<<"Please enter the Customer's date of birth:\nDay: ";
	cin>>custDay;
	cout<<"Month: ";
	cin>>custMonth;
	cout<<"Year: ";
	cin>>custYear;

	rList.back().setCustomerInfo(name,address,tel,custDay,custMonth,custYear);
	rList.back().setRoom(rooms[roomAvailable]);
}











