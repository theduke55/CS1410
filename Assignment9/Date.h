#pragma once
#include"DateUtil.h"

class Date
{
private://private variables
	int month;
	int day;
	int year;
public://public functions
	Date()//constructor with no args
	{
		DATE_UTIL::getCurrentDate(day, month, year);//calling function from other source file for today's date
	}
	Date(int d, int m, int y)//constructor with three args
	{
		month = m;
		day = d;
		year = y;
	}
	void setDay(int d);
	int getDay();
	void setMonth(int m);
	int getMonth();
	void setYear(int y);
	int getYear();
	void addDays(int n);
	void subDays(int n);
	void displayDate();
	void populateDate();

	Date operator ++();//prefix

	Date operator ++(int);//postfix

	Date operator --();//prefix

	Date operator --(int);//postfix

	Date operator +=(int d);

	Date operator -=(int d);

	bool operator ==(Date d);

	bool operator !=(Date d);

	bool operator > (Date d);

	bool operator < (Date d);

};
