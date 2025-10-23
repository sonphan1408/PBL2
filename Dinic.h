#include"Graph.h"
#include "MyQueue.cpp"
#include "MyQueue.h"
using namespace std;
class Dinic
{
private:
    Graph &g;
    int s,t;
    vector<int> level;
    vector<int> pos;  

public:
    Dinic(Graph &g, int s, int t) : g(g) , s(s), t(t){};
    ~Dinic(){};
    bool BFS();
    int DFS(int s, int flow);
    int maxFlow();
};


