#include <iostream>
#include "enums.h"

class Interface
{
public:
    Interface(){};
    void run_interface();
    int choose_function();
    enum possible_search_setting choose_setting();
    enum possible_type choose_type();
    
};