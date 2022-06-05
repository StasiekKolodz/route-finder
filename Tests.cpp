#include "Tests.h"
#include "City.h"
#include "Matrix.h"
#include "FinderAlgorithm.h"
#include "RouteFinder.h"
#include "DataBase.h"
#include <iostream>


using namespace std;


void Tests::test_City() const
{
cerr << "CITY TESTS" << endl;

// test 0 - creating default City
    City c1;
    if(c1.get_name() != "")
        cerr << "City: Test 0 - FAILED" << endl;
    else if(c1.isBusStation() || c1.isTrainStation())
        cerr << "City: Test 0 - FAILED" << endl;
    else
        cerr << "City: Test 0 - PASSED" << endl;


// test 1 - creating City with arguments
    City c2("Warszawa", false, true);
    if(c2.get_name() != "Warszawa")
        cerr << "City: Test 1 - FAILED" << endl;
    else if(!c2.isBusStation() || c2.isTrainStation())
        cerr << "City: Test 1 - FAILED" << endl;
    else
        cerr << "City: Test 1 - PASSED" << endl;


// test 2 - setting station in City
    c2.setTrainStation(true);
    c2.setBusStation(false);
    if(!c2.isTrainStation())
        cerr << "City: Test 2 - FAILED" << endl;
    else if(c2.isBusStation())
        cerr << "City: Test 2 - FAILED" << endl;
    else
        cerr << "City: Test 2 - PASSED" << endl;


// test 3 - equaling two Cities
    City c3("Warszawa", false, false);
    if(!(c3 == c2))
        cerr << "City: Test 3 - FAILED" << endl;
    else if(c3 != c2)
        cerr << "City: Test 3 - FAILED" << endl;
    else
        cerr << "City: Test 3 - PASSED" << endl;
}


void Tests::test_DirectConnection() const
{
    cerr << endl << "DIRECT CONNECTION TESTS" << endl;


    // Test 0 - creating Connection
    DirectConnection cnt(0,150000,30,240,City("Wrocław", true, true), City("Warszawa", true, true), Train);
    if(cnt.get_connection_id() != 0)
        cerr << "DC: Test 0 - FAILED" << endl;
    else if(cnt.get_cost() != 30)
        cerr << "DC: Test 0 - FAILED" << endl;
    else if(cnt.get_distance() != 150000)
        cerr << "DC: Test 0 - FAILED" << endl;
    else if(cnt.get_time() != 240)
        cerr << "DC: Test 0 - FAILED" << endl;
    else if(cnt.get_PlaceA().get_name() != "Wrocław")
        cerr << "DC: Test 0 - FAILED" << endl;
    else if(cnt.get_PlaceB().get_name() != "Warszawa")
        cerr << "DC: Test 0 - FAILED" << endl;
    else if(cnt.get_type() != Train)
        cerr << "DC: Test 0 - FAILED" << endl;
    else
        cerr << "DC: Test 0 - PASSED" << endl;


    // Test 1 - comparing Direct Connections
    DirectConnection cnt2(0,150000,30,240,City("Wrocław", true, true), City("Warszawa", true, true), Train);
    if (cnt != cnt2)
        cerr << "DC: Test 1 - FAILED" << endl;
    else if (!(cnt == cnt2))
        cerr << "DC: Test 1 - FAILED" << endl;
    else
        cerr << "DC: Test 1 - PASSED" << endl;

}


void Tests::test_Connection() const
{

    cerr << endl << "CONNECTION TESTS" << endl;


    // Test 0 - creating connection
    Connection con(City("Kraków"), City("Płock"));
    if(con.get_cost() != 0 || con.get_distance() !=0 || con.get_time() != 0)
        cerr << "CONNECTION: Test 0 - FAILED" << endl;
    else if(con.get_PlaceA().get_name() != "Kraków" || con.get_PlaceB().get_name() != "Płock")
        cerr << "CONNECTION: Test 0 - FAILED" << endl;
    else
        cerr << "CONNECTION: Test 0 - PASSED" << endl;


    // Test 1 - adding Direct Connection
    DirectConnection cnt1(1,150000,30,240,City("Płock", true, true), City("Warszawa", true, true), Train);
    DirectConnection cnt2(2,200000,40,140,City("Kraków", true, true), City("Warszawa", true, true), Train);
    con.add_direct_conection(&cnt1);
    con.add_direct_conection(&cnt2);
    if(con.get_cost() != 70 || con.get_distance() !=350000 || con.get_time() != 380)
        cerr << "CONNECTION: Test 1 - FAILED" << endl;
    else if(con.get_PlaceA().get_name() != "Kraków" || con.get_PlaceB().get_name() != "Płock")
        cerr << "CONNECTION: Test 1 - FAILED" << endl;
    else if(con.get_connection_elements().size()!=2)
        cerr << "CONNECTION: Test 1 - FAILED" << endl;
    else
        cerr << "CONNECTION: Test 1 - PASSED" << endl;


    // Test 2 - tring to add connection that already exist
    try
    {
        con.add_direct_conection(&cnt1);
                cerr << "CONNECTION: Test 2 - FAILED" << endl;
    }
    catch(const dcAlreadyAddedError e)
    {
        cerr << "CONNECTION: Test 2 - PASSED with error: " << e.what() << endl;
    }

}


void Tests::test_DataBase() const
{
    cerr << endl << "DATA BASE TESTS" << endl;

    // Test 0 - creating data base;
    try
    {
        DataBase db("test_file.csv");
        cerr << "DB: Test 0 - PASSED" << endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "DB: Test 0 - FAILED with error: " << e.what() << endl;
    }

    // Test 1 - loading file

        DataBase db("test_file.csv");
        db.load_file();
        if(db.get_connections().size() != 4)
        cerr << "DB: Test 1 - FAILED" << endl;
        else if(db.get_cities().size() != 4)
        cerr << "DB: Test 1 - FAILED" << endl;
        else if(db.get_current_matrix().get_size() != 0)
        cerr << "DB: Test 1 - FAILED" << endl;
        else
        cerr << "DB: Test 1 - PASSED" << endl;

    // Test 2 - generating cheapest matrix ( + BOTH parameter)
        db.create_cheapest_matrix(BOTH);
        if(db.get_current_matrix().get_size() != 4)
        cerr << "DB: Test 2 - FAILED" << endl;
        else if(db.get_current_setting() != CHEAPEST)
        cerr << "DB: Test 2 - FAILED" << endl;
        else if(db.get_current_stations_type() != BOTH)
        cerr << "DB: Test 2 - FAILED" << endl;
        else if(db.get_current_matrix()(1,3)->get_time() != 20)
        cerr << "DB: Test 2 - FAILED" << endl;
        else
        cerr << "DB: Test 2 - PASSED" << endl;

    // Test 3 - generating matrix to shortest ( + TRAIN parameter)
        db.create_shortest_matrix(TRAIN);
        if(db.get_current_matrix().get_size() != 4)
        cerr << "DB: Test 3 - FAILED" << endl;
        else if(db.get_current_setting() != SHORTEST)
        cerr << "DB: Test 3 - FAILED" << endl;
        else if(db.get_current_stations_type() != TRAIN)
        cerr << "DB: Test 3 - FAILED" << endl;
        else if(db.get_current_matrix()(1,3)->get_distance() != 50000)
        cerr << "DB: Test 3 - FAILED" << endl;
        else if(db.get_current_matrix()(2,3) != nullptr)
        cerr << "DB: Test 3 - FAILED" << endl;
        else
        cerr << "DB: Test 3 - PASSED" << endl;


    // Test 4 - generating fastest matrix ( + BUS parameter)
        db.create_fastest_matrix(BUS);
        if(db.get_current_matrix().get_size() != 4)
        cerr << "DB: Test 4 - FAILED" << endl;
        else if(db.get_current_setting() != FASTEST)
        cerr << "DB: Test 4 - FAILED" << endl;
        else if(db.get_current_stations_type() != BUS)
        cerr << "DB: Test 4 - FAILED" << endl;
        else if(db.get_current_matrix()(1,3) != nullptr)
        cerr << "DB: Test 4 - FAILED" << endl;
        else if(db.get_current_matrix()(2,3)->get_connection_id() != 2)
        cerr << "DB: Test 4 - FAILED" << endl;
        else
        cerr << "DB: Test 4 - PASSED" << endl;

    // Test 5 - adding Direct Connection
        db.add_direct_connection(150000,30,240,"Płock","Warszawa", Bus);
        if(db.get_connections().size() != 5)
        cerr << "DB: Test 5 - FAILED" << endl;
        else if(db.get_current_matrix().get_size() != 4)
        cerr << "DB: Test 5 - FAILED" << endl;
        else if(db.get_cities().size() != 5)
        cerr << "DB: Test 5 - FAILED" << endl;
        else if(db.get_cities()[1].isBusStation() != true)
        cerr << "DB: Test 5 - FAILED" << endl;

        db.create_cheapest_matrix(BUS);

        if(db.get_current_matrix().get_size() != 5)
        cerr << "DB: Test 5 - FAILED" << endl;
        else if(db.get_current_matrix()(1,4)->get_connection_id() != 5)
        cerr << "DB: Test 5 - FAILED" << endl;
        else if(db.get_current_matrix()(0,2) != nullptr)
        cerr << "DB: Test 5 - FAILED" << endl;
        else
        cerr << "DB: Test 5 - PASSED" << endl;


}


void Tests::test_FinderAlgorithms() const
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
    bool gone_wrong = false;

    cerr << endl << "FINDER ALGORITHM TESTS" << endl;


    // Test 1 creating FinderAlgorithm
    if(fa.get_connetions_matrix().get_size() != 4)
        std::cerr << "FA: Error in test 1\n";
    else
        cerr << "FA: Test 1 - PASSED" << endl;


    // Test 2 dijkstra_time function (first city in matrix)
    std::vector<int> exp_dist = {0, 240, 420, 180};
    std::vector<int> exp_prev = {-1, 0, 1, 0};
    fa.dijkstra_time(Krakow);
    gone_wrong = false;
    for(int i=0; i<4; i++){
        if(fa.get_distance()[i] != exp_dist[i] || fa.get_previous()[i] != exp_prev[i]){
            gone_wrong = true;
            std::cerr << "FA: Error in test 2: got time and previous " << fa.get_distance()[i] << " and "
            << fa.get_previous()[i] << " instead of " << exp_dist[i] << " and " << exp_prev[i] << std::endl;
        }
    }
    if(!gone_wrong)
        cerr << "FA: Test 2 - PASSED" << endl;


    // Test 3 dijkstra_time function (another city in matrix)
    exp_dist = {420, 180, 0, 600};
    exp_prev = {1, 2, -1, 0};
    fa.dijkstra_time(Gdynia);
    gone_wrong = false;
    for(int i=0; i<4; i++){
        if(fa.get_distance()[i] != exp_dist[i] || fa.get_previous()[i] != exp_prev[i]){
            gone_wrong = true;
            std::cerr << "FA: Error in test 3: got time and previous " << fa.get_distance()[i] << " and "
            << fa.get_previous()[i] << " instead of " << exp_dist[i] << " and " << exp_prev[i] << std::endl;
        }
    }
    if(!gone_wrong)
    cerr << "FA: Test 3 - PASSED" << endl;


    // Test 4 dijkstra_cost function (first city in matrix)
    exp_dist = {0, 80, 125, 45};
    exp_prev = {-1, 0, 1, 0};
    fa.dijkstra_cost(Krakow);
    gone_wrong = false;
    for(int i=0; i<4; i++){
        if(fa.get_distance()[i] != exp_dist[i] || fa.get_previous()[i] != exp_prev[i]){
            gone_wrong = true;
            std::cerr << "FA: Error in test 4: got cost and previous " << fa.get_distance()[i] << " and "
            << fa.get_previous()[i] << " instead of " << exp_dist[i] << " and " << exp_prev[i] << std::endl;
        }
    }
    if(!gone_wrong)
    cerr << "FA: Test 4 - PASSED" << endl;


    // Test 5 dijkstra_cost function (another city in matrix)
    exp_dist = {125, 45, 0, 170};
    exp_prev = {1, 2, -1, 0};
    fa.dijkstra_cost(Gdynia);
    gone_wrong = false;
    for(int i=0; i<4; i++){
        if(fa.get_distance()[i] != exp_dist[i] || fa.get_previous()[i] != exp_prev[i]){
            gone_wrong = true;
            std::cerr << "FA: Error in test 5: got cost and previous " << fa.get_distance()[i] << " and "
            << fa.get_previous()[i] << " instead of " << exp_dist[i] << " and " << exp_prev[i] << std::endl;
        }
    }
    if(!gone_wrong)
    cerr << "FA: Test 5 - PASSED" << endl;


    // Test 6 dijkstra_dist function (first city in matrix)
    exp_dist = {0, 300000, 550000, 250000};
    exp_prev = {-1, 0, 1, 0};
    fa.dijkstra_dist(Krakow);
    gone_wrong = false;
    for(int i=0; i<4; i++){
        if(fa.get_distance()[i] != exp_dist[i] || fa.get_previous()[i] != exp_prev[i]){
            gone_wrong = true;
            std::cerr << "FA: Error in test 6: got cost and previous " << fa.get_distance()[i] << " and "
            << fa.get_previous()[i] << " instead of " << exp_dist[i] << " and " << exp_prev[i] << std::endl;
        }
    }
    if(!gone_wrong)
    cerr << "FA: Test 6 - PASSED" << endl;


    // Test 7 dijkstra_dist function (another city in matrix)
    exp_dist = {550000, 250000, 0, 800000};
    exp_prev = {1, 2, -1, 0};
    fa.dijkstra_dist(Gdynia);
    gone_wrong = false;
    for(int i=0; i<4; i++){
        if(fa.get_distance()[i] != exp_dist[i] || fa.get_previous()[i] != exp_prev[i]){
            gone_wrong = true;
            std::cerr << "FA: Error in test 7: got cost and previous " << fa.get_distance()[i] << " and "
            << fa.get_previous()[i] << " instead of " << exp_dist[i] << " and " << exp_prev[i] << std::endl;
        }
    }
    if(!gone_wrong)
    cerr << "FA: Test 7 - PASSED" << endl;

}


void Tests::test_Matrix() const
{
   // TESTS OF MATRIX

    std::cout << std:: endl << "MATRIX TEST" << std::endl;

    Matrix matrix;
    City Krakow("Krakow", false, true);
    City Warszawa("Warszawa", false, true);
    City Gdynia("Gdynia", false, true);
    City Wroclaw("Wroclaw", false, true);


    // Test 0 - Creating an empty matrix
    if(matrix.get_size() != 0)
    std::cerr << "MATRIX: TEST 0 - FAILED" << std::endl;
    else if(matrix(Krakow, Warszawa) != nullptr)
    std::cerr << "MATRIX: TEST 0 - FAILED" << std::endl;
    else
    std::cerr << "MATRIX: TEST 0 - PASSED" << std::endl;


    // Test 1 - Adding connection to matrix
    DirectConnection Krakow_Warszawa(1,300000,80,240,Krakow,Warszawa,Bus);
    matrix.add_connection(&Krakow_Warszawa);

    if(matrix.get_size() != 2)
    std::cerr << "MATRIX: TEST 1 - FAILED" << std::endl;
    else if(matrix(Krakow,Warszawa)->get_connection_id()!=1)
    std::cerr << "MATRIX: TEST 1 - FAILED" << std::endl;
    else
    std::cerr << "MATRIX: TEST 1 - PASSED" << std::endl;


    // Test 2 - Adding more matrix
    DirectConnection Warszawa_Gdynia(2,250000,45,180,Warszawa,Gdynia, Bus);
    DirectConnection Wroclaw_Krakow(3,250000,45,180,Wroclaw,Krakow, Bus);
    matrix.add_connection(&Warszawa_Gdynia);
    matrix.add_connection(&Wroclaw_Krakow);

    if(matrix.get_size() != 4)
    std::cerr << "MATRIX: TEST 2 - FAILED" << std::endl;
    else if(matrix(Warszawa, Gdynia)->get_connection_id() != 2 || matrix(Krakow, Wroclaw)->get_connection_id() != 3)
    std::cerr << "MATRIX: TEST 2 - FAILED" << std::endl;
    else if(matrix(Gdynia, Krakow) != nullptr)
    std::cerr << "MATRIX: TEST 2 - FAILED" << std::endl;
    else
    std::cerr << "MATRIX: TEST 2 - PASSED" << std::endl;

    // Test 3 - cleaning matrix
    matrix.clean();
    if(matrix(1,2) != nullptr)
    std::cerr << "MATRIX: TEST 3 - FAILED" << std::endl;
    else
    std::cerr << "MATRIX: TEST 3 - PASSED" << std::endl;
}


void Tests::test_RouteFinder() const
{
    cerr << endl << "ROUTE FINDER TESTS" << endl;

    // Test 0 - creating Route Finder;
    try
    {
        RouteFinder rf("test_file.csv");
        cerr << "RF: Test 0 - PASSED" << endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "RF: Test 0 - FAILED with error: " << e.what() << endl;
    }

    // Test 1 - correctness of data base in Route Finder
    RouteFinder rf("test_file.csv");
    if(rf.get_db().get_connections().size() != 4)
        cerr << "RF: TEST 1 - FAILED" << endl;
    else
        cerr << "RF: TEST 1 - PASSED" << endl;

    // Test 2 - Finding city by name
    City cR("Radom", false, false);
    if(rf.find_city("Radom") != cR)
        cerr << "RF: TEST 2 - FAILED" << endl;
    else
        cerr << "RF: TEST 2 - PASSED" << endl;

    // Test 3 - Finding connection no changes
    if(rf.find_user_connection("Warszawa", "Radom", CHEAPEST, TRAIN).get_connection_elements().size() != 1)
        cerr << "RF: TEST 3 - FAILED" << endl;
    else
        cerr << "RF: TEST 3 - PASSED" << endl;

    // Test 4 - Finding connection with change
    if(rf.find_user_connection("Kraków", "Radom", CHEAPEST, TRAIN).get_connection_elements().size() != 2)
        cerr << "RF: TEST 4 - FAILED" << endl;
    else
        cerr << "RF: TEST 4 - PASSED" << endl;
    
    // Test 5 - Finding cheapest connection, type-BUS
    if(rf.find_user_connection("Warszawa", "Radom", CHEAPEST, TRAIN).get_cost() != 20)
        cerr << "RF: TEST 5 - FAILED" << endl;
    else
        cerr << "RF: TEST 5 - PASSED" << endl;

    // Test 6 - Finding fastest connection, type-BUS
    if(rf.find_user_connection("Warszawa", "Radom", FASTEST, TRAIN).get_time() != 90)
        cerr << "RF: TEST 6 - FAILED" << endl;
    else
        cerr << "RF: TEST 6 - PASSED" << endl;

    // Test 7 - Finding shortest connection, type-BUS
    if(rf.find_user_connection("Warszawa", "Radom", SHORTEST, TRAIN).get_distance() != 50000)
        cerr << "RF: TEST 7 - FAILED" << endl;
    else
        cerr << "RF: TEST 7 - PASSED" << endl;

    // Test 8 - Finding cheapest connection, type-BOTH, with change
    if(rf.find_user_connection("Kraków", "Radom", CHEAPEST, TRAIN).get_cost() != 110)
        cerr << "RF: TEST 8 - FAILED" << endl;
    else
        cerr << "RF: TEST 8 - PASSED" << endl;

    // Test 9 - Finding cheapest connection, type-BOTH, with change, Bus and train
    if(rf.find_user_connection("Tarnów", "Warszawa", CHEAPEST, BOTH).get_cost() != 76)
        cerr << "RF: TEST 9 - FAILED" << endl;
    else
        cerr << "RF: TEST 9 - PASSED" << endl;

    // Test 10 - Finding fastest connection, with 2 changes
    if(rf.find_user_connection("Tarnów", "Kraków", CHEAPEST, BOTH).get_time() != 370)
        cerr << "RF: TEST 10 - FAILED" << endl;

    else if(rf.find_user_connection("Tarnów", "Kraków", CHEAPEST, BOTH).get_connection_elements().size() != 3)
        cerr << "RF: TEST 10 - FAILED" << endl;
    else
        cerr << "RF: TEST 10 - PASSED" << endl;

    // Test 11 searching not existing connection
     try
    {
        rf.find_user_connection("Tarnów", "Radom", CHEAPEST, TRAIN);
        cerr << "RF: Test 11 - FAILED" << endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "RF: Test 11 - PASSED with error: " << e.what() << endl;
    }
}


void Tests::run_test() const
{
    this->test_City();
    this->test_Connection();
    this->test_DataBase();
    this->test_DirectConnection();
    this->test_FinderAlgorithms();
    this->test_Matrix();
    this->test_RouteFinder();
}