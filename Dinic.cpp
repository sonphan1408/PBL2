#include "Dinic.h"

using namespace std;
#define INF 99999
bool Dinic::BFS()
{   
  //  cout << "[DEBUG] BFS started\n";
    // khoi tao level
    level.assign(g.size()+1,-1);
    // khoi tao queue
    Queue<int> q(g.size() + 1);
    level[s] = 0;
    q.enqueue(s);
    auto &adj = g.getAdj();
    
    while(!q.isEmpty()){
        int u = q.getFront();
        q.dequeue();
       // cout << "  Visiting node: " << u << endl; 
        // duyet cac canh ke
        for(auto &v : adj[u]){
         //   cout << "[DEBUG] " << u << " -> " << v.to
         //<< " flow=" << v.flow
        // << " cap=" << v.capacity << "\n";
            if(level[v.to] == -1 && v.flow < v.capacity && v.active == 1){
                level[v.to] = level[u] + 1;
                q.enqueue(v.to);  
            //    cout << "    Found edge: " << u << " -> " << v.to
              // << " (flow=" << v.flow << ", cap=" << v.capacity << ")\n";
            }
        }
    }
    //cout << "[DEBUG] BFS finished, reachable sink? "
      //   << (level[t] != -1 ? "YES" : "NO") << endl; 
    return level[this->t] != -1;
}
int Dinic::DFS(int u, int pushed)
{
    if(u == this->t) return pushed;
    auto & adj = g.getAdj();
    

    for(int &i = pos[u]; i < adj[u].size();i++){
        Edge &e = adj[u][i];    
        if(level[e.to] == level[u] + 1 && e.flow < e.capacity && e.active == 1 ){
            int flow = DFS(e.to, min(pushed,e.capacity - e.flow));
            if (flow > 0){
        //        cout << "  Pushing flow " << flow << " along edge " << u
          //          << " -> " << e.to << endl;
                e.flow += flow;
                adj[e.to][e.rev].flow -= flow;
                return flow; 
            }
        }
    } 
    return 0;
}
int Dinic::maxFlow()
{
    int maxF = 0;
    while(BFS()){
        pos.assign(g.size() + 1,0);
        while(int pushed = DFS(this->s,INF) ){
            //cout << "[DEBUG] Added flow: " << pushed << endl;
            
            maxF += pushed;
        }
       // cout << "[DEBUG] One BFS phase done, total flow = " << maxF << endl;
    }
    cout << " Max flow  = " << maxF << endl;
    return maxF;    
}