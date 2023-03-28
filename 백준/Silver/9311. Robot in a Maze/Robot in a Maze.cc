#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
char arr[16][16];
int dp[16][16];
bool visit[16][16];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int n, m;
queue<pair<int, int>>q;
queue<pair<int, int>>que;
int bfs() {
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
			if ((arr[nx][ny] == '0' || arr[nx][ny] == 'O') && visit[nx][ny] == false) {
				visit[nx][ny] = true;
				dp[nx][ny] = dp[x][y] + 1;
				q.push({ nx,ny });
			}
			if (arr[nx][ny] == 'G') {
				return dp[x][y] + 1;
			}
		}
	}
	return -1;
}
int main() {
	int t;
	string s;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> s;
			for (int j = 0; j < m; j++) {
				arr[i][j] = s[j];
				if (arr[i][j] == 'S') {
					visit[i][j] = true;
					q.push({ i,j });
				}
			}
		}
		int res = bfs();
		if (res == -1) {
			cout << "No Exit\n";
		}
		else {
			cout << "Shortest Path: " << res << "\n";
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				visit[i][j] = false;
			}
		}
		q = que;
		memset(arr, 'X', sizeof(arr));
	}
}