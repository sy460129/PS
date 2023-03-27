#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
long long dp[10000001];
int main() {
	dp[1] = 1;
	int n;
	string s;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] * i;
		while (dp[i] % 10 == 0) {
			dp[i] /= 10;
		}
		dp[i] %= 1000000000000;
	}
	for (int i = 0; i < 5; i++) {
		s += to_string(dp[n] % 10);
		dp[n] /= 10;
	}
	reverse(s.begin(), s.end());
	cout << s;
}