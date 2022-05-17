
#include <iostream>
#include <vector>
class City
{
    private:
    std::string name;
    bool isTrainStation;
    bool isBusStation;
    // std::vector<DirectConnection> dc_vec;
    public:
    City(std::string n, bool isTrain=false, bool isBus=false);
    // void add_conection(const& DirectConection dc);
    std::string get_name() const;
    // std::vector<DirectConnection> get_dc_vec() const;
    bool isBusStation() const;
    bool isTrainStation() const;
    void setTrainStation(bool);
    void setBusStation(bool);
};