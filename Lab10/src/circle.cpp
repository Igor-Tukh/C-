#include "circle.h"
#include <string.h>
#include <cstdio>

Circle::Circle(int id, int x, int y, int radius, const char* label) : Figure(id, x, y){
    r = radius;
    name = new char[strlen(label) + 1];
    strcpy(name, label);
}

Circle::~Circle(){
    delete name;
}

void Circle::print() const {
    printf("Circle %d: x = %d y = %d radius = %d label = %s", id, x, y, r, name);
}

bool Circle::is_inside(const int x, const int y){
    return ((this->x - x) * (this-> x - x) + (this->y - y) * (this->y - y) <= r * r); 
}

void Circle::zoom(const int factor){
    r *= factor;
}
