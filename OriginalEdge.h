#pragma once
using namespace std;
class OriginalEdge
{
public:
    int u;
    int v;
    int cap;
    int cost;
    bool active;
public:
    OriginalEdge(int u, int v, int cap, int cost,bool active) : u(u), v(v), cap(cap), cost(cost), active(active){};
    ~OriginalEdge();
    void setActive(bool set);
};

