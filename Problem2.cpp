#include "Problem2.h"
#include <fstream>
using namespace std;

// void Problem2::readInput(const string& filename)
// {   
//     ifstream  in(filename);
//     if(!in.is_open()){
//         cout<<"Khong the mo "<<filename<<endl;
//         return;
//     }
//     in>> n >> m >> maxCost >> target;
//     for(int i = 0; i < m;i++){
//         Input ip;
//         in >> ip.u >> ip.v >> ip.cap >>ip.cost ;
//         data.push_back(ip); 
//     }
//     in.close();

// } 
Problem2::Problem2(Graph &g, int maxCost, int target)
    : Problem(g), maxCost(maxCost), target(target),
      bestFlow(0), usedBudget(0) {}

void Problem2::solve()
{
    bestFlow = 0;
    usedBudget = 0;
    bestRepairs.clear();

    vector<OriginalEdge> &data = g.getOriginal();
    int n = g.size();

    for (int budget = 0; budget <= maxCost; budget++) {

        Graph temp(n);
        vector<OriginalEdge> repaired;

        for (auto &e : data) {
            if (e.active) {
                temp.addEdge(e.u, e.v, e.cap, e.cost, true);
            }
            else if (!e.active && e.cost <= budget) {
                temp.addEdge(e.u, e.v, e.cap, e.cost, true);
                repaired.push_back(e);
            }
        }

        Dinic dinic(temp, 1, n);
        int flow = dinic.maxFlow();

        if (flow > bestFlow) {
            bestFlow = flow;
            usedBudget = budget;
            bestRepairs = repaired;
        }

        if (bestFlow >= target)
            break;
    }
}

void Problem2::show()
{
    cout << "[Problem 2]\n";

    if (bestFlow >= target) {
        cout << "Dat muc tieu voi chi phi: " << usedBudget << "\n";
        cout << "Luong cuc dai: " << bestFlow << "\n";
        cout << "Cac canh duoc sua:\n";
        for (auto &e : bestRepairs) {
            cout << "  (" << e.u << " -> " << e.v
                 << "), cost = " << e.cost << "\n";
        }
    } else {
        cout << "Khong dat duoc muc tieu voi chi phi toi da\n";
    }
    cout << "\n";
}