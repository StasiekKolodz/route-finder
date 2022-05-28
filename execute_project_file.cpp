#include <iostream>
#include "Matrix.h"
#include "DataBase.h"
#include <vector>
#include "enums.h"
#include "RouteFinder.h"

using namespace std;

int main()
{

    // TESTS OF MATRIX

    std::cout << "MATRIX TEST" << std::endl << std::endl;

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


    // TEST DATA BASE:
    DirectConnection Warszawa_Gdynia_db(2,250000,45,180,Warszawa,Gdynia, Bus);
    DirectConnection Wroclaw_Krakow_db(3,250000,45,180,Wroclaw,Krakow, Bus);
    DirectConnection Krakow_Warszawa_db(1,300000,80,240,Krakow,Warszawa,Bus);

    DataBase db("connections.csv");
    db.add_direct_connection(Krakow_Warszawa_db);
    db.add_direct_connection(Warszawa_Gdynia_db);
    db.add_direct_connection(Wroclaw_Krakow_db);

    // DirectConnection Wroclaw_Krakow_2(4,250000,20,180,Wroclaw,Krakow, Train);

    // db.add_direct_connection(Wroclaw_Krakow_2);

    db.create_cheapest_matrix(BOTH);
    std::cerr << db.get_current_matrix().get_size() << endl;


    //TESTY CSV

    std::vector<DirectConnection> connections;
    DataBase base("connections.csv", connections);
    base.load_file();
    for(auto connection : base.get_connections())
    {
        connection.print_connection_details();
        cout << endl;
    }


    // base.add_direct_connection(200,20,120,"Sopot","Świnioujście",Train);

    base.update_data_base();

    for(auto c : base.get_cities())
    {
        cout << c.get_name() << "(" <<c.isTrainStation()<< "," << c.isBusStation() << ")" << endl;
    }

    // base.create_cheapest_matrix(BOTH);
    // base.get_current_matrix().description();
    // base.create_cheapest_matrix(BUS);
    // base.create_cheapest_matrix(TRAIN);
    // base.create_fastest_matrix(BOTH);
    // base.create_fastest_matrix(BUS);
    // base.create_fastest_matrix(TRAIN);
    base.create_shortest_matrix(BOTH);
    base.create_shortest_matrix(BUS);
    base.create_shortest_matrix(TRAIN);

    RouteFinder rf("connections.csv");
    cout << endl;
    cout << rf.find_user_connection("Kraków","Tarnów", SHORTEST, BOTH);
    try
    {
        Connection con = rf.find_user_connection("Kraków","Tarnów", SHORTEST, TRAIN);
    }
    catch(ConnectionNotFoundException const& e)
    {
        std::cerr << e.what() << std::endl;
        std::cerr << "Chosen cities:" << std::endl << e.what_PlaceA() << std::endl;
        std::cerr << e.what_PlaceB() << std::endl;
    }



}