#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class lowBalance : public runtime_error {
public:
    lowBalance(const string& message) : runtime_error(message) {}
};

class PanCardRequire : public runtime_error {
public:
    PanCardRequire(const string& message) : runtime_error(message) {}
};

class Account {
private:
    int acno;
    string name;
    double balance;

public:
    // Constructor
    Account(int accountNumber, const string& accountName, double initialBalance)
        : acno(accountNumber), name(accountName), balance(initialBalance) {}

    // Method to accept account details
    void accept() {
        cout << "Enter Account Number: ";
        cin >> acno;
        cout << "Enter Account Holder Name: ";
        cin.ignore(); // To ignore the newline character left in the buffer
        getline(cin, name);
        cout << "Enter Initial Balance: ";
        cin >> balance;
    }

    // Method to display account details
    void display() const {
        cout << "Account Number: " << acno << endl;
        cout << "Account Holder Name: " << name << endl;
        cout << "Balance: " << balance << endl;
    }

    // Method to withdraw money
    void withdraw(double amount) {
        if (balance < 1000) {
            throw lowBalance("Withdrawal denied: Balance is below the minimum required amount of 1000.");
        }
        if (amount > balance) {
            cout << "Withdrawal denied: Insufficient funds." << endl;
            return;
        }
        balance -= amount;
        cout << "Withdrawal successful. New balance: " << balance << endl;
    }

    // Method to deposit money
    void deposit(double amount) {
        if (amount >= 50000) {
            throw PanCardRequire("Deposit denied: PAN Card required for deposits of 50,000 or more.");
        }
        balance += amount;
        cout << "Deposit successful. New balance: " << balance << endl;
    }
};

int main() {
    Account acc(0, "", 0.0); // Create an account object
    acc.accept(); // Accept account details

    // Display account details
    acc.display();

    // Test withdrawal
    try {
        acc.withdraw(500); // Attempt to withdraw
    } catch (const lowBalance& e) {
        cerr << e.what() << endl;
    }

    // Test deposit
    try {
        acc.deposit(60000); // Attempt to deposit
    } catch (const PanCardRequire& e) {
        cerr << e.what() << endl;
    }

    // Final display of account details
    acc.display();

    return 0;
}
