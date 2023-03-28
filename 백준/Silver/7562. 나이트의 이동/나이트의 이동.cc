#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int dx[] = { 1,1,-1,-1,2,2,-2,-2 };
int dy[] = { 2,-2,2,-2,1,-1,1,-1 };
int visit[301][301];
int dp[301][301];
bool c;
queue<pair<int, int>>q;
queue<pair<int, int>>que;
int n, t, sx, sy, ex, ey;
void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (x == ex && y == ey) {
				q = que;
				c = true;
			}
			if (nx < 0 || ny < 0 || nx>n - 1 || ny>n - 1 || visit[nx][ny] == 1) {
				continue;
			}
			else {
				if (!c) {
					dp[nx][ny] = dp[x][y] + 1;
					visit[nx][ny] = 1;
					q.push({ nx,ny });
				}
			}
		}
	}
}
int main() {
	cin >> t;
	while (t--) {
		c = false;
		cin >> n >> sx >> sy >> ex >> ey;
		memset(dp, 0, sizeof(dp));
		memset(visit, 0, sizeof(visit));
		visit[sx][sy] = 1;
		q.push({ sx, sy });
		bfs();
		cout << dp[ex][ey] << "\n";
	}
}