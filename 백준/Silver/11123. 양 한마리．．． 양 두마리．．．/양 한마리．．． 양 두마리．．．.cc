#include<iostream>
using namespace std;
int arr[101][101];
bool check[101][101];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int n, m, cnt;
void dfs(int x, int y) {
	check[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx<0 || nx>n || ny<0 || ny>m) {
			continue;
		}
		if (arr[nx][ny] == 1 && check[nx][ny] == false) {
			dfs(nx, ny);
		}
	}
}
int main() {
	string s;
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		cnt = 0;
		for (int i = 0; i < n; i++) {
			cin >> s;
			for (int j = 0; j < m; j++) {
				if (s[j] == '.') {
					arr[i][j] = 0;
				}
				else {
					arr[i][j] = 1;
				}
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
		cout << cnt << "\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				arr[i][j] = 0;
				check[i][j]=false;
			}
		}
	}
}