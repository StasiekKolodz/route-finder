#pragma once
#include "DirectConnection.h"
#include "City.h"
#include <vector>

class DataBase
{
    private:
    std::vector<DirectConnection> connections;
    // std::vector<City> cities;
    public:
    DataBase(std::vector<DirectConnection> c)
    {
        connections = c;
    }
    void load_file();
    std::vector<DirectConnection> get_connections()
    {
        return connections;
    }
    // Przeciążenie operatora []. Najlepiej kilka, np żeby dało się znaleźć miasto po nazwie

};