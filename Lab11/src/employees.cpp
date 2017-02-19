#include "../include/employees.h"
#include <iostream>
#include <fstream>
#include <cstring>

Employee::Employee(){
    _base_salary = 0;
    _name_len = 0;
    _type = 0;
}

Employee::~Employee(){
    delete[] _name;
}

Developer::Developer(){
    _type = 1;
}

std::istream& Developer::read(std::istream& is){
    std::string name;
    is >> name >> _base_salary >> _has_bonus; 
    _name = new char[name.length() + 1];
    strcpy(_name, name.std::string::c_str());
    _name_len = name.length() + 1;
    return is;
}

std::ifstream& Developer::fileRead(std::ifstream& is){
    char b = 'a';
    std::string name = "";
    while (b != '\0'){
        is.read(&b, sizeof(char));
        if (b != '\0')
            name = name + b;
    }
    _name = new char[name.length() + 1];
    strcpy(_name, name.std::string::c_str());
    _name_len = name.length() + 1;
       
    is.read((char*)(&_base_salary), sizeof(int32_t));    
    is.read((char*)(&_has_bonus), sizeof(bool));
    
    return is;
}

std::ostream& Developer::print(std::ostream& os) const{
    os << "Developer\n" << "Name: " << _name << "\n" << "Base Salary: " << _base_salary << "\n" << "Has bonus: ";
    
    if (_has_bonus)
        os << "+\n";
    else
        os << "-\n";
    
    return os; 
}

std::ofstream& Developer::filePrint(std::ofstream& os) const{
   os.write((char*)&_type, sizeof(int32_t));
   os.write(_name, _name_len * sizeof(char));
   os.write((char*)&_base_salary, sizeof(int32_t));
   os.write((char*)&_has_bonus, sizeof(bool));
   return os;
}

SalesManager::SalesManager(){
    _type = 2;
}

std::istream& SalesManager::read(std::istream& is){
    std::string name;
    is >> name >> _base_salary >> _sold_nm >> _price; 
    _name = new char[name.length() + 1];
    strcpy(_name, name.std::string::c_str());
    _name_len = name.length() + 1;
    return is;
}

std::ifstream& SalesManager::fileRead(std::ifstream& is){
    char b = 'a';
    std::string name = "";
    while (b != '\0'){
        is.read(&b, sizeof(char));
        if (b != '\0')
            name = name + b;
    }
    _name = new char[name.length() + 1];
    strcpy(_name, name.std::string::c_str());
    _name_len = name.length() + 1;
       
    is.read((char*)(&_base_salary), sizeof(int32_t));    
    is.read((char*)(&_sold_nm), sizeof(int32_t));    
    is.read((char*)(&_price), sizeof(int32_t));    
    
    return is;
}

std::ostream& SalesManager::print(std::ostream& os) const{
    os << "Sales Manager\n" << "Name: " << _name << "\n" << "Base Salary: " << _base_salary << "\n" << "Sold items: " << _sold_nm << "\n" << "Item price: " << _price << "\n";
    return os;
}

std::ofstream& SalesManager::filePrint(std::ofstream& os) const{
   os.write((char*)&_type, sizeof(int32_t));
   os.write(_name, _name_len * sizeof(char));
   os.write((char*)&_base_salary, sizeof(int32_t));
   os.write((char*)&_sold_nm, sizeof(int32_t));
   os.write((char*)&_price, sizeof(int32_t));
   return os;
}

std::string Employee::getType() const{
    if (_type == 1)
        return "Developer";
    if (_type == 2)
        return "SalesManager";
}

std::istream& operator >> (std::istream& is, Employee& e){
    e.read(is);
    return is;
}

std::ifstream& operator >> (std::ifstream& is, Employee& e){
    e.fileRead(is);
    return is;
}

std::ostream& operator << (std::ostream& os, const Employee& e){
    e.print(os);
    return os;   
}

std::ofstream& operator << (std::ofstream& os, const Employee& e){
    e.filePrint(os);
    return os;
}


std::ostream& operator << (std::ostream& os, const EmployeesArray& e){
    for(int32_t i = 0; i < e._size; i++){
        os << i + 1 << ". ";
        os << *e._employees[i];
    }
    os << "== Total salary: " << e.total_salary() << "\n\n";
    
    return os;
}


std::ofstream& operator << (std::ofstream& os, const EmployeesArray& e){
    os.write((char*)&e._size, sizeof(int32_t));
    for(int32_t i = 0; i < e._size; i++)
        os << *e._employees[i];
    
    return os;
}


std::ifstream& operator >> (std::ifstream& is, EmployeesArray& e){
    int32_t cnt, type;
    is.read((char*)&cnt, sizeof(int32_t));
    
    for(int32_t i = 0; i < cnt; i++){
        Employee* cur;
        is.read((char*)&type, sizeof(int32_t));
        if (type == 1){
            cur = new Developer();
            is >> *cur;
        }
        else{
            cur = new SalesManager();
            is >> *cur;
        }
        
        e.add(cur);
    }
    
    return is;
}

EmployeesArray::EmployeesArray(){
    _size = 0;
    _capacity = 2;
    _employees = new Employee*[2];
}

EmployeesArray::~EmployeesArray(){
    for(int32_t i = 0; i < _size; i++)
        delete _employees[i];
    delete[] _employees;
}

int EmployeesArray::total_salary() const{
    int salary = 0;
    for(int32_t i = 0; i < _size; i++)
        salary += _employees[i]->salary();
        
    return salary;
}

void EmployeesArray::add(const Employee *e){
    _size++;
    
    if (_size >= _capacity){
        _capacity *= 2;
        
        Employee** buf = new Employee*[_capacity];
    
        for(int32_t i = 0; i < _size; i++)
            buf[i] = _employees[i];
    
        std::swap(buf, _employees);
        delete[] buf;
    }
    
    _employees[_size - 1] = (Employee*) e; 
}
