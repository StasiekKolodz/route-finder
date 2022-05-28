#pragma once
#include <iostream>
#include "Connection.h"
#include "FinderAlgorithm.h"
#include "DataBase.h"

class RouteFinder
{
    DataBase db;
    FinderAlgorithm FA;
    public:
    RouteFinder()
    {
    db.load_file();
    }
    Connection find_user_connection(City const& A, City const& B, possible_search_setting setting, possible_type type)
    {
        switch (setting)
        {
        case CHEAPEST:
            db.create_cheapest_matrix(type);
            FA.set_connections_matrix(db.get_current_matrix());
            return FA.generate_connection_cost(A, B);
            break;
        case FASTEST:
            db.create_fastest_matrix(type);
            FA.set_connections_matrix(db.get_current_matrix());
            return FA.generate_connection_time(A, B);
            break;
        case SHORTEST:
            db.create_shortest_matrix(type);
            FA.set_connections_matrix(db.get_current_matrix());
            return FA.generate_connection_dist(A, B);
            break;
        default:
            break;
        }
    }
};