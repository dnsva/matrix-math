#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

//this file only does declarations
//everything is implemented in Matrix.cpp

class Matrix {
private:

    /*
    - "m_" prefix is a very common C++ naming convention for  member variables (data members).
    - “s_” prefix - for local static variables
    - “g_” prefix - for globals
    */

    int m_rows {};
    int m_cols {};

    //Array to store the 2d matrix:
    double* m_array = nullptr; //must set to nullptr first otherwise copy constructor will delete what doesnt have values. copy constructor checks if array address is nullptr


public:

    //Constructor Definitions:
    /*
    - Constructors don't have a return type
    */
    Matrix(); //explicitly default constructor
    Matrix(int rows, int cols);
    Matrix(int rows, int cols, double arr[]); //populate matrix w 1D array

    //Copy Constructor:
    /*
    A copy constructor would be called in the following example:
        Matrix matrix1 {2, 2};
        Matrix matrix2 {matrix1}; //copy constructor is called

    A copy constructor is a constructor that is used to initialize an object with an existing object
    of the same type. After the copy constructor executes, the newly created object should be a copy
    of the object passed in as the initializer.
    Source: (learncpp.com)

        - If an object is passed by value as an argument, it is always passed in as a copy
    */
    //Best Practice: Prefer the implicit copy constructor, unless you have a specific reason to create your own. Source: (learncpp.com)
    Matrix(const Matrix& other); //parameter should be a lvalue reference or const lvalue reference

    //Move Constructor:
    //transfer ownership
    /*
    about noexcept - Move constructors and move assignment should be marked as noexcept. This tells the compiler that these functions will not throw exceptions. (learncpp.com)
    */
    Matrix(Matrix&& other) noexcept;

    //Copy Assignment
    Matrix& operator=(const Matrix& other);

    //Move Assignment - transfer ownership
    Matrix& operator=(Matrix&& other) noexcept;

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
    const int& get_rows() const; //the second const keyword is the "member function const qualifier"
    const int& get_cols() const; //this promises not to modify the object it is being called on
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
    


    //For operator overloading on cout it needs to be a friend to access the members directly
    friend std::ostream& operator<<(std::ostream& out, const Matrix& matrix);
};

#endif