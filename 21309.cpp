#include<iostream>
#include<queue>
using namespace std;
int arr[1001][1001];
bool check[1001][1001];
bool visit[1001][1001];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int sx[] = { 1,-1,1,-1 };
int sy[] = { -1,1,1,-1 };
queue<pair<int, int>>q;
queue<pair<int, int>>que;
int n, m, cnt = 0, res = 0;
void bfs1() {
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
			if (arr[nx][ny] == 1 && !check[nx][ny]) {
				cnt++;
			}
		}
	}
}
void bfs2() {
	while (!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		que.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + sx[i];
			int ny = y + sy[i];
			if (nx<0 || ny<0 || nx>n - 1 || ny>m - 1) {
				continue;
			}
			if (arr[nx][ny] == 1 && !visit[nx][ny]) {
				res++;
			}
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 1 && !check[i][j]) {
				check[i][j] = true;
				q.push({ i,j });
				bfs1();
			}
			if (arr[i][j] == 1 && !visit[i][j]) {
				visit[i][j] = true;
				que.push({ i,j });
				bfs2();
			}
		}
	}
	cout << cnt << " " << res + cnt << "\n";
}