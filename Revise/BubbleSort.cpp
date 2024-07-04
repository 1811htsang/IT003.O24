#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int a[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] >= a[j]) {
                swap(a[i], a[j]);
            }
        }
    }
}

void input(int a[], int &n) {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
}

void output(int a[], int n) {
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << "\n";
}

int main() {
    int n;
    int a[n];
    input(a,n);
    output(a,n);
    bubbleSort(a,n);
    output(a,n);
}