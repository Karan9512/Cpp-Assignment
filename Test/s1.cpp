#include <iostream>
#include <string>
using namespace std;
class Address {
    string area;
    string city;
    int pincode;

public:
    // Constructor for Address
    Address(string area,string city, int pincode)
        : area(area), city(city), pincode(pincode) {}

    string getarea()
    {
    	return this->area;
    }
    string getcity()
    {
    	return this->city;
    }
    int getpincode()
    {
    	return this->pincode;
    }
};

class Student {

    int rno; // Roll number
    string name; // Name of the student
public:
    Address permanentAddress; // Permanent address
    Address currentAddress; // Current address

    // Constructor for Student
    Student(int rno, string name, string permArea, string permCity, int permPincode,string currArea, string currCity, int currPincode)
        : rno(rno), name(name),
          permanentAddress(permArea, permCity, permPincode),
          currentAddress(currArea, currCity, currPincode) {}

    // Function to display student details
    void display() {
        std::cout << "Roll Number: " <<this-> rno << endl;
        std::cout << "Name: " <<this-> name << endl;
        std::cout << "Permanent Address: " << permanentAddress.getarea()<< ", "
                  << permanentAddress.getcity() << ", " << permanentAddress.getpincode() << endl;
        std::cout << "Current Address: " << currentAddress.getarea() << ", "
                  << currentAddress.getcity() << ", " << currentAddress.getpincode() << endl;
    }
};

int main() {
    // Creating a Student object
    Student s1(101, "Sweta", "Shivaji Nagar", "Satara", 411009, "Pashan", "Pune", 411003);

    // Displaying the details of the student
    s1.display();

    return 0;
}

