#include <iostream>
using namespace std;
int dp[6];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string s;
	dp[0] = 1;
	for (int i = 1; i <= 5; i++) dp[i] = i * dp[i - 1];
	while(1) {
		int ans = 0, n = 1;
		cin >> s;
		if (s == "0") break;
		for (int i = s.length() - 1; i >= 0; i--) {
			ans += dp[n] * (s[i] - '0');
			n++;
		}
		cout << ans << "\n";
	}
}
