#include<iostream>
using namespace std;
int dp[1001][2];
int arr[1001];
int main() {
	int n, t = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		int m = 0;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]){
				m = max(m, dp[j][0]);
			}
		}
		dp[i][0] = m + 1;
	}
	for (int i = n - 1; i >= 0; i--) {
		int m = 0;
		for (int j = n - 1; j > i; j--) {
			if (arr[i] > arr[j]) {
				m = max(m, dp[j][1]);
			}
		}
		dp[i][1] = m + 1;
	}
	for (int i = 0; i < n; i++) {
		t = max(t, dp[i][0] + dp[i][1] - 1);
	}
	cout << t;
}