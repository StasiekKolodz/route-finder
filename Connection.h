#pragma once
#include "DirectConnection.h"

class Connection : public Route
{
    private:

        std::vector<DirectConnection*> connection_elements;
        std::vector<City> changes_list;

    public:

        // constructors
        Connection(City PA, City PB) : Route(0,0,0,0,PA,PB){}

        // getters
        std::vector<DirectConnection*> get_connection_elements() const { return connection_elements; }
        unsigned int get_connection_id() const{return connection_id;}

        // setters
        void add_direct_conection(DirectConnection* dc);
        void set_id(unsigned int id) { connection_id = id; }

        // stream methods
        friend std::ostream& operator<<(std::ostream& os, Connection const& cnt);
        void print_connection_details();
};