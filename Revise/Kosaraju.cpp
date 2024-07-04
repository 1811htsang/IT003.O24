#include <bits/stdc++.h>
using namespace std;

void nhap(int &v, int &e, vector<int> adj[], vector<int> t_adj[], bool visited[]) {
    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        t_adj[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
}

void DFS1(int sub_v, int v, int e, vector<int> adj[], bool visited[], stack<int> &st) {
    visited[sub_v] = true;
    for (auto i: adj[sub_v]) {
        if (!visited[i]) {
            DFS1(i,v,e,adj,visited, st);
        }
    }
    cout << sub_v << " ";
    st.push(sub_v);
}

void DFS2(int sub_v, int v, int e, vector<int> t_adj[], bool visited[]) {
    
    visited[sub_v] = true;
    cout << sub_v << " ";
    for (auto i: t_adj[sub_v]) {
        if (!visited[i]) {
            DFS2(i,v,e,t_adj,visited);
        }
    }
}

void ListSCC(int v, int e, vector<int> adj[], vector<int> t_adj[], bool visited[], stack<int> &st) {
    memset(visited, false, sizeof(visited));
    for (int i = 1; i <= v; i++) {
        if (!visited[i]) {
            DFS1(i,v,e,adj,visited, st);
        }
    }
    cout << endl;
    memset(visited, false, sizeof(visited));
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        if (!visited[u]) {
            DFS2(u,v,e,t_adj,visited);
            cout << endl;
        }
    }
    
}

int main() {
    int v,e;
    vector<int> adj[100];
    vector<int> t_adj[100];
    bool visited[100];
    stack<int> st;
    nhap(v,e,adj,t_adj,visited);
    ListSCC(v,e,adj,t_adj,visited,st);
}