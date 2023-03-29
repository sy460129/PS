#include<iostream>
#include<queue>
#include<tuple>
using namespace std;
int arr[1001][1001];
bool visit[1001][1001][11];
int dp[1001][1001][11];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
queue<tuple<int, int, int>>q;
int n, m, k;
int bfs() {
	int r = 2147483647;
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = get<0>(cur) + dx[i];
			int ny = get<1>(cur) + dy[i];
			int check = get<2>(cur);
			if (nx<0 || ny<0 || nx>n - 1 || ny>m - 1 || visit[nx][ny][check] == true) {
				continue;
			}
			if (arr[nx][ny] == 0) {
				if (nx == n - 1 && ny == m - 1) {
					return dp[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
				}
				dp[nx][ny][check] = dp[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
				visit[nx][ny][check] = true;
				q.push({ nx,ny,check });
			}
			else {
				if (arr[nx][ny] == 1 && check < k) {
					check++;
					dp[nx][ny][check] = dp[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
					visit[nx][ny][get<2>(cur)] = true;
					visit[nx][ny][check] = true;
					q.push({ nx,ny,check });
				}
			}
		}
	}
	return -2;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string s;
	cin >> n >> m >> k;
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
	visit[0][0][0] = true;
	int res = bfs();
	cout << res + 1 << "\n";
}