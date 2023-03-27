#include<iostream>
#include<cstring>
using namespace std;
int n, m;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int arr[51][51];
int dp[51][51];
bool visit[51][51];
int res = 0;
int dfs(int x, int y) {
	
	if (visit[x][y]) {
		cout << -1 << "\n";
		exit(0);
	}
	if (dp[x][y] != -1) {
		return dp[x][y];
	}
	dp[x][y] = 0;
	visit[x][y] = true;
	for (int i = 0; i < 4; i++) {
		
		int nx = x + dx[i] * arr[x][y];
		int ny = y + dy[i] * arr[x][y];		
		if (nx < 0 || ny < 0 || nx > n-1 || ny > m-1 || arr[nx][ny] == 0) {
			continue;
		}
		dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1);
	}
	visit[x][y] = false;
	return dp[x][y];
}
int main() {
	string s;
	cin >> n >> m;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j] == 'H') {
				s[j] = 0;
			}
			else {
				arr[i][j] = s[j] - '0';
			}
		}
	}
	cout << dfs(0, 0) + 1 << "\n";
}