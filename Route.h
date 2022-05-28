#include "City.h"

class Route
{
    protected:
    unsigned int connection_id;
    unsigned int distance;
    unsigned int cost;
    unsigned int time;
    City PlaceA;
    City PlaceB;
    public:
    Route(unsigned int id, unsigned int d, unsigned int c, 
    unsigned int t, City const& PA, City const& PB):connection_id(id), distance(d), cost(c), time(t), PlaceA(PA), PlaceB(PB){
        if(PA == PB) throw "Place A and place B must be different";
    }
    virtual void print_connection_details() = 0;
    unsigned int get_connection_id() {return connection_id; }
    unsigned int get_distance() const { return distance; }
    unsigned int get_cost() const { return cost; }
    unsigned int get_time() const { return time; }
    City get_PlaceA() const { return PlaceA; }
    City get_PlaceB() const { return PlaceB; }

};