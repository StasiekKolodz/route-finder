#pragma once
#include <iostream>
#include "Connection.h"
#include "FinderAlgorithm.h"
#include "DataBase.h"

class RouteFinder
{
    DataBase db;
    FinderAlgorithm FA;
    City UserCityA;
    City UserCityB;
    public:
    RouteFinder()
    {
    db.load_file();
    }
    Connection find_user_connection(std::string const& nameA, std::string const& nameB, possible_search_setting setting, possible_type type)
    {
        UserCityA = find_city(nameA);
        UserCityB = find_city(nameB);

        switch (setting)
        {
        case CHEAPEST:
            db.create_cheapest_matrix(type);
            FA.set_connections_matrix(db.get_current_matrix());
            return FA.generate_connection_cost(UserCityA, UserCityB);
            break;
        case FASTEST:
            db.create_fastest_matrix(type);
            FA.set_connections_matrix(db.get_current_matrix());
            return FA.generate_connection_time(UserCityA, UserCityB);
            break;
        case SHORTEST:
            db.create_shortest_matrix(type);
            FA.set_connections_matrix(db.get_current_matrix());
            return FA.generate_connection_dist(UserCityA, UserCityB);
            break;
        default:
            break;
        }
    }

    City find_city(std::string const& name)
    {
        for(auto c: db.get_cities())
        {
            if(c.get_name() == name)
            return c;
        }
        throw "STH";
    }

    DataBase get_db() const {return db;}
};