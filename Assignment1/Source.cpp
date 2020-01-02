#include <iostream>

using namespace std;

void currency();
void temperature();

int main()
{
	int userInput;


	do
	{
		cout << "Please select one of the following using 1, 2, or 3." << endl << endl;
		cout << "1. Convert Currency" << endl << "2. Convert Temperature" << endl << "3. Exit" << endl << endl;
		cin >> userInput;

		while (userInput <1 || userInput >3)
		{
			cout << "Invalid input: Please enter 1, 2, or 3." << endl;
			cin >> userInput;
		}

		switch (userInput)
		{
		case 1:
			currency();
			break;
		case 2:
			temperature();
			break;
		case 3:

			break;
		}//end of switch
	}//end of do
	while (userInput == 1 || userInput == 2);

	return 0;

	//system("pause");
}//end main

void currency()
{
	double dollar;

	//gathering user data
	system("cls");
	cout << "Enter a dollar amount to be converted: ";
	cin >> dollar;
	system("cls");

	double british = dollar * 1.33;
	double canadian = dollar * 0.77;
	double german = dollar * 0.58;
	double japananese = dollar * 0.00955;

	//display results
	cout << dollar << " dollar(s) converted to British pounds is: " << british << "." << endl;
	cout << dollar << " dollar(s) converted to Canadian dollars is: " << canadian << "." << endl;
	cout << dollar << " dollar(s) converted to German deutschemark is: " << german << "." << endl;
	cout << dollar << " dollar(s) converted to Japanese yen is: " << japananese << "." << endl << endl;

	system("pause");
	system("cls");
}//end currency

void temperature()
{
	double c;//celcius

	//gathering user data
	system("cls");
	cout << "Enter a temperature in degrees Celcius to convert to Farenheit: ";
	cin >> c;	
	system("cls");

	//calculate
	double f = (c * 9) / 5 + 32;//farenheit

	//display results
	cout << c << " degrees Celcius equals " << f << " degrees Farenheit." << endl << endl;

	system("pause");
	system("cls");
	
}//end temperature