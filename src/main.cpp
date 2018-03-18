#include <iostream>
#include "sqlite3.h"

int main()
{
    sqlite3 *db;
    const char *filename = "C:\\Sqlite\\test.db";

    if (sqlite3_open(filename, &db) != SQLITE_OK) {
        std::cout << "Connection to database failed.\n";
    }
    else {
        std::cout << "Connection successful\n";
    }

    if (sqlite3_close(db) != SQLITE_OK) {
        std::cout << "Connection failed to close\n";
    }
    else {
        std::cout << "Connection closed succesfully\n";
    }

    return 0;
}