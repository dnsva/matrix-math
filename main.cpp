#include "Matrix.h"
#include <iostream>

int main() {

    //Matrix hi{2,3};

    Matrix hi{2,3};
    //Matrix test{};
    //std::cout<<"hi";

   // Matrix copy = hi;
    //Matrix copy{hi};
   // std::cout<<copy.get_rows()<<"\n";

    Matrix copy = std::move(hi);
    return 0;
}
