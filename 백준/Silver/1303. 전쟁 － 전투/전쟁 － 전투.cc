#include<iostream>
#include<queue>
using namespace std;
char arr[101][101];
bool visit[101][101];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int n, m, w, b;
queue<pair<int, int>>q;
void bfsw() {
	while (!q.empty()) {
		w++;
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<1 || ny<1 || nx>n || ny>m) {
				continue;
			}
			if (!visit[nx][ny] && arr[nx][ny] == 'W') {
				q.push({ nx,ny });
				visit[nx][ny] = true;
			}
		}
	}
}
void bfsb() {
	while (!q.empty()) {
		b++;
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<1 || ny<1 || nx>n || ny>m) {
				continue;
			}
			if (arr[nx][ny] == 'B' && !visit[nx][ny]) {
				q.push({ nx,ny });
				visit[nx][ny] = true;
			}
		}
	}
}
int main() {
	int wh = 0, bl = 0;
	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!visit[i][j]) {
				visit[i][j] = true;
				q.push({ i,j });
				if (arr[i][j] == 'W') {
					w = 0;
					bfsw();
					wh += w * w;
				}
				else {
					b = 0;
					bfsb();
					bl += b * b;
				}
			}
		}
	}
	cout << wh << " " << bl << "\n";
}