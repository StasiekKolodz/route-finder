#pragma once
#include <iostream>
#include <vector>
#include "City.h"

enum station_type {Bus, Train};

class DirectConnection
{
    protected:
        station_type type;
        unsigned int connection_id;
        unsigned int distance;
        unsigned int cost;
        unsigned int time;
        City PlaceA;
        City PlaceB;
    public:
        DirectConnection(unsigned int id, unsigned int d, unsigned int c,
        unsigned int t, City const& PA, City const& PB, station_type type) :
        connection_id(id), distance(d), cost(c), time(t), PlaceA(PA), PlaceB(PB), type(type)
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
        station_type get_type() const { return type; }

};