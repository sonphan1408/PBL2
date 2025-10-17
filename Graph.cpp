#include"Graph.h"
void Graph::addEdge(int u,int v,int cap, int cost = 0)
{
    Edge a(v, adj[v].size(), cap, cost);
    Edge b(u, adj[u].size(), 0, -cost);
    adj[u].push_back(a);
    adj[v].push_back(b);
}
vector<vector<Edge>>& Graph::getAdj()
{
    return adj;
}
int Graph::size()
{
    return n;
}
