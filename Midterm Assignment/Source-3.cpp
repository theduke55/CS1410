#include <iostream>
#include <iomanip>
using namespace std;
#define Midterm_CRT_SECURE_NO_WARNINGS

struct DVD//data structure to hold all DVD characteristics
{
	int Id;
	char Title[51];
	char Rating[5];
	double Price;
	char Borrower[51];
};
DVD list[5] = { { 1, "The Avengers", "PG13", 19.99, },{ 2, "Arrival", "PG13", 19.99, },{ 3, "Captain America: Civil War", "PG13", 19.99, },{ 4, "John Wick: Chapter 2", "R", 19.99, },{ 5, "Jurrasic World", "PG13", 19.99, } };

void DisplayAllDVDS(void)//loop to show each ID, Title, and Rating in a clean column setting
{
	for (int i = 0; i < 5; i++)
	{
		cout << setw(1) << left << list[i].Id << ". " << setw(30) << left  << list[i].Title  << setw(4) << left  << list[i].Rating << endl;
	}
}

void ShowMovies()//extra function to display the ID and Title to be selected
{
	for (int j = 0; j < 5; j++)
	{
		cout << list[j].Id << ". " << setw(30) << left << list[j].Title << endl;
	}
}

void DisplayDvdDetail()//displays movies, gathers users input, clears the screen, and then displays the full details of the users selection
{
	int i;
	ShowMovies();

	cout << endl << "Enter the ID# for the movie you would like to see: ";
	cin >> i;
	system("cls");

	cout << setw(12) << "Title: " << setw(30) << list[i-1].Title << endl;
	cout << setw(12) << "Rating: " << setw(30) << list[i-1].Rating << endl;
	cout << setw(12) << "Price: " << setw(30) << list[i-1].Price << endl;
	cout << setw(12) << "Borrower: " << setw(30) << list[i-1].Borrower << endl << endl;
}

void CheckOutDvd()//displays movies, gathers user input, conducts error handling if needed, requests the users name, and finally adds their name to the borrower variable of the array
{
	int userInput;
	char name[51];
	ShowMovies();

	cout << endl << "Enter the ID# for the DVD you would like to check out: ";
	cin >> userInput;

	while (list[userInput-1].Borrower[0] != '\0')
	{
		cout << endl << list[userInput - 1].Title << " has already been checked out." << endl;
		cout << "Please select a different one: ";
		cin >> userInput;
	}

	if (list[userInput-1].Borrower[0] == '\0')
	{
		cout << endl << list[userInput - 1].Title << " is available for checkout." << endl;
		cout << "Please enter your full name: ";
		cin.ignore();
		cin.getline(name,51);
		strcpy_s(list[userInput-1].Borrower, name);
	}	
}

void CheckInDvd()//displays movies, gathers users input, conducts error handling if needed, removes the users name from "borrower", and thanks them for returning the selected video
{
	int vidReturn;
	ShowMovies();

	cout << endl << "Enter the ID# for the video you are returning: ";
	cin >> vidReturn;

	while (list[vidReturn-1].Borrower[0] == '\0')
	{
		cout << endl << list[vidReturn - 1].Title << " is not checked out." << endl;
		cout << "Please select the correct video to return: ";
		cin >> vidReturn;
	}

	if (list[vidReturn-1].Borrower[0] != '\0')
	{
		list[vidReturn-1].Borrower[0] = '\0';
		cout << endl << "Thank you for returning " << list[vidReturn-1].Title << "." << endl;
	}
}

int main()
{
	int userInput = 0;

	while (userInput != 5)
	{
		//displays menu
		cout << "1. Display All DVD's" << endl;
		cout << "2. Display DVD Details" << endl;
		cout << "3. Check out a DVD" << endl;
		cout << "4. Check in a DVD" << endl;
		cout << "5. Exit" << endl << endl;

		cout << "Select which option you would like to do: ";
		cin >> userInput;
		system("cls");

		switch (userInput)//calls each function listed above based upon the users input for each int character
		{
		case 1:
			DisplayAllDVDS();
			cout << endl;
			system("pause");
			system("cls");
			break;
			
		case 2:
			DisplayDvdDetail();
			cout << endl;
			system("pause");
			system("cls");
			break;

		case 3:
			CheckOutDvd();
			cout << endl;
			system("cls");
			break;

		case 4:
			CheckInDvd();
			cout << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	return 0;
}