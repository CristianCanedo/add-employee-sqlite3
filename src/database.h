#ifndef DATABASE_H
#define DATABASE_H

#include "employee.h"

class Database {

    public:
    Database() {}
    ~Database() {}

    static int id_callback(void*, int, char**, char**);
    static int generate_id();
    static int insert(const Employee &e);
    static std::string generate_query(int id, const Employee &e);
    static int insert_callback(void*, int, char**, char**);
};

#endif // DATABASE_H