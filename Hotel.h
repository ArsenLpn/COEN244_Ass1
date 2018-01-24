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
	Hotel(string="hotelName",string="hotelAddress",string="1234567890");//done
	~Hotel();//done

	//Hotel functions
	void setHotelName(string);//done
	void setHotelAddress(string);//done
	void setHotelTel(string);//done

	string getHotelName()const;//done
	string getHotelAddress()const;//done
	int getNbOfRooms()const;//done
	/*############################################################*/
	void printRoomsAvailability(int,int,int)const;//on given day,month,year
	void printCustomerReservation(int,int,int)const;//day,month,year
	void printCustomerRegularReservation(int,int,int)const;//day,month,year, time frame
	void printCustomerSuiteReservation(int,int,int)const;//given time frame
	void printCustomerStayLongerThan(int)const;//

	void printHotelInfo(){cout<<*this;};//...
	/*#############################################################*/
	//Reservation related functions
	void addReservation(int d, int m, int y, int duration, bool isSuite);
	void cancelReservation();//may create dangling pointers
	void updateReservationAttributes(string,string,string,int);
	void updateReservationLength(int);
	int getRoomNumber()const;

	//Room related functions
	void updateRoomAttributes(int,bool,bool);
	void updateRoomNumber(int);//
	void updateRoomAvailability(bool);
	void updateRoomType(bool);

	//Customer related functions
	void updateCustomerAttributes(string,string,string,int,int,int);
	void updateCustomerName(string);
	void updateCustomerAddress(string);
	void updateCustomerTel(string);
	void updateCustomerDateOfBirth(int,int,int);
	string getCustomerName()const;



};

#endif /* HOTEL_H_ */
