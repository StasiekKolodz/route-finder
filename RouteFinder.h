#pragma once
#include <iostream>
#include "Connection.h"
#include "FinderAlgorithm.h"
#include "DataBase.h"

class RouteFinder : public FinderAlgorithm, public DataBase
{
    public:
    RouteFinder()
    {}
    Connection find_user_connection(City const& A, City const& B, possible_search_setting setting, possible_type type)
    {
        switch (setting)
        {
        case CHEAPEST:
            create_cheapest_matrix(type);
            return generate_connection_cost(A, B);
            break;
        case FASTEST:
            create_fastest_matrix(type);
            return generate_connection_time(A, B);
            break;
        case SHORTEST:
            create_shortest_matrix(type);
            return generate_connection_dist(A, B);
            break;
        default:
            break;
        }
    }
};