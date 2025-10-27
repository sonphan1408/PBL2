#pragma once
#include "Problem.h"

using namespace std;
class Problem1 : public Problem
{
private:
    Graph g;
    int s,t,n,m;
    int maxFlow = 0;

public:
    Problem1(){};

    void readInput(const string &filename) override;
    void solve() override;
    void show() override;   
};

