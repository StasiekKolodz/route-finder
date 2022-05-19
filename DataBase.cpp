#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include "DataBase.h"

using namespace std;

void DataBase::load_file()
{
    ifstream file;
    file.open("connections.csv");

    // vector<DirectConnection> connections;

    string line = ""; //string to put the data into
    getline(file, line); //getting rid of the header line
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
}