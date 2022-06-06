#include <iostream>
#include "Interface.h"
#include "RouteFinder.h"
#include "enums.h"

using namespace std;

void Interface::run_interface()
{
    RouteFinder rf("connections.csv");

    bool running = true;
    int option;
    std::string PlaceA;
    std::string PlaceB;
    possible_search_setting setting;
    possible_type type;
    station_type station_type;
    std::string temp_dist;
    unsigned int distance;
    std::string temp_cost;
    unsigned int cost;
    std::string temp_time;
    unsigned int time;


    while(running)
        {
        option = choose_function();
        switch(option)
        {
            case 1:
                {
                    cout << "From: " << endl;
                    cin >> PlaceA;
                    cout << "To: " << endl;
                    cin >> PlaceB;

                    setting = choose_setting();
                    type = choose_type();
                    try
                    {
                        cout << rf.find_user_connection(PlaceA, PlaceB, setting, type);
                    }
                    catch(const CityNotFoundException &e)
                    {
                        cout << "No such connection with given parametres" << endl;
                    }
                }
                break;
            case 2:
                {
                    
                }
                break;
            case 3:
                {
                    cout << "From: " << endl;
                    cin >> PlaceA;
                    cout << "To: " << endl;
                    cin >> PlaceB;
                    cout << "Distance: " << endl;
                    cin >> temp_dist;
                    distance = atoi(temp_dist.c_str());
                    cout << "Cost: " << endl;
                    cin >> temp_cost;
                    cost = atoi(temp_cost.c_str());
                    cout << "Time: " << endl;
                    cin >> temp_time;
                    time = atoi(temp_time.c_str());
                    station_type = choose_station_type();
                    
                    rf.get_db().add_direct_connection(distance, cost, time, PlaceA, PlaceB, station_type);
                    rf.get_db().update_data_base();
                }
                break;
            case 4:
                {
                    running = false;
                }
                break;
            default: cout << "Choose correct option." << endl;
        }
        }
}


int Interface::choose_function()
{
    cout << "Welcome to our Route Finder!" << endl;
    cout << "----------------------------" << endl;
    cout << "1. Find connection." << endl;
    cout << "2. Plan a trip." << endl;
    cout << "3. Add connection." << endl;
    cout << "4. Exit." << endl;

    char wybor;
    cin >> wybor;
    system("clear");

    switch(wybor)
    {
        case '1':
            {
                //algorytm dla znajdowania polaczenia
                return 1;
            }
            break;
        case '2':
            {
                //algorytm dla zaplanowania podróży
                return 2;
            }
            break;
        case '3':
            {
                return 3;
            }
            break;
        case '4':
            { 
                return 4;
            }
            break;
        default: cout << "Choose correct option." << endl;
    }
}


possible_search_setting Interface::choose_setting()
{
    cout << "Do you want your travel to be: " << endl;
    cout << "1. Fastest" << endl;
    cout << "2. Cheapest" << endl;
    cout << "3. Shortest" << endl;

    char wybor;
    cin >> wybor;

    switch(wybor)
    {
        case '1':
            {
                return FASTEST;
            }
            break;
        case '2':
            {
                return CHEAPEST;
            }
            break;
        case '3':
            {
                return SHORTEST;
            }
            break;
        default: cout << "Choose correct option." << endl;
    }
}


possible_type Interface::choose_type()
{
    cout << "You want to travel by: " << endl;
    cout << "1. Bus" << endl;
    cout << "2. Train" << endl;
    cout << "3. Does not matter" << endl;

    char wybor;
    cin >> wybor;

    switch(wybor)
    {
        case '1':
            {
                return BUS;
            }
            break;
        case '2':
            {
                return TRAIN;
            }
            break;
        case '3':
            {
                return BOTH;
            }
            break;
        default: cout << "Choose correct option." << endl;
    }
}


station_type Interface::choose_station_type()
{
    cout << "Choose station type: " << endl;
    cout << "1. Bus" << endl;
    cout << "2. Train" << endl;

    char wybor;
    cin >> wybor;

    switch(wybor)
    {
        case '1':
            {
                return Bus;
            }
            break;
        case '2':
            {
                return Train;
            }
            break;
        default: cout << "Choose correct option." << endl;
    }
}