#pragma once
#include <iostream>
#include "Connection.h"
#include "FinderAlgorithm.h"
#include "DataBase.h"

class RouteFinder
{
    private:

        DataBase db;
        FinderAlgorithm FA;
        City UserCityA;
        City UserCityB;

    public:

        //constructor
        RouteFinder(std::string const& filepath) {db.set_file_path(filepath); db.load_file();}

        //method used in interface to handle settings
        Connection find_user_connection(std::string const& nameA, std::string const& nameB,
                                        possible_search_setting setting, possible_type type);

        //method to find city using string
        City find_city(std::string const& name);

        //getter
        DataBase& get_db() {return db;}
};