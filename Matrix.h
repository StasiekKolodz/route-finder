#pragma once
#include "DirectConnection.h"
#include<sstream>

class Matrix
{
private:
    DirectConnection ***p;
    unsigned int size;
    std::vector<City> cites;
    void extend_matrix();


public:
    Matrix();
    Matrix(Matrix const& matrix_to_copy);
    Matrix & operator=(Matrix const& matrix_to_assign);
    void add_connection(DirectConnection *cnt);
    bool isCity(City const& city) const;
    DirectConnection* operator()(City const& CityA, City const& CityB);
    DirectConnection* operator()(int i, int j);
    unsigned int get_size() const
    {
        return size;
    }
    std::vector<City> get_cities() const
    {
        return cites;
    }

    std::string description() const;

    ~Matrix();
    DirectConnection***get_p(){
        return p;
    }
    void print_matrix();

    void clean();
};


