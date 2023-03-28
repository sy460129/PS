#include<iostream>
using namespace std;
int arr[1001];
int dp[1001];
int main() {
	int n, t = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	dp[0] = arr[0];
	t = dp[0];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[i], dp[j]);
			}
		}
		dp[i] += arr[i];
		t = max(t, dp[i]);
	}
	cout << t;
}