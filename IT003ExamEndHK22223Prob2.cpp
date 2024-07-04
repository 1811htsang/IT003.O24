#include <bits/stdc++.h>
using namespace std;

struct data_block {
    int value;
    int count = 1;
};
int main() {
    int k; cin >> k;
    int n; cin >> n;
    vector<data_block> data_a(n);
    for (int i = 0; i < n; i++) {
        cin >> data_a[i].value;
    }
    for (int i = data_a.size() - 1; i >= 0; i--) {
        data_block &temp = data_a[i];
        for (int j = i - 1; j >= 0; j--) {
            if (temp.value == data_a[j].value) {
                temp.count++;
                data_a.erase(data_a.begin() + j);
                j--;
            }
        }
    }
    for (int i = data_a.size() - 1; i >= data_a.size() - k; i--) {
        cout << data_a[i].value << " " << data_a[i].count << endl;
    }
}