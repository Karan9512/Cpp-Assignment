#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Employee {
protected:
    int emp_id;
    string name;
    tm date_of_pinning; // Using std::tm for date representation
    double salary;

public:
    Employee(int id, const string& name, const tm& date, double salary);
    virtual ~Employee() {}

    virtual double Calculate() = 0; // Pure virtual function
};

class Manager : public Employee {
private:
    double ta; // Travelling Allowance
    double hra; // House Rent Allowance

public:
    Manager(int id, const string& name, const tm& date, double salary, double ta, double hra);
    double Calculate() override;
};

class SalesPerson : public Employee {
protected: // Change from private to protected
    double sales; // Sales amount
    double comn; // Commission

public:
    SalesPerson(int id, const string& name, const tm& date, double salary, double sales, double comn);
    double Calculate() override;
};

class WageEmp : public SalesPerson {
private:
    double rate; // Wage rate

public:
    WageEmp(int id, const string& name, const tm& date, double salary, double sales, double comn, double rate);
    double Calculate() override;
};

#endif // EMPLOYEE_H
