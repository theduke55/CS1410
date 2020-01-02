#if !defined(DATE_UTIL)
#define DATE_UTIL

long getNumberFromDate(int d, int m, int y);
void getCurrentDate(int& d, int& m, int& y);
void getDateFromNumber(const long &n, int& d, int& m, int& y);

#endif
