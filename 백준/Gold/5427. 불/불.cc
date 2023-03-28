#include<iostream>
#include<queue>
using namespace std;
char arr[1001][1001];
int dp[1001][1001];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
queue<pair<int, int>>q;
queue<pair<int, int>>fire;
int n, m, c;
int bfs() {
	c = 0;
	int x, y, wx, wy, wl, ql;
	while (!q.empty()) {
		ql = q.size();
		wl = fire.size();
		while (wl--) {
			wx = fire.front().first;
			wy = fire.front().second;
			fire.pop();
			for (int i = 0; i < 4; i++) {
				int nnx = wx + dx[i];
				int nny = wy + dy[i];
				if (nnx<0 || nny<0 || nnx>n - 1 || nny>m - 1) {
					continue;
				}
				if (arr[nnx][nny] == '.' && dp[nnx][nny] == 0) {
					dp[nnx][nny] = -1;
					fire.push({ nnx,nny });
				}
			}
		}
		while (ql--) {
			x = q.front().first;
			y = q.front().second;
			q.pop();
			if (x == 0 || y == 0 || x == n - 1 || y == m - 1) {
				c = 1;
				return 1;
			}
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx<0 || ny<0 || nx>n - 1 || ny>m - 1) {
					continue;
				}
				if (arr[nx][ny] == '.' && dp[nx][ny] == 0) {
					dp[nx][ny] = dp[x][y] + 1;
					if (nx == 0 || ny == 0 || nx==n-1 || ny==m-1) {
						return dp[nx][ny];
					}
					q.push({ nx,ny });
				}
			}
		}
	}
	return 0;
}
int main() {
	int res;
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		res = 0;
		cin >> m >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> arr[i][j];
				if (arr[i][j] == '*') {
					fire.push({ i,j });
				}
				if (arr[i][j] == '@') {
					q.push({ i,j });
				}
			}
		}
		res = bfs();
		if(res > 0 && c!=1) {
			cout << res + 1 << "\n";
		}
		else if (res == 1 && c==1) {
			cout << res << "\n";
		}
		else {
			cout << "IMPOSSIBLE\n";
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				arr[i][j] = ' ';
				dp[i][j] = 0;
			}
		}
		while (!fire.empty()) {
			fire.pop();
		}
		while (!q.empty()) {
			q.pop();
		}
	}
}