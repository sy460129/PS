#include<iostream>
#include<queue>
using namespace std;
char arr[51][51];
int dp[51][51];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
queue<pair<int, int>>q;
queue<pair<int, int>>water;
int n, m, a, b;
void bfs() {
	int x, y, wx, wy, wl, ql;
	while (!q.empty()) {
		ql = q.size();
		wl = water.size();
		while (wl--) {
			wx = water.front().first;
			wy = water.front().second;
			water.pop();
			for (int i = 0; i < 4; i++) {
				int nnx = wx + dx[i];
				int nny = wy + dy[i];
				if (nnx<0 || nny<0 || nnx>n - 1 || nny>m - 1) {
					continue;
				}
				if (arr[nnx][nny] == '.' && dp[nnx][nny]==0) {
					dp[nnx][nny] = -1;
					water.push({ nnx,nny });
				}
			}
		}
		while (ql--) {
			x = q.front().first;
			y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx<0 || ny<0 || nx>n - 1 || ny>m - 1) {
					continue;
				}
				if ((arr[nx][ny] == '.' || arr[nx][ny] == 'D') && dp[nx][ny] == 0) {
					dp[nx][ny] = dp[x][y] + 1;
					q.push({ nx,ny });
				}
			}
		}
	}
	if (dp[a][b] != 0) {
		cout << dp[a][b];
	}
	else {
		cout << "KAKTUS";
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == '*') {
				water.push({ i,j });
			}
			if (arr[i][j] == 'S') {
				q.push({ i,j });
			}
			if (arr[i][j] == 'D') {
				a = i;
				b = j;
			}
		}
	}
	bfs();
}