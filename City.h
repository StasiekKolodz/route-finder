
#include <iostream>
#include <vector>
class City
{
    private:
    std::string name;
    bool isTrain;
    bool isBus;
    // std::vector<DirectConnection> dc_vec;
    public:
    City(std::string n, bool isTrain=false, bool isBus=false) : name(n), isTrain(isTrain), isBus(isBus)
    {}
    // void add_conection(const& DirectConection dc);
    std::string get_name() const
    {return name;}
    // std::vector<DirectConnection> get_dc_vec() const;
    bool isBusStation() const
    {return isBus;}
    bool isTrainStation() const
    {return isTrain;}
    void setTrainStation(bool)
    {}
    void setBusStation(bool)
    {}
};