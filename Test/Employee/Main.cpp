#include "Employee.h"

int main() {
    // Create a date for the employee
    tm date = {};
    date.tm_year = 2023 - 1900; // Year since 1900
    date.tm_mon = 0; // January
    date.tm_mday = 1; // 1st day

    // Create instances of each class
    Manager mgr(1, "Alice", date, 50000, 5000, 3000);
    SalesPerson sp(2, "Bob", date, 40000, 20000, 0.1);
    WageEmp wageEmp(3, "Charlie", date, 30000, 15000, 0.05, 2000);

    // Calculate and display salaries
    cout << "Manager Salary: " << mgr.Calculate() << endl;
    cout << "SalesPerson Salary: " << sp.Calculate() << endl;
    cout << "Wage Employee Salary: " << wageEmp.Calculate() << endl;

    return 0;
}
