#include <iostream>
#include "Matrix.h"

int main()
{
    // // Matrix test
    // City A("A", true, false);
    // City B("B", true, false);
    // City C("C", true, false);
    // City D("D", true, false);

    // DirectConnection d_AB(1,2000,50,3000,A,B);
    // DirectConnection d_BC(2,2000,50,3000,B,C);
    // DirectConnection d_BD(2,2000,50,3000,B,D);

    // Matrix m;
    // m.add_connection(&d_AB);
    // std::cout << m.get_size() << std::endl;
    // std::cout << m.get_cities()[1].get_name() << std::endl;
    // // if(m.isCity(A)) std::cout << "kupa";

    // m.add_connection(&d_BC);
    // std::cout << m.get_size() << std::endl;
    // m.add_connection(&d_BD);
    // std::cout << m.get_size() << std::endl;

    // m.print();

    // std::cout << m(A,B)->get_PlaceA().get_name() << std::endl;
    // std::cout << m(B,C)->get_PlaceB().get_name() << std::endl;
    // std::cout << m(B,D)->get_PlaceB().get_name() << std::endl;

    // if(m(A,D) == nullptr)
    // std::cout << "DUPA" << std::endl;
    // else
    // std::cout << "DZIALA" << std::endl;


    // TESTS OF MATRIX

    std::cout << "MATRIX TEST" << std::endl << std::endl;

    Matrix matrix;
    City Krakow("Krakow", false, true);
    City Warszawa("Warszawa", false, true);
    City Gdynia("Gdynia", false, true);
    City Wroclaw("Wroclaw", false, true);


    // Test 0 - Creating an empty matrix
    if(matrix.get_size() != 0)
    std::cerr << "MATRIX: TEST 0 - FAILED" << std::endl;

    if(matrix(Krakow, Warszawa) != nullptr)
    std::cerr << "MATRIX: TEST 0 - FAILED" << std::endl;


    // Test 1 - Adding connection to matrix
    DirectConnection Krakow_Warszawa(1,300000,80,240,Krakow,Warszawa);
    matrix.add_connection(&Krakow_Warszawa);

    if(matrix.get_size() != 2)
    std::cerr << "MATRIX: TEST 1 - FAILED" << std::endl;

    try
    {
        matrix(Krakow, Warszawa);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() <<"MATRIX: TEST 1 - FAILED" << std::endl;
    }

    if(matrix(Krakow,Warszawa)->get_connection_id()!=1)
    std::cerr << "MATRIX: TEST 1 - FAILED" << std::endl;


    // Test 2 - Adding more matrix



    return 0;
}