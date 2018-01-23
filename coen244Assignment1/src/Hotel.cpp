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
#include <cmath>

ostream& operator<<(ostream &out, const Hotel &T){

	out <<"####################################################\n"
		<<"\tHere is everything about your Hotel:\n\n"
		<<"\nHotel's Name: "<<setw(T.name.length()+5)<<T.name
		<<".\nHotel's Address: "<<setw(T.address.length()+2)<<T.address
		<<".\nHotel's Telephone: "<<T.tel
		<<".\n\nThere are "<<T.nbOfRoom<<" rooms."
		<<"\nThere ";
		T.rList.size()>1? out<<"are ":out<<"is ";
	    out<<"currently "<<T.rList.size();
		T.rList.size()>1? out<<" reservations.":out<<" reservation."
		<<"\n####################################################\n";


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
bool Hotel::isFull(){
//return -1 if full, else return the index of first available room
	int i;
	for(i=0;i<nbOfRoom;++i)
		if(rooms[i].isAvailable())
			break;
	return (i<nbOfRoom? false:true);
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

void Hotel::addReservation(int day, int month, int year, int stayDuration, bool wantSuite){
	string name, address, tel;
	int custDay, custMonth, custYear;
	int roomAvailable;
	//checking if any room is available,if so then checking if right type
	for(roomAvailable = 0;roomAvailable<nbOfRoom;++roomAvailable )
		if(rooms[roomAvailable].isAvailable() && rooms[roomAvailable].getRoomType()==wantSuite)
			break;
	if(roomAvailable == nbOfRoom){
		cout<<"Cannot make the reservation. All rooms are booked!\n";
		return;
	}
	//

	rooms[roomAvailable].setAvailability(false);
	rList.push_back(*new Reservation());//adding a new reservation to the list
	rList.back().setArrivalDate(day,month,year);
	rList.back().setStayDuration(stayDuration);

	cout<<"****************************************************\n"
		<<"\tStarting Registration Process.\n"
		<<"Please enter the Customer's name:";

	getline(cin,name);
	cin.clear();

	cout<<"Please enter the customer's address:";
	getline(cin,address);
	cin.clear();

	cout<<"Please enter the customer's telephone:";
	getline(cin,tel);
	cin.clear();

	cout<<"Please enter the Customer's date of birth:\n\tDay: ";
	cin>>custDay;
	cout<<"\tMonth: ";
	cin>>custMonth;
	cout<<"\tYear: ";
	cin>>custYear;
	cin.ignore();

	rList.back().setCustomerInfo(name,address,tel,custDay,custMonth,custYear);
	rList.back().setRoom(rooms[roomAvailable]);//copy hotel room attributes to Reservation room
	cout<<"\tRegistration Completed.\n"
		<<"****************************************************\n"
		<<rList.back();
}
void Hotel::cancelReservation(string custName){

	list<Reservation>::iterator iterator;
	list<Reservation>::iterator end;

	for(iterator = rList.begin(),end = rList.end();iterator != end; ++iterator)//checking for available room at date entered
		if(!iterator->getCustomerName().compare(custName))
			break;
	if(iterator == end){
		cout<<"No match for this name.\n";
		return;
	}
	rooms[iterator->getRoomNumber()].setAvailability(true);
	rList.erase(iterator);
	cout<<"Reservation deleted.\n";

}
void Hotel::printRoomsAvailability(int day, int month, int year){

	Date *temp = new Date(day,month,year);
	int* rAvailable = new int[nbOfRoom];
	list<Reservation>::iterator iterator, end;
	for(int i=0;i<nbOfRoom;++i)
		rAvailable[i]=1;

	int counter=0;
	for(iterator = rList.begin(),end = rList.end();iterator != end; ++iterator, ++counter)
		if(iterator->getRoomAvailability()==false && abs(iterator->getArrivalDate().dateDifferential(*temp))<= iterator->getStayDuration())
			--rAvailable[counter];
	cout<<"****************************************************\n"
		<<"\tRooms Availability on the "<<*temp<<".\n\n";
	for(int i=0;i<nbOfRoom;++i){
		cout<<"\tRoom #"<<i+1<<" is";
		if(rAvailable[i]==0)
			cout<<" NOT";
		cout<<" available.\n";
	}
	cout<<"****************************************************\n";

	delete temp;
	delete[] rAvailable;
}
void Hotel::printCustomerReservation(int day,int month,int year){
	Date *temp = new Date(day,month,year);

	cout<<"****************************************************\n"
		<<"\t Customer's that have reserved a room on " << *temp<<endl;
	for(list<Reservation>::iterator iterator=rList.begin(), end=rList.end();iterator!=end;++iterator)
		if(abs(iterator->getArrivalDate().dateDifferential(*temp))<= iterator->getStayDuration())
			cout<<'\t'<<iterator->getCustomerName()<<'\n';
	cout<<"****************************************************\n";
	delete temp;
}
void Hotel::printCustomerSuiteReservation(int day,int month,int year){
	Date *temp = new Date(day,month,year);

	cout<<"****************************************************\n"
		<<"\t Customer's that have reserved a SUITE on " << *temp<<endl;
	for(list<Reservation>::iterator iterator=rList.begin(), end=rList.end();iterator!=end;++iterator)
		if(abs(iterator->getArrivalDate().dateDifferential(*temp))<= iterator->getStayDuration() && iterator->getRoomType()==true)
			cout<<'\t'<<iterator->getCustomerName()<<'\n';
	cout<<"****************************************************\n";
	delete temp;
}








