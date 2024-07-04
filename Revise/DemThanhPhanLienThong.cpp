#include <bits/stdc++.h>
using namespace std;

void input(int &v, int &e, vector<int> adj[], bool visited[]) {
    cin >> v;
    cin >> e;
    for (int i = 0; i < e; i++) {
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
}

void dfs(int u, bool visited[], vector<int> adj[]) {
    cout << u << " ";
    visited[u] = true;
    for (auto x: adj[u]) {
        if (!visited[x]) {
            dfs(x, visited, adj);
        }
    }
    
}

int DemThanhPhanLienThong(int v,bool visited[], vector<int> adj[]) {
    int count = 0;
    for (int i = 0; i <= v; i++) {
        if (!visited[i]) {
            ++count;
            cout << "thanh phan lien thong thu " << count << ": \n";
            dfs(i, visited, adj);
        }
    }
    return count;
}

int main() {
    int v,e;
    vector<int> adj[1000];
    bool visited[100];
    input(v,e,adj,visited);
    dfs(1, visited, adj);
    cout << DemThanhPhanLienThong(v, visited, adj);
}