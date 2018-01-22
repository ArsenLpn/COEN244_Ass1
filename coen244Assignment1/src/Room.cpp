/*
 * Room.cpp
 *
 *  Created on: Jan 16, 2018
 *      Author: vpuyf
 */
#include "Room.h"
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

ostream& operator<<(ostream& out, const Room &r){

	out //<< "\tRoom Information\n"
		<<"Room number: "<<r.roomNb
		<<".\nRoom Type: "<<r.roomType()
		<<".\nAvailable: ";
	r.available?out<<"Yes.\n":out<<"No.\n";
	return out;
}
Room& Room::operator=(Room &r){

	this->roomNb=r.roomNb;
	this->isSuite=r.isSuite;// basically swappingg, for other classes i ll use swap
	this->available=r.available;
	return *this;
}
Room::Room(int roomNb, bool isSuite, bool available){
	this->roomNb = roomNb;
	this->isSuite = isSuite;
	this->available = available;
}
Room::Room(const Room &copy){
	roomNb= copy.roomNb;
	isSuite=copy.isSuite;
	available=copy.available;
}
Room::~Room(){
	//nothing for now
}
void Room::setRoomNb(int roomNb){
	this->roomNb=roomNb;
}
void Room::setAvailability(bool occupied){
	available = occupied;
}
void Room::changeRoomType(bool changeType){
	cout<<"The room #"<<roomNb<<" was of type ";
	isSuite?cout<<"Suite.\n":cout<<"Regular.\n";

	isSuite = changeType;
	cout << "The roomType has been changed to ";
	isSuite?cout<<"Suite.\n":cout<<"Regular.\n";
}
int Room::getRoomNumber()const{
	return roomNb;
}
bool Room::isAvailable()const
{
	return available;
}
string Room::roomType()const
{
	return isSuite?"Suite":"Regular";
}
void Room::printRoomInfo()const{
	cout<<*this;
}

