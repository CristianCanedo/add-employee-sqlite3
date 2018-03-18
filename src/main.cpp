#include <iostream>
#include <string>
#include <ctype.h>
#include "employee.h"
#include "sqlite3.h"

static int callback(void *NotUsed, int argc, char **argv, char **azColName);
void insertEmployee(const Employee e);
int calculateId();

int main()
{
    
    char response;
    std::cout << "****Create New Employee****\n";
    std::cout << "---------------------------\n";
    std::cout << "First Name: ";

    std::string fname;
    std::getline(std::cin, fname);

    std::cout << "\nLast Name: ";
    std::string lname;
    std::getline(std::cin, lname);

    std::cout << "\nAge: ";
    int age;
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
        insertEmployee(e);
    }

    return 0;
}

void insertEmployee(const Employee e) {
    sqlite3 *db;
    const char *filename = "C:\\Sqlite3\\test.db";
    // CalculateId();
    const char *query = "";
}

int calculateId() {
    sqlite3 *db;
    const char *filename = "C:\\Sqlite3\\test.db";
    int rc;

    
}