#include "Date.h"
#include <iostream>

using namespace std;
Date::Date()
{
	Day = 0;
	Month = 0;
	Year = 0;
}
Date::Date(int newDay, int newMonth, int newYear)
{
	ChangeDate(newDay, newMonth, newYear);
}


Date::~Date()
{
}


void Date::ChangeDate(int Day, int Month, int Year)
{
	this->Day = Day;
	this->Month = Month;
	this->Year = Year;
}


void Date::PrintDate()
{
	cout << Day << "/" << Month << "/" << Year;
}
