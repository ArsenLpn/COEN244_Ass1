//============================================================================
// Name        : Assignement5.cpp
// Author      : Valentin Puyfourcat 40001780
// Version     :
// Copyright   : Coen 243 Fall 2017 Concordia
// Description : Basic Date class, date differential
//============================================================================
/*
 * Old Date class from Coen 243
 */
#include <iostream>
#include <string>
#include <array>

#include "Date.h"
using namespace std;



array<int,12> Date::daysInMonth ={{31,28,31,
								   30,31,30,
								   31,31,30,
								   31,30,31}};
ostream& operator <<(ostream &out, const Date &t){

	out << t.day<<'/'<<t.month<<'/'<<t.year;
	return out;
}
Date::Date (int d, int m, int y)
{
	 day = d;
	 month = m;
	 year = y ;
}
Date::~Date(){

}
Date::Date(Date &other){
	day=other.day;
	month=other.month;
	year=other.year;
}
void Date::printDate() const
{
	cout << day << "/" << month << "/" << year << "\n";
}
void Date::setDate(int d, int m, int y){
	year = y >= 0 ? y : 0;
	month = m < 1 || m > 12 ? 0 : m;
	day = d < 1 || d > daysInMonth[m-1] ? 0 : d;
	//checking if we d is greater than number of days
	//in month m: 0 if true
}
string Date::getMonth(){

	array<string,12> months{{"January","February","March",
		"April","May","June","July","August","September",
		"October","November","December"}};

	return months[month-1];
}
int Date::dateDifferential(Date &otherDate){


	if(this->year > otherDate.year)
		//swapping the dates so that the date that the function dateDifferential
		//is called on chronologically happens before the passed Date
		return otherDate.dateDifferential(*new Date(day,month,year));
	else
	{
		//altough i dont allow to input 29/02/XXXX, i ll take into account leap year
		// in overall answer
		//checking if born on leap year and after 29 feb=>add a day
		int firstTotalDays = year % 4 == 0 && month > 2 ? day + 1: day,
			otherTotalDays = otherDate.year % 4 == 0 && otherDate.month > 2 ?
							otherDate.day + 1: otherDate.day;

		//adding all days from beginning of year until the end
		//of month - 1
		for(int i = 1; i <= month - 1; ++i)
			firstTotalDays += Date::daysInMonth[i-1];
		for(int i = 1; i <= otherDate.month - 1; ++i)
			otherTotalDays +=Date::daysInMonth[i-1];

		int total = otherTotalDays - firstTotalDays;
		//adding appropriate number of days when year is leap or not leap

		for(int i = year; i<otherDate.year; ++i)//little algo to determine whether a year is leap or not
			if( i % 4 == 0)
				if(i % 100 == 0)
					if(i % 400 == 0)
						total += 366;
					else total += 365;
				else total += 366;
			else total += 365;
		return total;
	}
}
int Date::compareDates(const Date &d)const{
	//-1 means the caller happens before
	//1 means the caller happens after
	//0 means same day
	if (year<d.year)
		return -1;
	else if (year>d.year)
		return 1;
	else if (month<d.month)
		return -1;
	else if (month>d.month)
		return 1;
	else if(day<d.day)
		return -1;
	else if(day>d.day)
	 	 return 1;

   return 0;
}
void Date::addDays(int days){
	while(days>0){
		while(day<=daysInMonth[month-1] && days>0)
		{//adding days to day for the current month
			++day;
			--days;
		}
		if(days>0){
			day = 1;
			++month;
		}
	}
}
























