
#include <iostream>
#include <vector>
using namespace std;

int smallestCommon(vector<int> nums1, vector<int> nums2) {
    int i,j,k;
    i = 0; 
    j = 0;
    
    for (k = 0; k < nums1.size() + nums2.size(); k++) {

    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> nums1;
    vector<int> nums2;

    int val = 0;
    for (auto i = 0; i < n; i++) {
        cin >> val;
        nums1.push_back(val);
    }
    for (auto i = 0; i < m; i++) {
        cin >> val;
        nums2.push_back(val);
    }

    cout << smallestCommon(nums1, nums2) << endl;

    return 0;
}
