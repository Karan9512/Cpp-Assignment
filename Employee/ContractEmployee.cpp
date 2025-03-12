#include "ContractEmployee.h"

ContractEmployee::ContractEmployee(std::string name, int id, float rate, int hours)
    : Employee(name, id), hourlyRate(rate), hoursWorked(hours) {}

void ContractEmployee::calcSalary() 
{
    float salary = hourlyRate * hoursWorked;
    std::cout << "Contract Employee Salary: " << salary << std::endl;
}

void ContractEmployee::display() const 
{
    Employee::display();
    std::cout << "Employee Type: Contract" << std::endl;
}

