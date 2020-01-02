#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Functions.h"
using namespace std;

int main()

{
	//Create an array of bank account pointers:

	BankAccount * accounts[2];

	accounts[0] = new CheckingAccount(5);

	accounts[0]->setOwner("Betty");

	accounts[0]->deposit(1000);

	accounts[0]->withdraw(800);

	accounts[0]->withdraw(300);

	accounts[1] = new SavingsAccount(0.0125);

	accounts[1]->setOwner("Joe and Betty");

	accounts[1]->deposit(5000);

	accounts[1]->withdraw(3000);

	accounts[1]->withdraw(3000); //This shouldn't be allowed

								 //// This pointer needs to be cast to SavingsAccount because despositInterest() does not exist in the BankAccount.

	static_cast<SavingsAccount*>(accounts[1])->depositInterest();

	cout << "Account 1: " << accounts[0]->getOwner() << " " << accounts[0]->getBalance() << endl;

	cout << "Account 2: " << accounts[1]->getOwner() << " " << accounts[1]->getBalance() << endl;

	delete accounts[0];

	delete accounts[1];

	system("pause");

	return 0;
}