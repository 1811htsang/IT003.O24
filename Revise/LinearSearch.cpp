#include <bits/stdc++.h>
using namespace std;

void nhap(int a[], int &n, int &x) {
    cin >> x;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
} 

bool linearSearch(int a[], int n, int x) {
    for (int i = 0; i < n; i++) 
        if (a[i] == x) {
            return true;
            break;
        }
    return false;   
}

int main() {
    int n,x;
    int a[n];
    nhap(a,n,x);
    cout << endl;
    cout << linearSearch(a,n,x);
}