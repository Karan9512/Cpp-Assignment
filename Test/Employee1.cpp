#include <iostream>
#include <vector>
#include <string>

class Emp {
public:
    int eid; // Employee ID
    std::string name; // Employee name
    std::string address; // Employee address
    double salary; // Employee salary

    // Constructor
    Emp(int id, std::string name, std::string address, double salary)
        : eid(id), name(name), address(address), salary(salary) {}
};

void addRecord(std::vector<Emp>& employees) {
    int id;
    std::string name, address;
    double salary;

    std::cout << "Enter Employee ID: ";
    std::cin >> id;
    std::cin.ignore(); // To ignore the newline character after reading id
    std::cout << "Enter Employee Name: ";
    std::getline(std::cin, name);
    std::cout << "Enter Employee Address: ";
    std::getline(std::cin, address);
    std::cout << "Enter Employee Salary: ";
    std::cin >> salary;

    employees.emplace_back(id, name, address, salary);
    std::cout << "Record added successfully!\n";
}

void displayAll(const std::vector<Emp>& employees) {
    if (employees.empty()) {
        std::cout << "No records found.\n";
        return;
    }

    std::cout << "Employee Records:\n";
    for (const auto& emp : employees) {
        std::cout << "ID: " << emp.eid << ", Name: " << emp.name 
                  << ", Address: " << emp.address << ", Salary: " << emp.salary << "\n";
    }
}

void searchRecord(const std::vector<Emp>& employees) {
    int id;
    std::cout << "Enter Employee ID to search: ";
    std::cin >> id;

    for (const auto& emp : employees) {
        if (emp.eid == id) {
            std::cout << "Record found: ID: " << emp.eid << ", Name: " << emp.name 
                      << ", Address: " << emp.address << ", Salary: " << emp.salary << "\n";
            return;
        }
    }
    std::cout << "Record not found.\n";
}

void deleteRecord(std::vector<Emp>& employees) {
    int id;
    std::cout << "Enter Employee ID to delete: ";
    std::cin >> id;

    for (auto it = employees.begin(); it != employees.end(); ++it) {
        if (it->eid == id) {
            employees.erase(it);
            std::cout << "Record deleted successfully!\n";
            return;
        }
    }
    std::cout << "Record not found.\n";
}

void modifyRecord(std::vector<Emp>& employees) {
    int id;
    std::cout << "Enter Employee ID to modify: ";
    std::cin >> id;

    for (auto& emp : employees) {
        if (emp.eid == id) {
            std::string name, address;
            double salary;

            std::cin.ignore(); // To ignore the newline character after reading id
            std::cout << "Enter new Employee Name: ";
            std::getline(std::cin, name);
            std::cout << "Enter new Employee Address: ";
            std::getline(std::cin, address);
            std::cout << "Enter new Employee Salary: ";
            std::cin >> salary;

            emp.name = name;
            emp.address = address;
            emp.salary = salary;

            std::cout << "Record modified successfully!\n";
            return;
        }
    }
    std::cout << "Record not found.\n";
}

int main() {
    std::vector<Emp> employees;
    int choice;

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add Record\n";
        std::cout << "2. Display All Records\n";
        std::cout << "3. Search Record\n";
        std::cout << "4. Delete Record\n";
        std::cout << "5. Modify Record\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addRecord(employees);
                break;
            case 2:
                displayAll(employees);
                break;
            case 3:
                searchRecord(employees);
                break;
            case 4:
                deleteRecord(employees);
                break;
            case 5:
                modifyRecord(employees);
                break;
            case 6:
                std::cout << "Exiting program.\n";
                break;

            default:

                std::cout << "Invalid choice. Please try again.\n";

        }

    } while (choice != 6);


    return 0;

}
