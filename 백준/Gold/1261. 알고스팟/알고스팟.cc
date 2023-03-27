#include<iostream>
#include<queue>
#include<tuple>
using namespace std;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int n, m;
char arr[101][101];
bool visit[101][101];
typedef tuple<int, int, int>t;
priority_queue<t, vector<t>, greater<t>>q;
void bfs() {
	while (!q.empty()) {
		auto cur = q.top();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int c = get<0>(cur);
			int nx = get<1>(cur) + dx[i];
			int ny = get<2>(cur) + dy[i];
			if (get<1>(cur) == n && get<2>(cur) == m) {
				cout << c << "\n";
				exit(0);
			}
			if (nx<1 || ny<1 || nx>n || ny>m) {
				continue;
			}
			if (!visit[nx][ny]) {
				if (arr[nx][ny] == '0') {
					q.push({ c,nx,ny });
				}
				else {
					q.push({ c + 1, nx, ny });
				}
				visit[nx][ny] = true;
			}
		}
	}
}
int main() {
	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}
	q.push({ 0,1,1 });
	visit[1][1] = true;
	bfs();
}