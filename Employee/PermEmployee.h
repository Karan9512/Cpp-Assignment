#ifndef PERMEMLOYEE_H
#define PERMEMLOYEE_H

#include "Employee.h"

class PermEmployee : public Employee {
    float basicSalary;
    float ta;
    float hra;
public:
    PermEmployee(std::string name, int id, float salary, float ta, float hra);
    void calcSalary() override;
    void display() const override;
};

#endif

