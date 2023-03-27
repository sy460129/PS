#include<iostream>
using namespace std;
int arr[501][501];
int dp[501][501];
int main(){
	int n, res = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> arr[i][j];
		}
	}
	dp[0][0] = arr[0][0];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j > 0) {
				dp[i][j] = dp[i - 1][j - 1] + arr[i][j];
			}
			dp[i][j] = max(dp[i][j], dp[i - 1][j] + arr[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		res = max(res, dp[n - 1][i]);
	}
	cout << res;
}