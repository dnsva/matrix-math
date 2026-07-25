# Matrix Math — Project Context

## What this is
A C++ matrix math library built from scratch as a learning project. The focus is on understanding C++ fundamentals (memory management, constructors, operator overloading) rather than writing production-ready code.

## Project structure
```
matrix-math/
├── include/Matrix.h        ← class declaration
├── src/Matrix.cpp          ← implementations
├── main.cpp                ← scratch pad / manual testing
├── tests/test_matrix.cpp   ← test suite (currently commented out in CMake)
└── CMakeLists.txt
```

Build system: **CMake**. Executables land in `build/bin/`.
```bash
cmake -B build -S .
cmake --build build
./build/bin/demo
```

## Current state of Matrix.h / Matrix.cpp

### Member variables (private)
```cpp
int m_rows {};
int m_cols {};
double* m_array;   // raw heap array, size = m_rows * m_cols, row-major
```

### Constructors implemented
| Constructor | Notes |
|---|---|
| `Matrix()` | explicitly defaulted (`= default`) |
| `Matrix(int rows, int cols)` | allocates zeroed array with `new` |
| `Matrix(int rows, int cols, double arr[])` | copies values from a plain C array |
| `Matrix(const Matrix& other)` | deep-copy copy constructor |
| `Matrix(Matrix&& other) noexcept` | move constructor, nulls out source |

### Assignment operators
- `operator=(Matrix& other)` — copy assignment (deep copy, self-assignment guard)
- `operator=(Matrix&& other) noexcept` — move assignment (transfers ownership)

### Destructor
Manual `delete[] m_array` with a null-check guard.

### Public member functions
- `get_rows() const` → `const int&`
- `get_cols() const` → `const int&`

### Operator overloads
- `operator<<` — prints the matrix to `std::ostream` (friend, defined in Matrix.cpp)

## What's not done yet
- `get(r, c)` / `set(r, c, val)` accessors
- Arithmetic operators (`+`, `-`, `*`)
- `transpose()`, `determinant()`, `inverse()`
- Bounds checking
- The test suite is written (`tests/test_matrix.cpp`) but disabled in CMakeLists.txt

## Known issues / things to watch
- `operator<<` index formula on line 179 of Matrix.cpp is `r*c + r` — this is wrong for a row-major layout, should be `r * m_cols + c`
- `m_array` is uninitialized in the default constructor — accessing it before assigning is undefined behavior
- Copy constructor checks `if(m_array != nullptr)` before deleting, but `m_array` is uninitialized at that point in a freshly constructed object; this works by luck but is technically UB

## Style / conventions
- `m_` prefix for member variables
- Lots of `std::cout` debug prints intentionally left in (learning aid)
- Comments reference learncpp.com as the primary learning resource
