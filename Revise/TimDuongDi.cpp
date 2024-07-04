#include <bits/stdc++.h>
using namespace std;

void nhap(int &be, int &en, int &v, int &e, vector<int> adj[], bool visited[], int parent[]) {
    cin >> be >> en;
    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
    memset(parent, 0, sizeof(parent));
}

void DFS(int start, int v, int e, vector<int> adj[], bool visited[], int parent[]) {
    visited[start] = true;
    for (auto vertex: adj[start]) {
        if (!visited[vertex]) {
            parent[vertex] = start;
            DFS(vertex,v,e,adj,visited,parent);
        }
    }
}

void findPath(int be, int en, int v, int e, vector<int> adj[], bool visited[], int parent[]) {
    DFS(be,v,e,adj,visited,parent);
    if (!visited[en]) {
        cout << "none";
    } else {
        vector<int> path;
        while (en != be) {
            path.push_back(en);
            en = parent[en];
        }        
        path.push_back(be);
        reverse(path.begin(), path.end());
        for (auto i: path) {
            cout << i << " ";
        }
    }
    
}

int main() {
    int v,e, st, en;
    vector<int> adj[100];
    bool visited[100];
    int parent[100];
    nhap(st,en,v,e,adj,visited,parent);
    findPath(st,en,v,e,adj,visited,parent);
}