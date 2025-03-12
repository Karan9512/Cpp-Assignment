#include "Employee.h"

Employee::Employee(std::string name, int id) : name(name), id(id) {}

void Employee::display() const 
{
    std::cout << "Name: " << name << ", ID: " << id << std::endl;
}

