#include <bits/stdc++.h>
using namespace std;

typedef struct {
    float x,y,z;
} diem;

int main() {
    int n; cin >> n;
    diem arr_n[100];
    for (int i = 0; i < n; i++){
        cin >> arr_n[i].x >> arr_n[i].y >> arr_n[i].z;
    }

    int m; cin >> m;
    diem arr_m[100];
    for (int i = 0; i < m; i++){
        cin >> arr_m[i].x >> arr_m[i].y >> arr_m[i].z;
    }

    // for (int i = 0; i < n; i++){
    //     cout << arr_n[i].x << " " << arr_n[i].y << " " << arr_n[i].z << '\n';
    // }
    // for (int i = 0; i < m; i++) {
    //     cout << arr_m[i].x << " " << arr_m[i].y << " " << arr_m[i].z << '\n';
    // }

    for (int i = 0; i < m; i++) {
        diem p = arr_m[i];
        int l = 0, r = n - 1;
        int count = 0;
        while (l <= r) {
            count++;
            int mid = l + (r - l) / 2;
            if (arr_n[mid].x == p.x && arr_n[mid].y == p.y && arr_n[mid].z == p.z) {
                cout << count << '\n';
                break;
            } 
            else if (arr_n[mid].x < p.x || (arr_n[mid].x == p.x && arr_n[mid].y < p.y) || (arr_n[mid].x == p.x && arr_n[mid].y == p.y && arr_n[mid].z < p.z) || (arr_n[mid].x < p.x && arr_n[mid].y < p.y && arr_n[mid].z < p.z)) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        if (l > r) cout << "KHONG\n";
    }
}