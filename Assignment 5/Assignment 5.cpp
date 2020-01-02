#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"DateUtil.h"
using namespace std;

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

	//setting and getting each variable
	void setDay(int d)
	{
		day = d;
	}
	int getDay()
	{
		return day;
	}
	void setMonth(int m)
	{
		month = m;
	}
	int getMonth()
	{
		return month;
	}
	void setYear(int y)
	{
		year = y;
	}
	int getYear()
	{
		return year;
	}

	void addDays(int n)
	{
		long i = DATE_UTIL::getNumberFromDate(day, month, year);//calling function from other source
		i += n;//add the number of days provided in the argument "n"
		DATE_UTIL::getDateFromNumber(i, day, month, year);//calling function with the new number attached
	}
	void subDays(int n)
	{
		long i = DATE_UTIL::getNumberFromDate(day, month, year);
		i -= n;
		DATE_UTIL::getDateFromNumber(i, day, month, year);
	}
	void displayDate()
	{
		cout << month << "/" << day << "/" << year << endl;
	}
	void populateDate()
	{
		cout << "Please enter a date in the following format (ex. day month year): ";
		cin >> day >> month >> year;
	}

	Date operator ++()//prefix
	{
		Date temp = Date(day, month, year);
		temp.addDays(1);
		day = temp.day;
		month = temp.month;
		year = temp.year;
		return temp;
	}

	Date operator ++(int)//postfix
	{
		Date original = Date(day, month, year);
		Date temp = Date(day, month, year);
		temp.addDays(1);
		day = temp.day;
		month = temp.month;
		year = temp.year;
		return original;
	}

	Date operator --()//prefix
	{
		Date temp = Date(day, month, year);
		temp.subDays(1);
		day = temp.day;
		month = temp.month;
		year = temp.year;
		return temp;
	}

	Date operator --(int)//postfix
	{
		Date original = Date(day, month, year);
		Date temp = Date(day, month, year);
		temp.subDays(1);
		day = temp.day;
		month = temp.month;
		year = temp.year;
		return original;
	}

	Date operator +=(int d)
	{
		Date temp = Date(day, month, year);
		temp.addDays(d);
		day = temp.day;
		month = temp.month;
		year = temp.year;
		return temp;
	}

	Date operator -=(int d)
	{
		Date temp = Date(day, month, year);
		temp.subDays(d);
		day = temp.day;
		month = temp.month;
		year = temp.year;
		return temp;
	}

	bool operator ==(Date d)
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

	bool operator !=(Date d)
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

	bool operator > (Date d)
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

	bool operator < (Date d)
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
};

int main()
{
	//setting variables
	Date d1;
	Date d2(13, 01, 1988);

	//display todays date
	cout << "d1: ";
	d1.displayDate();

	//display my birthday
	cout << "d2: ";
	d2.displayDate();

	//display 30 days after my birthday
	d2.addDays(30);
	cout << "d2 + 30: ";
	d2.displayDate();

	//resetting my birthday variable
	d2.setDay(13);
	d2.setMonth(01);
	d2.setYear(1988);

	//display 30 days prior to my birthday
	d2.subDays(30);
	cout << "d2 - 30: ";
	d2.displayDate();


	//collect date from user and re-arrange it
	Date d3;
	d3.populateDate();
	cout << "d3: ";
	d3.displayDate();
	cout << endl;

	++d1;
	d1.displayDate();
	d1++;
	d1.displayDate();

	--d1;
	d1.displayDate();
	d1--;
	d1.displayDate();

	d1+=(7);
	d1.displayDate();
	d1-=(7);
	d1.displayDate();

	//compare if dates are the same
	
	if (d1 == d3)
	{
		cout << endl << "d1: ";
		d1.displayDate();
		cout << "d3: ";
		d3.displayDate();
		cout << "d1 equals d3" << endl;
	}
	else
	{
		cout << endl << "d1: ";
		d1.displayDate();
		cout << "d3: ";
		d3.displayDate();
		cout << "d1 does not equal d3" << endl;
	}

	//compare if one date is larger
	
	if (d1 > d3)
	{
		cout << endl << "d1: ";
		d1.displayDate();
		cout << "d3: ";
		d3.displayDate();
		cout << "d1 is greater d3" << endl;
	}
	if (d1 < d3)
	{
		cout << endl << "d1: ";
		d1.displayDate();
		cout << "d3: ";
		d3.displayDate();
		cout << "d1 is less than d3" << endl;
	}

	system("pause");

	return 0;
}