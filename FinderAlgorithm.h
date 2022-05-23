#pragma once
#include "Matrix.h"
#include "Connection.h"
#include <algorithm>
#include "enums.h"

class FinderAlgorithm
{
    private:
    Matrix connections_matrix;
    std::vector<int> distance;
    std::vector<int> previous;
    std::vector<City> used;
    std::vector<City> cities;
   public:
    FinderAlgorithm(Matrix const& cm);
    FinderAlgorithm(){}
    Matrix get_connetions_matrix() const;
    std::vector<int> get_distance() const;
    std::vector<int> get_previous() const;
    void set_connections_matrix(Matrix const& cm);
    bool is_used(City const& ct) const;
    City min_city_node() const;
    int find_city_index(City const& ct);
    void dijkstra_dist(City const& PlaceA); 
    void dijkstra_time(City const& PlaceA); 
    void dijkstra_cost(City const& PlaceA);
    Connection generate_connection_time(City const& PlaceA, City const& PlaceB);
    Connection generate_connection_cost(City const& PlaceA, City const& PlaceB);
    Connection generate_connection_dist(City const& PlaceA, City const& PlaceB);
    Connection generate_connection(City const& PlaceA, City const& PlaceB);
    Connection generate_connection_setting(City const& PlaceA, City const& PlaceB, possible_search_setting s_set);
    void reset();

};