# Matrix Math

This library is mainly for learning purposes. 

I will write the useful stuff I learn in each file so there will be alot of comments. This is basically my notes. 

I am learning from www.learncpp.com/

No AI used in this project to write code


# Some Notes (Not in code files):

### what is this

> `this` is a pointer to the current object that the member fn was called on

`Matrix* this;`
> `this` is a pointer to Matrix
> You can change Matrix and you could also change where the pointer is pointing to.
> this never actually exists in code

`Matrix* const this;`
> `this` is a CONST pointer to Matrix
> You cann change Matrix but you cannot change where the pointer is pointing to.
> This is how it is for a regular member function.

`const Matrix* const this;`
> `this` is a CONST pointer to a CONST Matrix
> You cannot change Matrix or the pointer itself.
> This is how it is for a const member function.

### std::move()

From [geeksforgeeks.org](https://www.geeksforgeeks.org/cpp/move-constructors-in-c-with-examples/)
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
Once you start using move semantics more regularly, you’ll start to find cases where you want to invoke move semantics, but the objects you have to work with are l-values, not r-values. 

In C++11, std::move is a standard library function that casts (using static_cast) its argument into an r-value reference, so that move semantics can be invoked. Thus, we can use std::move to cast an l-value into a type that will prefer being moved over being copied. std::move is defined in the utility header.

[learncpp.com](https://www.learncpp.com/cpp-tutorial/stdmove/)

### Implicit move constructor and move assignment operator (learncpp.com)

The compiler will create an implicit move constructor and move assignment operator if all of the following are true:

- There are no user-declared copy constructors or copy assignment operators.
- There are no user-declared move constructors or move assignment operators.
- There is no user-declared destructor.

These functions do a memberwise move, which behaves as follows:

- If member has a move constructor or move assignment (as appropriate), it will be invoked. Otherwise, the member will be copied.

Notably, this means that pointers will be copied, not moved!

Warning:
The implicit move constructor and move assignment will copy pointers, not move them. If you want to move a pointer member, you will need to define the move constructor and move assignment yourself.

[learncpp.com](https://www.learncpp.com/cpp-tutorial/move-constructors-and-move-assignment/)

### const member function

> "A const member function is a member function that guarantees it will not modify the object or call any non-const member functions (as they may modify the object)."
>
> -- [learncpp.com](https://www.learncpp.com/cpp-tutorial/const-class-objects-and-const-member-functions/)

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

### classes and header files

> "Best practice: Prefer to put your class definitions in a header file with the same name as the class. Trivial member functions (such as access functions, constructors with empty bodies, etc…) can be defined inside the class definition. Prefer to define non-trivial member functions in a source file with the same name as the class."
>
> -- [learncpp.com](https://www.learncpp.com/cpp-tutorial/classes-and-header-files/)

### const member functions can't return non-const references to data members

> "A const member function is not allowed to return a non-const reference to members. This makes sense -- a const member function is not allowed to modify the state of the object, nor is it allowed to call functions that would modify the state of the object. It should not be doing anything that might lead to the modification of the object.
>
> If a const member function was allowed to return a non-const reference to a member, it would be handing the caller a way to directly modify that member. This violates the intent of a const member function."
>
> -- [learncpp.com](https://www.learncpp.com/cpp-tutorial/member-functions-returning-references-to-data-members/)

# `explicit` keyword (not used in this project)

> Making a constructor explicit has two notable consequences:

- An explicit constructor cannot be used to do copy initialization or copy list initialization.
- An explicit constructor cannot be used to do implicit conversions (since this uses copy initialization or copy list initialization).

> -- [learncpp.com](https://www.learncpp.com/cpp-tutorial/converting-constructors-and-the-explicit-keyword/)

# Rule of 3 and Rule of 5

> The rule of three is a well known C++ principle that states that if a class requires a user-defined copy constructor, destructor, or copy assignment operator, then it probably requires all three. In C++11, this was expanded to the rule of five, which adds the move constructor and move assignment operator to the list.
>
> -- [learncpp.com](https://www.learncpp.com/cpp-tutorial/introduction-to-the-copy-constructor/)

> The rule of five says that if the copy constructor, copy assignment, move constructor, move assignment, or destructor are defined or deleted, then each of those functions should be defined or deleted.
> -- [learncpp.com](https://www.learncpp.com/cpp-tutorial/move-constructors-and-move-assignment/)

# Random Cool Things:

C++16 has `std::optional<T>` which can either have a value of type T, or not. 

# returning const reference or just reference VS by copy:
Read https://www.learncpp.com/cpp-tutorial/return-by-reference-and-return-by-address/

Remember: Return by reference for expensive-to-copy members and by value for cheap-to-copy types

"Cheap-to-copy types": `int`, `float`, `double`, `bool`, `char`, enums, pointers


# Continue from:
