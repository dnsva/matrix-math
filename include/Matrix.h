#ifndef MATRIX_H
#define MATRIX_H

//this file only does declarations
//everything is implemented in Matrix.cpp

class Matrix {
private:

    /*
    - "m_" prefix is a very common C++ naming convention for  member variables (data members).
    - “s_” prefix - for local static variables
    - “g_” prefix - for globals
    */

    int m_rows{};
    int m_cols{};

public:

    //Constructor Definitions:
    /*
    - Constructors don't have a return type
    */
    Matrix(int rows, int cols);
    Matrix(int rows, int cols, double fill);

    //Access Functions:
    /*
    - GETTERS aka ACCESSORS:
        - public member fns that return the value of a member variable
    - SETTERS aka MUTATORS:
        - public member fns that set the value of a private member variable
    
    */
    //Some constant member functions (which are also getters):
    /*
        From learncpp.com:
        Since member functions are always called on an object, and that object must
        exist in the scope of the caller, it is generally safe for a member function
        to return a data member by (const) lvalue reference (as the member being
        returned by reference will still exist in the scope of the caller when the
        function returns).

    - Instead of using int&, we can also use auto& 
    - This avoids conversions

    - Why const:
        - A member function that returns a non-const reference provides direct access to that member
    */
    const int& get_rows() const;
    const int& get_cols() const;
    //Setters:
    //to do...
    /*
    rows and col change. if bigger than current than just extend. if not then throw exception? warning? and cutt off the data? 
    */


    //Destructor:
    /*
    - Must have the same name as the class, preceded by a tilde (~).
    - Can not take arguments.
    - No return type.
    */
    ~Matrix();
    
};

#endif