#include<iostream>
using namespace std;
int arr[51][51];
bool check[51][51];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int n, m, k;
void dfs(int x, int y) {
	check[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx<0 || ny<0 || nx>m - 1 || ny>n - 1) {
			continue;
		}
		if (arr[nx][ny] == 1 && check[nx][ny] == false) {
			dfs(nx, ny);
		}
	}
}
int main() {
	int a, b, c;
	cin >> c;
	while (c--) {
		int bug = 0;
		cin >> m >> n >> k;
		for (int i = 0; i < k; i++) {
			cin >> a >> b;
			arr[a][b] = 1;
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] == 1 && check[i][j] == false) {
					dfs(i, j);
					bug++;
				}
			}
		}
		cout << bug << "\n";
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				arr[i][j] = 0;
				check[i][j] = false;
			}
		}
	}
}