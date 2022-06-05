#include <iostream>
#include "enums.h"

class Interface
{
public:
    Interface(){};
    void run_interface();
    int choose_function();
    possible_search_setting choose_setting();
    possible_type choose_type();
    station_type choose_station_type();
};