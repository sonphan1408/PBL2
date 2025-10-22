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
    Edge() : to(0), rev(0), capacity(0), cost(0), flow(0) {}
    Edge(int to, int rev, int capacity, int cost = 0) : to(to), rev(rev), capacity(capacity), cost(cost), flow(0){};
    ~Edge(){};
};


