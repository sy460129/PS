#include <iostream>
using namespace std;
int gcd(int a, int b) {
    int c;
    while (b) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}
int main() {
    int t, a, b;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        cout << lcm(a, b) << ' ' << gcd(a, b) << "\n";
    }
}