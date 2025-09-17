#include <bits/stdc++.h>
using namespace std;    

class CA {
public:
    int id, load;
    CA(int id) : id(id), load(0) {}
    bool operator<(const CA &other) const {
        return load > other.load; // min-heap theo load
    }
};

class LoadBalancer {
private:
    int m, k;
    vector<int> mapping;
    int maxLoad;

public:
    LoadBalancer(int m, int k) : m(m), k(k) {
        mapping.resize(m+1);
        maxLoad = 0;
    }

    void assignRequests() {
        priority_queue<CA> pq;
        for (int i = 1; i <= k; i++) pq.push(CA(i));

        for (int req = 1; req <= m; req++) {
            CA ca = pq.top(); pq.pop();
            mapping[req] = ca.id;
            ca.load++;
            maxLoad = max(maxLoad, ca.load);
            pq.push(ca);
        }
    }

    void printResult(const string &filename) {
        ofstream fout(filename);
        fout << "Minimum total time (max load): " << maxLoad << "\n";
        for (int req = 1; req <= m; req++) {
            fout << "Request " << req << " -> CA" << mapping[req] << "\n";
        }
        fout.close();
    }
};

int main() {
    ifstream fin("requests.txt");
    int m, k; fin >> m >> k;
    fin.close();
    LoadBalancer lb(m, k);
    lb.assignRequests();
    lb.printResult("output4.txt");
    cout << "Done! Output saved in output4.txt\n";
}
