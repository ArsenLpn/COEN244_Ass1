/*
 * Customer.cpp
 *
 *  Created on: Jan 16, 2018
 *      Author: vpuyf
 */
#include "Customer.h"
#include <string>
using namespace std;
Customer::Customer(string name, string address, string tel){
	this->name = name;
	this->address = address;
	this->tel = tel;
	this->dateOfBirth = new Date();
}
Customer::Customer(string name, string address, string tel, int day, int month, int year){
	this->name = name;
	this->address = address;
	this->tel = tel;
	this->dateOfBirth = new Date(day,month,year);
}
Customer::~Customer(){
	delete dateOfBirth;
}
void Customer::setName(string name){
	this -> name = name;
}
void Customer::setAddress(string address){
	this->address = address;
}
void Customer::setTel(string tel){
	this->tel = tel;
}
void Customer::setDate(int day, int month, int year){
	this->dateOfBirth->setDate(day,month,year);
}
ostream& operator <<(ostream &out, const Customer &c){

	out << "Name: "<< c.name
			<<"\nAddress: " << c.address
			<<"\nTelephone: " << c.tel
			<<"\nDate of birth: " << *c.dateOfBirth << endl;
	return out;
}
void Customer::printCustomerInfo() const{
	cout<<*this;
}
string Customer::getName()const{
	return name;
}
