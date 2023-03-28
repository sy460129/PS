#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
char arr[51][51];
int dp[51][51];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int n, m;
queue<pair<int, int>>q;
int bfs() {
	int ma = 0;
	dp[q.front().first][q.front().second] = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<0 || ny<0 || nx>n - 1 || ny>m - 1) {
				continue;
			}
			if (arr[nx][ny] == 'L' && dp[nx][ny] == -1) {
				dp[nx][ny] = dp[x][y] + 1;
				ma = max(ma, dp[nx][ny]);
				q.push({ nx,ny });
			}
		}
	}
	return ma;
}
int main() {
	int res = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 'L') {
				q.push({ i,j });
				memset(dp, -1, sizeof(dp));
				res = max(res, bfs());
			}
		}
	}
	cout << res << "\n";
}