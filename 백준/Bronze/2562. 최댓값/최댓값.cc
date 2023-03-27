#include <iostream>
using namespace std;
int main() {
    int N[9];
    int x;
    int max = 0;
    for (int i = 0; i < 9; i++) {
        cin >> x;
        N[i] = x;
    }
    max = N[0];
    for (int j = 1; j < 9; j++) {
        if (max < N[j]) {
            max = N[j];
        }
    }
    for (int k = 0; k < 9; k++) {
        if (N[k] == max) {
            cout << N[k] << "\n";
            cout << k + 1;
        }
    }
}