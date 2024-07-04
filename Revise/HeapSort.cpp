#include <bits/stdc++.h>
using namespace std;

void heapify(int a[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < n && a[left] >= a[largest]) {
        largest = left;
    }

    if (right < n && a[right] >= a[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(a[largest], a[i]);
        heapify(a,n,largest);
    }
}

void heapSort(int a[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(a,n,i);
    }
    for (int i = n - 1; i >= 0; i--) {
        swap(a[0], a[i]);
        heapify(a,i,0);
    }
}

void nhap(int a[], int &n) {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
}

void xuat(int a[], int &n) {
    cout << endl;
    for (int i = 0; i < n; i++) cout << a[i] << " ";
}

int main() {
    int n;
    int a[n];
    nhap(a,n);
    xuat(a,n);
    heapSort(a,n);
    xuat(a,n);
}