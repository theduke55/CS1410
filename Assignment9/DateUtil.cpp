#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include "DateUtil.h"

long getNumberFromDate(int d, int m, int y)
{
	// see http://aa.usno.navy.mil/faq/docs/JD_Formula.php
	return d - 32075 + 1461 * (y + 4800 + (m - 14) / 12) / 4 + 367 * (m - 2 - (m - 14) / 12 * 12) / 12 - 3 * ((y + 4900 + (m - 14) / 12) / 100) / 4;
}

void getCurrentDate(int& d, int& m, int& y)
{
	time_t t = time(0);   // get time now
	struct tm * now = localtime(&t);
	d = now->tm_mday;
	m = now->tm_mon + 1;
	y = now->tm_year + 1900;
}

void getDateFromNumber(const long& n, int& d, int& m, int& y)
{
	// see http://aa.usno.navy.mil/faq/docs/JD_Formula.php
	long i = n + 68569;
	long j = 4 * i / 146097;
	i = i - (146097 * j + 3) / 4;
	y = 4000 * (i + 1) / 1461001;
	i = i - 1461 * y / 4 + 31;
	m = 80 * i / 2447;
	d = i - 2447 * m / 80;
	i = m / 11;
	m = m + 2 - 12 * i;
	y = 100 * (j - 49) + y + i;
}