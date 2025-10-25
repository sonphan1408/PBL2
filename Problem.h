#pragma once
#include <iostream>
#include"Dinic.h"
using namespace std;
class Problem
{
public:
    virtual void readInput(const string &filename) = 0;
    virtual void solve() = 0;
    virtual void show() = 0;

};