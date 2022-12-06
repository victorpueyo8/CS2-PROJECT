#pragma once
#include <iostream>
#include <string>

using namespace std;

//REMOVED (Balance = 0.0) VARIABLE AND ADDED IT TO TRANSACTIONS CLASS AS WELL AS THE FUNCTIONS THAT HAD ANY RELATION WITH TRANSACTIONS LIKE DEPOSIT AND WITHDRAWAL. 

class Account
{
private:
	string name;
	string birthDate;
	string SSN;
	string Address;
	string phoneNum;

public:
	Account() //Default Constructor.
	{
		name = " ";
		birthDate = " ";
		SSN = " ";
		Address = " ";
		phoneNum = " ";
	}
	~Account() //Destructor
	{
		cout << "**********deleting all of the information***********" << endl << endl;
		cout << "The account was removed. " << endl << endl;
	}
	Account(string n, string bD, string ssn, string add, string pN) //Constructor
	{
		name = n;
		birthDate = bD;
		SSN = ssn;
		Address = add;
		phoneNum = pN;
	}
	void setName(string n)
	{
		name = n;
	}
	void setbirthDate(string bD)
	{
		birthDate = bD;
	}
	void setSSN(string ssn)
	{
		SSN = ssn;
	}
	void setAddress(string add)
	{
		Address = add;
	}
	void setphoneNum(string pN)
	{
		phoneNum = pN;
	}
	string getName()const
	{
		return name;
	}
	string getbirthDate()const
	{
		return birthDate;
	}
	string getSSN()const
	{
		return SSN;
	}
	string getAddress()const
	{
		return Address;
	}
	string getphoneNum()const
	{
		return phoneNum;
	}
	
	void newCust(string n, string bD, string ssn, string add, string pN);
	void updCustInfo(int s);
};

