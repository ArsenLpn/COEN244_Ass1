/*
 * Hotel.h
 *
 *  Created on: Jan 17, 2018
 *      Author: vpuyf
 */

#ifndef HOTEL_H_
#define HOTEL_H_
#include "Room.h"
#include "Date.h"
#include "Customer.h"
#include "Reservation.h"
#include <iostream>
#include <list>


class Hotel{
	friend ostream& operator<<(ostream &out, const Hotel &T);

	string name;
	string address;
	string tel;
	const int nbOfRoom = 10;
	list<Reservation> rList;
	Room *rooms;
	void initRooms(bool printInfo);//helper fct for rooms initialization  //done

public:
	Hotel(string="hotelName",string="hotelAddress",string="1234567890",bool = false);//done
	~Hotel();/*TO DO*/

	//Hotel functions
	void setHotelName(string);//done
	void setHotelAddress(string);//done
	void setHotelTel(string);//done

	string getHotelName()const;//done
	string getHotelAddress()const;//done
	int getNbOfRooms()const;//done

	void printRoomsAvailability(int,int,int);//on given day,month,year //done
	void printCustomerReservation(int,int,int,int,int,int);//time frame
	void printCustomerRegularReservation(int,int,int,bool = false);//time frame
	void printCustomerSuiteReservation(int,int,int);//time frame
	void printCustomerStayLongerThan(int)const;//DONE
	void printHotelInfo(){cout<<*this;};//done
	bool isFull();//-1 if full, else index of first available room //done
	void addReservation(int d, int m, int y, int duration, bool isSuite);//done
	void cancelReservation(string customerName);//done
};

#endif /* HOTEL_H_ */
