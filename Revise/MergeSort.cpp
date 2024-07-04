#include <bits/stdc++.h>
using namespace std;

void merge(int a[], int left, int mid, int right) {
    int temp[right - left + 1];
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right) {
        (a[i] <= a[j])? temp[k] = a[i++]: temp[k] = a[j++];
        k++;
    }

    while (i <= mid) {
        temp[k++] = a[i++];
    }

    while (j <= right) {
        temp[k++] = a[j++];
    }

    for (int i = left; i <= right; i++) {
        a[i] = temp[i-left];
    }
}

void mergeSortRecursion(int a[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortRecursion(a, left, mid);
        mergeSortRecursion(a, mid + 1, right);
        merge(a,left, mid, right);
    }
}

void mergeSort(int a[], int n) {
    mergeSortRecursion(a, 0, n - 1);
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
    mergeSort(a,n);
    xuat(a,n);
}