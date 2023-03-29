#include<iostream>
#include<queue>
using namespace std;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int arr[9][9];
int virus[9][9];
queue<pair<int, int>>q;
queue<pair<int, int>>que;
int n, m, res = 0;
void bfs() {
	int ma = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			virus[i][j] = arr[i][j];
		}
	}
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
			if (virus[nx][ny] == 0) {
				virus[nx][ny] = 2;
				q.push({ nx,ny });
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (virus[i][j] == 0) {
				ma++;
			}
		}
	}
	res = max(res, ma);
}
void block(int cnt) {
	if (cnt == 3) {
		q = que;
		bfs();
	}
	else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == 0) {
					arr[i][j] = 1;
					block(cnt + 1);
					arr[i][j] = 0;
				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				q.push({ i,j });
			}
		}
	}
	que = q;
	block(0);
	cout << res << "\n";
}