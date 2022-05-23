#include "DataBase.h"

DataBase::DataBase()
{}

void DataBase::create_cheapest_matrix(possible_type const& type)
{
    current_station_type = type;
    current_search_setting = CHEAPEST;
    if(type == BOTH)
    {
    for(int i = 0; i < connections.size(); i++)
    {
        if(current_matrix(connections[i].get_PlaceA(), connections[i].get_PlaceB()) == nullptr)
        {
            current_matrix.add_connection(&connections[i]);
        }
        else if(current_matrix(connections[i].get_PlaceA(), connections[i].get_PlaceB())->get_cost() < connections[i].get_cost())
        {
            current_matrix.add_connection(&connections[i]);
        }

    }
    }
 else if(type == BUS)
    {
    for(auto dc : connections)
    {
        if((current_matrix(dc.get_PlaceA(), dc.get_PlaceB()) != nullptr
        && current_matrix(dc.get_PlaceA(), dc.get_PlaceB())->get_cost() < dc.get_cost())
        && dc.get_type()==Bus)
        {
            current_matrix.add_connection(&dc);
        }
        else if(current_matrix(dc.get_PlaceA(), dc.get_PlaceB()) == nullptr && dc.get_type()==Bus)
        {
            current_matrix.add_connection(&dc);
        }
    }
    }
    else
    {
    for(auto dc : connections)
    {
        if((current_matrix(dc.get_PlaceA(), dc.get_PlaceB()) != nullptr
        && current_matrix(dc.get_PlaceA(), dc.get_PlaceB())->get_cost() < dc.get_cost())
        && dc.get_type()==Train)
        {
            current_matrix.add_connection(&dc);
        }
        else if(current_matrix(dc.get_PlaceA(), dc.get_PlaceB()) == nullptr && dc.get_type()==Train)
        {
            current_matrix.add_connection(&dc);
        }
    }
    }
}

void DataBase::create_fastest_matrix(possible_type const& type)
{
    current_station_type = type;
    current_search_setting = FASTEST;
    if(type == BOTH)
    {
    for(auto dc : connections)
    {
        if(current_matrix(dc.get_PlaceA(), dc.get_PlaceB()) != nullptr
        || current_matrix(dc.get_PlaceA(), dc.get_PlaceB())->get_time() < dc.get_time())
        {
            current_matrix.add_connection(&dc);
        }
        else if(current_matrix(dc.get_PlaceA(), dc.get_PlaceB()) == nullptr)
        {
            current_matrix.add_connection(&dc);
        }
    }
    }
     else if(type == BUS)
    {
    for(auto dc : connections)
    {
        if((current_matrix(dc.get_PlaceA(), dc.get_PlaceB()) != nullptr
        || current_matrix(dc.get_PlaceA(), dc.get_PlaceB())->get_time() < dc.get_time())
        && dc.get_type()==Bus)
        {
            current_matrix.add_connection(&dc);
        }
        else if(current_matrix(dc.get_PlaceA(), dc.get_PlaceB()) == nullptr && dc.get_type()==Bus)
        {
            current_matrix.add_connection(&dc);
        }
    }
    }
    else
    {
    for(auto dc : connections)
    {
        if((current_matrix(dc.get_PlaceA(), dc.get_PlaceB()) != nullptr
        || current_matrix(dc.get_PlaceA(), dc.get_PlaceB())->get_time() < dc.get_time())
        && dc.get_type()==Train)
        {
            current_matrix.add_connection(&dc);
        }
        else if(current_matrix(dc.get_PlaceA(), dc.get_PlaceB()) == nullptr && dc.get_type()==Train)
        {
            current_matrix.add_connection(&dc);
        }
    }
    }
}

void DataBase::create_shortest_matrix(possible_type const& type)
{
    current_station_type = type;
    current_search_setting = SHORTEST;
    if(type == BOTH)
    {
    for(auto dc : connections)
    {
        if(current_matrix(dc.get_PlaceA(), dc.get_PlaceB()) != nullptr
        || current_matrix(dc.get_PlaceA(), dc.get_PlaceB())->get_distance() < dc.get_distance())
        {
            current_matrix.add_connection(&dc);
        }
        else if(current_matrix(dc.get_PlaceA(), dc.get_PlaceB()) == nullptr)
        {
            current_matrix.add_connection(&dc);
        }
    }
    }
    else if(type == BUS)
    {
    for(auto dc : connections)
    {
        if((current_matrix(dc.get_PlaceA(), dc.get_PlaceB()) != nullptr
        || current_matrix(dc.get_PlaceA(), dc.get_PlaceB())->get_distance() < dc.get_distance())
        && dc.get_type()==Bus)
        {
            current_matrix.add_connection(&dc);
        }
        else if(current_matrix(dc.get_PlaceA(), dc.get_PlaceB()) == nullptr && dc.get_type()==Bus)
        {
            current_matrix.add_connection(&dc);
        }
    }
    }
    else
        {
    for(auto dc : connections)
    {
        if((current_matrix(dc.get_PlaceA(), dc.get_PlaceB()) != nullptr
        || current_matrix(dc.get_PlaceA(), dc.get_PlaceB())->get_distance() < dc.get_distance())
        && dc.get_type()==Train)
        {
            current_matrix.add_connection(&dc);
        }
        else if(current_matrix(dc.get_PlaceA(), dc.get_PlaceB()) == nullptr && dc.get_type()==Train)
        {
            current_matrix.add_connection(&dc);
        }
    }
    }
}

// DataBase::~DataBase()
// {
//     current_matrix.~Matrix();
// }

