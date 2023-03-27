#include<iostream>
#include<queue>
#include<tuple>
using namespace std;
int dx[] = { 1,-1,0,0,2,2,-2,-2,1,1,-1,-1 };
int dy[] = { 0,0,1,-1,1,-1,1,-1,2,-2,2,-2 };
int w, h, n;
int arr[201][201];
int dp[201][201];
bool visit[201][201][31];
bool check;
queue<tuple<int, int, int>>q;
void bfs() {
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		for (int i = 0; i < 12; i++) {
			int nx = get<0>(cur) + dx[i];
			int ny = get<1>(cur) + dy[i];
			int c = get<2>(cur);
			if (nx<1 || ny<1 || nx>h || ny>w) {
				continue;
			}
			if (i >= 4) {
				if (arr[nx][ny] == 0 && !visit[nx][ny][c + 1]) {
					if (c < n) {
						visit[nx][ny][c + 1] = true;
						dp[nx][ny] = dp[get<0>(cur)][get<1>(cur)] + 1;
						q.push({ nx,ny,c + 1 });
					}
				}
			}
			else {
				if (arr[nx][ny] == 0 && !visit[nx][ny][c]) {
					dp[nx][ny] = dp[get<0>(cur)][get<1>(cur)] + 1;
					visit[nx][ny][c] = true;
					q.push({ nx,ny,c });
				}
			}
			if (dp[h][w] != 0) {
				while (!q.empty()) {
					q.pop();
				}
			}
		}
	}
}
int main() {
	cin >> n >> w >> h;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			cin >> arr[i][j];
		}
	}
	q.push({ 1,1,0 });
	visit[1][1][0] = true;
	if (w == 1 && h == 1) {
		cout << 0 << "\n";
		return 0;
	}
	bfs();
	if (dp[h][w] != 0) {
		cout << dp[h][w] << "\n";
	}
	else {
		cout << -1 << "\n";
	}
}