#include<iostream>
using namespace std;
int n;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int arr[501][501];
int dp[501][501];
int dfs(int x, int y) {
	if (dp[x][y]) {
		return dp[x][y];
	}
	dp[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx<0 || ny<0 || nx>n - 1 || ny>n - 1) {
			continue;
		}
		if (arr[nx][ny] > arr[x][y]) {
			dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1);
		}
	}
	return dp[x][y];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	int ma = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ma = max(dfs(i, j), ma);
		}
	}
	cout << ma << "\n";
}