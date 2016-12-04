#include "figure.h"

class Rectangle : public Figure {
public:
    Rectangle(int id, int x, int y, int width, int height);
    
    void print() const ;
    bool is_inside(const int x, const int y) const;
    void zoom(const int factor);
private:
    int w;
    int h;
};
