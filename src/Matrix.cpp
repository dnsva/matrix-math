#include "Matrix.h"

#include <iostream> //cout

//Constructors:
/*
- Members in a member initializer list are always initialized in the order in which they are defined inside the class (not in the order they are defined in the member initializer list 
- Once the member initializer list has finished executing, the object is considered initialized. Once the function body has finished executing, the object is considered constructed.
- Source: (learncpp.com)
*/

/*
    Default constructor implicitly generated:
    Matrix()
    {
    }

    To explicitly generate use: = default;
    Matrix() = default; // generates an explicitly defaulted default constructor

*/

Matrix::Matrix() = default; /* Prefer an explicitly defaulted default constructor (= default) over a default constructor with an empty body. (learncpp.com)*/

Matrix::Matrix(int rows, int cols)
    /* u could do: (int rows=0, int cols=0) to act as a default constructor */
    : m_rows{rows} // values are initialized to 0
    , m_cols{cols} // aka 0-initialized
{
}

Matrix::Matrix(int rows, int cols, double fill)
{ //todo
}

/* Using implcit copy constrctor instead of the one below.
Matrix::Matrix(const Matrix& other) 
    : m_rows{other.m_rows}
    , m_cols{other.m_cols}
{
}

Again, we could use the defalt syntax:
Matrix::Matrix(const Matrix& matrix) = default;

Delete can be used if we don't want objects of a certain class to be copyable.
Matrix::Matrix(const Matrix& matrix) = delete;
- This deletes the copy constructor
*/



//Destructor:
Matrix::~Matrix(){
    std::cout<<"Obj at memory: " << this << " got destructed...\n";
}

//Public member functions:
const int& Matrix::get_rows() const {return m_rows;}
const int& Matrix::get_cols() const {return m_cols;}