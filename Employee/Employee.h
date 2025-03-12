#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>

class Employee {
protected:
	std::string name;
    	int id;
public:
    	Employee(std::string name, int id);
    	virtual void calcSalary() = 0; // Abstract function
    	virtual void display() const;
    	virtual ~Employee() {}
};

#endif

