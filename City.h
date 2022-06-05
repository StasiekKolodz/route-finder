#include <iostream>
#include <vector>
#pragma once

class City
{
    private:

        std::string name;
        bool isTrain;
        bool isBus;

    public:

        // constructors
        City(std::string n="", bool isTrain=false, bool isBus=false) : name(n), isTrain(isTrain), isBus(isBus){}

        // getters
        std::string get_name() const { return name; }
        bool isBusStation() const { return isBus; }
        bool isTrainStation() const { return isTrain; }
        void setTrainStation(bool const& b) { isTrain = b; }
        void setBusStation(bool const& b) { isBus = b; }

        //operators
        bool operator==(City const& other_city) const { return (this->name == other_city.name); }
        bool operator!=(City const& other_city) const { return (this->name != other_city.name); }
        friend std::ostream& operator<<(std::ostream& os, City const& ct) { os << ct.get_name(); return os; }
};