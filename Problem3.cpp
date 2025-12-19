#include "Problem3.h"
#include <fstream>
#include <iostream>

using namespace std;
const int INF = 1e9;

Problem3::Problem3(Graph &g)
    : Problem(g), servedCount(0) {}

void Problem3::solve()
{
    servedCount = 0;

   
    Graph temp = g;

    int SS = 0;
    int TT = temp.size() + 1;

    temp.setSize(temp.size() + 2);

   
    for (auto &loc : temp.getLocations()) {
        if (loc.getType() == "warehouse") {
            temp.addEdge(SS, loc.getID(), INF);
        }
        else if (loc.getType() == "area") {
            temp.addEdge(loc.getID(), TT, loc.getDemand());
        }
    }

    Dinic dinic(temp, SS, TT);
    dinic.maxFlow();

   
    for (auto &loc : temp.getLocations()) {
        if (loc.getType() == "area") {
            int id = loc.getID();
            int need = loc.getDemand();

            for (auto &e : temp.getAdj()[id]) {
                if (e.to == TT && e.flow == need) {
                    servedCount++;
                    break;
                }
            }
        }
    }
}

void Problem3::show()
{
    cout << "[Problem 3]\n";
    cout << "So khu vuc duoc phuc vu day du: "
         << servedCount << "\n\n";
}