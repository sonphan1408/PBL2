#include "Problem.h"
using namespace std;
struct Input
{   
    int u;
    int v;
    int cap;
    int cost;
};
class Problem2 : public Problem
{
private:
        int n, m; // n so tram , m so tuyen van chuyen
        int target, maxCost;
        vector<Input> data;
        int bestFlow = 0;
        int usedBudget = 0;
    
public:
    Problem2(){};
    void readInput(const string &filename) override;
    void solve() override;
    void show() override;   
};

