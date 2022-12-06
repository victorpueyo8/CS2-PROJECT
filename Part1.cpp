#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Transactions.h"

using namespace std;


//CALLING A OBJECT FROM A CLASS WAS CHANGED (Account customer) to (Transactions customer)
//WITH THE CREATION OF TRANSACTIONS CLASS, ALL THE VARIABLES, AND MEMBER FUNCTIONS ARE INHERITED IN TRANSACTIONS CLASS
//AT THE END OF THE PROGRAM, AFTER THE DESTRUCTOR YOU CAN FIND THE POLYMORPHISM PART

void menu();
void delCust(Account &);
void ViewCustInfo(const Transactions &); //THIS WAS ADDED FOR POLYMORPHISM

int main()
{

	int choice;
	string name, birthDate, SSN, Address, phoneNum;
	int val; // Value of 1 or 2 for the Update Cust
	string newAddress; // Value for the updated Address
	string newPhoneNum; // Value for the updated Phone num
	double amount, amountOut; //Holds amount to deposit and withdrawal
	/*const int SIZE = 6;
	vector<Account> customers(SIZE);*/

	Transactions customer; 

	do
	{
		menu();

		cout << "Please enter your choice: ";
		cin >> choice;

		cout << endl;

		while (choice < 1 || choice > 8)
		{
			cout << "ERROR: Unavailable Option" << endl << endl;;
			cout << "Please enter an option from 1-8. Thank you." << endl << endl;
			cout << "Please enter your choice: ";
			cin >> choice;
		}

		switch (choice)
		{
		case 1:
			cout << "\nCreating a new checking account... In progress..." << endl << endl;
			cout << "Please, carefully follow the next instruccions..." << endl;
			cin.ignore();
			cout << "\nWhat is you full name: ";
			getline(cin, name);
			cout << "\nWhat is your date of birth (following format: MM/DD/YYYY): ";
			getline(cin, birthDate);
			cout << "\nWhat is your citizenship number: ";
			getline(cin, SSN);
			cout << "\nWhat is your address: ";
			getline(cin, Address);
			cout << "\nWhat is your phone number (+1): ";
			getline(cin, phoneNum);
			customer.newCust(name, birthDate, SSN, Address, phoneNum);
			break;
		case 2:
			cout << "\nRemoving an existing account... In progress..." << endl << endl;
			delCust(customer);
			break;
		case 3:
			cout << "Updating Information of an existing customer... In progress..." << endl;

			cout << "\n\nWhat would you like to modify: \nOption 1: Address. \nOption 2 Phone number." << endl;
			cout << "\nPlease enter 1 or 2: ";
			cin >> val;
			try
			{
				if (val == 1)
				{
					cin.ignore();
					cout << "Please enter the new address: ";
					getline(cin, newAddress);
					customer.setAddress(newAddress);
					customer.updCustInfo(1);
				}
				else if (val == 2)
				{
					cin.ignore();
					cout << "Please enter the new phone num: ";
					getline(cin, newPhoneNum);
					customer.setphoneNum(newPhoneNum);
					customer.updCustInfo(2);
				}
				else
					throw string("You entered a different value than 1 or 2.");
				    cout << endl;
			}
			catch (string msg)
			{
				cout << "\nERROR: " << msg;
				cout << endl;
			}
			break;
		case 4:
			cout << "Deposit transaction..." << endl << endl;
			cout << "How much do you want to deposit in your account: $ ";
			cin >> amount;
			customer.deposit(amount);
			break;
		case 5:
			cout << "Withdrawal transaction..." << endl << endl;
			cout << "How much do you want to withdrawal from your account: $ ";
			cin >> amountOut;
			customer.withdrawal(amountOut);
			break;
		case 6:
			ViewCustInfo(customer); //THIS PART WAS CHANGED
			break;
		case 7:
			break;
		case 8:
			break;
		}
	
	}while (choice != 8);
	
	cout << "Thank you for using Credit Union. See you soon. " << endl << endl;

	system("pause");
	return 0;
}

void menu()
{
	cout << "              Lawrence Tech Employee Credit Union" << endl << endl;
	cout << "             ***** Welcome to the Main Menu *****\n\n" << endl;
	cout << "            1. Create a new checking account." << endl;
	cout << "            2. Remove an existing account." << endl;
	cout << "            3. Update name, address information for an existing customer." << endl;
	cout << "            4. Deposit transaction." << endl;
	cout << "            5. Withdrawal transaction." << endl;
	cout << "            6. List information of an existing customer." << endl;
	cout << "            7. List customer names and ids." << endl;
	cout << "            8. Exist the program." << endl << endl;
}

void delCust(Account &obj)
{
	char choice;

	cout << "Are you sure you want to delete your account | Press 'Y' (Yes) or 'N' (No): ";
	cin >> choice;

	if (choice == 'y' || choice == 'Y')
	{
		cout << endl;
		obj.~Account();
		Account customer;
	}
	else
	{
		exit(EXIT_FAILURE); // Go back and check this else once everything is done.
	}
}

//POLYMORPHISM, IT IS LINKED TO LINE 118. 
void ViewCustInfo(const Transactions &person)
{
	cout << "\n\tACCOUNT INFORMATION" << endl;
	cout << "      ________________________________" << endl << endl;
	cout << "\tName: " << person.getName();
	cout << "\n\n\tDate of birth: " << person.getbirthDate();
	cout << "\n\n\tCitizenship number (SSN): " << person.getSSN();
	cout << "\n\n\tAddress: " << person.getAddress();
	cout << "\n\n\tPhone Number: " << person.getphoneNum();
	cout << "\n\n\tAccount Type: Checking ";
	cout << "\n\n\tThe current amount: $ " << person.getBalance() << endl << endl;
}