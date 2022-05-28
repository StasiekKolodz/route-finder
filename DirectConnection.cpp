#include "DirectConnection.h"

std::ostream& operator<<(std::ostream& os, DirectConnection const& dc)
{
    std::string station_tp[2] = {"Bus", "Train"};
    os << "Direct connection between " << dc.get_PlaceA() << " and " << dc.get_PlaceB() << std::endl;
    os << "Time: " << dc.get_time()/60 << ":" << dc.get_time()%60 << std::endl;
    os << "Cost: " << dc.get_cost() << " zł" << std::endl;
    os << "Distance: " << dc.get_distance()/1000 << " km" << std::endl;
    os << "Type: " << station_tp[dc.get_type()] << std::endl;
    return os;
}

void DirectConnection::print_connection_details()
{
    std::string station_tp[2] = {"Bus", "Train"};
    std::cout << "Connection ID: " << connection_id << std::endl;
    std::cout << "PlaceA: " << PlaceA << std::endl;
    std::cout << "PlaceB: " << PlaceB << std::endl;
    std::cout << "Time: " << time/60 << ":" << time%60 << std::endl;
    std::cout << "Cost: " << cost << " zł" << std::endl;
    std::cout << "Distance: " << distance/1000 << " km" << std::endl;
    std::cout << "Type: " << station_tp[type] << std::endl;
}