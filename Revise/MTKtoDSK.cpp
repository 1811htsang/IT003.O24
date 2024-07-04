#include<bits/stdc++.h>
using namespace std;

void nhap(int &v, int &e, int** &mtrx) {
    cin >> v >> e;
    mtrx = new int*[v];
    for (int i = 0; i < v; i++) {
        mtrx[i] = new int[v];
        for (int j = 0; j < v; j++) {
            cin >> mtrx[i][j];
        }
    }
}

void biendoi(int v, int e,int** mtrx, vector<int>* &adj) {
    adj = new vector<int>[v];
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            if (mtrx[i][j] == 1) {
                adj[i].push_back(j);
                // adj[j].push_back(i);
            }
        }
    }
}

void printMTK(int v, int e, int** mtrx) {
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            cout << mtrx[i][j] << " ";
        }
        cout << endl;
    }
}

void printDSK(int v, int e, vector<int>* adj) {
    for (int i = 0; i < v; i++) {
        cout << i << ": ";
        for (auto j: adj[i]) {
            cout << j << " ";
        }
        cout << endl;
    }
}


int main() {
    int** a;
    int v,e;
    vector<int>* adj;
    nhap(v,e,a);
    cout << endl;
    printMTK(v,e,a);

    biendoi(v,e,a,adj);
    cout << endl;
    printDSK(v,e,adj);
}