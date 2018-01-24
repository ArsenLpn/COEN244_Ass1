/*
 * Old Date class from Coen 243
 */
#ifndef DATE_H_
#define DATE_H_
#include <string>
#include <iostream>
#include <array>

class Date {
	friend std::ostream &operator <<(std::ostream& out, const Date &t);
	public:
		Date(int=1, int=1, int=0001); // sets day, month, year
		Date( Date&);
		~Date();
		void printDate() const; // print date to the screen
		void setDate(int,int,int);
		std::string getMonth();
		int dateDifferential(Date&);
		int compareDates(const Date&)const;
		void addDays(int);
	private:

		int day;
		int month;
		int year;
		static std::array<int,12> daysInMonth;//initialized in date.cpp

};
#endif


