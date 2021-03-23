// Date.h

#pragma once
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Date
{
private:
	unsigned int year, month, day;
public:
	unsigned int GetYear() const { return year; };
	unsigned int GetMonth() const { return month; };
	unsigned int GetDay() const { return day; };

	void SetYear(unsigned int);
	void SetMonth(unsigned int);
	void SetDay(unsigned int);

	Date();
	Date(unsigned int);
	Date(unsigned int, unsigned int);
	Date(unsigned int, unsigned int, unsigned int);

	Date& operator = (const Date&);
	operator string() const;

	Date& operator ++();
	Date& operator --();
	Date operator ++(int);
	Date operator --(int);

	friend ostream& operator << (ostream&, const Date&);
	friend istream& operator >> (istream&, Date&);

	// Визначення чи рік високосний
	bool IsVysokostnyi();

	// Порівняння 
	bool IsEarlierThan(Date);
	bool IsSameAs(Date);
	bool IsLaterThan(Date);

	// Допоміжна функція
	short DaysInMonth(unsigned int);

	// Віднімання днів
	void SubstractDays();

	// Дата через n днів
	void DateAfterDays();

	// Кількість днів між датами
	friend unsigned int DaysBetweenAmount(Date, Date);

};