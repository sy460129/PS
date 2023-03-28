#include<iostream>
#include<queue>
#include<tuple>
using namespace std;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int n;
int arr[51][51];
bool visit[51][51][51];
typedef tuple<int, int, int> t;
priority_queue<t, vector<t>, greater<t>>q;
void bfs() {
	while (!q.empty()) {
		auto cur = q.top();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int c = get<0>(cur);
			int nx = get<1>(cur) + dx[i];
			int ny = get<2>(cur) + dy[i];
			if (nx<1 || ny<1 || nx>n || ny>n) {
				continue;
			}
			if (arr[nx][ny] == 1 && !visit[nx][ny][c]) {
				visit[nx][ny][c] = true;
				q.push({ c,nx,ny });
			}
			else if (arr[nx][ny] == 0 && !visit[nx][ny][c]) {
				c++;
				visit[nx][ny][c] = true;
				q.push({ c, nx, ny });
			}
			if (nx == n && ny == n) {
				cout << c << "\n";
				exit(0);
			}
		}
	}
}
int main() {
	cin >> n;
	string s;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		for (int j = 1; j <= n; j++) {
			arr[i][j] = s[j - 1] - '0';
		}
	}
	if (arr[1][1] == 1) {
		q.push({ 0,1,1 });
		visit[1][1][0] = true;
	}
	else {
		q.push({ 1,1,1 });
		visit[1][1][1] = true;
	}
	bfs();
}