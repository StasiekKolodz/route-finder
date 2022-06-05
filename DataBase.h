#pragma once
#include "Matrix.h"
#include <vector>
#include "enums.h"


class DataBase
{
    private:

        // functions only use by class not to repeat code
        void add_city_using_connection(DirectConnection const& dc);
        std::vector<City> city_using_info(std::string const& nameA, std::string const& nameB, station_type type);

        //attributes
        std::vector<DirectConnection> connections;
        std::vector<City> cities;
        Matrix current_matrix;
        possible_type current_station_type;
        possible_search_setting current_search_setting;
        std::string path;

    public:

        //constructors
        DataBase(){}
        DataBase(std::string const& filepath) : path(filepath) {}
        DataBase(std::string const& filepath, std::vector<DirectConnection> c): path(filepath), connections(c) {}


        //adding direct connections using different arguments
        void add_direct_connection(DirectConnection const& dc);
        void add_direct_connection(unsigned int dist, unsigned int cost, unsigned int time,
        std::string const& PlaceA, std::string const& PlaceB, station_type type);


        //getters
        possible_search_setting get_current_setting() const { return current_search_setting; }
        possible_type get_current_stations_type() const     { return current_station_type; }
        Matrix get_current_matrix() const                   { return current_matrix; }
        std::vector<DirectConnection> get_connections()     { return connections; }
        std::vector<City> get_cities() const                { return cities; }

        //setter
        void set_file_path(std::string const& p) { path = p; }

        //functions to create matrix of chosen option
        void create_cheapest_matrix(possible_type const& type);
        void create_fastest_matrix(possible_type const& type);
        void create_shortest_matrix(possible_type const& type);


        //funtions used in file cooperation
        void update_data_base() const;
        void load_file();

};