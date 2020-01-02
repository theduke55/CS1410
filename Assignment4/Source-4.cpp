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
	Date()
	{
		DATE_UTIL::getCurrentDate(day, month, year);//calling function from other source file for today's date
	}
	Date(int d, int m, int y)
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
	
	system("pause");

	return 0;
}