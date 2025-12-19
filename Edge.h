#pragma once
#include <iostream>
using namespace std;
class Edge
{   
public:
    int to;
    int rev;
    int capacity;
    int cost;
    int flow;
    bool active;
    Edge() : to(0), rev(0), capacity(0), cost(0), flow(0), active(1) {}
    Edge(int to, int rev, int capacity, int cost = 0,bool active = 1) : to(to), rev(rev), capacity(capacity), cost(cost), flow(0),active(active){};
    ~Edge(){};
};


