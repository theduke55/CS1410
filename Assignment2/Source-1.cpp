#include <iostream>;
#include <Windows.h>;
#include <time.h>;

using namespace std;

bool isFinished = false;
int numWins = 0;
int numLoss = 0;
char userInput = ' ';

int main()
{
	srand(time(NULL));

	do
	{
		int die1 = 1 + (rand() % 6);
		int die2 = 1 + (rand() % 6);
		int total = die1 + die2;

		cout << "Player rolled " << die1 << " + " << die2 << " = " << total << endl;

		if (total == 7 || total == 11)
		{
			cout << "Player Wins!" << endl;
			numWins++;
		}
		else if (total == 2 || total == 3 || total == 12)
		{
			cout << "Player Loses!" << endl;
			numLoss++;
		}
		else
		{
			int point1 = total;
			int newTotal = 0;

			cout << "Point is: " << point1 << endl;

			while (newTotal != point1 && newTotal != 7)
			{
				die1 = 1 + (rand() % 6);
				die2 = 1 + (rand() % 6);
				newTotal = die1 + die2;
					
				cout << "Player rolled " << die1 << " + " << die2 << " = " << newTotal << endl;
			}
			if (newTotal == point1)
			{
				cout << "Player Wins!" << endl;
				numWins++;
			}
			else if (newTotal == 7)
			{
				cout << "Player Loses!" << endl;
				numLoss++;
			}
		}

		cout << "Would you like to play again? (y/n) ";
		cin >> userInput;
		system("cls");
		if (userInput == 'n')
		{
			isFinished = true;
		}
		else
		{
			isFinished = false;
		}
	} while (isFinished == false);


	system("cls");
	cout << numWins << " wins and " << numLoss << " losses" << endl;
	system("pause");
}