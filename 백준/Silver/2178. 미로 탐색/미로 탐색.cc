#include<iostream>
#include<queue>
using namespace std;
int arr[101][101];
int dp[101][101];
int n, m;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
queue<pair<int, int>>q;
void bfs() {
	int x, y;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<0 || ny<0 || nx>n - 1 || ny>m - 1) {
				continue;
			}
			if (arr[nx][ny] == 1 && dp[nx][ny] == 0) {
				dp[nx][ny] = dp[x][y] + 1;
				q.push({ nx,ny });
			}
		}
	}
	cout << dp[n - 1][m - 1] + 1;
}
int main() {
	cin >> n >> m;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			arr[i][j] = s[j] - '0';
		}
	}
	q.push({ 0,0 });
	bfs();
}