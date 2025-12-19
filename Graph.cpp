#include"Graph.h"
Graph::Graph(int n)
{
    this->n = n;
    adj.resize(n+1);
    this->m = 0;
}
void Graph::addEdge(int u,int v,int cap, int cost, bool active )
{
    Edge a(v, adj[v].size(), cap, cost,active);
    Edge b(u, adj[u].size(), 0, -cost,active);
    adj[u].push_back(a);
    adj[v].push_back(b);
    

}
 vector<vector<Edge>>& Graph::getAdj() 
{
    return adj;
}
vector<Location>& Graph::getLocations()
{
    return locations;
}
int Graph::size()
{
    return n;
}
void Graph::setSize(int size)
{
    this->n = size;
    
    adj.resize(size+1);
}
void Graph::addLocation(const Location &loc)
{
    locations.push_back(loc);
}
int Graph::getNumberEdge()
{
    return this->m;
}
vector<OriginalEdge>& Graph::getOriginal()
{
    return data;
}
void Graph::setNumberEdge(int size)
{   
    this->m = size;
}