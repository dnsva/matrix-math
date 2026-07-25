#include "Matrix.h"
#include <iostream>

int main() {

    //Matrix hi{2,3};

    //Matrix hi{2,3};
    //Matrix test{};
    //std::cout<<"hi";

   // Matrix copy = hi;
    //Matrix copy{hi};
   // std::cout<<copy.get_rows()<<"\n";

   // Matrix copy = std::move(hi);


    double matrix_vals[] = {2, 3, 4, 1, 2, 3};
    std::cout<<"matrix_vals[] addy: "<<&matrix_vals<<"\n";

    Matrix hi2{2,3, matrix_vals};
    std::cout<<"hiiii\n";
    std::cout<<"the matrix is \n"<<hi2<<"\n";
    return 0;
}
