#include <bits/stdc++.h>
using namespace std;

void nhap(int a[], int &n) {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
}

void xuat(int a[], int n) {
    for (int i = 0; i < n; i++) cout << a[i] << " ";
}

void selectionSort(int a[], int n) {
    int min_idx;
    for (int i = 0; i < n - 1; i++) {
        min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (a[min_idx] > a[j]) min_idx = j;
        }
        swap(a[i], a[min_idx]);
    }
}

int main() {
    int n;
    int a[n];
    nhap(a,n);
    xuat(a,n);
    cout << endl;
    selectionSort(a,n);
    xuat(a,n);
}