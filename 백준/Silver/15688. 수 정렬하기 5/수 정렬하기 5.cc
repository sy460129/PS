#include<iostream>
#include<algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int* p = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    sort(p, p + n);
    for (int i = 0; i < n; i++) {
        cout << p[i] << "\n";
    }
}