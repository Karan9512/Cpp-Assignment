#include<iostream>
#include "Account.h"

int Account::count = 0;  // Initialize the static member

// Default constructor
Account::Account() : AccountNumber(10001), Name("Karan"), Balance(10000), Amount(0) {
    count++;
    AccountNumber += count;
}

// Parameterized constructor
Account::Account(string name, double balance) : Name(name), Balance(balance), Amount(0) {
    count++;
    AccountNumber = 10001 + count;  // Unique Account Number for each account
}

void Account::Accept() {
    cout << "\nEnter Customer Details:";
    cout << "\nEnter Customer Name: ";
    cin >> this->Name;
    cout << "\nEnter Amount: ";
    cin >> this->Balance;
    cout <<"\nYour Account Number Is : "<< this->AccountNumber;
}

void Account::Display() {
    cout << "\nAccount Details: ";
    cout << "\nAccount Number: " << this->AccountNumber;
    cout << "\nCustomer Name: " << this->Name;
    cout << "\nBank Balance: " << this->Balance;
}

void Account::Withdraw() {
    cout << "\nEnter Withdraw Amount: ";
    cin >> this->Amount;

    if (this->Balance - this->Amount < 500) {
        cout << "\nInsufficient Balance!";
    } else {
        this->Balance -= this->Amount;
        cout << "\nYour New Balance is: " << this->Balance;
    }
}

void Account::Deposit() {
    cout << "\nEnter Deposit Amount: ";
    cin >> this->Amount;
    if(this->Amount < 0)
    {
    	cout << "\n Enter A valid Number !!!";
    }
    else
    {
    	this->Balance += this->Amount;
    	cout << "\nYour New Balance is: " << this->Balance;
    }
}

int Account::getAccountNumber() const {
    return AccountNumber;  // Return the Account Number
}

