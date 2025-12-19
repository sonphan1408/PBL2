#pragma once
#include <iostream>
#include"Dinic.h"
using namespace std;
class Problem {
    protected:
        Graph &g;   
    public:
        Problem(Graph &graph) : g(graph) {}
        virtual void solve() = 0;
        virtual void show() = 0;
    };