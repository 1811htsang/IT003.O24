#include <bits/stdc++.h>
using namespace std;

void nhap(int &start, int &v, int &e, vector<int> adj[], bool visited[]) {
    cin >> start;
    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
}

void DFS(int sub_v,int v, int e, vector<int> adj[], bool visited[]) {
    cout << sub_v << " ";
    visited[sub_v] = true;
    for (auto i: adj[sub_v]) {
        if (!visited[i]) {
            DFS(i,v,e,adj,visited);
        }
    }
}



int main() {
    int v,e, start;
    vector<int> adj[100];
    bool visited[100];
    nhap(start,v,e,adj,visited);
    DFS(start, v,e,adj,visited);
}