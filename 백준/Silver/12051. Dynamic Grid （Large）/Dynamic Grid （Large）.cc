#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int n, m, a, b, c;
int arr[101][101];
bool check[101][101];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
queue<pair<int, int>>q;
void bfs() {
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<0 || ny<0 || nx>n - 1 || ny>m - 1) {
				continue;
			}
			if (arr[nx][ny] == 1 && !check[nx][ny]) {
				check[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}
}
int main() {
	int t, x, cnt;
	cin >> t;
	for (int k = 1; k <= t; k++) {
		string s;
		char ch;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> s;
			for (int j = 0; j < m; j++) {
				arr[i][j] = s[j] - '0';
			}
		}
		cin >> x;
		cout << "Case #" << k << ":\n";
		while (x--) {
			cin >> ch;
			if (ch == 'Q') {
				cnt = 0;
				for (int i = 0; i <= n; i++) {
					for (int j = 0; j <= m; j++) {
						if (arr[i][j] == 1 && !check[i][j]) {
							check[i][j] = true;
							q.push({ i,j });
							cnt++;
							bfs();
						}
					}
				}
				cout << cnt << "\n";
				memset(check, false, sizeof(check));
			}
			else {
				cin >> a >> b >> c;
				arr[a][b] = c;
			}
		}
		memset(arr, false, sizeof(arr));
	}
}