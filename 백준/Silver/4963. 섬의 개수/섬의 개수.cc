#include<iostream>
#include<queue>
using namespace std;
int arr[51][51];
int check[51][51];
int dx[] = { 1,-1,0,0,1,1,-1,-1 };
int dy[] = { 0,0,1,-1,1,-1,1,-1 };
int n, m, cnt;
queue<pair<int, int>>q;
void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<0 || nx>n - 1 || ny<0 || ny>m - 1) {
				continue;
			}
			if (arr[nx][ny] == 1 && check[nx][ny] == false) {
				check[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}
}
int main() {
	while (1) {
		cnt = 0;
		cin >> m >> n;
		if (n == 0 && m == 0) {
			break;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> arr[i][j];
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == 1 && check[i][j] == false) {
					q.push({ i,j });
					check[i][j] = true;
					bfs();
					cnt++;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				check[i][j] = false;
			}
		}
		cout << cnt << "\n";
	}
}