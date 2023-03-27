#include<iostream>
using namespace std;
int arr[501][501];
bool check[501][501];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int n, m, k, res, t = 0, cnt = 0;
void dfs(int x, int y) {
	res++;
	check[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx<0 || ny<0 || nx>n-1 || ny>m-1) {
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
				res = 0;
				dfs(i, j);
				cnt++;
				t = max(res, t);
			}
		}
	}
	cout << cnt << "\n" << t;
}