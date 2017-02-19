#ifndef __LAB11_EMPLOYEES_H_INCLUDED
#define __LAB11_EMPLOYEES_H_INCLUDED

#include <stdint.h>
#include <iostream>

class Employee{
public:
    virtual std::istream& read(std::istream& is) = 0;
    virtual std::ifstream& fileRead(std::ifstream& is) = 0;
    virtual std::ostream& print(std::ostream& os) const = 0;
    virtual std::ofstream& filePrint(std::ofstream& os) const = 0;
    
    friend std::istream& operator >> (std::istream& is, Employee& e);
    friend std::ifstream& operator >> (std::ifstream& is, Employee& e);
    friend std::ostream& operator << (std::ostream& os, const Employee& e);
    friend std::ofstream& operator << (std::ofstream& os, const Employee& e);
    
    virtual int salary() const = 0;
    Employee();
    ~Employee();
    std::string getType() const;
protected:
    char *_name;
    int32_t _name_len;
    int32_t _base_salary;    
    int32_t _type;
    Employee(const Employee&);
    void operator=(const Employee&);
};

class Developer: public Employee {
public:
    Developer();
        
    int salary() const {
        int salary = _base_salary;
        if (_has_bonus) { salary += 1000; }
        return salary;
    }
  
    std::istream& read(std::istream& is);
    std::ifstream& fileRead(std::ifstream& is);
    std::ostream& print(std::ostream& os) const;
    std::ofstream& filePrint(std::ofstream& os) const;
private:
    bool _has_bonus;
};

class SalesManager: public Employee {
public:
    SalesManager();
    
    int salary() const {
        return _base_salary + _sold_nm * _price * 0.01;
    }
  
    std::istream& read(std::istream& is);
    std::ifstream& fileRead(std::ifstream& is);
    std::ostream& print(std::ostream& os) const;
    std::ofstream& filePrint(std::ofstream& os) const;
private:    
    int32_t _sold_nm, _price;
};

class EmployeesArray {
public:
    EmployeesArray();
    ~EmployeesArray();
    void add(const Employee *e);
    int total_salary() const;
    int getSize() const;
    
    friend std::ostream& operator << (std::ostream& os, const EmployeesArray& e);
    friend std::ofstream& operator << (std::ofstream& os, const EmployeesArray& e);
    friend std::ifstream& operator >> (std::ifstream& is, EmployeesArray& e);
private:
    Employee **_employees;
    int32_t _size;
    int32_t _capacity;
    EmployeesArray(const EmployeesArray&);
    void operator=(const EmployeesArray&);
};

#endif
