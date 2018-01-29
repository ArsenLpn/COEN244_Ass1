#pragma once
class Room
{
public:
	Room(int=1, bool=1, bool=0);				////Style: 0 = regular, 1 = suit
	bool ReturnAvailability();
	bool ReturnCategory();
	void PrintInfo();
	int GetNumber();
	~Room();
private:
	int Number;
	bool Style;
	bool Available;

};

