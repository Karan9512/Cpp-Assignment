#include <iostream>
using namespace std;

// Base User class
class User {
protected:
    string name;
    int storage;  // Storage in GB
    double price; // Price in USD

public:
    User(string n, int s, double p) : name(n), storage(s), price(p) {}

    virtual void showDetails() {  // Virtual function for polymorphism
        cout << "User: " << name << "\nStorage: " << storage << "GB\nPrice: $" << price << endl;
    }

    virtual void applyDiscount(string code) {  // Virtual function to apply discount
        if (code == "NET50") {
            price /= 2;  // Apply 50% discount
            cout << "Discount Applied! New Price: $" << price << endl;
        } else {
            cout << "Invalid Discount Code!" << endl;
        }
    }

    virtual ~User() {} // Virtual destructor
};

// Derived class for Basic Users
class BasicUser : public User {
public:
    BasicUser(string n, int s) : User(n, s, 10.0) {} // Base price: $10 for Basic

    void showDetails() override {
        cout << "--- Basic User ---\n";
        User::showDetails();
    }
};

// Derived class for Premium Users
class PremiumUser : public User {
public:
    PremiumUser(string n, int s) : User(n, s, 20.0) {} // Base price: $20 for Premium

    void showDetails() override {
        cout << "--- Premium User ---\n";
        User::showDetails();
    }
};

// Function to determine user type
void choosePlan(string name, int storage, string discountCode) {
    User* user;  // Base class pointer for polymorphism

    if (storage <= 50) {
        user = new BasicUser(name, storage);
    } else {
        user = new PremiumUser(name, storage);
    }

    user->showDetails(); // Call overridden function
    user->applyDiscount(discountCode); // Apply discount if applicable

    delete user; // Free allocated memory
}

int main() {
    string name, discountCode;
    int storage;

    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter storage size in GB: ";
    cin >> storage;
    cout << "Enter discount code (if any): ";
    cin >> discountCode;

    choosePlan(name, storage, discountCode);

    return 0;
}
