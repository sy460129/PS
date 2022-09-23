#include<iostream>
using namespace std;
int dp[100001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, t, a, b;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i < n; i++) {
		if (arr[i - 1] > arr[i]) {
			dp[i] = dp[i - 1] + 1;
		}
		else {
			dp[i] = dp[i - 1];
		}
	}
	cin >> t;
	while (t--) {
		cin >> a >> b;
		cout << dp[b - 1] - dp[a - 1] << "\n";
	}
}