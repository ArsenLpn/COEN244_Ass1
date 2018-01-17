#pragma once
class Date
{
public:
	Date();
	Date(int newDay, int newMonth, int newYear);
	~Date();
private:
	int Day;
	int Month;
	int Year;
public:
	void ChangeDate(int day, int month, int year);
	void PrintDate();
};

