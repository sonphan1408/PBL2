#pragma once
#include "Graph.h"
#include <vector>
#include <string>

class Application
{
private:
    Graph g;                         // graph đang thao tác
    bool graphLoaded;                // đã nạp graph chưa
    std::vector<string> graphFiles; // danh sách file graph

public:
    Application();

   
    void loadGraphList(const string &filename); // đọc danh sách graph
    void chooseGraph();                              // chọn graph
    void loadGraphFile(const string &filename); // nạp graph cụ thể

    void editGraphMenu();
    void addEdgeMenu();
    void toggleEdgeMenu();

  
    void runProblem1();
    void runProblem2();
    void runProblem3();

  
    void menu();
};
