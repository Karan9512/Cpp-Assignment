#ifndef CONTRACTEMPLOYEE_H
#define CONTRACTEMPLOYEE_H

#include "Employee.h"

class ContractEmployee : public Employee 
{
    float hourlyRate;
    int hoursWorked;
public:
    ContractEmployee(std::string name, int id, float rate, int hours);
    virtual void calcSalary();
    virtual void display() const;
};

#endif

