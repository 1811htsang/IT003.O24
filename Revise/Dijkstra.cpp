#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int maxn = 100001;

void intput(int &v, int &e, int &start, int &ent, vector<pair<int,int>> adj[]) {
    cin >> start >> ent;
    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        int x, y; cin >> x >> y;
        int w; cin >> w;
        adj[x].push_back({y,w});
    }
}

void dijkstra(int v, int sub_v, int ent, vector<pair<int,int>> adj[], int parent[]) {
    vector<int> d(v + 1, INF);
    d[sub_v] = 0;
    parent[sub_v] = sub_v;
    priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair <int,int> > > pr_qu;
    pr_qu.push({d[sub_v], sub_v});
    while (pr_qu.empty() == false) {
        pair<int,int> top = pr_qu.top();
        pr_qu.pop();
        int length = top.first;
        int current_v = top.second;
        if (length > d[current_v]) continue;
        else {
            for (auto it: adj[current_v]) {
                int u = it.first;
                int w = it.second;
                if (d[u] > d[current_v] + w) {
                    d[u] = d[current_v] + w;
                    pr_qu.push({d[u], u});
                    parent[u] = current_v;
                }
            }
        }
    }

    for (int i = 1; i <= v; i++) {
        cout << d[i] << " ";
    }
    cout << endl;
    cout << d[ent] << "\n";
    vector<int> path;
    while (1) {
        path.push_back(ent);
        if (ent == sub_v) break;
        ent = parent[ent];
    }
    reverse(begin(path), end(path));
    for (auto i: path) {cout << i << " ";}
}

int main() {
    int v,e,s,et;
    vector<pair<int,int>> adj[1000];
    int parent[1000];
    intput(v,e,s,et,adj);
    dijkstra(v,s,et,adj, parent);
}