#include "Connection.h"
#include <algorithm>

//method to adding direcect connection to list
void Connection::add_direct_conection(DirectConnection* dc)
{
    if(std::find(connection_elements.begin(), connection_elements.end(), dc) != connection_elements.end())
    {
        throw dcAlreadyAddedError("Connection already added to connection_elements", dc->get_connection_id());
    }

    connection_elements.push_back(dc);

    if(std::find(changes_list.begin(), changes_list.end(), dc->get_PlaceA()) == changes_list.end())
    {
        if(dc->get_PlaceA() != this->PlaceA && dc->get_PlaceA() != this->PlaceB){
        changes_list.push_back(dc->get_PlaceA());
        }
    }
    if(std::find(changes_list.begin(), changes_list.end(), dc->get_PlaceB()) == changes_list.end())
    {
        if(dc->get_PlaceB() != this->PlaceA && dc->get_PlaceB() != this->PlaceB){
        changes_list.push_back(dc->get_PlaceB());
        }
    }

    distance += dc->get_distance();
    cost += dc->get_cost();
    time += dc->get_time();
}


// function to move information to stream
std::ostream& operator<<(std::ostream& os, Connection const& cnt)
{
    os << "Connection between " << cnt.get_PlaceA() << " and " << cnt.get_PlaceB() << std::endl;
    os << "Time: " << cnt.get_time()/60 << ":" << cnt.get_time()%60 << std::endl;
    os << "Cost: " << cnt.get_cost() << " zł" << std::endl;
    os << "Distance: " << cnt.get_distance()/1000 << " km" << std::endl;
    if(cnt.changes_list.size() != 0)
    os << "There are changes in: ";

    for(int i=0; i < cnt.changes_list.size(); i++)
    {
        os << cnt.changes_list[i] << " ";
    }
    os << std::endl;

    return os;
}


// function to directly print details to cout
void Connection::print_connection_details()
{
    std::cout << "Connection details: " << std::endl << std::endl;
    std::cout << "PlaceA: " << PlaceA << std::endl;
    std::cout << "PlaceB: " << PlaceB << std::endl;
    std::cout << "Time: " << time/60 << ":" << time%60 << std::endl;
    std::cout << "Cost: " << cost << " zł" << std::endl;
    std::cout << "Distance: " << distance/1000 << " km" << std::endl;
    if(changes_list.size() != 0){
    std::cout << "Parts of this connection:" << std::endl << std::endl;
    for(auto& v:connection_elements)
    {
        v->print_connection_details();
        std::cout << std::endl;
    }
    }
}
