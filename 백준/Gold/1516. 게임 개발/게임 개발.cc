#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int arr[501];
int t[501];
int dp[501];
vector<int>v[501];
queue<int>q;
int main() {
	int n, x, y;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t[i];
		while (1) {
			cin >> y;
			if (y == -1) {
				break;
			}
			else {
				v[y].push_back(i);
				arr[i]++;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (arr[i] == 0) {
			q.push(i);
			dp[i] = t[i];
		}
	}
	while (!q.empty()) {
		int nx = q.front();
		q.pop();
		for (int i = 0; i < v[nx].size(); i++) {
			int next = v[nx][i];
			arr[next]--;
			if (arr[next] == 0) {
				q.push(next);
			}
			if (dp[next] < dp[nx] + t[next]) {
				dp[next] = dp[nx] + t[next];
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << dp[i] << "\n";
	}
}