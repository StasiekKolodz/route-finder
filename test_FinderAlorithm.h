#include "FinderAlgorithm.h"
#include "RouteFinder.h"

using namespace std;

int test_FinderAlogithm()
{
        Matrix matrix;
    City Krakow("Krakow", false, true);
    City Warszawa("Warszawa", false, true);
    City Gdynia("Gdynia", false, true);
    City Wroclaw("Wroclaw", false, true);
    DirectConnection Warszawa_Gdynia(2,250000,45,180,Warszawa,Gdynia,Bus);
    DirectConnection Wroclaw_Krakow(3,250000,45,180,Wroclaw,Krakow,Bus);
    DirectConnection Krakow_Warszawa(1,300000,80,240,Krakow,Warszawa,Bus);
    matrix.add_connection(&Krakow_Warszawa);
    matrix.add_connection(&Warszawa_Gdynia);
    matrix.add_connection(&Wroclaw_Krakow);
    FinderAlgorithm fa(matrix);


    // Test 1 creating FinderAlgorithm

    if(fa.get_connetions_matrix().get_size() != 6)
        std::cerr << "FA : Error in test 1\n";

    // Test 2 dijkstra_time function (first city in matrix)
    std::vector<int> exp_dist = {0, 240, 420, 180};
    std::vector<int> exp_prev = {-1, 0, 1, 0};
    fa.dijkstra_time(Krakow);
    for(int i=0; i<4; i++){
        if(fa.get_distance()[i] != exp_dist[i] || fa.get_previous()[i] != exp_prev[i]){
            std::cerr << "FA : Error in test 2: got time and previous " << fa.get_distance()[i] << " and "
            << fa.get_previous()[i] << " instead of " << exp_dist[i] << " and " << exp_prev[i] << std::endl;
        }
    }
    // Test 3 dijkstra_time function (another city in matrix)
    exp_dist = {420, 180, 0, 600};
    exp_prev = {1, 2, -1, 0};
    fa.dijkstra_time(Gdynia);
    for(int i=0; i<4; i++){
        if(fa.get_distance()[i] != exp_dist[i] || fa.get_previous()[i] != exp_prev[i]){
            std::cerr << "FA : Error in test 3: got time and previous " << fa.get_distance()[i] << " and "
            << fa.get_previous()[i] << " instead of " << exp_dist[i] << " and " << exp_prev[i] << std::endl;
        }
    }

    // Test 4 dijkstra_cost function (first city in matrix)
    exp_dist = {0, 80, 125, 45};
    exp_prev = {-1, 0, 1, 0};
    fa.dijkstra_cost(Krakow);
    for(int i=0; i<4; i++){
        if(fa.get_distance()[i] != exp_dist[i] || fa.get_previous()[i] != exp_prev[i]){
            std::cerr << "FA : Error in test 4: got cost and previous " << fa.get_distance()[i] << " and "
            << fa.get_previous()[i] << " instead of " << exp_dist[i] << " and " << exp_prev[i] << std::endl;
        }
    }

    // Test 5 dijkstra_cost function (another city in matrix)
    exp_dist = {125, 45, 0, 170};
    exp_prev = {1, 2, -1, 0};
    fa.dijkstra_cost(Gdynia);
    for(int i=0; i<4; i++){
        if(fa.get_distance()[i] != exp_dist[i] || fa.get_previous()[i] != exp_prev[i]){
            std::cerr << "FA : Error in test 5: got cost and previous " << fa.get_distance()[i] << " and "
            << fa.get_previous()[i] << " instead of " << exp_dist[i] << " and " << exp_prev[i] << std::endl;
        }
    }

    // Test 6 dijkstra_dist function (first city in matrix)
    exp_dist = {0, 300000, 550000, 250000};
    exp_prev = {-1, 0, 1, 0};
    fa.dijkstra_dist(Krakow);
    for(int i=0; i<4; i++){
        if(fa.get_distance()[i] != exp_dist[i] || fa.get_previous()[i] != exp_prev[i]){
            std::cerr << "FA : Error in test 6: got cost and previous " << fa.get_distance()[i] << " and "
            << fa.get_previous()[i] << " instead of " << exp_dist[i] << " and " << exp_prev[i] << std::endl;
        }
    }

    // Test 7 dijkstra_dist function (another city in matrix)
    exp_dist = {550000, 250000, 0, 800000};
    exp_prev = {1, 2, -1, 0};
    fa.dijkstra_dist(Gdynia);
    for(int i=0; i<4; i++){
        if(fa.get_distance()[i] != exp_dist[i] || fa.get_previous()[i] != exp_prev[i]){
            std::cerr << "FA : Error in test 7: got cost and previous " << fa.get_distance()[i] << " and "
            << fa.get_previous()[i] << " instead of " << exp_dist[i] << " and " << exp_prev[i] << std::endl;
        }
    }

    return 0;
}