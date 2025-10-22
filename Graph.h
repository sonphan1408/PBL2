#pragma once
#include"Edge.h"
#include <vector>
using namespace std;
class Graph
{
private:
    int n;
    vector<vector<Edge>> adj;
public:

    Graph(int n);
    ~Graph(){};
    void addEdge(int u, int v, int cap, int cost = 0);
     vector<vector<Edge>> &getAdj() ;
    int size();
};


