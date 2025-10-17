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
    Edge(int to, int rev, int capacity, int cost = 0) : to(to), rev(rev), capacity(capacity), cost(cost), flow(0){};
    ~Edge();
};


