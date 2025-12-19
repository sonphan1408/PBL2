#pragma once
#include "Problem.h"
#include "Location.h"
#include <vector>

class Problem3 : public Problem {
    private:
        int servedCount;
    
    public:
        Problem3(Graph &g);
    
        void solve() override;
        void show() override;
    };