#pragma once
#include "Matrix.h"
#include <vector>
#include "enums.h"


class DataBase
{
    protected:
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

            // ~DataBase();
};