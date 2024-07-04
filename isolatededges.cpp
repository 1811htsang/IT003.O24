#include<bits/stdc++.h>
using namespace std;

int a[1000][1000];
int main() {
    int vertice, edge;
    cin >> vertice >> edge;
    
    for (int i = 0; i < edge; i++) {
        int x, y;cin >> x >> y;
        a[x][y] = a[y][x] = 1;
    }
    // for (int i = 0; i < vertice; i++) {
    //     for (int j = 0; j < vertice; j++) {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    int count = 0;
    for (int x = 0; x < vertice; x++) {
        int sum = 0;
        for (int y = 0; y < vertice; y++) {
            sum += a[x][y];
        }
        if (sum == 0) count++;
        else continue;
    }
    cout << count;
}