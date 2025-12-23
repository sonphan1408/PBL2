#pragma once
#include "Problem.h"
#include "Location.h"
#include <vector>
#include <unordered_map>

class Problem3 : public Problem {
    private:
        int servedCount;
        unordered_map<int, int> received;  
        unordered_map<int, int> missing;  
    public:
        Problem3(Graph &g);
    
        void solve() override;
        void show() override;
    };