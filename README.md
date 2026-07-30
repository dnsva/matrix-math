# Matrix Math

This library is for dealing with matrices, with a lot of comments throughout documenting what I learn about c++. I am mainly learning from [learncpp.com](www.learncpp.com/), a great online resource I found.

**A note on AI:** No autocomplete, no AI writing code. I wanted this project to be purely a learning opportunity for myself.

- `Matrix.h` is the header file for the Matrix class
- `Matrix.cpp` is the implementation file

Currently testing the functions in `main.cpp`. The true testing phase of this project hasn't started yet - I am still implementing the class.

**Another note:** The data types and implementations are fairly primitive, so this library isn't intended for heavy and big matrices. 

**<u>Currently Implemented:</u>**
- Constructors
- Rule of 5 (copy constructor, move constructor, copy assignment operator, move assignment operator, destructor)
- Getters and Setter member functions (`get_rows`, `get_cols`, `get(r,c)`, `set(r,c,value)`)
- Operator overloads (e.g., `<<` (for cout), `+`, `-`, `*`, `==`, `!=`)
- Math functions (e.g., transpose, identity)

___

## Miscellaneous Learning Notes:

### classes and header files

> "Best practice: Prefer to put your class definitions in a header file with the same name as the class. Trivial member functions (such as access functions, constructors with empty bodies, etc…) can be defined inside the class definition. Prefer to define non-trivial member functions in a source file with the same name as the class."

Source: [learncpp.com](https://www.learncpp.com/cpp-tutorial/classes-and-header-files/)

### what is `this`
- `this` is a pointer to the current object that the member fn was called on

`Matrix* this;`
- `this` is a pointer to Matrix
- you can change Matrix and you could also change where the pointer is pointing to.
- this never actually exists in code

`Matrix* const this;`
- `this` is a CONST pointer to Matrix
- you can change Matrix but you cannot change where the pointer is pointing to.
- this is how it is for a regular member function.

`const Matrix* const this;`
- this` is a CONST pointer to a CONST Matrix
- you cannot change Matrix or the pointer itself.
- this is how it is for a const member function.

### `const` member function

> "A const member function is a member function that guarantees it will not modify the object or call any non-const member functions (as they may modify the object)."

Source: [learncpp.com](https://www.learncpp.com/cpp-tutorial/const-class-objects-and-const-member-functions/)

```cpp
class Matrix {
public:
    int rows() const  // const member function -- cannot modify the object
    {
        return rows_;
    }

private:
    int rows_;
};
```

### const member functions can't return non-const references to data members

> "A const member function is not allowed to return a non-const reference to members. This makes sense -- a const member function is not allowed to modify the state of the object, nor is it allowed to call functions that would modify the state of the object. It should not be doing anything that might lead to the modification of the object.
>
> If a const member function was allowed to return a non-const reference to a member, it would be handing the caller a way to directly modify that member. This violates the intent of a const member function."

Source: [learncpp.com](https://www.learncpp.com/cpp-tutorial/member-functions-returning-references-to-data-members/)

### Rule of 3 and Rule of 5

> The rule of three is a well known C++ principle that states that if a class requires a user-defined copy constructor, destructor, or copy assignment operator, then it probably requires all three. In C++11, this was expanded to the rule of five, which adds the move constructor and move assignment operator to the list.

Source: [learncpp.com](https://www.learncpp.com/cpp-tutorial/introduction-to-the-copy-constructor/)

> The rule of five says that if the copy constructor, copy assignment, move constructor, move assignment, or destructor are defined or deleted, then each of those functions should be defined or deleted.

Source: [learncpp.com](https://www.learncpp.com/cpp-tutorial/move-constructors-and-move-assignment/)

### `explicit` keyword (not used in this project)

Making a constructor explicit has two notable consequences:
- An explicit constructor cannot be used to do copy initialization or copy list initialization.
- An explicit constructor cannot be used to do implicit conversions (since this uses copy initialization or copy list initialization).

Source: [learncpp.com](https://www.learncpp.com/cpp-tutorial/converting-constructors-and-the-explicit-keyword/)

### std::move()

```cpp
    // Constructor is called
    Geeks obj1(42);              
    // Move constructor is called
    Geeks obj2 = std::move(obj1); 

    cout << "\nAfter move:\n";
    cout << "obj1: ";
    // Should show "No data"
    obj1.display();              
    cout << "obj2: ";
    // Should show "Value: 42"
    obj2.display(); 
```
Code block from: [geeksforgeeks.org](https://www.geeksforgeeks.org/cpp/move-constructors-in-c-with-examples/)

> Once you start using move semantics more regularly, you’ll start to find cases where you want to invoke move semantics, but the objects you have to work with are l-values, not r-values. 

> In C++11, `std::move` is a standard library function that casts (using static_cast) its argument into an r-value reference, so that move semantics can be invoked. Thus, we can use `std::move` to cast an l-value into a type that will prefer being moved over being copied. `std::move` is defined in the utility header.

Source: [learncpp.com](https://www.learncpp.com/cpp-tutorial/stdmove/)

### Implicit move constructor and move assignment operator (learncpp.com)

The compiler will create an implicit move constructor and move assignment operator if all of the following are true:
- There are no user-declared copy constructors or copy assignment operators.
- There are no user-declared move constructors or move assignment operators.
- There is no user-declared destructor.
These functions do a memberwise move, which behaves as follows:

    If member has a move constructor or move assignment (as appropriate), it will be invoked. Otherwise, the member will be copied.
Notably, this means that pointers will be copied, not moved!

Warning:
The implicit move constructor and move assignment will copy pointers, not move them. If you want to move a pointer member, you will need to define the move constructor and move assignment yourself.

Source: [learncpp.com](https://www.learncpp.com/cpp-tutorial/move-constructors-and-move-assignment/)

### returning const reference or just reference VS by copy:

Read https://www.learncpp.com/cpp-tutorial/return-by-reference-and-return-by-address/

Remember: Return by reference for expensive-to-copy members and by value for cheap-to-copy types

"Cheap-to-copy types": `int`, `float`, `double`, `bool`, `char`, enums, pointers

### Random Cool Things:

C++16 has `std::optional<T>` which can either have a value of type T, or not. 

