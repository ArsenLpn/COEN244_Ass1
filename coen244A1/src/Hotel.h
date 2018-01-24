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
	void printCustomerReservation(int,int,int);//day,month,year //done
	void printCustomerRegularReservation(int,int,int,bool = false);//day,month,year, time frame // done
	void printCustomerSuiteReservation(int,int,int);//given time frame /done
	void printCustomerStayLongerThan(int)const;//

	void printHotelInfo(){cout<<*this;};//...

	bool isFull();//-1 if full, else index of first available room //done


	//Reservation related functions
	void addReservation(int d, int m, int y, int duration, bool isSuite);//done
	void cancelReservation(string customerName);//done

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
