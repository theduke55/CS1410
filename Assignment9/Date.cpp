#pragma once
#include "Date.h"
#include "DateUtil.h"
#include <iostream>
using namespace std;



//setting and getting each variable
void Date::setDay(int d)
{
	day = d;
}
int Date::getDay()
{
	return day;
}
void Date::setMonth(int m)
{
	month = m;
}
int Date::getMonth()
{
	return month;
}
void Date::setYear(int y)
{
	year = y;
}
int Date::getYear()
{
	return year;
}

void Date::addDays(int n)
{
	long i = DATE_UTIL::getNumberFromDate(day, month, year);//calling function from other source
	i += n;//add the number of days provided in the argument "n"
	DATE_UTIL::getDateFromNumber(i, day, month, year);//calling function with the new number attached
}
void Date::subDays(int n)
{
	long i = DATE_UTIL::getNumberFromDate(day, month, year);
	i -= n;
	DATE_UTIL::getDateFromNumber(i, day, month, year);
}
void Date::displayDate()
{
	cout << month << "/" << day << "/" << year << endl;
}
void Date::populateDate()
{
	cout << "Please enter a date in the following format (ex. day month year): ";
	cin >> day >> month >> year;
}

Date Date::operator ++()//prefix
{
	Date temp = Date(day, month, year);
	temp.addDays(1);
	day = temp.day;
	month = temp.month;
	year = temp.year;
	return temp;
}

Date Date::operator ++(int)//postfix
{
	Date original = Date(day, month, year);
	Date temp = Date(day, month, year);
	temp.addDays(1);
	day = temp.day;
	month = temp.month;
	year = temp.year;
	return original;
}

Date Date::operator --()//prefix
{
	Date temp = Date(day, month, year);
	temp.subDays(1);
	day = temp.day;
	month = temp.month;
	year = temp.year;
	return temp;
}

Date Date::operator --(int)//postfix
{
	Date original = Date(day, month, year);
	Date temp = Date(day, month, year);
	temp.subDays(1);
	day = temp.day;
	month = temp.month;
	year = temp.year;
	return original;
}

Date Date::operator +=(int d)
{
	Date temp = Date(day, month, year);
	temp.addDays(d);
	day = temp.day;
	month = temp.month;
	year = temp.year;
	return temp;
}

Date Date::operator -=(int d)
{
	Date temp = Date(day, month, year);
	temp.subDays(d);
	day = temp.day;
	month = temp.month;
	year = temp.year;
	return temp;
}

bool Date::operator ==(Date d)
{
	long temp = getNumberFromDate(day, month, year);//left of operator
	long var = getNumberFromDate(d.day, d.month, d.year);

	if (temp == var)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Date::operator !=(Date d)
{
	long temp = getNumberFromDate(day, month, year);//left of operator
	long var = getNumberFromDate(d.day, d.month, d.year);

	if (temp != var)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Date::operator > (Date d)
{
	long temp = getNumberFromDate(day, month, year);//left of operator
	long var = getNumberFromDate(d.day, d.month, d.year);

	if (temp > var)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Date::operator < (Date d)
{
	long temp = getNumberFromDate(day, month, year);//left of operator
	long var = getNumberFromDate(d.day, d.month, d.year);

	if (temp < var)
	{
		return true;
	}
	else
	{
		return false;
	}
}
