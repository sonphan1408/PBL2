#include "Problem1.h"
using namespace std;
#include <fstream>
void Problem1::readInput(const string &filename)
{
    ifstream in(filename);
    if(!in.is_open()){
        cout<<"Khong the mo"<<filename<<endl;

    }
    in >> n >> m >> s >> t;
    g.setSize(n);
    for(int i = 0; i < m ; i++){
        int u , v, c;
        in >> u >> v >> c;
        g.addEdge(u,v,c);
    }
    in.close();
}
void Problem1::solve()
{
    Dinic dinic(g, s, t); 
    maxFlow = dinic.maxFlow();
   
}
void Problem1::show()
{
    cout << "\n==> Luong cuc dai (Max Flow): " << maxFlow << "\n";

}