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

    /*
    double matrix_vals[] = {2, 3, 4, 1, 2, 3};
    std::cout<<"matrix_vals[] addy: "<<&matrix_vals<<"\n";

    Matrix hi2{2,3, matrix_vals};
    std::cout<<"hiiii\n";
    std::cout<<"the matrix is \n"<<hi2<<"\n";
    */
    //hi2.set(0, 4, 3);

    //Addition/Sub Operator Test
    std::cout<<"test - addition + operator\n";

    double a_list[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Matrix a {3, 3, a_list};

    double b_list[] = {9, 8, 7, 6, 5, 4, 3,  2, 1};
    Matrix b {3, 3, b_list};

        /* exception thrown:
            double b_list[] = {9, 8, 7, 6, 5, 4};
            Matrix b {3, 2, b_list};
        */

    std::cout<<"adding:\n"<<a+b<<"subtracting:\n"<<a-b<<"\n";

    /* mult */
    std::cout<<"MULT: "<<a*b<<"\n";


    return 0;
}
