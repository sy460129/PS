#include<iostream>
using namespace std;
int main() {
    int n, c = 1;
	cin >> n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            c = n / i;
            break;
        }
    }
    cout << n - c;
}