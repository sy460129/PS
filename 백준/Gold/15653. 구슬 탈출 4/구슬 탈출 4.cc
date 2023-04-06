#include <iostream>
#include <queue>
using namespace std;
int n, m, cnt = 0, hx, hy;
char arr[11][11];
bool check[11][11][11][11];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
queue<pair<int,int>>qr, qb;
void bfs() {
	while (!qr.empty()) {
		int t = qr.size();
		cnt++;
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
					cout << cnt << "\n";
					exit(0);
				}
				if (nrx == nbx && nry == nby) {
					if (i == 0) {
						rx > bx ? nbx-- : nrx--;
					}
					else if (i == 1) {
						rx < bx ? nbx++ : nrx++;
					}
					else if (i == 2) {
						ry > by ? nby-- : nry--;
					}
					else {
						ry < by ? nby++ : nry++;
					}
				}
				if (!check[nrx][nry][nbx][nby]) {
					qr.push({ nrx,nry });
					qb.push({ nbx,nby });
					check[nrx][nry][nbx][nby] = true;
				}
			}
		}
	}
}
int main() {
	cin >> n >> m;
	string s;
	for(int i=0; i<n; i++){
		cin >> s;
		for(int j=0; j<m; j++){
			arr[i][j] = s[j];
			if(s[j]=='R'){
				qr.push({i,j});
			}
			else if(s[j]=='B'){
				qb.push({i,j});
			}
			else if(s[j]=='O'){
				hx=i, hy=j;
			}
		}
	}
	check[qr.front().first][qr.front().second][qb.front().first][qb.front().second]=true;
	bfs();
	cout << -1 << "\n";
}