#pragma once
#include <iostream>
#include <string>
#include "Account.h"

//HERE, ALL THE ACCOUNT CLASS VARIABLES, MEMBER FUNCTIONS, FUNCTIONS ARE INHERITED. THE ONES THAT YOU CAN FIND HERE ARE ONLY IN THE TRANSACTIONS CLASS
//ONLY THE ONES RELATED TO SOME TRANSACTION PROCESS

class Transactions : public Account
{
private:
	double balance;
public:
	Transactions()
	{
		balance = 0.0;
	}
	Transactions(double bal)
	{
		balance = bal;
	}
	double getBalance() const
	{
		return balance;
	}
	void deposit(double amt);
	void withdrawal(double amtOut);
};

void Transactions::deposit(double amt)
{
	try
	{
		if (amt > 0)
		{
			balance += amt;
			cout << "\nYour current amount is: $ " << getBalance() << endl << endl;
		}
		else
			throw string("The value entered cannot be a negative value.");
		cout << endl;
	}
	catch (string msg)
	{
		cout << "\nERROR: " << msg;
		cout << endl;
	}
}
void Transactions::withdrawal(double amtOut)
{
	if (balance < amtOut)
	{
		cout << "ERROR: The amount that you have in your account is not enough. " << endl << endl;
		cout << "\nYour current amount is: $ " << getBalance() << endl << endl;
	}
	else
	{
		balance -= amtOut;
		cout << "\nYour current amount is: $ " << getBalance() << endl << endl;
	}
}

