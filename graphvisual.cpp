#include <bits/stdc++.h>
using namespace std;

// int a[1000][1000]; Dung cho danh sach canh sang ma tran ke

// vector<int> adj[1000]; Dung cho danh sach canh sang danh sach ke

// vector<pair<int,int>> edge; Dung cho ma tran ke sang danh sach canh
// int a[1000][1000];

// int a[1000][1000]; Dung cho ma tran ke sang danh sach ke
// vector<int> adj[1000];

// int a[1000][1000]; Dung cho danh sach ke sang ma tran ke

// vector<pair<int,int>> edge; Dung cho danh sach ke sang danh sach canh
int n; int m;
vector<int> adj[1000];
bool visited[1000];

void input() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
}
void DFS(int u) {
    cout << u << " ";
    visited[u] = true; //danh dau la da duyet
    for (int v: adj[u]) {
        if (visited[v] == false)  { //neu dinh chua duoc duyet thi goi toi 
            DFS(v);
        }
    }
}


int main() {
    /*Danh sach canh sang ma tran ke*/
    // cin >> n >> m;
    // for (int i = 0; i < n; i++) {
    //     int x,y; cin >> x >> y;
    //     a[x][y] = a[y][x] = 1;
    // }
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    /*Danh sach canh sang danh sach ke*/
    // cin >> n >> m;
    // for (int i = 0; i < n; i++) {
    //     int x,y; cin >> x >> y;
    //     adj[x].push_back(y);
    //     adj[y].push_back(x);
    // }
    // for (int i = 1; i <= m; i++) {
    //     cout << i << ": ";
    //     for (int x: adj[i]) {
    //         cout << x << " ";
    //     }
    //     cout << endl;
    // }

    /*Ma tran ke sang danh sach canh*/
    // cin >> n;
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         cin >> a[i][j];
    //     }
    // }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         if (a[i][j] == 1 && i < j) {
    //             edge.push_back({i,j});
    //         }
    //     }
    // }
    // for (auto i: edge) {
    //     cout << i.first << " " <<  i.second << endl;
    // }

    /*Ma tran ke sang danh sach ke*/
    // cin >> n;
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         cin >> a[i][j];
    //     }
    // }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         if (a[i][j] == 1) {
    //             adj[i].push_back(j);
    //         }
    //     }
    // }
    // for (int i = 1; i <= n; i++) {
    //     cout << i << ": ";
    //     for (auto j: adj[i]) {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }

    /*Danh sach ke sang ma tran ke*/
    // cin >> n;
    // cin.ignore();
    // for (int i = 1; i <= n; i++) {
    //     string s, num;
    //     getline(cin,s);
    //     stringstream ss(s);
    //     while (ss >> num) {
    //         a[i][stoi(num)] = 1;
    //     }
    // }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    /*Danh sach ke sang danh sach canh*/
    // cin >> n;
    // cin.ignore();
    // for (int i = 1; i <= n; i++) {
    //     string s, num;
    //     getline(cin,s);
    //     stringstream ss(s);
    //     while (ss >> num) {
    //         if (stoi(num) > i) {
    //             edge.push_back({i, stoi(num)});
    //         }
    //     }
    // }
    // for (auto i: edge) {
    //     cout << i.first << " " <<  i.second << endl;
    // }

    /*DFS voi input danh sach ke*/
    input();
    DFS(3);
}