#pragma once
#include "Problem.h"

using namespace std;

class Problem1 : public Problem {
    private:
        int s, t;
        int maxFlow;
    
    public:
        Problem1(Graph &g, int s, int t);
    
        void solve() override;
        void show() override;
    };

