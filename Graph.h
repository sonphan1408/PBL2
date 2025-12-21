#pragma once
#include"Edge.h"
#include <vector>
#include "Location.h"
#include "OriginalEdge.h"
using namespace std;
class Graph
{
    

private:
    int n,m;
    vector<Location> locations;
    vector<vector<Edge>> adj;
    vector<OriginalEdge> data;
    

public:


    Graph(int n = 0);
    ~Graph(){};
    void addEdge(int u, int v, int cap, int cost = 0,bool active = 1);
    void addLocation(const Location &loc);
    vector<OriginalEdge> &getOriginal();
    vector<vector<Edge>> &getAdj() ; 
    vector<Location> &getLocations();
    int size();
    int getNumberEdge();
    void setSize(int size);
    void setNumberEdge(int size);
    void rebuildAdj();
};


