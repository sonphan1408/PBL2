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
        received.clear();
        missing.clear();
    
        Graph temp = g;
    
        int N = temp.size();
        int SS = N + 1;
        int TT = N + 2;
    
        temp.setSize(N + 2);
    
       
        for (auto &loc : g.getLocations()) {
            int id = loc.getID();
    
            if (id < 1 || id > N) continue; 
    
            if (loc.getType() == "warehouse") {
                temp.addEdge(SS, id, INF,0,true);
            }
            else if (loc.getType() == "area") {
                temp.addEdge(id, TT, loc.getDemand(),0,true);
            }
        }
    
        Dinic dinic(temp, SS, TT);
        dinic.maxFlow();
    
        int adjSize = temp.getAdj().size();
    
        for (auto &loc : g.getLocations()) {
            if (loc.getType() != "area") continue;
    
            int id = loc.getID();
            int demand = loc.getDemand();
            int got = 0;
    
            if (id >= 0 && id < adjSize) {
                for (auto &e : temp.getAdj()[id]) {
                    if (e.to == TT) {
                        got = e.flow;
                        break;
                    }
                }
            }
    
            received[id] = got;
            missing[id] = max(0, demand - got);
    
            if (got >= demand) {
                servedCount++;
            }
        }
    }
    
    
    
void Problem3::show()
{
    cout << "So khu vuc duoc phuc vu day du: "
         << servedCount << "\n";

    for (auto &loc : g.getLocations())
    {
        if (loc.getType() == "area")
        {
            int id = loc.getID();

            cout << "Khu vuc " << loc.getName() << ": ";

            if (missing[id] == 0)
            {
                cout << "DUOC PHUC VU DAY DU";
            }
            else
            {
                cout << "THIEU " << missing[id];
            }

            cout << " (Nhan "
                 << received[id] << "/"
                 << loc.getDemand() << ")\n";
        }
    }

    cout << "\n";
}
