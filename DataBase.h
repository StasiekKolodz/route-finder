#pragma once
#include "Matrix.h"
#include <vector>
#include "enums.h"


class DataBase
{
    private:

    void add_city_using_connection(DirectConnection const& dc);
    std::vector<City> city_using_info(std::string const& nameA, std::string const& nameB, station_type type);

    protected:
        std::vector<DirectConnection> connections;
        std::vector<City> cities;
        Matrix current_matrix;
        possible_type current_station_type;
        possible_search_setting current_search_setting;


    public:
        DataBase();

        void update_data_base();
        void add_direct_connection(DirectConnection const& dc);
        void add_direct_connection(unsigned int dist, unsigned int cost, unsigned int time,
        std::string const& PlaceA, std::string const& PlaceB, station_type type);

        void create_cheapest_matrix(possible_type const& type);
        void create_fastest_matrix(possible_type const& type);
        void create_shortest_matrix(possible_type const& type);

        Matrix get_current_matrix() const { return current_matrix;}
        possible_type get_current_stations_type() const { return current_station_type;}
        possible_search_setting get_current_setting() const { return current_search_setting;}
        std::vector<City> get_cities() const {return cities;}

        DataBase(std::vector<DirectConnection> c)
        {
            connections = c;
        }

        void load_file();

        std::vector<DirectConnection> get_connections(){ return connections; }
        // Przeciążenie operatora []. Najlepiej kilka, np żeby dało się znaleźć miasto po nazwie

            // ~DataBase();

};