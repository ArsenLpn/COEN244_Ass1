#pragma once
class Date
{
public:
	Date();
	Date(int newDay, int newMonth, int newYear);
	~Date();
	void ChangeDate(int day, int month, int year);
	void PrintDate();

	const int GetDay() { return this->Day; };
	const int GetMonth() { return this->Month; };
	const int GetYear() { return this->Year; };
private:
	int Day;
	int Month;
	int Year;
	
};

