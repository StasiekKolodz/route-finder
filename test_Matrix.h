#include <iostream>
#include "Matrix.h"
#include "DataBase.h"
#include <vector>
#include "enums.h"
#include "RouteFinder.h"

using namespace std;

int test_Matrix()
{

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
    else if(matrix(Krakow, Warszawa) != nullptr)
    std::cerr << "MATRIX: TEST 0 - FAILED" << std::endl;
    else
    std::cerr << "MATRIX: TEST 0 - PASSED" << std::endl;


    // Test 1 - Adding connection to matrix
    DirectConnection Krakow_Warszawa(1,300000,80,240,Krakow,Warszawa,Bus);
    matrix.add_connection(&Krakow_Warszawa);

    if(matrix.get_size() != 2)
    std::cerr << "MATRIX: TEST 1 - FAILED" << std::endl;
    else if(matrix(Krakow,Warszawa)->get_connection_id()!=1)
    std::cerr << "MATRIX: TEST 1 - FAILED" << std::endl;
    else
    std::cerr << "MATRIX: TEST 1 - PASSED" << std::endl;


    // Test 2 - Adding more matrix
    DirectConnection Warszawa_Gdynia(2,250000,45,180,Warszawa,Gdynia, Bus);
    DirectConnection Wroclaw_Krakow(3,250000,45,180,Wroclaw,Krakow, Bus);
    matrix.add_connection(&Warszawa_Gdynia);
    matrix.add_connection(&Wroclaw_Krakow);

    if(matrix.get_size() != 4)
    std::cerr << "MATRIX: TEST 2 - FAILED" << std::endl;
    else if(matrix(Warszawa, Gdynia)->get_connection_id() != 2 || matrix(Krakow, Wroclaw)->get_connection_id() != 3)
    std::cerr << "MATRIX: TEST 2 - FAILED" << std::endl;
    else if(matrix(Gdynia, Krakow) != nullptr)
    std::cerr << "MATRIX: TEST 2 - FAILED" << std::endl;
    else
    std::cerr << "MATRIX: TEST 2 - PASSED" << std::endl;

    return 0;
}