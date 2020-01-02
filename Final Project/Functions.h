#pragma once

class BankAccount
{
protected:

	char owner[50];
	double balance;

public:

	BankAccount() : balance(0) { }

	char* getOwner();

	void setOwner(char* o);

	void deposit(const double amount);

	virtual void withdraw(const double amount);

	double getBalance();

};

class CheckingAccount : public BankAccount
{
private:
	double feeForOverdraftWithdraw;
public:
	CheckingAccount(double of);

	void withdraw(double w);
};

class SavingsAccount : public BankAccount
{
private:
	double monthlyInterestRate;
public:
	SavingsAccount(double s);

	void depositInterest();
};