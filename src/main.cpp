#include <iostream>
#include <stdio.h>
#include <string>
#include <ctype.h>
#include "employee.h"
#include "sqlite3.h"
#include "database.h"

int main()
{
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

    std::cout << "Add to database? (y/n)";
    char res;
    std::cin >> res;
    tolower(res);

    if (res == 'n') {
        std::cout << "Exiting program\n";
    }
    else if (res == 'y') {
        std::cout << "Preparing to add record to database...\n";
        Database::insert(e);
    }

    return 0;
}
