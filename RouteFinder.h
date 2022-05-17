#include <iostream>
#include <Connection.h>

class RouteFinder
{
    Connection best_connection;
    
    public:
    RouteFinder(Connection bc) : best_connection(bc) {}
    find_fastest(City A, City B);
    find_shortest(City A, City B);
    find_cheapest(City A, City B);
};