#include <iostream>
#include "Matrix.h"

int main()
{
    // Matrix test
    City A("A", true, false);
    City B("B", true, false);

    DirectConnection d1(1,2000,50,3000,A,B);

    Matrix m(1);
    m.add_connection(&d1);
    std::cout << m(0,0).get_PlaceA().get_name();



    return 0;
}