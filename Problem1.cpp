#include "Problem1.h"
using namespace std;
#include <fstream>
// void Problem1::readInput(const string &filename)
// {
//     ifstream in(filename);
//     if(!in.is_open()){
//         cout<<"Khong the mo"<<filename<<endl;

//     }
//     in >> n >> m >> s >> t;
//     g.setSize(n);
//     for(int i = 0; i < m ; i++){
//         int u , v, c;
//         in >> u >> v >> c;
//         g.addEdge(u,v,c);
//     }
//     in.close();
// }

Problem1::Problem1(Graph &g, int s, int t)
    : Problem(g), s(s), t(t), maxFlow(0) {}

void Problem1::solve()
{
   
    Graph temp = g;

    Dinic dinic(temp, s, t);
    maxFlow = dinic.maxFlow();
}

void Problem1::show()
{
    cout << "[Problem 1]\n";
    cout << "Luong cuc dai (Max Flow): " << maxFlow << "\n\n";
}