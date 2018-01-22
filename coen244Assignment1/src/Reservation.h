/*
 * Reservation.h
 *
 *  Created on: Jan 16, 2018
 *      Author: vpuyf
 */

#ifndef RESERVATION_H_
#define RESERVATION_H_
#include "Date.h"
#include "Customer.h"
#include "Room.h"
#include <string>
#include <iostream>

class Reservation{
	friend ostream& operator<<(ostream &out, const Reservation &R);

	static int totalReservation;

	int reservationNb;
	Customer *customer;
	Room *room;
	Date *arrivalDate;
	int stayDuration;
public:
	Reservation(string="customerName",string="customerAddress",
				string="customerTelephone",int=1);//done
	~Reservation();//done
	void setArrivalDate(int ,int ,int);//done

	void setRoom(int, bool, bool);//done
	void setRoom( Room&);
	void setStayDuration(int);//done
	void setCustomerInfo(string, string, string, int, int, int);//done
	void resetTotalReservation();//done
	int getRoomNumber()const;//done
	int getStayDuration()const;
	bool getRoomAvailability()const;
	string getCustomerName()const;//done
	void printReservationInfo()const;//done
	Date& getArrivalDate();
};



#endif /* RESERVATION_H_ */
