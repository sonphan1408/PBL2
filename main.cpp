#include "Dinic.h"
using namespace std;
int main() {
;

    int n, m;
    cin >> n >> m;

    Graph g(n);
    

    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        g.addEdge(u, v, c);
    }
    //  cout<<"output"<<endl;
    //  auto &adj = g.getAdj();
    // for (int i = 0; i < adj.size();i++) {
    //    for(int j = 0; j < adj[i].size();j++ ){
    //     cout<<adj[i][j].to<<" "<<adj[i][j].rev<<" "<<adj[i][j].capacity<<endl;
    //  }
    //  }


      Dinic dinic(g, 1, 10);
      int maxflow = dinic.maxFlow();

      cout << "\n==> Luong cuc dai (Max Flow): " << maxflow << "\n";

    return 0;
}