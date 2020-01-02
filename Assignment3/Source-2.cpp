#include <iostream>
using namespace std;

struct Distance//creating structure to hold feet and inches
{
	int feet;
	double inches;
};//end of Distance

Distance populate(void)//get user input and populate the two distance structures
{
	Distance d;//creating a distance variable

	cout << "Enter the distance in feet: " << endl;
	cin >> d.feet;

	cout << "Enter the remaining inches: " << endl;
	cin >> d.inches;

	return d;
}//end of populate

Distance add(const Distance& d1, const Distance& d2)//Collect both constant distances and add them. Then return them in another structure.
{
	Distance d3;

	d3.inches = d1.inches + d2.inches;
	d3.feet = 0;

	while (d3.inches >= 12.0)//if inches total more than 12 inches
	{
		d3.inches -= 12.0;//subtract 12 inches
		d3.feet++;//add 1 to the feet
	}
	d3.feet += d1.feet + d2.feet;
	
	return d3;
}//end of add

void display(const Distance& d3)//displays d3 values in the requested format
{
	cout << endl;
	cout << "The total is: " << d3.feet << '\'' << d3.inches << '\"' << endl;
}//end of display

int main(void)
{
	char cont = ' ';

	do
	{
		Distance d1 = populate();//collects the first distance
		Distance d2 = populate();//collects the second distance

		Distance d3 = add(d1, d2);//adds both distances and ensures the inches doesn't exceed 12

		display(d3);//prints out the total distance

		cout << "Again? (y/n)";
		cin >> cont;
	
		while (cont != 'y' && cont != 'n')//error handling
		{
			cout << "Invalid entry: Please enter either 'y' or 'n'." << endl;
			cin >> cont;
		}
		system("cls");
	} while (cont == 'y');	
}//end of main