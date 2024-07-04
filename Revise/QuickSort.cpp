#include <bits/stdc++.h>
using namespace std;

int partition(int a[], int left, int right) {
    int pivot = a[right];
    int index = left - 1;
    for (int i = left; i < right; i++) {
        if (a[i] < pivot) {
            index++;
            swap(a[i], a[index]);
        }
    }
    index++;
    swap(a[index], a[right]);
    return index;
}

void quickSortRecursion(int a[], int left, int right) {
    if (left <= right) {
        int mid = partition(a,left,right);
        quickSortRecursion(a,mid + 1, right);
        quickSortRecursion(a,left, mid - 1);
    }
}

void quickSort(int a[], int n) {
    quickSortRecursion(a,0,n-1);
}

void nhap(int a[], int &n) {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
}

void xuat(int a[], int n) {
    cout << endl;
    for (int i = 0; i < n; i++) cout << a[i] << " ";
}

int main() {
    int n;
    int a[n];
    nhap(a,n);
    xuat(a,n);
    quickSort(a,n);
    xuat(a,n);
}