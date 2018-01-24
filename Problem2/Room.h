#pragma once
class Room
{
public:
	Room(int Number, bool Available, bool Style);
	~Room();
private:
	int Number;
	bool Style;
	bool Available;
public:
	bool ReturnAvailability();
	bool ReturnCategory();
	void PrintInfo();
};

