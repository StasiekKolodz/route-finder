#include "FinderAlgorithm.h"
#include <bits/stdc++.h>
#include <algorithm>

FinderAlgorithm::FinderAlgorithm(Matrix const& cm)
{
    connections_matrix = cm;
    for(unsigned int i=0; i<cm.get_size(); i++){
        distance.push_back(INT_MAX);
        previous.push_back(-1);
    }
    cities = cm.get_cities();
}

void FinderAlgorithm::set_connections_matrix(Matrix const& cm)
{
    connections_matrix = cm;
    std::vector<int> new_distance;
    std::vector<int> new_previous;
    for(unsigned int i=0; i<cm.get_size(); i++){
        new_distance.push_back(INT_MAX);
        new_previous.push_back(-1);
    }
    cities = cm.get_cities();
    distance = new_distance;
    previous = new_previous;
}

City FinderAlgorithm::min_city_node() const
{   
    int min_dist = INT_MAX;
    int min_idx = -1;
    int i =0;
    for(auto ct:cities){
        if(std::find(used.begin(), used.end(), ct) == used.end() && distance[i] <= min_dist){
            min_dist = distance[i];
            min_idx = i;
        }
        i++;
    }
    if(min_idx == -1){
        throw "All cities are already used";
    }
    return cities[min_idx];
}

int FinderAlgorithm::find_city_index(City const& ct)
{
    int city_index = 0;
    for(auto city:cities){
        if(city == ct){
            return city_index;
        }
        city_index++;
    }
    throw "City not found in connections matrix";
}

bool FinderAlgorithm::is_used(City const& ct) const
{
    if(std::find(used.begin(), used.end(), ct) == used.end()) return false;

    return true;
} 

Matrix FinderAlgorithm::get_connetions_matrix() const
{
    return connections_matrix;
}

void FinderAlgorithm::dijkstra_time(City const& PlaceA)
{
    this->reset();
    int Aidx = this->find_city_index(PlaceA);
    distance[Aidx] = 0;
    int cur_idx;
    for(unsigned int i=0; i<connections_matrix.get_size()-1; i++){
        cur_idx = this->find_city_index(this->min_city_node());
        used.push_back(this->min_city_node());
        for(unsigned int k=0; k<connections_matrix.get_size(); k++){
            if(!is_used(cities[k]) && connections_matrix(cur_idx, k) != nullptr
                && distance[cur_idx] + int(connections_matrix(cur_idx, k)->get_time()) < distance[k]){
                    distance[k] = distance[cur_idx] + connections_matrix(cur_idx, k)->get_time();
                    previous[k] = cur_idx;
                }
                
        }
    }
}

void FinderAlgorithm::dijkstra_dist(City const& PlaceA)
{
    this->reset();
    int Aidx = this->find_city_index(PlaceA);
    distance[Aidx] = 0;
    int cur_idx;
    for(unsigned int i=0; i<connections_matrix.get_size()-1; i++){
        cur_idx = this->find_city_index(this->min_city_node());
        used.push_back(this->min_city_node());
        for(unsigned int k=0; k<connections_matrix.get_size(); k++){
            if(!is_used(cities[k]) && connections_matrix(cur_idx, k) != nullptr
                && distance[cur_idx] + int(connections_matrix(cur_idx, k)->get_distance()) < distance[k]){
                    distance[k] = distance[cur_idx] + connections_matrix(cur_idx, k)->get_distance();
                    previous[k] = cur_idx;
                }
                
        }
    }
}

void FinderAlgorithm::dijkstra_cost(City const& PlaceA)
{
    this->reset();
    int Aidx = this->find_city_index(PlaceA);
    distance[Aidx] = 0;
    int cur_idx;
    for(unsigned int i=0; i<connections_matrix.get_size()-1; i++){
        cur_idx = this->find_city_index(this->min_city_node());
        used.push_back(this->min_city_node());
        for(unsigned int k=0; k<connections_matrix.get_size(); k++){
            if(!is_used(cities[k]) && connections_matrix(cur_idx, k) != nullptr
                && distance[cur_idx] + int(connections_matrix(cur_idx, k)->get_cost()) < distance[k]){
                    distance[k] = distance[cur_idx] + connections_matrix(cur_idx, k)->get_cost();
                    previous[k] = cur_idx;
                }
                
        }
    }
    for(auto v:distance){
        if(v == INT_MAX) 
            v = -1;
    }
}
std::vector<int> FinderAlgorithm::get_distance() const
{
    return distance;
}

std::vector<int> FinderAlgorithm::get_previous() const
{
    return previous;
}

void FinderAlgorithm::reset(){
    for(unsigned int i=0; i<connections_matrix.get_size(); i++){
        distance[i] = INT_MAX;
        previous[i] = -1;
    }
    used.clear();
}

Connection FinderAlgorithm::generate_connection_time(City const& PlaceA, City const& PlaceB)
{
    this->dijkstra_time(PlaceA);
    return this->generate_connection(PlaceA, PlaceB);
}

Connection FinderAlgorithm::generate_connection_cost(City const& PlaceA, City const& PlaceB)
{
    this->dijkstra_cost(PlaceA);
    return this->generate_connection(PlaceA, PlaceB);
}

Connection FinderAlgorithm::generate_connection_dist(City const& PlaceA, City const& PlaceB)
{
    this->dijkstra_dist(PlaceA);
    return this->generate_connection(PlaceA, PlaceB);    
}
Connection FinderAlgorithm::generate_connection(City const& PlaceA, City const& PlaceB)
{
    Connection ret_connection(PlaceA, PlaceB);
    std::vector<int> path;
    int cur_idx;
    int Bidx = this->find_city_index(PlaceB);
    int Aidx = this->find_city_index(PlaceA);
    cur_idx = Bidx;
    while(cur_idx != Aidx){
        path.insert(path.begin(), cur_idx);
        cur_idx = previous[cur_idx];
    }
    path.insert(path.begin(), Aidx);
    for(int i=0; i<path.size()-1; i++){
        ret_connection.add_direct_conection(connections_matrix(path[i], path[i+1]));
    }
    return ret_connection;
}

Connection FinderAlgorithm::generate_connection_setting(City const& PlaceA, City const& PlaceB, possible_search_setting s_set)
{
    if(s_set == CHEAPEST){
        return this->generate_connection_cost(PlaceA, PlaceB);
    }
    else if(s_set == FASTEST){
        return this->generate_connection_time(PlaceA, PlaceB);
    }
    else if(s_set == SHORTEST){
        return this->generate_connection_dist(PlaceA, PlaceB);
    }
    // Wyjątek dla enuma
}