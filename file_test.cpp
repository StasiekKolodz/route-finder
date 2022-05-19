using namespace std;
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include "DirectConnection.h"

int main()
{
    ifstream file;
    file.open("connections.csv");

    vector<DirectConnection> connections; //wektor przechowujący w sobie obiekty klasy DirectConnection

    string line = "";
    getline(file, line); //pozbywanie sie pierwszej linijki nagłówków
    line = "";

    while(getline(file, line))
    {
        unsigned int connection_id;
        unsigned int distance;
        unsigned int cost;
        unsigned int time;
        string nameA;
        bool isTrainA;
        bool isBusA;
        string nameB;
        bool isTrainB;
        bool isBusB;

        string tempString; //pusty string do zapisu atrybutow DirectConnection, ktore przekonwertujemy na int/double

        stringstream inputString(line);

        getline(inputString, tempString, ','); //zapisywanie do tymczasowego stringa id stringa
        connection_id = atoi(tempString.c_str()); //konwercja stringa na inta

        tempString = ""; //czyszczenie chwilowego stringa

        getline(inputString, tempString, ',');
        distance = atoi(tempString.c_str());

        tempString = "";

        getline(inputString, tempString, ',');
        cost = atoi(tempString.c_str());

        tempString = "";

        getline(inputString, tempString, ',');
        time = atoi(tempString.c_str());

        getline(inputString, nameA, ',');

        tempString = "";

        getline(inputString, tempString, ',');
        if(tempString == "True")
        {
            isTrainA = true;
        }
        else isTrainA = false;

        tempString = "";

        getline(inputString, tempString, ',');
        if(tempString == "True")
        {
            isBusA = true;
        }
        else isBusA = false;

        getline(inputString, nameB, ',');

        tempString = "";

        getline(inputString, tempString, ',');
        if(tempString == "True")
        {
            isTrainB = true;
        }
        else isTrainB = false;

        tempString = "";

        getline(inputString, tempString, ',');
        if(tempString == "True")
        {
            isBusB = true;
        }
        else isBusB = false;

        City PlaceA(nameA, isTrainA, isBusA);
        City PlaceB(nameB, isTrainB, isBusB);

        DirectConnection connection(connection_id, distance, cost, time, PlaceA, PlaceB); //tworzenie obiektu DirectConnection

        connections.push_back(connection); //dodanie obiektu do wektora połączeń
    }
    

    for(auto connection : connections)
    {
        cout << "Id: " << connection.get_connection_id() << endl <<
        "Distance: " << connection.get_distance() << endl <<
        "Cost: " << connection.get_cost() << endl <<
        "Time: " << connection.get_time() << endl <<
        "From: " << connection.get_PlaceA().get_name() << "(" << connection.get_PlaceA().isTrainStation() <<
        connection.get_PlaceA().isBusStation() << ")" << endl <<
        "To: " <<  connection.get_PlaceB().get_name() << "(" << connection.get_PlaceB().isTrainStation() <<
        connection.get_PlaceB().isBusStation() << ")";
    }
    return 0;
}