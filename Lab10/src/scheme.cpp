#include "scheme.h"
#include <utility>
#include <cstddef>

Scheme::Scheme(int capacity){
    figures_ = new Figure*[capacity];
    sz = 0;
}

Scheme::~Scheme(){
    
    for(int i = 0; i < sz; i++)
        delete figures_[i];

    delete [] figures_;
}

void Scheme::push_back_figure(Figure* fg){
    figures_[sz++] = fg;
}

void Scheme::remove_figure(const int id){
    for(int i = 0; i < sz; i++)
        if (id == figures_[i]->get_id()){
            for(int j = i; j < sz; j++)
                std::swap(figures_[j], figures_[j + 1]);
            delete figures_[sz];
            sz--;
            break;
        }
}

void Scheme::print_all_figures(){
    for(int i = 0; i < sz; i++)
        figures_[i]->print();
}

void Scheme::zoom_figure(const int id, const int factor){
    for(int i = 0; i < sz; i++)
        if (figures_[i]->get_id() == id)
            figures_[i]->zoom(factor);
}

Figure* Scheme::is_inside_figure(const int x, const int y){
    for(int i = 0; i < sz; i++)
        if (figures_[i]->is_inside(x, y))
            return figures_[i];
            
    return NULL;
}

void Scheme::move(const int id, const int new_x, const int new_y){
    for(int i = 0; i < sz; i++){
        if (figures_[i]->get_id() == id)
            figures_[i]->move(new_x, new_y);
    }
}
