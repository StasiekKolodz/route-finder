#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
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

using namespace std;

void DataBase::load_file()
{
    ifstream file;
    file.open("connections.csv");

    // vector<DirectConnection> connections;

    string line = ""; //string to put the data into
    getline(file, line); //getting rid of the header line
    line = "";

    while(getline(file, line))
    {
        unsigned int connection_id;
        unsigned int distance;
        unsigned int cost;
        unsigned int time;
        string nameA;
        bool isTrainA;
        bool isBusA;
        string nameB;
        bool isTrainB;
        bool isBusB;
        station_type type;

        string tempString; //pusty string do zapisu atrybutow DirectConnection, ktore przekonwertujemy na int/double

        stringstream inputString(line);

        getline(inputString, tempString, ','); //zapisywanie do tymczasowego stringa id stringa
        connection_id = atoi(tempString.c_str()); //konwercja stringa na inta

        tempString = ""; //czyszczenie chwilowego stringa

        getline(inputString, tempString, ',');
        distance = atoi(tempString.c_str());

        tempString = "";

        getline(inputString, tempString, ',');
        cost = atoi(tempString.c_str());

        tempString = "";

        getline(inputString, tempString, ',');
        time = atoi(tempString.c_str());

        getline(inputString, nameA, ',');

        tempString = "";

        getline(inputString, tempString, ',');
        if(tempString == "True")
        {
            isTrainA = true;
        }
        else isTrainA = false;

        tempString = "";

        getline(inputString, tempString, ',');
        if(tempString == "True")
        {
            isBusA = true;
        }
        else isBusA = false;

        getline(inputString, nameB, ',');

        tempString = "";

        getline(inputString, tempString, ',');
        if(tempString == "True")
        {
            isTrainB = true;
        }
        else isTrainB = false;

        tempString = "";

        getline(inputString, tempString, ',');
        if(tempString == "True")
        {
            isBusB = true;
        }
        else isBusB = false;

        tempString = "";

        getline(inputString, tempString, ',');
        if(tempString == "Bus")
        {
            type = Bus;
        }
        else if(tempString == "Train")
        {
            type = Train;
        }
        else
        {
            throw "Wrong type of station type. Only Bus or Train is acceptable";
        }

        City PlaceA(nameA, isTrainA, isBusA);
        City PlaceB(nameB, isTrainB, isBusB);

        DirectConnection connection(connection_id, distance, cost, time, PlaceA, PlaceB, type); //tworzenie obiektu DirectConnection

        connections.push_back(connection); //dodanie obiektu do wektora połączeń
    }
};
