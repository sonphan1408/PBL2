#include"Graph.h"
Graph::Graph(int n)
{
    this->n = n;
    adj.resize(n+1);
}
void Graph::addEdge(int u,int v,int cap, int cost )
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
void Graph::setSize(int m)
{
    this->n = m;
    adj.resize(m+1);
}
