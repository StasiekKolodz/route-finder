#include "Connection.h"
#include <algorithm>

void Connection::add_direct_conection(DirectConnection* dc)
{
    if(std::find(connection_elements.begin(), connection_elements.end(), dc) != connection_elements.end()){
        throw "Connection already added to connection_elements";
    }
    connection_elements.push_back(dc);
    distance += dc->get_distance();
    cost += dc->get_cost();
    time += dc->get_time();
}

void Connection::set_id(unsigned int id)
{
    connection_id = id;
}

std::vector<DirectConnection *> Connection::get_connection_elements() const
{
    return connection_elements;
}