#include "matrix.h"
#include <utility>
#include <string.h>

Matrix::Matrix(const Matrix& m) {
  _rows = m._rows;
  _cols = m._cols;
  
  _data = new int*[_rows];
  for(std::size_t i = 0; i < _rows; i++) {
    _data[i] = new int[_cols];
    memcpy(_data[i], m._data[i], _cols * sizeof(int));
  }
}

Matrix::Matrix(std::size_t r, std::size_t c) {
  _rows = r;
  _cols = c;
  
  _data = new int*[r];
  
  for(std::size_t i = 0; i < r; i++)
    _data[i] = new int[c]();
}

std::size_t Matrix::get_rows() const { return _rows; }
std::size_t Matrix::get_cols() const { return _cols; }

void Matrix::set(std::size_t i, std::size_t j, int val) {
  _data[i][j] = val;
}

int Matrix::get(std::size_t i, std::size_t j) const {
  return _data[i][j];
}

void Matrix::print(FILE* f) const {
  for(std::size_t i = 0; i < _rows; i++){ 
    for(std::size_t j = 0; j < _cols; j++)
      fprintf(f, "%d ", _data[i][j]); 
    fprintf(f, "\n");
  }
}

Matrix Matrix::operator=(const Matrix& m) {
  if (*this != m){
    Matrix tmp = Matrix(m);
    (*this).swap(tmp);
  }
  return (*this);  
}

Matrix Matrix::operator+(const Matrix& m) const {
  Matrix ans = *this;
  ans += m;
  return ans;
}

Matrix Matrix::operator-(const Matrix& m) const {
  Matrix ans = *this;
  ans -= m;
  return ans; 
}

Matrix Matrix::operator*(const Matrix& m) const {
  Matrix ans = Matrix(_rows, m._cols);
  
  for(std::size_t i = 0; i < _rows; i++)
    for(std::size_t j = 0; j < _cols; j++)
      for(std::size_t k = 0; k < m._cols; k++)
        ans._data[i][k] += _data[i][j] * m._data[j][k];
        
  return ans;
}

Matrix& Matrix::operator+=(const Matrix& m) {
  for(std::size_t i = 0; i < _rows; i++)
    for(std::size_t j = 0; j < _cols; j++)
      _data[i][j] += m._data[i][j];
  
  return *this;
}

Matrix& Matrix::operator-=(const Matrix& m) {
  for(std::size_t i = 0; i < _rows; i++)
    for(std::size_t j = 0; j < _cols; j++)
      _data[i][j] -= m._data[i][j];
      
  return *this;  
}

Matrix& Matrix::operator*=(const Matrix& m) {
  (*this) = (*this) * m;
  return *this; 
}

bool Matrix::operator==(const Matrix& m) const {
  for(std::size_t i = 0; i < _rows; i++)
    for(std::size_t j = 0; j < _cols; j++)
      if (_data[i][j] != m._data[i][j])
        return false;
  
  return true;
}

bool Matrix::operator!=(const Matrix& m) const {
  return !(*this == m);  
}

Matrix::~Matrix() {
  for(std::size_t i = 0; i < _rows; i++)
    delete [] _data[i];
  delete [] _data;
}


void Matrix::swap(Matrix& m) {
  std::swap(_rows, m._rows);
  std::swap(_cols, m._cols);
  std::swap(_data, m._data);
}
