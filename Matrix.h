#pragma once
#include "DirectConnection.h"
#include<sstream>

class Matrix
{
private:

    DirectConnection ***p;
    unsigned int size;
    std::vector<City> cites;

    //private method using by other methods
    void extend_matrix();


public:

    //constructors
    Matrix();
    Matrix(Matrix const& matrix_to_copy);

    //geters
    unsigned int get_size() const { return size; }
    std::vector<City> get_cities() const { return cites; }

    //operators
    Matrix & operator=(Matrix const& matrix_to_assign);
    DirectConnection* operator()(City const& CityA, City const& CityB);
    DirectConnection* operator()(int i, int j);


    void add_connection(DirectConnection *cnt);
    bool isCity(City const& city) const;

    //stream methods
    std::string description() const;
    void print_matrix();

    //method to clean whole matrix
    void clean();

    //destrucotr
    ~Matrix();

};


