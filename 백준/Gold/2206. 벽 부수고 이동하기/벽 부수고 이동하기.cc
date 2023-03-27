#include<iostream>
#include<queue>
#include<tuple>
using namespace std;
int arr[1001][1001];
bool visit[1001][1001][2];
int dp[1001][1001][2];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0, 0, 1, -1 };
queue<tuple<int, int, int>>q;
int n, m;
int bfs() {
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = get<0>(cur) + dx[i];
			int ny = get<1>(cur) + dy[i];
			int check = get<2>(cur);
			if (nx<0 || ny<0 || nx>n - 1 || ny>m - 1) {
				continue;
			}
			if (arr[nx][ny] == 0 && visit[nx][ny][check] == false) {
				dp[nx][ny][check] = dp[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
				visit[nx][ny][check] = true;
				q.push({ nx,ny,check });
			}
			else {
				if (check == 0) {
					check = 1;
					dp[nx][ny][check] = dp[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
					visit[nx][ny][check] = true;
					q.push({ nx,ny,check });
				}
			}
		}
	}
	if ((dp[n - 1][m - 1][0]) && (dp[n - 1][m - 1][1])) {
		return min(dp[n-1][m-1][0], dp[n-1][m-1][1]);
	}
	if ((dp[n - 1][m - 1][0]) && !(dp[n - 1][m - 1][1])) {
		return dp[n-1][m-1][0];
	}
	if (!(dp[n - 1][m - 1][0]) && (dp[n - 1][m - 1][1])) {
		return dp[n - 1][m - 1][1];
	}
	else {
		return -1;
	}
}
int main() {
	string s;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			arr[i][j] = s[j] - '0';
		}
	}
	if (n == 1 && m == 1) {
		cout << 1 << "\n";
		return 0;
	}
	q.push({ 0,0,0 });
	int res = bfs();
	if (res == -1) {
		cout << -1 << "\n";
	}
	else {
		cout << res + 1 << "\n";
	}
}