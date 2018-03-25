#include <iostream>
#include <string>
#include <limits>
#include "employee.h"

void Employee::create() {
    std::string fname;
    std::string lname;
    int age;

    std::cout << "****Create New Employee****" << std::endl;
    std::cout << "---------------------------" << std::endl;
    setFirstName();
    setLastName();
    setAge();
}

void Employee::setFirstName() {
    std::string fname;

    while (true) {
        std::cout << "First Name: " << std::endl;
        std::getline(std::cin, fname, '\n');

        if (!isNameValid(fname)) {
            continue;
        }
        break;
    }
    _firstname = fname;
}

void Employee::setLastName() {
    std::string lname;

    while (true) {
        std::cout << "Last Name: " << std::endl;
        std::getline(std::cin, lname, '\n');

        if (!isNameValid(lname)) {
            continue;
        }
        break;
    }
    _lastname = lname;
}

bool Employee::isNameValid(const std::string &name) {
    if (name.length() <= 2) {
        std::cout << "Name must be at least 3 characters long." << std::endl;
        return false;
    }
    else if (name.length() >= 20) {
        std::cout << "Name must be shorter than 20 characters." << std::endl;
        return false;
    }

    for (int i = 0; i < name.length(); i++) {
        if (isdigit(name[i])) {
            std::cout << "Name cannot contain digits." << std::endl;
            return false;
        }
        else if (name[i] == ' ') {
            std::cout << "Name cannot contain spaces." << std::endl;
            return false;
        }
    }
    return true;
}

void Employee::setAge() {
    int age;

    while (true) {
        std::cout << "Age: " << std::endl;
        std::cin >> age;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout << "Invalid input. Please re-enter." << std::endl;
            continue;
        }

        if (!isAgeValid(age)) {
            continue;
        }
        break;
    }

    _age = age;
}

bool Employee::isAgeValid(int age) {
    if (age <= 0 || age >= 103) {
        std::cout << "Must enter a valid age." << std::endl;
        return false;
    }
    return true;
}