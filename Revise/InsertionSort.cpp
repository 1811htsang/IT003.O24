#include <bits/stdc++.h>
using namespace std;

void nhap(int a[], int &n) {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
}

void xuat(int a[], int n) {
    cout << endl;
    for (int i = 0; i < n; i++) cout << a[i] << " ";
}

void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int hold = a[i];
        int j = i - 1;
        for (j;j >= 0 && a[j] >= hold; j--) {
            a[j + 1] = a[j];
        }
        a[j + 1] = hold;
    }
}

int main() {
    int n;
    int a[n];
    nhap(a,n);
    xuat(a,n);
    insertionSort(a,n);
    xuat(a,n);
}