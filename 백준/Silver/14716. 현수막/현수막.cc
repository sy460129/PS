#include<iostream>
using namespace std;
int arr[251][251];
int check[251][251];
int dx[] = { 1,-1,0,0,1,1,-1,-1 };
int dy[] = { 0,0,1,-1,1,-1,1,-1 };
int n, m, cnt = 0;
void dfs(int x, int y) {
	check[x][y] = true;
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx<0 || nx>n - 1 || ny<0 || ny>m - 1) {
			continue;
		}
		if (arr[nx][ny] == 1 && check[nx][ny] == false) {
			dfs(nx, ny);
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
			if (arr[i][j] == 1 && check[i][j] == false) {
				cnt++;
				dfs(i, j);
			}
		}
	}
	cout << cnt;
}