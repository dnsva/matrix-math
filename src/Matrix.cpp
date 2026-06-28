#include "Matrix.h"

#include <iostream> //cout

//Constructors:
/*
- members in a member initializer list are always initialized in the order in which they are defined inside the class (not in the order they are defined in the member initializer list (learncpp.com)
*/

Matrix::Matrix(int rows, int cols)
    : m_rows{rows} // values are initialized to 0
    , m_cols{cols} // aka 0-initialized
{
}

Matrix::Matrix(int rows, int cols, double fill)
{ //todo
}


//Destructor:
Matrix::~Matrix(){
    std::cout<<"Obj at memory: " << this << " got destructed...\n";
}

//Public member functions:
const int& Matrix::get_rows() const {return m_rows;}
const int& Matrix::get_cols() const {return m_cols;}