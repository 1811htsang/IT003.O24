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

void BFS(int start, int v, int e, vector<int> adj[], bool visited[]) {
    queue<int> qu;
    qu.push(start);
    visited[start] = true;
    while (qu.empty() == false) {
        int temp = qu.front();
        visited[temp] = true;
        cout << temp << " ";
        qu.pop();
        for (auto i: adj[temp]) {
            if (!visited[i]) {
                qu.push(i);
                visited[i] = true;
            }
        }
    }
}

int main() {
    int v,e, start;
    vector<int> adj[100];
    bool visited[100];
    nhap(start,v,e,adj,visited);
    BFS(start, v,e,adj,visited);
}