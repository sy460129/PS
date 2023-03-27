#include<iostream>
using namespace std;
int main() {
    int a, b, c, cnt = 1;
    int E = 1, S = 1, M = 1;
    cin >> a >> b >> c;
    while (1) {
        if (a == E && b == S && c == M) {
            cout << cnt << "\n";
            break;
        }
        else {
            cnt++, E++, S++, M++;
            if (E > 15) {
                E = 1;
            }
            if (S > 28) {
                S = 1;
            }
            if (M > 19) {
                M = 1;
            }
        }
    }
}