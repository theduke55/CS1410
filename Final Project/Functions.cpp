#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Functions.h"
#include <iostream>
using namespace std;

SavingsAccount::SavingsAccount(double s)
{
	monthlyInterestRate = s;
}

void SavingsAccount::depositInterest()
{
	balance += balance * monthlyInterestRate;
}

CheckingAccount::CheckingAccount(double of)
{
	feeForOverdraftWithdraw = of;
}

void CheckingAccount::withdraw(double w)
{
	if ((balance - w) < 0)
	{
		balance = balance - feeForOverdraftWithdraw - w;
	}
	else
	{
		balance = balance - w;
	}
}

char* BankAccount::getOwner()
{
	return owner;
}

void BankAccount::setOwner(char* o) // or void setOwner(char[] owner)
{
	strcpy(owner, o);
}

void BankAccount::deposit(const double amount)
{
	balance += amount;
}

void BankAccount::withdraw(const double amount)
{
	if ((balance - amount) > 0)
	{
		balance -= amount;
	}
	else
	{
		cout << "Cannot withdraw more than you have" << endl;
	}
}

double BankAccount::getBalance()
{
	return balance;
}