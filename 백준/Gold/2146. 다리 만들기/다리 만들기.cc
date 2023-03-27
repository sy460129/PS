#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int arr[101][101];
int dp[101][101];
queue<pair<int, int>>q;
queue<pair<int, int>>que;
int n, c = 2, t, res, mi = 2147483647;
void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<0 || ny<0 || nx>n - 1 || ny>n - 1) {
				continue;
			}
			if (arr[nx][ny] == 1) {
				arr[nx][ny] = c;
				q.push({ nx,ny });
			}
		}
	}
}
void bfs2() {
	dp[que.front().first][que.front().second] = 0;
	while (!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		que.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<0 || ny<0 || nx>n - 1 || ny>n - 1) {
				continue;
			}
			if (arr[nx][ny] == 0 && dp[nx][ny] == -1) {
				dp[nx][ny] = dp[x][y] + 1;
				que.push({ nx,ny });
			}
			else if (arr[nx][ny] != 0 && arr[nx][ny]!= t) {
				res = dp[x][y];
				mi = min(mi, res);
			}
		}
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1) {
				arr[i][j] = c;
				q.push({ i,j });
				bfs();
				c++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] != 0) {
				t = arr[i][j];
				memset(dp, -1, sizeof(dp));
				if ((i > 0 && j > 0) && (arr[i - 1][j] == 0 || arr[i][j - 1] == 0)) {
					que.push({ i,j });
				}
				else if (i > 0 && arr[i - 1][j] == 0) {
					que.push({ i,j });
				}
				else if (j > 0 && arr[i][j - 1] == 0) {
					que.push({ i,j });
				}
				else {
					if (arr[i + 1][j] == 0 || arr[i][j + 1] == 0) {
						que.push({ i,j });
					}
				}
				if (!que.empty()) {
					bfs2();
				}
			}
		}
	}
	cout << mi << "\n";
}