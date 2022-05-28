#pragma once
#include <iostream>
#include <vector>
#include "City.h"
#include "Route.h"
#include "enums.h"

class DirectConnection : public Route
{
    protected:

        station_type type;

    public:

        //constructor
        DirectConnection(unsigned int id, unsigned int d, unsigned int c,
        unsigned int t, City const& PA, City const& PB, station_type tp) : Route(id, d, c, t, PA, PB), type(tp) {}

        // getters
        unsigned int get_connection_id() const { return connection_id; }
        station_type get_type() const { return type; }

        //operators
        bool operator==(DirectConnection dc) { return dc.get_connection_id() == connection_id; }
        bool operator!=(DirectConnection dc) { return not(dc.get_connection_id() == connection_id); }

        //stream methods
        friend std::ostream& operator<<(std::ostream& os, DirectConnection const& dc);
        virtual void print_connection_details();
};