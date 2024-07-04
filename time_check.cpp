#include <iostream>
using namespace std;

int i = 0;
int main() {
    while (1) { 
        cout << i << " " ;
        const int flag = 10;
        if (i == flag) break;

        i++;
    }
}