#include <iostream>
using namespace std;
int k[1001];
int s[1001];
int dp[1001][10001];
int main() {
	int n, t;
	cin >> n >> t;
	for(int i=1; i<=n; i++){
		cin >> k[i] >> s[i];
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=t; j++){
			k[i]>j ? dp[i][j]=dp[i-1][j] : dp[i][j]=max(dp[i-1][j], s[i]+dp[i-1][j-k[i]]);
		}
	}
	cout << dp[n][t];
}