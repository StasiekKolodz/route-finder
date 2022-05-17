#pragma once
#include <iostream>
#include <Connection.h>

class RouteFinder
{
    Connection best_connection;

    public:
    RouteFinder(Connection bc) : best_connection(bc) {}
    Connection find_fastest(City A, City B);
    Connection find_shortest(City A, City B);
    Connection find_cheapest(City A, City B);
};