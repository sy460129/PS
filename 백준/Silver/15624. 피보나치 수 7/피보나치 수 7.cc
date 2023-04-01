#include<iostream>
using namespace std;
int dp[10000001];
int main() {
	dp[1] = 1;
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
	}
	cout << dp[n];
}