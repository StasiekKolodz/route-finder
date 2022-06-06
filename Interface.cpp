#include <iostream>
#include "Interface.h"
#include "RouteFinder.h"
#include "enums.h"

using namespace std;

void Interface::run_interface()
{
    system("clear");
    RouteFinder rf("connections.csv");

    bool running = true;
    char wait;
    bool planner_running = true;
    bool planner_place_chosen = false;
    int option;
    int planner_option;
    std::string PlaceA;
    std::string PlaceB;
    std::string PreviousPlace;
    std::vector<std::string> Places_vec;
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
                    try
                    {
                    cout << "From: " << endl;
                    cin >> PlaceA;
                    rf.find_city(PlaceA);
                    cout << "To: " << endl;
                    cin >> PlaceB;
                    rf.find_city(PlaceB);
                    system("clear");
                    setting = choose_setting();
                    type = choose_type();
                   
                        cout << rf.find_user_connection(PlaceA, PlaceB, setting, type) << endl;
                        cout << "Press any key to exit..." << endl;
                        cin >> wait;
                        system("clear");
                    }
                    catch(const CityNotFoundException &e)
                    {
                        system("clear");
                        cout << "No such connection with given parametres" << endl;
                    }
                }
                break;
            case 2:
                {
                    system("clear");
                    planner_running = true;
                    planner_place_chosen = false;
                    while(!planner_place_chosen)
                    {
                        try
                        {
                        cout << "Enter a starting point for your journey: " << endl;
                        cin >> PlaceA; 
                        rf.find_city(PlaceA);
                        Places_vec.push_back(PlaceA);
                        planner_place_chosen = true;
                        PreviousPlace = PlaceA;
                        system("clear");
                        }
                        catch(...)
                        {
                            cout << "There are no connections from this place" << endl;
                        }

                    }
                    while(planner_running){
                       planner_option = choose_planner_mode(Places_vec);
                       switch(planner_option)
                       {
                           case 1:
                           {
                            planner_place_chosen = false;
                            while(!planner_place_chosen){  
                                try
                                {  
                                    cout << "Enter next place: " << endl;
                                    cin >> PlaceA; 
                                    if(PlaceA == PreviousPlace)
                                        throw WrongRouteException("Place A and place B must be different");
                                    rf.find_city(PlaceA);
                                    Places_vec.push_back(PlaceA);
                                    PreviousPlace = PlaceA;
                                    planner_place_chosen = true;
                                    system("clear");
                                }
                                catch(const WrongRouteException &e)
                                {
                                    system("clear");
                                    cout << "Next place cant be same as previous one" << endl;
                                }
                                catch(...)
                                {
                                    system("clear");
                                    cout << "There are no connections from this place" << endl;
                                }
                            }

                           }
                           break;
                           case 2:
                           {   if(Places_vec.size() > 1){
                               system("clear");
                               setting = choose_setting();
                               type = choose_type();
                               system("clear");
                               cout << "Your trip:" << endl;
                               for(auto it = Places_vec.begin(); it!=Places_vec.end()-1; it++)
                               {
                                   cout << rf.find_user_connection(*it, *(it+1), setting, type) << endl << endl;
                               }
                                cout << "1. Show connections details" << endl;
                                cout << "2. Exit" << endl;
                                cin >> planner_option;
                                switch(planner_option){
                                    case 1:
                                    {
                                        cout << "Your trip:" << endl;
                                        int i = 1;
                                        for(auto it = Places_vec.begin(); it!=Places_vec.end()-1; it++)
                                        {
                                            cout << i << ". ";
                                            rf.find_user_connection(*it, *(it+1), setting, type).print_connection_details();
                                            i++;
                                        }
                                        cout << endl << "Press any key to exit" << endl;
                                        cin >> wait;
                                        planner_running = false;
                                    }
                                    break;
                                    case 2:
                                    { 
                                        planner_running = false;
                                    }
                                    break;
                                    default: cout << "Choose correct option." << endl;
                                }
                               planner_running = false;
                            }
                            else{
                                system("clear");
                                cout << "Trip needs to have at least two places" << endl << endl;
                            }
                           }
                           break;
                           case 3:
                           {
                               system("clear"); 
                               planner_running = false;
                           }
                           break;
                           default: cout << "Choose correct option." << endl;
                       }


                    }

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
            default:
            {
                system("clear");
                cout << "Choose correct option." << endl;
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
    cout << "3. Add connection." << endl;
    cout << "4. Exit." << endl;

    char wybor;
    cin >> wybor;
    system("clear");

    switch(wybor)
    {
        case '1':
            {
                system("clear");
                //algorytm dla znajdowania polaczenia
                return 1;
            }
            break;
        case '2':
            {
                system("clear");
                //algorytm dla zaplanowania podróży
                return 2;
            }
            break;
        case '3':
            {
                system("clear");
                return 3;
            }
            break;
        case '4':
            { 
                system("clear");
                return 4;
            }
            break;
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
                system("clear");
                return FASTEST;
            }
            break;
        case '2':
            {
                system("clear");
                return CHEAPEST;
            }
            break;
        case '3':
            {
                system("clear");
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
                system("clear");
                return BUS;
            }
            break;
        case '2':
            {
                system("clear");
                return TRAIN;
            }
            break;
        case '3':
            {
                system("clear");
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
                system("clear");
                return Bus;
            }
            break;
        case '2':
            {
                system("clear");
                return Train;
            }
            break;
        default: cout << "Choose correct option." << endl;
    }
}

int Interface::choose_planner_mode(std::vector<std::string>& Places_vec){
    int opt;
    int fi = 0;
    cout << "Your trip: ";
    for(auto& ct:Places_vec){
        if(fi !=0)
        cout << "-" << ct;
        else
        cout << ct;
        fi = 1;
    }
    cout << endl;
    cout << "1. Add place" << endl;
    cout << "2. Generate trip" << endl;
    cout << "3. Exit Planner" << endl;
    cin >> opt;
    system("clear");
    return opt;
}