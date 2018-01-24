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
Hotel::Hotel(string name, string address, string tel, bool displayInfo){

	this->name = name;
	this->address=address;
	this->tel=tel;
	rooms = new Room[this->nbOfRoom]();
	initRooms(displayInfo);
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
void Hotel::addReservation(int day, int month, int year , int duration, bool wantSuite){
/*
 * Look through room array to find a matching room
 * chevk if there s a reservation on this room
 *       if yes check if datrs dont intergfere
 * add a reservation if no reservation
 *
 * */

	Date *arrivalRequest =  new Date(day,month,year);
	list<Reservation>::iterator iterator, end;
	int *roomFound = new int[nbOfRoom];
	int chosenRoom=-1;
	int custDay, custMonth, custYear;
	string custName, custAddress, custTel;


	if(duration<1){
		cout<<"Stay duration invalid: you entered "<<duration<<'\n';
		return;
	}
	for(int i=0;i<nbOfRoom;++i)
	{//initializing roomFound to 0, and updating value if matching room is found
		roomFound[i]=0;
		if(rooms[i].getRoomType() == wantSuite)
			++roomFound[i];
	}
	//inverse logic here, we are looking for reservations that interfere with the request
	for(int counter=0;counter<nbOfRoom;++counter)
		for(iterator = rList.begin(),end = rList.end();iterator != end; ++iterator)
			//checking if there are any reservation on that room
			if(iterator->getRoomNumber() == counter+1)
			{
				if(iterator->getArrivalDate().dateDifferential(*arrivalRequest)>=0)
				{//checking if the reserved room and counter match, and if request happens AFTER the reservation arrival date
					if( iterator->getArrivalDate().dateDifferential(*arrivalRequest) <= iterator->getStayDuration())
						//check if request happens before iteration stay is over, hence removing that room as an option
						--roomFound[counter];//withdrawing that room
				}
				else if(arrivalRequest->dateDifferential(iterator->getArrivalDate()) < duration)
					//case where request happens BEFORE iterator, hence checking if request stay will overlap with iteration arrival
					--roomFound[counter];//withdrawing
			}
	//doing that for all rooms
	//the resulting roomFound[] should represent all your available rooms for the time requested
	/*for(int i=0;i<nbOfRoom;++i)
		cout<<"roomFound "<<roomFound[i]<<'\n';*/
	for(int i=0;i<nbOfRoom;++i)
		if(roomFound[i]==1)
		{//choosing first room
			chosenRoom=i;
			break;
		}
	//cout<<chosenRoom<<endl;
	if(chosenRoom==-1){
		cout<<"No room of type";
		wantSuite?cout<<" Suite":cout<<" regular";
		cout<<" available on "<<*arrivalRequest<<" for a stay of "<< duration <<" day(s).\n";
		return;
	}
	rList.push_back(*new Reservation());
	rList.back().setArrivalDate(day,month,year);
	rList.back().setStayDuration(duration);
	cout<<"****************************************************\n"
			<<"\tStarting Registration Process.\n"
			<<"Please enter the Customer's name:";

		getline(cin,custName);
		cin.clear();

		cout<<"Please enter the customer's address:";
		getline(cin,custAddress);
		cin.clear();

		cout<<"Please enter the customer's telephone:";
		getline(cin,custTel);
		cin.clear();

		cout<<"Please enter the Customer's date of birth:\n\tDay: ";
		cin>>custDay;
		cout<<"\tMonth: ";
		cin>>custMonth;
		cout<<"\tYear: ";
		cin>>custYear;
		cin.ignore();

		rList.back().setCustomerInfo(custName,custAddress,custTel,custDay,custMonth,custYear);
		rList.back().setRoom(rooms[chosenRoom]);//copy hotel room attributes to Reservation room
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
	for(int counter=0;counter<nbOfRoom;++counter)
		for(iterator = rList.begin(),end = rList.end();iterator != end; ++iterator)
			if(iterator->getRoomNumber()==counter+1)
			{
				if(iterator->getArrivalDate().dateDifferential(*temp) >= 0)
				{
					if(iterator->getArrivalDate().dateDifferential(*temp) <= iterator->getStayDuration())
						--rAvailable[counter];
				}
				else if(temp->dateDifferential(iterator->getArrivalDate()) < iterator->getStayDuration())
						--rAvailable[counter];
			}

	cout<<"****************************************************\n"
		<<"\tRooms Availability on "<<*temp<<".\n\n";
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
		<<"Customer's that have reserved a room on " << *temp<<endl;
	for(list<Reservation>::iterator iterator=rList.begin(), end=rList.end();iterator!=end;++iterator)
		if(iterator->getArrivalDate().dateDifferential(*temp)<= iterator->getStayDuration() && iterator->getArrivalDate().dateDifferential(*temp) >= 0)
			cout<<'\t'<<iterator->getCustomerName()<<'\n';
		else if(temp->dateDifferential(iterator->getArrivalDate()) > iterator->getStayDuration())
			cout<<'\t'<<iterator->getCustomerName()<<'\n';
	cout<<"****************************************************\n";
	delete temp;
}
void Hotel::printCustomerRegularReservation(int day,int month, int year,bool type){
	Date *temp = new Date(day,month,year);

		cout<<"****************************************************\n"
			<<"Customer's that have reserved a";
		type?cout<<" Suite":cout<<" Regular";
		cout<<" on " << *temp<<endl;
		for(list<Reservation>::iterator iterator=rList.begin(), end=rList.end();iterator!=end;++iterator)
			if(iterator->getArrivalDate().dateDifferential(*temp)<= iterator->getStayDuration() && iterator->getRoomType()==type)
				if(iterator->getArrivalDate().dateDifferential(*temp)>0)
					cout<<'\t'<<iterator->getCustomerName()<<'\n';
		cout<<"****************************************************\n";
		delete temp;
}
void Hotel::printCustomerSuiteReservation(int day,int month,int year){
	this->printCustomerRegularReservation(day,month,year,SUITE);
}
void Hotel::printCustomerStayLongerThan(int duration)const{

	cout<<"****************************************************\n"
		<<"Customer's that have reserved a room for longer than "<<duration;
	duration>1?cout<<" days.\n":cout<<" day.\n";

	for(list<Reservation>::const_iterator iterator=rList.begin(), end=rList.end();iterator!=end;++iterator)
		if(iterator->getStayDuration()>duration){
			cout<<'\t'<<iterator->getCustomerName()<<" is staying "<<iterator->getStayDuration();
			iterator->getStayDuration()>1?cout<<" days.\n":cout<<" day.\n";
		}
	cout<<"****************************************************\n";
}







