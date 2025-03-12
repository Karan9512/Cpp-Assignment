#include "Account.h"
#include <iostream>
using namespace std;

int main() {
    const int MAX_ACCOUNTS = 10;  // Maximum number of accounts that can be created
    Account accounts[MAX_ACCOUNTS];  // Array of Account objects
    int accountCount = 0;  // To keep track of the number of accounts created

    while (1) {
        cout << "\nSelect One: ";
        cout << "\n1. Open New Account ";
        cout << "\n2. Account Details ";
        cout << "\n3. Deposit ";
        cout << "\n4. Withdraw ";
        cout << "\n5. Exit ";

        int ch;
        cout << "\nPlease Enter Your Choice: ";
        cin >> ch;

        switch (ch) {
            case 1: {
                if (accountCount >= MAX_ACCOUNTS) {
                    cout << "\nCannot open more accounts. Max limit reached!";
                    break;
                }
                // Create a new Account object and accept details
                accounts[accountCount].Accept();
                accountCount++;  // Increment account counter
                break;
            }
            case 2: {
                if (accountCount == 0) {
                    cout << "\nNo accounts available!";
                } else {
                    cout << "\nEnter Account Number to view details: ";
                    int accNum;
                    cin >> accNum;

                    bool found = false;
                    for (int i = 0; i < accountCount; ++i) {
                        if (accounts[i].getAccountNumber() == accNum) {  // Compare Account Number
                            accounts[i].Display();
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        cout << "\nAccount not found!";
                    }
                }
                break;
            }
            case 3: {
                if (accountCount == 0) {
                    cout << "\nNo accounts available!";
                } else {
                    cout << "\nEnter Account Number to deposit: ";
                    int accNum;
                    cin >> accNum;

                    bool found = false;
                    for (int i = 0; i < accountCount; ++i) {
                        if (accounts[i].getAccountNumber() == accNum) {  // Compare Account Number
                            accounts[i].Deposit();
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        cout << "\nAccount not found!";
                    }
                }
                break;
            }
            case 4: {
                if (accountCount == 0) {
                    cout << "\nNo accounts available!";
                } else {
                    cout << "\nEnter Account Number to withdraw: ";
                    int accNum;
                    cin >> accNum;

                    bool found = false;
                    for (int i = 0; i < accountCount; ++i) {
                        if (accounts[i].getAccountNumber() == accNum) {  // Compare Account Number
                            accounts[i].Withdraw();
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        cout << "\nAccount not found!";
                    }
                }
                break;
            }
            case 5: {
                cout << "\nExiting program.";
                return 0;
            }
            default: {
                cout << "\nPlease Enter a valid Choice!";
                break;
            }
        }
    }

    return 0;
}

