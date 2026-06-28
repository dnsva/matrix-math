cmake_minimum_required(VERSION 3.15)
project("Matrix Math")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# write all executables into this directory:
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

# Shared library target — reused by both the demo and tests
add_library(matrix_lib src/Matrix.cpp)
target_include_directories(matrix_lib PUBLIC include)
target_compile_options(matrix_lib PRIVATE -Wall -Wextra)

# Demo executable
add_executable(demo main.cpp)
target_link_libraries(demo PRIVATE matrix_lib)

# Test executable
# add_executable(tests tests/test_matrix.cpp)
# target_link_libraries(tests PRIVATE matrix_lib)



