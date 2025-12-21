#include "Application.h"
#include "Problem1.h"
#include "Problem2.h"
#include "Problem3.h"

#include <iostream>
#include <fstream>

using namespace std;

Application::Application()
{
    graphLoaded = false;
}
string Application::getFileName()
{
    return fileName;
}


void Application::loadGraphList(const string &filename)
{
    ifstream in(filename);
    if (!in.is_open()) {
        cout << "Khong mo duoc file danh sach do thi!\n";
        return;
    }

    int k;
    in >> k;
    graphFiles.clear();

    for (int i = 0; i < k; i++) {
        string name;
        in >> name;
        graphFiles.push_back(name);
    }

    in.close();
}



void Application::chooseGraph()
{

    if (graphFiles.empty()) {
        cout << "Danh sach do thi rong!\n";
        return;
    }

    cout << "\n===== DANH SACH DO THI =====\n";
    for (auto i = 0; i < graphFiles.size(); i++) {
        cout << i + 1 << ". " << graphFiles[i] << endl;
    }

    int choice;
    cout << "Chon do thi: ";
    cin >> choice;

    if (choice < 1 || choice > graphFiles.size()) {
        cout << "Lua chon khong hop le!\n";
        return;
    }
    fileName = graphFiles[choice - 1];
    loadGraphFile(graphFiles[choice - 1]);
}

void Application::saveGraph()
{
    

    ofstream out(fileName);
    if (!out.is_open()) {
        cout << "Khong mo duoc file de ghi!\n";
        return;
    }

    out << g.size() << " " << g.getNumberEdge() << "\n";

    auto &locs = g.getLocations();
    out << locs.size() << "\n";
    for (auto &l : locs) {
        out << l.getID() << " "
            << l.getName() << " "
            << l.getType() << " "
            << l.getDemand() << "\n";
    }

    auto &data = g.getOriginal();
    for (auto &e : data) {
        out << e.u << " " << e.v << " "
            << e.cap << " " << e.cost << " "
            << e.active << "\n";
    }

    out.close();
    cout << "Da luu do thi vao file: " << fileName << endl;
}


void Application::loadGraphFile(const string &filename)
{
    ifstream in(filename);
    if (!in.is_open()) {
        cout << "Khong mo duoc file do thi!\n";
        return;
    }

    // reset graph
    g = Graph();
    graphLoaded = true;

    int n, m;
    in >> n >> m;
    g.setSize(n);
    g.setNumberEdge(m);

   
    int k;
    in >> k;
    for (int i = 0; i < k; i++) {
        int id, demand;
        string name, type;
        in >> id >> name >> type >> demand;
        g.addLocation(Location(id, name, type, demand));
    }

    for (int i = 0; i < m; i++) {
        int u, v, cap, cost;
        bool active;
        in >> u >> v >> cap >> cost >> active;


        g.addEdge(u, v, cap, cost, active);
    }

    in.close();
    cout << "Da nap do thi: " << filename << endl;
}



void Application::editGraphMenu()
{
    if (!graphLoaded) {
        cout << "Chua nap do thi!\n";
        return;
    }

    int choice;
    cout << "\n=== CHINH SUA DO THI ===\n";
    cout << "1. Them canh moi\n";
    cout << "2. Bat/Tat canh \n";
    cout << "0. Quay lai\n";
    cout << "Chon: ";
    cin >> choice;

    switch (choice) {
    case 1: addEdgeMenu(); break;
    case 2: toggleEdgeMenu(); break;
    }
}

void Application::addEdgeMenu()
{
    int u, v, cap, cost;
    bool active;

    cout << "Nhap u v cap cost active: ";
    cin >> u >> v >> cap >> cost >> active;

    g.addEdge(u, v, cap, cost, active);
    cout << "Da them canh!\n";
    saveGraph();
}

void Application::toggleEdgeMenu()
{
    auto &data = g.getOriginal();

    cout << "\n=== DANH SACH CANH ===\n";
    for (int i = 0; i < data.size(); i++) {
        cout << i << ": (" << data[i].u << " -> " << data[i].v
             << "), active = " << data[i].active
             << ", cost = " << data[i].cost << endl;
    }

    int id;
    cout << "Chon canh can doi trang thai: ";
    cin >> id;

    if (id < 0 || id >= data.size()) {
        cout << "ID khong hop le!\n";
        return;
    }

    data[id].active = !data[id].active;
    g.rebuildAdj();
    
    cout << "Da doi trang thai canh!\n";
    saveGraph();
}



void Application::runProblem1()
{
    if (!graphLoaded) return;

    Problem1 p1(g, 1, g.size());
    p1.solve();
    p1.show();
}

void Application::runProblem2()
{
    if (!graphLoaded) return;

    int maxCost, target;
    cout << "Nhap maxCost va target: ";
    cin >> maxCost >> target;

    Problem2 p2(g, maxCost, target);
    p2.solve();
    p2.show();
}

void Application::runProblem3()
{
    if (!graphLoaded) return;

    Problem3 p3(g);
    p3.solve();
    p3.show();
}



void Application::menu()
{
    loadGraphList("graphs.txt");

    int choice;
    do {
        cout << "\n===== MENU CHINH =====\n";
        cout << "1. Chon do thi\n";
        cout << "2. Chinh sua do thi\n";
        cout << "3. Bai toan 1 (Max Flow)\n";
        cout << "4. Bai toan 2 (Toi uu sua chua)\n";
        cout << "5. Bai toan 3 (Phan phoi cuu tro)\n";
        cout << "0. Thoat\n";
        cout << "Chon: ";
        cin >> choice;

        switch (choice) {
        case 1: chooseGraph(); break;
        case 2: editGraphMenu(); break;
        case 3: runProblem1(); break;
        case 4: runProblem2(); break;
        case 5: runProblem3(); break;
        }
    } while (choice != 0);
}
