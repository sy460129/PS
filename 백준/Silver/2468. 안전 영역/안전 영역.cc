#include<iostream>
#include<queue>
using namespace std;
int arr[101][101];
int check[101][101];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int n, cnt = 0;
queue<pair<int, int>>q;
void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<0 || nx>n - 1 || ny<0 || ny>n - 1) {
				continue;
			}
			if (arr[nx][ny] >= cnt && check[nx][ny] == false) {
				check[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}
}
int main() {
	int ma, res = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	while (1) {
		cnt++;
		ma = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] >=cnt && check[i][j] == false) {
					q.push({ i,j });
					check[i][j] = true;
					bfs();
					ma++;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				check[i][j] = false;
			}
		}
		if (ma == 0) {
			break;
		}
		res = max(res, ma);
	}
	cout << res << "\n";
}