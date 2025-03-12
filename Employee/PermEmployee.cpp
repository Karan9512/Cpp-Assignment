#include "PermEmployee.h"

PermEmployee::PermEmployee(std::string name, int id, float salary, float ta, float hra)
    : Employee(name, id), basicSalary(salary), ta(ta), hra(hra) {}

void PermEmployee::calcSalary() {
    float totalSalary = basicSalary + ta + hra;
    std::cout << "Basic Salary: " << basicSalary << std::endl;
    std::cout << "TA: " << ta << std::endl;
    std::cout << "HRA: " << hra << std::endl;
    std::cout << "Total Salary: " << totalSalary << std::endl;
}

void PermEmployee::display() const {
    Employee::display();
    std::cout << "Employee Type: Permanent" << std::endl;
}

