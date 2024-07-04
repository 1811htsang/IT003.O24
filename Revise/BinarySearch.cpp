#include <bits/stdc++.h>
using namespace std;

void nhap(int a[], int &n, int &x) {
    cin >> x;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
}

bool binarySearch(int a[], int n, int x) {
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] == x) return true;
        else if (a[mid] < x) left = mid + 1;
        else right = mid - 1;
    }
    return false;
}

int main() {
    int n,x;
    int a[n];
    nhap(a,n,x);
    cout << endl;
    cout << binarySearch(a,n,x);
}