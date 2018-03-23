#include <iostream>
#include <stdio.h>
#include <string>
#include <ctype.h>
#include "employee.h"
#include "sqlite3.h"
#include "database.h"

Employee createEmployee();
void insertInDatabase(Employee e);

int main()
{
    Employee e = createEmployee();
    insertInDatabase(e);

    // or
    // insertInDatabase(CreateEmployee()); ?
    return 0;
}

Employee createEmployee() {
    std::string fname;
    std::string lname;
    int age;

    std::cout << "****Create New Employee****\n";
    std::cout << "---------------------------\n";
    std::cout << "First Name: ";
    std::getline(std::cin, fname, '\n');
    std::cout << "\nLast Name: ";
    std::getline(std::cin, lname, '\n');
    std::cout << "\nAge: ";
    std::cin >> age;

    Employee e(fname, lname, age);

    return e;
}

void insertInDatabase(Employee e) {
    std::cout << "Add to database? (y/n)";
    char res;
    std::cin >> res;
    tolower(res);

    // input validation not yet implemented
    if (res == 'n') {
        std::cout << "Exiting program\n";
    }
    else if (res == 'y') {
        std::cout << "Preparing to add record to database...\n";
        Database::insert(e);
    }
}