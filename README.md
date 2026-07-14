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



# Random Cool Things:

C++16 has `std::optional<T>` which can either have a value of type T, or not. 