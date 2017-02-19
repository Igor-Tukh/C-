#include <string>
#include <cstdio>
#include <iostream>
#include <fstream>

#include "../include/employees.h"

int main(int, char **) {
    std::string cmd, filename;
    int32_t type;

    EmployeesArray ea;
    
    while (std::cin) {
        std::cin >> cmd;
        
        if (cmd == "exit") {
            break;
        } else if (cmd == "load") {
            std::cin >> filename;
            std::ifstream fin(filename.std::string::c_str(), std::ifstream::binary);
            
            fin >> ea;
        } else if (cmd == "list") {
            std::cout << ea;                   
        } else if (cmd == "add"){
            std::cin >> type;
            
            Employee* cur;
            
            if (type == 1)
                cur = new Developer();
            else
                cur = new SalesManager();
            
            std::cin >> *cur;
            
            ea.add(cur);
        } else{
            std::cin >> filename;
            std::ofstream fout(filename.std::string::c_str(), std::ofstream::binary);
            fout << ea;
        }
    }
    
    return 0;
}
