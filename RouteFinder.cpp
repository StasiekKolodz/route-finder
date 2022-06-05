#include "RouteFinder.h"


// method to handle setting in interface
Connection RouteFinder::find_user_connection(std::string const& nameA, std::string const& nameB, possible_search_setting setting, possible_type type)
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


//method to find city using string name
City RouteFinder::find_city(std::string const& name)
{
    for(auto c: db.get_cities())
    {
        if(c.get_name() == name)
        return c;
    }
    throw "STH";
}