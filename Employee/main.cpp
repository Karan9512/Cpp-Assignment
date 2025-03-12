#include "PermEmployee.h"
#include "ContractEmployee.h"

int main() {
    Employee* emp1 = new PermEmployee("Karan Chile", 101, 50000, 5000, 10000);
    
    Employee* emp2 = new ContractEmployee("Atharav Patil", 102, 1000, 40);

    emp1->display();
    emp1->calcSalary();

    std::cout << "---------------------------" << std::endl;

    emp2->display();
    emp2->calcSalary();

    delete emp1;
    delete emp2;

    return 0;
}

