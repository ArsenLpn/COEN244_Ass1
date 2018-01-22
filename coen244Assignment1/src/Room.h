/*
 * Room.h
 *
 *  Created on: Jan 16, 2018
 *      Author: vpuyf
 */

#ifndef ROOM_H_
#define ROOM_H_
#include <string>
#include <iostream>
using namespace std;
#define REGULAR false
#define SUITE true

class Room{
	friend ostream& operator<<(ostream& out, const Room &t);
	int roomNb;
	bool isSuite;
	bool available;
public:
	Room(int = -1, bool = REGULAR, bool = true);
	Room(const Room&);
	~Room();
	Room& operator=(Room &r);


	void setRoomNb(int);
	void setAvailability(bool);
	void changeRoomType(bool);
	int getRoomNumber() const;

	bool isAvailable() const;
	string roomType() const;
	void printRoomInfo()const ;

};
#endif /* ROOM_H_ */
