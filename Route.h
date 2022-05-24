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
    virtual unsigned int get_connection_id() const =0;

};