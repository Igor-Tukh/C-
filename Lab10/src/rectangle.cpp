#include "rectangle.h"
#include <cstdio>
#include <algorithm>

Rectangle::Rectangle(int id, int x, int y, int width, int height): Figure(id, x, y){
    w = width;
    h = height;
}

void Rectangle::print() const {
    printf("Rectangle %d: x = %d y = %d width = %d height = %d", id, x, y, w, h);
}

bool Rectangle::is_inside(int x, int y){
    return (abs(this->x - x) * 2 <= w && abs(this->y - y) * 2 <= h); 
}

void Rectangle::zoom(int factor){
    w *= factor;
    h *= factor;
}
