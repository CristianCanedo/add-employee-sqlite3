#include <iostream>
#include <string>
#include <sstream>
#include "database.h"
#include "employee.h"
#include "sqlite3.h"

int Database::insert(const Employee e) {
    sqlite3 *db;
    const char *filename = "C:\\Sqlite3\\test.db";
    char *errMsg = 0;
    const char *query;
    int rc;
    int id = generate_id(); // Generate id based on select count(*)
    
    std::string generatedQuery = generate_query(id, e); // Generated the structured query
    query = generatedQuery.c_str(); // Converting string to char *

    rc = sqlite3_open(filename, &db);

    if (rc != SQLITE_OK) {
        std::cout << "Failed to establish database connection.\n";
        sqlite3_close(db);
        return 1;
    }

    rc = sqlite3_exec(db, query, insert_callback, 0, &errMsg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
        return 1;
    }
    else {
        sqlite3_close(db);
        std::cout << "Record inserted successfully\n";
        return 0;    
    }
}

int Database::generate_id() {
    sqlite3 *db;
    const char *filename = "C:\\Sqlite3\\test.db";
    const char *query = "SELECT COUNT(*) FROM EMPLOYEES";
    char *errMsg = 0;
    int id;
    int rc;

    rc = sqlite3_open(filename, &db);

    if (rc != SQLITE_OK) {
        std::cout << "Failed to establish database connection.\n";
        sqlite3_close(db);
        return 1;
    }
    
    rc = sqlite3_exec(db, query, NULL, 0, &errMsg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
        return 1;
    }
    else {
        rc = sqlite3_exec(db, query, id_callback, &id, &errMsg);

        if (rc != SQLITE_OK) {
            fprintf(stderr, "SQL error: %s\n", errMsg);
            sqlite3_free(errMsg);
            return 1;
        }

        sqlite3_close(db);
        return id;
    }
}

int Database::id_callback(void *data, int count, char **rows, char**) {
    if (count == 1 && rows) {
        *static_cast<int*>(data) = atoi(rows[0]);
        return 0;
    }
    return 1;
}

std::string Database::generate_query(int id, const Employee e) {
    std::ostringstream oss;
    std::string query;

    oss << "INSERT INTO EMPLOYEES VALUES("<< id << 
           "," << "\"" >> e.getLastName << "\","<<
           "\"" << e.getFirstName << "\"," << e.getAge << 
           ");"; 
        
    query = oss.str();
}

int Database::insert_callback(void *notused, int argc, char **argv, char **azColName) {
    int i;
    for(i = 0; i < argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0; 
}