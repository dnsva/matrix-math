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
    std::cout<<this<<" was allocated using the Matrix(r,c) constructor\n";
    m_array = new double[rows*cols];
   // std::cout<<"the new matrix: \n"<<*this<<"\n";
   
}

Matrix::Matrix(int rows, int cols, double fill)
{ //todo
}

/* Usually its implicit. Only define if you have to.

Again, we could use the defalt syntax:
Matrix::Matrix(const Matrix& matrix) = default;

Delete can be used if we don't want objects of a certain class to be copyable.
Matrix::Matrix(const Matrix& matrix) = delete;
- This deletes the copy constructor
*/
//Copy Constructor:
Matrix::Matrix(const Matrix& other) 
    : m_rows{other.m_rows}
    , m_cols{other.m_cols}
{

    std::cout<<"Inside the copy constructor for setting object at "<<this<<" from obj "<<&other<<"\n";

    if(m_array != nullptr){
        //std::cout<<m_array<<" is gonna get deleted\n";
        delete[] m_array;
        //std::cout<<"successfully deleted!\n";
    }
    
    int num_elems = other.m_rows*other.m_cols;
    m_array = new double[num_elems];
    for(int i = 0; i < num_elems; i++){
        m_array[i] = other.m_array[i];
    }

}

//Move Constructor:
Matrix::Matrix(Matrix&& other) noexcept
    : m_rows{other.m_rows}
    , m_cols{other.m_cols}
    , m_array{other.m_array}
{
    std::cout<<"Inside the move constructor for setting object at "<<this<<" from rval obj "<<&other<<"\n";
    other.m_rows = 0;
    other.m_cols = 0;
    other.m_array = nullptr;
}

//the = operator:

//Copy Assignment
Matrix& Matrix::operator=(Matrix& other){

    /*
    used in the following scenario:
    Matrix hi{2,3};
    Matrix copy;
    copy = hi;
    
    */

    std::cout<<"Inside the copy assignment operator overload!!!\n";
    std::cout<<"Setting object at "<<this<<" from obj "<<&other<<"\n";
    
    //Detecting self-assignment
    if(&other == this) return *this;

    this->m_rows = other.m_rows;
    this->m_cols = other.m_cols;

    //Below i just directly pasted from the constructor
    if(m_array != nullptr) delete[] m_array;
    
    int num_elems = other.m_rows*other.m_cols;
    m_array = new double[num_elems];
    for(int i = 0; i < num_elems; i++){
        m_array[i] = other.m_array[i];
    }

    return *this;
   
}

//Move Assignment
Matrix& Matrix::operator=(Matrix&& other) noexcept{

    std::cout<<"Inside the move assignment operator overload!!!\n";
    std::cout<<"Setting object at "<<this<<" from obj (rval) "<<&other<<"\n";

    //Detecting self-assignment again
    if(&other == this) return *this;

    //Release any resources we are holding:
    delete[] m_array;

    //Transfer ownership of r value to l value
    m_rows = other.m_rows;
    m_cols = other.m_cols;
    m_array = other.m_array;
    
    other.m_rows = 0;
    other.m_cols = 0;
    other.m_array = nullptr;
    return *this;
}

//Destructor:
Matrix::~Matrix(){
    std::cout<<"Obj at memory: " << this << " got destructed...\n";

    delete[] m_array;
    m_array = nullptr;
}

//Public member functions:
const int& Matrix::get_rows() const {return m_rows;}
const int& Matrix::get_cols() const {return m_cols;}


//Operator overloading for cout

std::ostream& operator<<(std::ostream& out, const Matrix& matrix){

    for(int r = 0; r < matrix.m_rows; ++r){
        for(int c = 0; c < matrix.m_cols; ++c){
            std::cout<< matrix.m_array[r*c + r] <<" ";
        }
        std::cout<<"\n";
    }

    return out; //this is needed so that calls to the operator<< can be chained 
}