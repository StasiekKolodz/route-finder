#pragma once
#include "Matrix.h"
#include <vector>

enum possible_type {BOTH, BUS, TRAIN};
enum possible_search_setting {CHEAPEST, FASTEST, SHORTEST};

class DataBase
{
    private:
        std::vector<DirectConnection> connections;
        std::vector<City> cities;
        Matrix current_matrix;
        possible_type current_station_type;
        possible_search_setting current_search_setting;


    public:
        DataBase();

        void update_data_base();
        void add_direct_connection(DirectConnection const& dc)
        { connections.push_back(dc);}

        void create_cheapest_matrix(possible_type const& type);
        void create_fastest_matrix(possible_type const& type);
        void create_shortest_matrix(possible_type const& type);

        Matrix get_current_matrix() const { return current_matrix;}
        possible_type get_current_stations_type() const { return current_station_type;}
        possible_search_setting get_current_setting() const { return current_search_setting;}

        // ~DataBase();
};