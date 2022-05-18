#include "DataBase.h"

void DataBase::create_cheapest_matrix(possible_type type = BOTH)
{
    if(type == BOTH)
    {
    for(auto dc : connections)
    {
        if(current_matrix(dc.get_PlaceA(), dc.get_PlaceB()) != nullptr
        || current_matrix(dc.get_PlaceA(), dc.get_PlaceB())->get_cost() < dc.get_cost())
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
        || current_matrix(dc.get_PlaceA(), dc.get_PlaceB())->get_cost() < dc.get_cost())
        && dc.get_type()==type)
        {
            current_matrix.add_connection(&dc);
        }
    }
    }
}


void DataBase::create_fastest_matrix(possible_type type = BOTH)
{
    if(type == BOTH)
    {
    for(auto dc : connections)
    {
        if(current_matrix(dc.get_PlaceA(), dc.get_PlaceB()) != nullptr
        || current_matrix(dc.get_PlaceA(), dc.get_PlaceB())->get_time() < dc.get_time())
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
        && dc.get_type()==type)
        {
            current_matrix.add_connection(&dc);
        }
    }
    }
}


void DataBase::create_shortest_matrix(possible_type type = BOTH)
{
    if(type == BOTH)
    {
    for(auto dc : connections)
    {
        if(current_matrix(dc.get_PlaceA(), dc.get_PlaceB()) != nullptr
        || current_matrix(dc.get_PlaceA(), dc.get_PlaceB())->get_distance() < dc.get_distance())
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
        && dc.get_type()==type)
        {
            current_matrix.add_connection(&dc);
        }
    }
    }
}

