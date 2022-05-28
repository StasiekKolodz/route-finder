#pragma once
#include "DirectConnection.h"

class Connection : public Route
{
    private:
    std::vector<DirectConnection*> connection_elements;
    std::vector<City> changes_list;
    // unsigned int total_time;
    // unsigned int total_distance;
    // unsigned int total_cost;

    public:
    Connection(City PA, City PB) : Route(0,0,0,0,PA,PB){}
    std::vector<DirectConnection*> get_connection_elements() const;
    void add_direct_conection(DirectConnection* dc);
    void set_id(unsigned int id);
    unsigned int get_connection_id() const{return connection_id;}
    // unsigned int get_total_time() const { return total_time;}
    // unsigned int get_total_distance() const { return total_distance;}
    // unsigned int get_total_cost() const { return total_cost;}
    // funkcje set_total_time albo add_time
    friend std::ostream& operator<<(std::ostream& os, Connection const& cnt);
    void print_connection_details();
};