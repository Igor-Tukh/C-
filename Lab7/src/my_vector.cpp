#include "my_vector.h"
#include <cassert>
#include <utility>

MyVector::MyVector(){
    _cp = 2;
    _sz = 0;
    _data = new int[2];
}

MyVector::MyVector(std::size_t init_capacity){
    _cp = init_capacity;
    _sz = 0;
    _data = new int[init_capacity];
}

MyVector::~MyVector(){
    _cp = 0;
    _sz = 0;
    delete[]_data;    
}

void MyVector::set(std::size_t index, int value){
    assert (index < _sz && "MyVector::set: Index out of range"); 
    _data[index] = value;
}

int MyVector::get(std::size_t index){    
    assert (index < _sz && "MyVector::get: Index out of range");
    return _data[index];
}

std::size_t MyVector::size(){
    return _sz;
}

std::size_t MyVector::capacity(){
    return _cp;
}  


void MyVector::reserve(std::size_t new_capacity){
    if (new_capacity > _cp){
        int * buf = new int[new_capacity];
        for(std::size_t i = 0; i < _sz; i++) buf[i] = _data[i];
        delete[]_data;
        _data = buf;
        _cp = new_capacity;
    }
}

void MyVector::push_back(int value){
    if (_sz == _cp) this -> reserve(2 * _cp);
    _data[_sz] = value;
    _sz++;
}
  
void MyVector::resize(std::size_t new_size){
    for(std::size_t i = _sz; i < new_size; i++){
        this -> push_back(0);
    }
    
    _sz = new_size;    
}

void MyVector::insert(std::size_t index, int value){
    assert (index <= _sz && "MyVector::insert: Index out of range"); 
   
    int cur = value;
    for(std::size_t i = index; i < _sz; i++){
        std::swap(cur, _data[i]);
    } 
    
    
    this -> push_back(cur);
}

void MyVector::erase(std::size_t index){
    assert (index < _sz && "MyVector::erase: Index out of range"); 
    
    for(std::size_t i = _sz - 1; i > index; i--){
        std::swap(_data[i - 1], _data[i]);
    }
    
    _sz--;    
}
