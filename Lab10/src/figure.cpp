#include "figure.h"

Figure::Figure(int id, int x, int y){
    this->id = id;
    this->x = x;
    this->y = y;
}

void Figure::move(const int new_x, const int new_y){
    this->x = new_x;
    this->y = new_y;
}

int Figure::get_id(){
    return id;
}

Figure::~Figure() {}
