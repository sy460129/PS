#include<iostream>
#include<queue>
using namespace std;
int arr[1001][1001];
bool visit[1001][1001];
int dp[1001][1001];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0, 0, 1, -1 };
queue<pair<int, int>>q;
int n, m;
void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<0 || ny<0 || nx>n - 1 || ny>m - 1) {
				continue;
			}
			if (arr[nx][ny] == 1 && visit[nx][ny] == false) {
				dp[nx][ny] = dp[x][y] + 1;
				visit[nx][ny]= true;
				q.push({ nx,ny });
			}
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				q.push({ i,j });
			}
		}
	}
	bfs();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 1 && dp[i][j] == 0) {
				dp[i][j] = -1;
			}
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}
}