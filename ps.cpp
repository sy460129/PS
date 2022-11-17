#include <iostream>
#include <cstring>
using namespace std;
int dp[3001];
int n, t;
bool check;
void str(string s) {
    string c;
    int x, y = 0;
    while (s!="1") {
        for (int i = 0; i < s.length(); i++) {
            if (!check && s[i] - '0' == 0) continue;
            check = true;
            x = s[i] - '0' + y;
            if (x % 2 == 0) {
                y = 0;
                c += ((x / 2) + '0');
            }
            else {
                y = 10;
                c += ((x / 2) + '0');
            }
        }
        t++;
        s = c;
        c.clear();
        check = false;
    }
    t++;
}
int main() {
    string s;
    cin >> n >> s;
    for (int i = 2; i <= n; i++) {
        i % 2 == 0 ? dp[i] = (dp[i - 1] * 2 + 1) % 1000000007 : dp[i] = (dp[i - 1] * 2) % 1000000007;
    }
    str(s);
    if (n % 2 == 0) {
        t % 2 != 0 ? cout << dp[n] : cout << dp[n] - 1;
    }
    else {
        t % 2 != 0 ? cout << dp[n] : cout << dp[n] + 1;
    }
}