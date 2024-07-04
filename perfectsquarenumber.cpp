#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    float base_guess = log10(n);
    float previous_guess;
    float current_guess;
    do {
        previous_guess = base_guess;
        current_guess = (previous_guess + n/previous_guess) / 2;
        base_guess = current_guess;
    } while (abs(current_guess - previous_guess) > 0.00001);
    if (current_guess - (int)current_guess == 0) {
        cout << "Perfect square number" << endl;
    } else {
        cout << "Not a perfect square number" << endl;
    }
}