#include<iostream>
#include<vector>
using namespace std;
int dp[100001];
int main() {
	vector<int>v;
	int n;
	v.push_back(1);
	for (int i = 2; i <= 12; i++) {
		v.push_back(v.back() * i);
	}
	cin >> n;
	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
		for (int j = 0; j < i; j++) {
			if (i - v[j] < 0) {
				break;
			}
			dp[i] = min(dp[i], dp[i - v[j]] + 1);
		}
	}
	cout << dp[n];
}