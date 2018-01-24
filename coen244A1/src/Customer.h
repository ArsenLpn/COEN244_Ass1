/*
 * Customer.h
 *
 *  Created on: Jan 16, 2018
 *      Author: vpuyf
 */

#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <string>
#include <iostream>
#include <array>
#include "Date.h"
using namespace std;

class Customer{

	friend ostream &operator <<(ostream &out, const Customer &c);
	string name;
	string address;
	string tel;
	Date *dateOfBirth;

public:
	Customer(string="uninitialized", string ="uninitialized", string="uninitialized");
	Customer(string,string,string,int day,int month, int year);
	~Customer();
	void setName(string name);
	void setAddress(string address);
	void setTel(string tel);
	void setDate(int day, int month, int year);
	void printCustomerInfo() const;
	string getName()const;

};




#endif /* CUSTOMER_H_ */
