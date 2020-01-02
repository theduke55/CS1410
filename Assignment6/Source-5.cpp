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

	Contact() : Person(nullptr,nullptr), a1(nullptr,nullptr,nullptr,nullptr) {}

	Contact(char *pfn, char *pln, char *pstreet, char *pcity, char *pstate, char *pzip) : Person(pfn, pln) , a1(pstreet, pcity, pstate, pzip){}

	void printLabel()
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

	BusinessContact() : Contact(nullptr, nullptr, nullptr, nullptr, nullptr, nullptr){}

	BusinessContact(char *pbn, char *pfn, char *pln, char *pstreet, char *pcity, char *pstate, char *pzip) : Contact(pfn,pln,pstreet,pcity,pstate,pzip)
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
	cout << "Contacts: " << endl;
	Contact c1("Jon", "Doe", "123 Street", "Ogden", "UT", "84404");
	c1.printLabel(); 

	Contact c2("Blaire", "Barker", "456 Easton Drive", "Tampa Bay", "FL", "98123");
	c2.printLabel();

	Contact c3("Zack", "Price", "98145 California Drive", "San Diego", "CA", "78213");
	c3.printLabel();
	
	Contact c4("Austin", "Price", "7349 W. 2917 N.", "Farr West", "UT", "84401");
	c4.printLabel();

	Contact c5("Trudy", "Bustos", "1782 W. 3400 N.", "Plain City", "UT", "84315");
	c5.printLabel();

	cout << "Business Contacts: " << endl;
	BusinessContact b1("Weber State University", "Trevor", "Barker", "1146 Harrop Street", "Ogden", "UT", "84404");
	b1.printLabel();

	BusinessContact b2("Voyage Academy", "Blaire", "Barker", "456 Easton Drive", "Tampa Bay", "FL", "98123");
	b2.printLabel();

	BusinessContact b3("Hill Air Force Base", "Zack", "Price", "98145 California Drive", "San Diego", "CA", "78213");
	b3.printLabel();

	BusinessContact b4("Ogden/Weber Applied Technology Center", "Austin", "Price", "7349 W. 2917 N.", "Farr West", "UT", "84401");
	b4.printLabel();

	BusinessContact b5("Internal Revenue Service", "Trudy", "Bustos", "1782 W. 3400 N.", "Plain City", "UT", "84315");
	b5.printLabel();

	system("pause");
	return 0;
}