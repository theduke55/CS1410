#define _CRT_SECURE_NO_WARNINGS
#include "Date.h"
#include "DateUtil.h"
#include<iostream>
using namespace std;

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

	d1 += (7);
	d1.displayDate();
	d1 -= (7);
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