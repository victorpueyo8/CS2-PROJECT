#include "Account.h"
#include <iostream>

//REMOVED SOME FUNCTIONS FROM HERE AND ADDED THEM TO THE TRANSACTIONS CLASS

using namespace std;

void Account::newCust(string n, string bD, string ssn, string add, string pN)
{
	name = n;
	birthDate = bD;
	SSN = ssn;
	Address = add;
	phoneNum = pN;

	cout << "\n\n\tNew checking account opened " << endl;
	cout << "      ________________________________" << endl << endl;
	cout << "\tName: " << getName();
	cout << "\n\n\tDate of birth: " << getbirthDate();
	cout << "\n\n\tCitizenship number (SSN): " << getSSN();
	cout << "\n\n\tAddress: " << getAddress();
	cout << "\n\n\tPhone Number: " << getphoneNum() << endl << endl << endl;
}

void Account::updCustInfo(int s)
{
	if (s == 1)
	{
		cout << "\nThe new address is updated. " << endl << endl;
		cout << "The new address is: " << getAddress() << endl;
	}
	else if (s == 2)
	{
		cout << "\nThe new phone number is updated. " << endl << endl;
		cout << "The new phone number is: " << getphoneNum() << endl;
	}
}