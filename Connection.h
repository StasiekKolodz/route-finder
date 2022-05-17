#include "DirectConnection.h"

class Conection
{
    private:
    std::vector<DirectConnection> conection_elements;
    unsigned int total_time;
    unsigned int total_distance;
    unsigned int total_cost;

    public:
    Conection();
    void add_direct_conection(DirectConnection const& dc);
    unsigned int get_total_time() const { return total_time;}
    unsigned int get_total_distance() const { return total_distance;}
    unsigned int get_total_cost() const { return total_cost;}
    // funkcje set_total_time albo add_time
};

