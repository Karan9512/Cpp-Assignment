#include<iostream>
#include<string>
using namespace std;

class Account {
    private:
        static int count;
        int AccountNumber;
        string Name;
        double Balance;
        double Amount;

    public:
        Account();  // Default constructor
        Account(string name, double balance);  // Parameterized constructor
        void Accept(); 
       	void Display();  // Display account details
        void Withdraw();  // Withdraw amount
        void Deposit();  // Deposit amount
        int getAccountNumber() const;  // Getter function for Account Number
};

