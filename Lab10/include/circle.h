#pragma once

#include "figure.h"

class Circle : public Figure {
  public:
    Circle(int id, int x, int y, int radius, const char* label);
    ~Circle();

    void print() const ;
    bool is_inside(const int x, const int y);
    void zoom(const int factor);
  private:
    char* name;
    int r;  
};
