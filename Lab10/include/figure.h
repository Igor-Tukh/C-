#pragma once

class Figure {
  public:
    Figure(int id, int x, int y);
    virtual ~Figure();

    virtual void print() const = 0;
    virtual bool is_inside(const int x, const int y) const = 0;
    virtual void zoom(const int factor) = 0;
    void move(const int new_x, const int new_y);
    int get_id();
    
  protected:
    int id;
    int x;
    int y;
};
