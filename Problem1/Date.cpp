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
	Day = newDay;
	Month = newMonth;
	Year = newYear;
}


Date::~Date()
{
}


void Date::ChangeDate(int newDay, int newMonth, int newYear)
{
	Day = newDay;
	Month = newMonth;
	Year = newYear;
}


void Date::PrintDate()
{
	cout << Day << "//" << Month << "//" << Year;
}
