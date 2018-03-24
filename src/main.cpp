#include <iostream>
#include <stdio.h>
#include <string>
#include <ctype.h>
#include "employee.h"
#include "sqlite3.h"
#include "database.h"

void createEmployee();
void prepareForStorage(const Employee &e);
void insertInDatabase(const Employee &e);

int main()
{
    createEmployee();
    return 0;
}

void createEmployee() {
    std::string fname;
    std::string lname;
    int age;

    std::cout << "****Create New Employee****" << std::endl;
    std::cout << "---------------------------" << std::endl;
    std::cout << "First Name: ";
    std::getline(std::cin, fname, '\n');
    std::cout << "Last Name: ";
    std::getline(std::cin, lname, '\n');
    std::cout << "Age: ";
    std::cin >> age;
    std::cout << std::endl;

    Employee e(fname, lname, age);

    prepareForStorage(e);
}

void prepareForStorage(const Employee &e) {
    char res;

    while (true) {
        std::cout << "Add to database? (y/n):";
        std::cin >> res;

        if (std::cin.fail()) {
            std::cerr << "Unable to read input. Try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(10, '\n');
            continue;
        }

        tolower(res);

        if (res == 'n') {
            std::cout << "Exiting program." << std::endl;
            break;
        }
        else if (res == 'y') {
            insertInDatabase(e);
            break;
        }
        else {
            std::cout << "Not a valid input." << std::endl;
            continue;
        }
    }
}

void insertInDatabase(const Employee &e) {
    std::cout << "Preparing to add record to database..." << std::endl;
    Database::insert(e);
}