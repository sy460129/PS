#include<iostream>
#include<queue>
using namespace std;
int arr[301][301];
bool check[301][301];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int n, m;
queue<int>q;
void dfs(int x, int y) {
	int t = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx<0 || ny<0 || nx>m || ny>n) {
			continue;
		}
		if (arr[nx][ny] == 0) {
			t ++;
		}
	}
	q.push(t);
}
void dfs_check(int x, int y) {
	check[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx<0 || ny<0 || nx>m || ny>n) {
			continue;
		}
		if (arr[nx][ny] != 0 && check[nx][ny] == false) {
			dfs_check(nx, ny);
		}
	}
}
int main() {
	int year = 0;
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	while (1) {
		year++;
		int cnt = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] != 0) {
					dfs(i, j);
				}
			}
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] != 0) {
					arr[i][j] -= q.front();
					q.pop();
					if (arr[i][j] < 0) {
						arr[i][j] = 0;
					}
				}
			}
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] != 0 && check[i][j]==false) {
					cnt++;
					dfs_check(i, j);
				}
			}
		}
		if (cnt >= 2) {
			cout << year;
			return 0;
		}
		else if (cnt == 0) {
			cout << 0;
			return 0;
		}
		else {
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					check[i][j] = false;
				}
			}
		}
	}
}