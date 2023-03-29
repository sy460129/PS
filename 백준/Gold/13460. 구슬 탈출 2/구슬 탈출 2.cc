#include<iostream>
#include<queue>
using namespace std;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int n, m, hx, hy, res = 1;
char arr[11][11];
bool visit[11][11][11][11];
queue<pair<int, int>>qr, qb;
void bfs() {
	while (!qr.empty()) {
		int t = qr.size();
		if (res > 10) {
			break;
		}
		while (t--) {
			int rx = qr.front().first;
			int ry = qr.front().second;
			int bx = qb.front().first;
			int by = qb.front().second;
			qr.pop(); qb.pop();
			for (int i = 0; i < 4; i++) {
				int nrx = rx;
				int nry = ry;
				int nbx = bx;
				int nby = by;
				while (1) {
					if (arr[nrx][nry] != '#') {
						nrx += dx[i];
						nry += dy[i];
						if (arr[nrx][nry] == 'O') {
							break;
						}
					}
					else {
						nrx -= dx[i], nry -= dy[i];
						break;
					}
				}
				while (1) {
					if (arr[nbx][nby] != '#') {
						nbx += dx[i];
						nby += dy[i];
						if (arr[nbx][nby] == 'O') {
							break;
						}
					}
					else {
						nbx -= dx[i], nby -= dy[i];
						break;
					}
				}
				if (nbx == hx && nby == hy) {
					continue;
				}
				else if (nrx == hx && nry == hy) {
					cout << res << "\n";
					exit(0);
				}
				if (nrx == nbx && nry == nby) {
					if (i == 0) {
						rx < bx ? nrx-- : nbx--;
					}
					else if (i == 1) {
						rx > bx ? nrx++ : nbx++;
					}
					else if (i == 2) {
						ry < by ? nry-- : nby--;
					}
					else {
						ry > by ? nry++ : nby++;
					}
				}
				if (!visit[nrx][nry][nbx][nby]) {
					qr.push({ nrx,nry });
					qb.push({ nbx,nby });
					visit[nrx][nry][nbx][nby] = true;
				}
			}
		}
		res++;
	}
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'R') {
				qr.push({ i,j });
			}
			else if (arr[i][j] == 'B') {
				qb.push({ i,j });
			}
			else if (arr[i][j] == 'O') {
				hx = i, hy = j;
			}
		}
	}
	visit[qr.front().first][qr.front().second][qb.front().first][qb.front().second] = true;
	bfs();
	cout << -1 << "\n";
}