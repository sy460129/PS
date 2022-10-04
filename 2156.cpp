#include<iostream>
using namespace std;
int dp[10001];
int main() {
	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	dp[0] = arr[0];
	dp[1] = arr[0] + arr[1];
	dp[2] = max(arr[0] + arr[1], max(arr[0]+arr[2], arr[1] + arr[2]));
	for (int i = 3; i < n; i++) {
		dp[i] = max(dp[i - 2], dp[i - 3] + arr[i - 1]) + arr[i];
		dp[i] = max(dp[i], dp[i - 1]);
	}
	cout << dp[n - 1] << "\n";
}