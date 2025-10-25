#include "Problem2.h"
#include <fstream>
using namespace std;

void Problem2::readInput(const string& filename)
{   
    ifstream  in(filename);
    if(!in.is_open()){
        cout<<"Khong the mo "<<filename<<endl;
        return;
    }
    in>> n >> m >> maxCost >> target;
    for(int i = 0; i < m;i++){
        Input ip;
        in >> ip.u >> ip.v >> ip.cap >>ip.cost ;
        data.push_back(ip); 
    }
    in.close();

} 
void Problem2::solve()
{
    for(int i = 1 ; i <= this->maxCost;i++){
        Graph g(n);
        for(auto a : data ){
            if(a.cost == 0 || a.cost <= i){
                g.addEdge(a.u,a.v,a.cap,a.cost);
            }
        }
        Dinic dinic(g,1,n);
        int flow = dinic.maxFlow();
        if(flow > bestFlow){
            bestFlow = flow;
            usedBudget = i;
        }
        if(bestFlow >= target){
            break;
        }
        

    }
}
void Problem2::show()
{
        if (bestFlow >= target)
            cout << "Dat duoc muc tieu voi chi phi " << usedBudget
                 << "\nLuong cuc dai: " << bestFlow << endl;
        else
            cout << "Can them chi phi de sua chua"<<endl;
    
}