#include <bits/stdc++.h>
using namespace std;

int parameter(char ch) {
    if (ch == 'C') {
        return 4;
    } else if (ch == 'B') {
        return 3;
    } else if (ch == 'R') {
        return 2;
    } else return 1;
}

int main() {
    int n; cin >> n;
    stack<string> st;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        st.push(str);
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        
        if (int(temp[0]) - 48 > int(st.top()[0]) - 48) {
            count++;
        } else if (int(temp[0]) - 48 == int(st.top()[0]) - 48) {
            int chatAdam = parameter(st.top()[1]);
            int chatEva = parameter(temp[1]);
            (chatEva > chatAdam)? count++:count;
        }
        st.pop();
    }
    (count > 0)? cout << 1: cout << 0;
}