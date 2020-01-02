#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;

class String 
{
private:
	char* pstr;
public:
	String() 
	{
		// allocate 101 characters and initialize pstr 
		// Set the first character in the array to the null terminating character
		pstr = new char[101];
		pstr[0] = '\0';
	}

	String(const char* s) 
	{
		// allocate 101 characters and initialize pstr 
		// copy the characters from s into pstr
		pstr = new char[101];
		int i = 0;
		while (*s !=  '\0')
		{
			*(pstr + i) = *s;
			s++;
			i++;
		}
		pstr[i] = '\0';
	}

	~String() 
	{
		// deallocate the memory for the character array
		delete[] pstr;
	}

	int length() const 
	{
		// loop through array and keep count
		int count = 0;
		while (*(pstr + count) != '\0')
		{
			count++;
		}
		return count;
	}

	bool operator == (const String& s) 
	{
		// loop and compare characters in each array by passing a String as the arg
		bool t;
		for (int i = 0; i < s.length(); i++)
		{
			if (*(s.pstr +i) == *(pstr +i))
			{
				t = true;
			}
			else
			{
				return false;
			}
		}
		return t;
	}

	bool operator == (const char* ps) 
	{
		// loop and compare characters in each array by passing a char* as the arg
		int count = 0;
		while (*(ps + count) != '\0')
		{
			count++;
		}

		bool t;
		for (int i = 0; i < count; i++)
		{
			if (*(pstr + i) == *(ps + i))
			{
				t = true;
			}
			else
			{
				return false;
			}
		}
		return t;
	}

	void operator += (const char* ps) // concatenate 
	{
		 // add the characters to the end of the existing characters by passing a char* as the arg
		int count = 0;
		while (*(pstr + count) != '\0')
		{
			count++;
		}

		while (*ps != '\0')
		{
			*(pstr + count) = *ps;
			ps++;
			count++;
		}
		pstr[count] = '\0';
	}

	void operator += (const String& s) // concatenate 
	{
		// add the characters to the end of the existing characters by passing a String as the arg
		int count = 0;
		while (*(pstr + count) != '\0')
		{
			count++;
		}

		char* p = s.pstr;
		while (*p != '\0')
		{
			*(pstr + count) = *p;
			count++;
			p++;
		}
		pstr[count] = '\0';
	}

	operator char* () // conversion operator 
	{ // return a pointer to the characters
		return pstr;
	}
};

int main() 
{
	String s1;
	s1 += "Hello";
	cout << s1 << endl;
	s1 += " there";
	cout << s1 << endl;
	cout << "Length = " << s1.length() << endl;
	cout << endl;
	String s2 = "Hello";
	cout << s2 << endl;
	s2 += String(" again");
	cout << s2 << endl;
	cout << "Length = " << s2.length() << endl;
	cout << (s1 == s2) << endl;
	cout << (s1 == "Hello there") << endl;
	system("pause");
	return 0;
}