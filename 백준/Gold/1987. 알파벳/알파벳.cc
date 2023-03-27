#include<iostream>
#include<queue>
char arr[21][21];
bool check[26];
int dp[21][21];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int n, m, t = 0;
using namespace std;
void dfs(int x, int y, int cnt) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx<0 || ny<0 || nx>n - 1 || ny>m - 1) {
			continue;
		}
		if (check[arr[nx][ny] - 65] == true) {
			if (cnt > t) {
				t = cnt;
			}
			continue;
		}
		else {
			check[arr[nx][ny] - 65] = true;
			dfs(nx, ny, cnt + 1);
			check[arr[nx][ny] - 65] = false;
		}
	}
}
int main() {
	string s;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			arr[i][j] = s[j];
		}
	}
	check[arr[0][0] - 65] = true;
	dfs(0, 0, 1);
	cout << t << "\n";
}