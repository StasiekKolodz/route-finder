#include <iostream>
#include "Interface.h"
#include "RouteFinder.h"
#include "enums.h"

using namespace std;

void Interface::run_interface()
{
    RouteFinder rf("connections.csv");

    int option;
    std::string PlaceA;
    std::string PlaceB;
    possible_search_setting setting;
    possible_type type;
    bool working = true;

    while( working )
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
                cout << rf.find_user_connection(PlaceA, PlaceB, setting, type) << endl;
                }
                catch(const CityNotFoundException& e)
                {
                cout << "No such connection" << endl;
                }

            }
            break;
        case 2:
            {

            }
            break;
        case 3:
            {

            }
            break;
        case 4:
            {
                working = false;
            }
    }
    }
}


int Interface::choose_function()
{
    cout << "Welcome to our Route Finder!" << endl;
    cout << "----------------------------" << endl;
    cout << "1. Find connection." << endl;
    cout << "2. Plan a trip." << endl;
    cout << "3. Switch to admin." << endl;
    cout << "4. Exit." << endl;

    char wybor;
    cin >> wybor;

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
                cout << "Test 2" << endl;
                return 2;
            }
            break;
        case '3':
            {
                cout << "Test 3" << endl;
                return 3;
            }
            break;
        case '4':
            {
                return 4;
            }
    }
}


enum possible_search_setting Interface::choose_setting()
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
    }
}


enum possible_type Interface::choose_type()
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
    }
}