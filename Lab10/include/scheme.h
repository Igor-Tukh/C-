#pragma once

#include "figure.h"
#include <map>

class Scheme{
  public:
    Scheme(int capacity); 
    ~Scheme();

    void push_back_figure(Figure* fg);
    void remove_figure(const int id);

    void print_all_figures();
    void zoom_figure(const int id, const int factor);
    Figure* is_inside_figure(const int x, const int y);
    void move(const int id, const int new_x,const int new_y);

  private:  
    Figure** figures_;
    int sz;
    int cp;
};
