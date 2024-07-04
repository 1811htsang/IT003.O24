#include <bits/stdc++.h>
using namespace std;

void nhap(int &v, int &e, vector<pair<int,int>> &el) {
    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        int x,y;
        cin >> x >> y;
        el.push_back({x,y});
    }
}

void biendoi(int v, int e, vector<pair<int,int>> el, vector<int> adj[]) {
    for (auto edge: el) {
        adj[edge.first].push_back(edge.second);
        adj[edge.second].push_back(edge.first);
    }
}

void printDSC(int v, int e, vector<pair<int,int>> el) {
    for (auto edge: el) {
        cout << edge.first << " " << edge.second << "\n";
    }
}

void printDSK(int v, int e, vector<int> adj[]) {
    for (int i = 0; i < v; i++) {
        cout << i << ": ";
        for (auto j: adj[i]) {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main() {
    int v,e;
    vector<pair<int,int>> el;
    vector<int> adj[100];
    nhap(v,e,el);
    cout << endl;
    printDSC(v,e,el);
    biendoi(v,e,el,adj);
    cout << endl;
    printDSK(v,e,adj);
}