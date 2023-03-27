#include<iostream>
#include<vector>
using namespace std;
int dp[100001];
int main() {
	int n, cnt = 0;
	cin >> n;
	vector<long long>v;
	v.resize(n + 1);
	v[0] = 0;
	dp[0] = 0;
	dp[1] = 1;
	for (long long i = 1; i <=n; i++) {
		v[i] = i * i;
	}
	for (int i = 2; i <=n; i++) {
		dp[i] = dp[i - 1] + 1;
		for (int j = 1; j * j <= i; j++) {
			dp[i] = min(dp[i], dp[i - v[j]] + 1);
		}
	}
	cout << dp[n] << "\n";
}