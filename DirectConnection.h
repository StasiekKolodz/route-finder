#pragma once
#include <iostream>
#include <vector>
#include "City.h"
class DirectConnection
{
    protected:
        unsigned int connection_id;
        unsigned int distance;
        unsigned int cost;
        unsigned int time;
        City PlaceA;
        City PlaceB;
    // mean_of_transport ??
    public:
        DirectConnection(unsigned int id, unsigned int d, unsigned int c,
        unsigned int t, City PA, City PB) : connection_id(id), distance(d), cost(c), time(t), PlaceA(PA), PlaceB(PB)
        {
            if(PA == PB) throw "Place A and place B must be different";
        }
        // Obsługa błędu gdy PlaceA == PlaceB
        unsigned int get_connection_id() const { return connection_id; }
        unsigned int get_distance() const { return distance; }
        unsigned int get_cost() const { return cost; }
        unsigned int get_time() const { return time; }
        City get_PlaceA() const { return PlaceA; }
        City get_PlaceB() const { return PlaceB; }
        bool operator==(DirectConnection dc){
            return dc.get_connection_id() == connection_id;
        }
        bool operator!=(DirectConnection dc){
            return not(dc.get_connection_id() == connection_id);
        }

};