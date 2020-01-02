#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Person //Person class
{
protected: //member variables
	char firstName[51];
	char lastName[51];

public: //member functions
	Person(char *fn, char *ln) //constructor that initializes the first and last name
	{
		strcpy(firstName, fn);
		strcpy(lastName, ln);
	}
	void Print() //prints the first and last name
	{
		cout << firstName << " " << lastName << endl;
	}
};

class Address //Address class
{
private: //member variables
	char street[51];
	char city[26];
	char state[3];
	char zip[6];

public: //member functions
	Address(char *pstreet, char *pcity, char *pstate, char *pzip) //constructor that initializes each variable
	{
		strcpy(street, pstreet);
		strcpy(city, pcity);
		strcpy(state, pstate);
		strcpy(zip, pzip);
	}

	void print() //prints the member variables
	{
		cout << street << endl;
		cout << city << ", " << state << " " << zip << endl;
	}
};

class Contact : public Person //Contact class that inherits and aggregates from the Person class and Address class
{
private:
	Address a1;

public:

	Contact();

	Contact(char *pfn, char *pln, char *pstreet, char *pcity, char *pstate, char *pzip) : Person(pfn, pln), a1(pstreet, pcity, pstate, pzip) {}

	virtual void printLabel()
	{
		Person::Print();
		a1.print();
		cout << endl;
	}
};

class BusinessContact : public Contact //BusinessContact class that inherits and aggregates from the Person class and Address class
{
private:
	char businessName[51];

public:

	BusinessContact();

	BusinessContact(char *pbn, char *pfn, char *pln, char *pstreet, char *pcity, char *pstate, char *pzip) : Contact(pfn, pln, pstreet, pcity, pstate, pzip)
	{
		strcpy(businessName, pbn);
	}

	void printLabel()
	{
		cout << businessName << endl;
		cout << "Atten: ";
		Contact::printLabel();
		cout << endl;
	}
};

int main()
{
	Contact** c = new Contact*[6];
	c[0] = new Contact("Jon", "Doe", "123 Street", "Ogden", "UT", "84404");
	c[1] = new Contact("Blaire", "Barker", "456 Easton Drive", "Tampa Bay", "FL", "98123");
	c[2] = new Contact("Zack", "Price", "98145 California Drive", "San Diego", "CA", "78213");
	c[3] = new BusinessContact("Weber State University", "Trevor", "Barker", "1146 Harrop Street", "Ogden", "UT", "84404");
	c[4] = new BusinessContact("Voyage Academy", "Blaire", "Barker", "456 Easton Drive", "Tampa Bay", "FL", "98123");
	c[5] = new BusinessContact("Hill Air Force Base", "Zack", "Price", "98145 California Drive", "San Diego", "CA", "78213");

	for (int i = 0; i < 6; i++)
	{
		c[i]->printLabel();
	}
	delete c;

	system("pause");
	return 0;
}