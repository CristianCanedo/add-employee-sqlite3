#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee {
    private:
    std::string _firstname;
    std::string _lastname;
    int _age;

    public:
    Employee() {}
    Employee(std::string fn, std::string ln, int a)
            :_firstname(fn), _lastname(ln), _age(a) {}
    ~Employee() {}

    void create();
    void setFirstName();
    void setLastName();
    void setAge();
    bool isNameValid(const std::string &name);
    bool isAgeValid(int age);

    std::string getFirstName() const { return _firstname; }
    std::string getLastName() const { return _lastname; }
    int getAge() const { return _age; }
};

#endif // EMPLOYEE_H