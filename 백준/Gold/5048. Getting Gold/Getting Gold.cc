#include<iostream>
#include<queue>
using namespace std;
queue<pair<int, int>>q;
queue<pair<int, int>>q2;
int w, h, cnt = 0;
char arr[51][51];
bool check, c;
bool visit[51][51];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			c = false;
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<0 || ny<0 || nx>h - 1 || ny >w - 1) {
				continue;
			}
			if (arr[nx][ny] == 'T') {
				c = true;
				break;
			}
		}
		if (!c) {
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx<0 || ny<0 || nx>h - 1 || ny >w - 1) {
					continue;
				}
				if (arr[nx][ny] == '.' && !visit[nx][ny]) {
					visit[nx][ny] = true;
					q.push({ nx,ny });
				}
				else if (arr[nx][ny] == 'G' && !visit[nx][ny]) {
					q.push({ nx,ny });
					visit[nx][ny] = true;
					cnt++;
				}
			}
		}
	}
}
int main() {
	cin >> w >> h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'P') {
				q.push({ i,j });
				visit[i][j] = true;
			}
		}
	}
	bfs();
	cout << cnt << "\n";
}