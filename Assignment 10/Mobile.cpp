#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class MobilePhone {
public:
    string serialNo;
    string modelNo;
    string brandName;
    double price;

    MobilePhone(string sNo, string mNo, string bName, double p)
        : serialNo(sNo), modelNo(mNo), brandName(bName), price(p) {}

    void display() const {
        cout << "Serial No: " << serialNo 
             << ", Model No: " << modelNo 
             << ", Brand: " << brandName 
             << ", Price: " << price << endl;
    }
};

void addMobilePhoneToFile(const string& filename) {
    string serialNo, modelNo, brandName;
    double price;

    cout << "Enter Serial Number: ";
    cin >> serialNo;
    cout << "Enter Model Number: ";
    cin >> modelNo;
    cout << "Enter Brand Name: ";
    cin >> brandName;
    cout << "Enter Price: ";
    cin >> price;

    ofstream file(filename, ios::app);
    if (file) {
        file << serialNo << " " << modelNo << " " << brandName << " " << price << endl;
    } else {
        cerr << "Unable to open file." << endl;
    }
}

vector<MobilePhone> readMobilePhonesFromFile(const string& filename) {
    vector<MobilePhone> mobilePhones;
    ifstream file(filename);
    string serialNo, modelNo, brandName;
    double price;

    while (file >> serialNo >> modelNo >> brandName >> price) {
        mobilePhones.emplace_back(serialNo, modelNo, brandName, price);
    }
    return mobilePhones;
}

void displaySortedMobilePhones(const string& filename) {
    auto mobilePhones = readMobilePhonesFromFile(filename);
    sort(mobilePhones.begin(), mobilePhones.end(), [](const MobilePhone& a, const MobilePhone& b) {
        return a.price < b.price;
    });

    cout << "\nMobile Phones sorted by price:\n";
    for (const auto& phone : mobilePhones) {
        phone.display();
    }
}

int main() {
    string filename = "mobile_phones.txt";
    int choice;

    do {
        cout << "\nMenu:\n"
             << "1. Add Mobile Phone\n"
             << "2. Read all Mobile Phones\n"
             << "3. Display Mobile Phones sorted by price\n"
             << "4. Exit\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addMobilePhoneToFile(filename); break;
            case 2: {
                auto mobilePhones = readMobilePhonesFromFile(filename);
                cout << "\nAll Mobile Phones:\n";
                for (const auto& phone : mobilePhones) {
                    phone.display();
                }
                break;
            }
            case 3: displaySortedMobilePhones(filename); break;
            case 4: cout << "Exiting the program." << endl; break;
            default: cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
