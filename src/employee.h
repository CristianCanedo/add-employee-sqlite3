#include <string>

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee {
    private:
    std::string _firstName;
    std::string _lastName;
    int _age;

    public:
    Employee() {}
    Employee(std::string fn, std::string ln, int a)
            :_firstName(fn), _lastName(ln), _age(a) {}
    ~Employee() {}
}

#endif // EMPLOYEE_H