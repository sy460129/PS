#include<iostream>
#include<cstring>
using namespace std;
int dp[100001][2];
int arr[100001][2];
int main() {
	int n, t, x;
	cin >> t;
	while (t--) {
		int a = 2;
		cin >> n;
		memset(dp, 0, sizeof(dp));
		memset(arr, 0, sizeof(arr));
		while (a--) {
			for (int i = 0; i < n; i++) {
				cin >> arr[i][a];
			}
		}
		dp[0][0] = arr[0][0];
		dp[0][1] = arr[0][1];
		dp[1][0] = dp[0][1] + arr[1][0];
		dp[1][1] = dp[0][0] + arr[1][1];
		for (int i = 2; i < n; i++) {
			dp[i][0] = max(dp[i - 1][1], max(dp[i - 2][0], dp[i - 2][1])) + arr[i][0];
			dp[i][1] = max(dp[i - 1][0], max(dp[i - 2][0], dp[i - 2][1])) + arr[i][1];
		}
		cout << max(dp[n - 1][0], dp[n - 1][1]) << "\n";
	}
}