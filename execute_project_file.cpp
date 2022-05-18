#include <iostream>
#include "Matrix.h"

int main()
{
    // Matrix test
    City A("A", true, false);
    City B("B", true, false);
    City C("C", true, false);
    City D("D", true, false);

    DirectConnection d_AB(1,2000,50,3000,A,B);
    DirectConnection d_BC(2,2000,50,3000,B,C);
    DirectConnection d_BD(2,2000,50,3000,B,D);

    Matrix m;
    m.add_connection(&d_AB);
    std::cout << m.get_size() << std::endl;
    std::cout << m.get_cities()[1].get_name() << std::endl;
    // if(m.isCity(A)) std::cout << "kupa";

    m.add_connection(&d_BC);
    std::cout << m.get_size() << std::endl;
    m.add_connection(&d_BD);
    std::cout << m.get_size() << std::endl;

    m.print();

    std::cout << m(A,B)->get_PlaceA().get_name() << std::endl;
    std::cout << m(B,C)->get_PlaceB().get_name() << std::endl;
    std::cout << m(B,D)->get_PlaceB().get_name() << std::endl;

    if(m(A,D) == nullptr)
    std::cout << "DUPA" << std::endl;
    else
    std::cout << "DZIALA" << std::endl;

    return 0;
}