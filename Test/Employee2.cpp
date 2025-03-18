#include <iostream>
#include <string>

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    void display() const {
        std::cout << day << "/" << month << "/" << year;
    }
};

class Employee {
protected:
    int id; // Employee ID
    std::string name; // Employee Name
    Date dateOfPinning; // Date of pinning
    double salary; // Salary

public:
    Employee(int empId, std::string empName, Date pinningDate, double empSalary)
        : id(empId), name(empName), dateOfPinning(pinningDate), salary(empSalary) {}

    virtual double calculate() const = 0; // Pure virtual function

    void display() const {
        std::cout << "ID: " << id << ", Name: " << name << ", Date of Pinning: ";
        dateOfPinning.display();
        std::cout << ", Salary: " << salary << std::endl;
    }
};

class Manager : public Employee {
private:
    double ta; // Travelling Allowance
    double hra; // House Rent Allowance

public:
    Manager(int empId, std::string empName, Date pinningDate, double empSalary, double travellingAllowance, double houseRentAllowance)
        : Employee(empId, empName, pinningDate, empSalary), ta(travellingAllowance), hra(houseRentAllowance) {}

    double calculate() const override {
        return salary + ta + hra; // Total salary for Manager
    }

    void display() const {
        Employee::display();
        std::cout << "Total Salary (Manager): " << calculate() << std::endl;
    }
};

class SalesPerson : public Employee {
protected: // Change to protected
    double sales; // Sales made
    double comn; // Commission

public:
    SalesPerson(int empId, std::string empName, Date pinningDate, double empSalary, double salesMade, double commission)
        : Employee(empId, empName, pinningDate, empSalary), sales(salesMade), comn(commission) {}

    double calculate() const override {
        return salary + (sales * comn); // Total salary for SalesPerson
    }

    void display() const {
        Employee::display();
        std::cout << "Total Salary (SalesPerson): " << calculate() << std::endl;
    }
};

class WageEmp : public SalesPerson {
private:
    double rate; // Rate per hour

public:
    WageEmp(int empId, std::string empName, Date pinningDate, double empSalary, double salesMade, double commission, double hourlyRate)
        : SalesPerson(empId, empName, pinningDate, empSalary, salesMade, commission), rate(hourlyRate) {}

    double calculate() const override {
        return salary + (sales * comn) + (rate * 40); // Assuming 40 hours of work for WageEmp
    }

    void display() const {
        SalesPerson::display();
        std::cout << "Total Salary (Wage Employee): " << calculate() << std::endl;
    }
};

int main() {
    Date date1(15, 3, 2020);
    Manager mgr(1, "Alice", date1, 50000, 5000, 3000);
    mgr.display();

    Date date2(20, 5, 2021);
    SalesPerson sp(2, "Bob", date2, 30000, 100000, 0.1);
    sp.display();

    Date date3(10, 7, 2022);
    WageEmp wageEmp(3, "Charlie", date3, 20000, 50000, 0.05, 20);
    wageEmp.display();

    return 0;
}
