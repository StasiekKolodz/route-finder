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
};


