#pragma once
#include <iostream>
using namespace std;
class Location
{
private:
    int id;
    string name;
    string type;
    int demand;
public:
    Location(){};
    Location(int id, string name, string type, int demand = 0) : id(id), name(name), type(type), demand(demand){};
    ~Location();
    int getID();
    string getType();
    int getDemand();

    
};

