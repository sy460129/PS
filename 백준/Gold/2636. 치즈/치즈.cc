#include<iostream>
#include<queue>
using namespace std;
int arr[101][101];
bool check[101][101];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int n, m;
queue<pair<int, int>>q;
void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		check[x][y] = true;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<0 || ny<0 || nx>n - 1 || ny>m - 1) {
				continue;
			}
			if (arr[nx][ny] == 0 && check[nx][ny] == false) {
				q.push({ nx,ny });
			}
			else if (arr[nx][ny] == 1) {
				arr[nx][ny] = 0;
			}
			check[nx][ny] = true;
		}
	}
}
int main() {
	int  ghlttn = 0, res = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	while (1) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == 1) {
					cnt++;
				}
				check[i][j] = false;
			}
		}
		if (cnt != 0) {
			ghlttn++;
			res = cnt;
			q.push({ 0,0 });
			bfs();
		}
		else {
			break;
		}
	}
	cout << ghlttn << "\n" << res << "\n";
}