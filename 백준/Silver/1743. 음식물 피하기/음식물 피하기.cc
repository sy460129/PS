#include<iostream>
using namespace std;
char arr[101][101];
bool check[101][101];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int n, m, k, res, t = 0;
void dfs(int x, int y) {
	res++;
	check[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx<1 || ny<1 || nx>n || ny>m) {
			continue;
		}
		if (arr[nx][ny] == '#' && check[nx][ny] == false) {
			dfs(nx, ny);
		}
	}
}
int main() {
	int a, b;
	cin >> n >> m >> k;
	while (k--) {
		cin >> a >> b;
		arr[a][b] = '#';
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (arr[i][j] != '#') {
				arr[i][j] = '.';
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (arr[i][j] == '#' && check[i][j] == false) {
				res = 0;
				dfs(i, j);
				t = max(res, t);
			}
		}
	}
	cout << t;
}