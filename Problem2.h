#include "Problem.h"
using namespace std;

class Problem2 : public Problem {
    private:
        int maxCost;
        int target;
    
        int bestFlow;
        int usedBudget;
        std::vector<OriginalEdge> bestRepairs;
    
    public:
        Problem2(Graph &g, int maxCost, int target);
    
        void solve() override;
        void show() override;
    };
    
