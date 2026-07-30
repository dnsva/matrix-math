#include "Matrix.h"

#include <iostream> //cout
#include <stdexcept> //for throwing exceptions

//#include <optional> //for optional arguments 

//Helper fn:
int Matrix::to_index(int r, int c) const{
    return r*m_cols + c;
}

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
    : m_rows{rows}
    , m_cols{cols}
{
    if(rows <= 0 || cols <= 0) throw std::invalid_argument("Can't be negative dimensions!\n");

    std::cout<<this<<" was allocated using the Matrix(r,c) constructor\n";
    m_array = new double[rows*cols](); //the () ensures that you fill w/ 0s
   // std::cout<<"the new matrix: \n"<<*this<<"\n";
   
}

/*NOTE DO NOT USE 0 TO FILL. IF NEED TO FILL W/ 0s, USE THE CONSTRUCTOR r, c*/
Matrix::Matrix(int rows, int cols, double fill)
    : m_rows{rows}
    , m_cols{cols}
{
    if(rows <= 0 || cols <= 0) throw std::invalid_argument("Can't be negative dimensions!\n");
    
    std::cout<<this<<" was allocated using the Matrix(r,c,fill) constructor\n";
    m_array = new double[rows*cols];
    for(int i = 0; i < rows*cols; ++i) m_array[i] = fill;
    //std::cout<<"successfully filled\n";
}
/* 
something to think about - an array of ints could be passed in and it wont compile.
find a way to cast to arr of doubles so that it works too
*/

/*
note: since double arr[] is technically a double*, there is no way to know if rows and cols is accurate
to the size of the arr...

*/
Matrix::Matrix(int rows, int cols, double arr[]) //to the compiler, this is identical as saying double* arr
    
    : m_rows{rows}
    , m_cols{cols}
   
{ 
    if(rows <= 0 || cols <= 0) throw std::invalid_argument("Can't be negative dimensions!\n");

    //std::cout<<"the address of the array from the arg is "<<&arr<<"\n";
    //std::cout<<"m_array now holds "<<&m_array<<"\n";
    std::cout<<this<<" was allocated using the Matrix(r,c,arr) constructor\n";

    m_array = new double[rows*cols];
    for(int i = 0; i < rows*cols; ++i) m_array[i] = arr[i]; /* pre vs post increment: https://www.learncpp.com/cpp-tutorial/increment-decrement-operators-and-side-effects/*/

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

    //Before,  i had delete[] m_array if m_array != nullptr. This isnt necessary
    //because this is a copy CONSTRUCTOR. it shoulnt have existing array data

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

//the = operator: assignment (copy and move)
//Copy Assignment
Matrix& Matrix::operator=(const Matrix& other){

    /*
    used in the following scenario:
    Matrix hi{2,3};
    Matrix copy;
    copy = hi;
    
    */

   /*
   Future to do: use/implement swap function
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

    //if(m_array == nullptr) return; //idk if this is necessary
    /*
    The above isnt necessary. it is actually SAFE to delete nullptrs. 
    See https://en.cppreference.com/cpp/language/delete
    */

    std::cout<<"Obj at memory: " << this << " got destructed...\n";

   // std::cout<<"attemptingn to delete array at "<<m_array<<"\n";
    delete[] m_array;
   // std::cout<<"array now deletd\n";
    m_array = nullptr;

   // std::cout<<"successfully destructed\n";
}

//Public member functions:
int Matrix::get_rows() const {return m_rows;}
int Matrix::get_cols() const {return m_cols;}

double Matrix::get(int r, int c) const {
    if(r >= m_rows  || c >= m_cols ||  r < 0 || c < 0){
        throw std::out_of_range("The indices are out of bounds!");
    }
    return m_array[to_index(r,c)];
}

void Matrix::set(int r, int c, double value){
    if(r >= m_rows  || c >= m_cols ||  r < 0 || c < 0){
        throw std::out_of_range("The indices are out of bounds!");
    }
    m_array[to_index(r,c)] = value;
}

//Operator Overloads

//for cout:
std::ostream& operator<<(std::ostream& out, const Matrix& matrix){

    for(int r = 0; r < matrix.m_rows; ++r){
        for(int c = 0; c < matrix.m_cols; ++c){
            out << matrix.m_array[matrix.to_index(r, c)] <<" ";
        }
        out <<"\n";
    }

    return out; //this is needed so that calls to the operator<< can be chained 
}

/* ARITHMETIC OPERATORS: */

//Addition
//Add the corresponding values of the cells together
Matrix operator+(const Matrix& a, const Matrix& b){
    if(a.m_rows != b.m_rows || a.m_cols != b.m_cols){
        throw std::length_error("The sizes of both matricies must equal each other!");
    }
    Matrix result = a; //should trigger copy consntructor
    for(int i = 0; i < a.m_rows*a.m_cols; i++){
        result.m_array[i] += b.m_array[i];
    }

    return result;
}

Matrix operator-(const Matrix& a, const Matrix& b){
    //copy paste from above with just a sign change
    if(a.m_rows != b.m_rows || a.m_cols != b.m_cols){
        throw std::length_error("The sizes of both matricies must equal each other!");
    }
    Matrix result = a; //should trigger copy consntructor
    for(int i = 0; i < a.m_rows*a.m_cols; i++){
        result.m_array[i] -= b.m_array[i];
    }

    return result;
}

//Multiply
Matrix operator*(const Matrix& a, double scalar){
    Matrix result = a;
    for(int i = 0; i < result.m_rows*result.m_cols; ++i){
        result.m_array[i] *= scalar;
    }
    return result;
}

Matrix operator*(double scalar, const Matrix& a){
    return a*scalar; //call above
}

Matrix operator*(const Matrix& a, const Matrix& b){ 
    //throw error if dims are incorrect
    //a.m_cols must equal b.m_rows
    if(a.m_cols != b.m_rows) throw std::length_error("First matrices columns must equal the second matrices rows");

    std::cout<<"inside * operator overload\n";
    Matrix result{a.m_rows, b.m_cols}; //fill w/ 0 is done
    //std::cout<<"Test\n";
    int curr_result_cell = 0;
    //std::cout<<"about to enter the loops\n";
    for(int a_row = 0; a_row < a.m_rows; ++a_row){
        //std::cout<<"in row for loop : "<<a_row<<"\n";
        for(int b_col = 0; b_col < b.m_cols; ++b_col){
           // std::cout<<"in col for loop : "<<b_col<<"\n";
            for(int k = 0; k < a.m_cols; ++k){ //or b.m_cols
                /* calculates the dot product of the row and col */
               //result.m_array[curr_result_cell] += a.m_array[a_row*a.m_cols + k] * b.m_array[k*b.m_cols + b_col];
               result.m_array[curr_result_cell] += a.m_array[a.to_index(a_row, k)] * b.m_array[b.to_index(k, b_col)];
            }
            ++curr_result_cell; 
        }
    }

    return result;

}

bool operator==(const Matrix& a, const Matrix& b){

    if(a.m_rows != b.m_rows || a.m_cols != b.m_cols){
        return false; //diff sizes automatically means theyre not the same.
    }

    for(int i = 0; i < a.m_rows*a.m_cols; ++i){
        /* epsilon = 1e-9*/
        if(std::abs(a.m_array[i] - b.m_array[i]) > 1e-9) return false; //use epsilon comparison in case there are small rounding differences between floats
    }
    return true;
}

bool operator!=(const Matrix& a, const Matrix& b){
    return !(a == b);
}

/* ACTUAL MATH FUNCTIONS: ------------------------------- */

Matrix Matrix::transpose() const{ //flip rows and cols 

    /*
    An operation that flips a matrix over its diagonal
    */

    Matrix new_matrix {m_cols, m_rows}; //(m,n) matrix turns inito (n,m) matrix

    for(int r = 0; r < m_rows; r++){
        for(int c = 0; c < m_cols; c++){
            new_matrix.m_array[to_index(c,r)] =  m_array[to_index(r,c)]; //no need to call set() since the rs and cs are guarranteed within range
        }
    }

    return new_matrix;
}

Matrix Matrix::identity(int dim){

    if(dim <= 0) throw std::out_of_range("The indices are out of bounds!");

    Matrix identity_matrix{dim, dim, 0.0};

    for(int i = 0; i < dim; ++i){
        identity_matrix.m_array[identity_matrix.to_index(i,i)] = 1.0;
    }

    return identity_matrix;

}

