#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include "DataBase.h"
using namespace std;


// method that create cheapest matrix of every direct connection with correct station type
void DataBase::create_cheapest_matrix(possible_type const& type)
{
    current_matrix.clean();
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
            else if(current_matrix(connections[i].get_PlaceA(), connections[i].get_PlaceB())->get_cost() > connections[i].get_cost())
            {
                current_matrix.add_connection(&connections[i]);
            }
        }
    }

    else if(type == BUS)
    {
        for(int i = 0; i < connections.size(); i++)
        {
            if(current_matrix(connections[i].get_PlaceA(), connections[i].get_PlaceB()) == nullptr)
            {
                if(connections[i].get_type() == Bus)
                current_matrix.add_connection(&connections[i]);
            }
            else if(current_matrix(connections[i].get_PlaceA(), connections[i].get_PlaceB())->get_cost() > connections[i].get_cost()
            && connections[i].get_type( ) == Bus)
            {
                current_matrix.add_connection(&connections[i]);
            }
        }
    }

    else if(type == TRAIN)
    {
        for(int i = 0; i < connections.size(); i++)
        {
            if(current_matrix(connections[i].get_PlaceA(), connections[i].get_PlaceB()) == nullptr)
            {
                if(connections[i].get_type() == Train)
                current_matrix.add_connection(&connections[i]);
            }
            else if(current_matrix(connections[i].get_PlaceA(), connections[i].get_PlaceB())->get_cost() > connections[i].get_cost()
            && connections[i].get_type()==Train)
            {
                current_matrix.add_connection(&connections[i]);
            }
        }
    }

    else
        throw StationTypeError("Incorrect station type");
}



// method that create fastest matrix of every direct connection with correct station type
void DataBase::create_fastest_matrix(possible_type const& type)
{
    current_matrix.clean();
    current_station_type = type;
    current_search_setting = FASTEST;

    if(type == BOTH)
    {
        for(int i = 0; i < connections.size(); i++)
        {
            if(current_matrix(connections[i].get_PlaceA(), connections[i].get_PlaceB()) == nullptr)
            {
                current_matrix.add_connection(&connections[i]);
            }
            else if(current_matrix(connections[i].get_PlaceA(), connections[i].get_PlaceB())->get_time() > connections[i].get_time())
            {
                current_matrix.add_connection(&connections[i]);
            }
        }
    }

     else if(type == BUS)
    {
        for(int i = 0; i < connections.size(); i++)
        {
            if(current_matrix(connections[i].get_PlaceA(), connections[i].get_PlaceB()) == nullptr)
            {
                if(connections[i].get_type() == Bus)
                current_matrix.add_connection(&connections[i]);
            }
            else if(current_matrix(connections[i].get_PlaceA(), connections[i].get_PlaceB())->get_time() > connections[i].get_time()
            && connections[i].get_type() == Bus)
            {
                current_matrix.add_connection(&connections[i]);
            }
        }
    }

    else if(type == TRAIN)
    {
        for(int i = 0; i < connections.size(); i++)
        {
            if(current_matrix(connections[i].get_PlaceA(), connections[i].get_PlaceB()) == nullptr)
            {
                if(connections[i].get_type() == Train)
                current_matrix.add_connection(&connections[i]);
            }
            else if(current_matrix(connections[i].get_PlaceA(), connections[i].get_PlaceB())->get_time() > connections[i].get_time()
            && connections[i].get_type() == Train)
            {
                current_matrix.add_connection(&connections[i]);
            }
        }
    }

    else
    throw StationTypeError("Incorrect station type");

}


// method that create shortest matrix of every direct connection with correct station type
void DataBase::create_shortest_matrix(possible_type const& type)
{
    current_matrix.clean();
    current_station_type = type;
    current_search_setting = SHORTEST;

    if(type == BOTH)
    {
        for(int i = 0; i < connections.size(); i++)
            {
                if(current_matrix(connections[i].get_PlaceA(), connections[i].get_PlaceB()) == nullptr)
                {
                    current_matrix.add_connection(&connections[i]);
                }
                else if(current_matrix(connections[i].get_PlaceA(), connections[i].get_PlaceB())->get_distance() > connections[i].get_distance())
                {
                    current_matrix.add_connection(&connections[i]);
                }
            }
    }

    else if(type == BUS)
    {
        for(int i = 0; i < connections.size(); i++)
        {
            if(current_matrix(connections[i].get_PlaceA(), connections[i].get_PlaceB()) == nullptr)
            {
                if(connections[i].get_type() == Bus)

                current_matrix.add_connection(&connections[i]);
            }
            else if(current_matrix(connections[i].get_PlaceA(), connections[i].get_PlaceB())->get_distance() > connections[i].get_distance()
            && connections[i].get_type() == Bus)
            {
                current_matrix.add_connection(&connections[i]);
            }
        }
    }

    else if(type == TRAIN)
    {
        for(int i = 0; i < connections.size(); i++)
        {
            if(current_matrix(connections[i].get_PlaceA(), connections[i].get_PlaceB()) == nullptr)
            {
                if(connections[i].get_type() == Train)
                current_matrix.add_connection(&connections[i]);
            }
            else if(current_matrix(connections[i].get_PlaceA(), connections[i].get_PlaceB())->get_distance() > connections[i].get_distance()
            && connections[i].get_type() == Train)
            {
                current_matrix.add_connection(&connections[i]);
            }
        }
    }

    else
    throw StationTypeError("Incorrect station type");
}


//function to load direct connections from file
void DataBase::load_file()
{
    ifstream file;
    file.open(path);

    if(file.good())
    {

        string line = ""; //string to put the data into
        getline(file, line); //getting rid of the header line
        unsigned int connection_id;
        unsigned int distance;
        unsigned int cost;
        unsigned int time;
        string nameA;
        string nameB;
        station_type type;
        line = "";


        string tempString; //empty string to save DirectConnection attributes, which are going to be converted to int

        while(getline(file, line))
        {

            stringstream inputString(line);

            getline(inputString, tempString, ',');      //save to temporary string
            connection_id = atoi(tempString.c_str());   //conversion string to int
            tempString = "";                            //cleaning temporary string

            getline(inputString, tempString, ',');
            distance = atoi(tempString.c_str());
            tempString = "";

            getline(inputString, tempString, ',');
            cost = atoi(tempString.c_str());
            tempString = "";

            getline(inputString, tempString, ',');
            time = atoi(tempString.c_str());
            tempString = "";

            getline(inputString, nameA, ',');
            tempString = "";

            getline(inputString, nameB, ',');
            tempString = "";

            getline(inputString, tempString, ',');
            if(tempString == "Bus") type = Bus;
            else if(tempString == "Train") type = Train;
            else throw StationTypeError("Wrong type of station type. Only Bus or Train is acceptable", tempString);

            //founding cities using info from single direct connection ( and adding them to vector of city )
            vector<City> places = city_using_info(nameA, nameB, type);

            //creating DirectConnection object
            DirectConnection connection(connection_id, distance, cost, time, places[0], places[1], type);

            //adding DirectConnection to vector of connections
            connections.push_back(connection);
        }

            file.close();
    }
}


//adding cities to vector of cities based on Direct Connection
void DataBase::add_city_using_connection(DirectConnection const& dc)
{
    city_using_info(dc.get_PlaceA().get_name(), dc.get_PlaceB().get_name(), dc.get_type());
}


//adding DirectConnection object manually (using referention to object)
void DataBase::add_direct_connection(DirectConnection const& dc)
{
    connections.push_back(dc);
    add_city_using_connection(dc);
}


//adding DirectConnection object manually (using strings instead of City objects)
void DataBase::add_direct_connection(unsigned int dist, unsigned int cost, unsigned int time,
string const& nameA, string const& nameB, station_type type)
{

    vector<City> places = city_using_info(nameA,nameB,type);

    DirectConnection dc(connections.size()+1, dist, cost, time, places[0], places[1],type);
    connections.push_back(dc);
    add_city_using_connection(dc);
}


//function to add new city or change current city based on information from connection
// returns this two cities
std::vector<City> DataBase::city_using_info(std::string const& nameA, std::string const& nameB, station_type type)
{
    std::vector<City> cities_to_push;
    std::vector<string> names;
    names.push_back(nameA);
    names.push_back(nameB);
    for(auto name : names)
    {
        bool is_train = false;
        bool is_bus = false;
        bool is_found = false;

        for (int i = 0; i<cities.size(); i++)
        {
            if(cities[i].get_name() == name)
            {
                is_found = true;
                if(type == Bus)
                {
                    cities[i].setBusStation(true);
                }
                else if(type == Train)
                {
                    cities[i].setTrainStation(true);
                }
                cities_to_push.push_back(cities[i]);
                break;
            }
        }

        if(!is_found)
        {
            if(type == Train)
            is_train = true;
            else if(type == Bus)
            is_bus = true;
            else
            throw "Incorrect type of connection";

            City city_to_push(name, is_train, is_bus);
            cities_to_push.push_back(city_to_push);
            cities.push_back(city_to_push);
        }

    }
    return cities_to_push;
}


//function to save manually added connections into file
void DataBase::update_data_base() const
{
    std::vector<string> stations = {"Bus", "Train"};
    fstream file;
    file.open(path,std::ios::out);

    if(file.good())
    {
        file << "ConnectionId,Distance,Cost,Time,CityA,CityB,Type" << endl;
        for(auto dc : connections)
        {
        std::string id = to_string(dc.get_connection_id());
        std::string distance = to_string(dc.get_distance());
        std::string cost = to_string(dc.get_cost());
        std::string time = to_string(dc.get_time());
        std::string PlaceA = dc.get_PlaceA().get_name();
        std::string PlaceB = dc.get_PlaceB().get_name();
        std::string type = stations[dc.get_type()];

        file << id <<"," << distance << "," << cost <<"," << time << "," <<
        PlaceA << "," << PlaceB << "," << type << endl;
        }
    file.close();
    }
}
