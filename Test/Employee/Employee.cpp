#include "Employee.h"

// Employee constructor
Employee::Employee(int id, const string& name, const tm& date, double salary)
    : emp_id(id), name(name), date_of_pinning(date), salary(salary) {}

// Manager constructor
Manager::Manager(int id, const string& name, const tm& date, double salary, double ta, double hra)
    : Employee(id, name, date, salary), ta(ta), hra(hra) {}

double Manager::Calculate() {
    return salary + ta + hra; // Total salary for Manager
}

// SalesPerson constructor
SalesPerson::SalesPerson(int id, const string& name, const tm& date, double salary, double sales, double comn)
    : Employee(id, name, date, salary), sales(sales), comn(comn) {}

double SalesPerson::Calculate() {
    return salary + (sales * comn); // Total salary for SalesPerson
}

// WageEmp constructor
WageEmp::WageEmp(int id, const string& name, const tm& date, double salary, double sales, double comn, double rate)
    : SalesPerson(id, name, date, salary, sales, comn), rate(rate) {}

double WageEmp::Calculate() {
    return salary + (sales * comn) + rate; // Total salary for WageEmp
}
