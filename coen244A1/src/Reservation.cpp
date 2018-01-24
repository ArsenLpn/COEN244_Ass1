/*
 * Reservation.cpp
 *
 *  Created on: Jan 16, 2018
 *      Author: vpuyf
 */
#include <iostream>
#include <iomanip>
#include"Room.h"
#include "Date.h"
#include "Customer.h"
#include "Reservation.h"
#include <string>
using namespace std;

int Reservation::totalReservation = 0;
ostream& operator<<(ostream &out, const Reservation &R){

	out <<"####################################################\n"
		<< "\tReservation Information\n\nReservation #"
		<< R.reservationNb
		<<"\nBy customer: \n" <<*R.customer<<'\n'
		<<*R.room
		<<"Arrival Date: "<<*R.arrivalDate
		<<"\nStay duration: "<<R.stayDuration<<" day";
		R.stayDuration>1?out<<"s.\n":out<<".\n";
	out <<"####################################################\n";
	return out;
}
Reservation::Reservation(string name, string address, string tel, int stayDuration){
	reservationNb = ++totalReservation;
	customer = new Customer(name,address,tel);
	this->stayDuration = stayDuration;
	room = new Room();
	arrivalDate = new Date();
}
Reservation::~Reservation(){
	delete customer;
	delete room;
	delete arrivalDate;
}
void Reservation::setArrivalDate(int day, int month, int year){
	arrivalDate->setDate(day,month,year);
}
void Reservation::setRoom(int roomNb, bool type, bool available){
	room->setRoomNb(roomNb);
	room->setAvailability(available);
	room->changeRoomType(type);
}
void Reservation::setRoom(Room& r){
	*room = r;
}
void Reservation::setStayDuration(int days){
	stayDuration = days;
}
void Reservation::setCustomerInfo(string name, string address, string tel, int day, int month, int year){
	customer->setName(name);
	customer->setAddress(address);
	customer->setTel(tel);
	customer->setDate(day,month,year);
}
void Reservation::setRoomNumber(int roomNb){
	this->room->setRoomNb(roomNb);
}
void Reservation::resetTotalReservation(){
	Reservation::totalReservation=0;
}
int Reservation::getRoomNumber()const{
	return this->room->getRoomNumber();
}

int Reservation::getStayDuration()const{
	return stayDuration;
}
bool Reservation::getRoomAvailability()const{
	return room->isAvailable();
}
bool Reservation::getRoomType()const{
	return room->getRoomType();
}
string Reservation::getCustomerName()const{
	return customer->getName();
}
void Reservation::printReservationInfo()const{
	cout<<*this;
}

Date& Reservation::getArrivalDate(){
	Date *copy = new Date(*arrivalDate);
	return *copy;
}













