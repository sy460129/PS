#include<iostream>
#include<queue>
using namespace std;
int n, m;
char arr[11][11];
bool check[11][11];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
queue<pair<int, int>>q;
void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		int cnt = 0;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (!check[nx][ny]) {
				cnt++;
			}
		}
		if (cnt >= 3) {
			arr[x][y] = '.';
		}
		q.pop();
	}
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'X') {
				check[i][j] = true;
				q.push({ i,j });
			}
		}
	}
	bfs();
	int a = 11, b = 11, x = -1, y = -1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (arr[i][j] == 'X') {
				a = min(a, i);
				x = max(x, i);
				b = min(b, j);
				y = max(y, j);
			}
		}
	}
	for (int i = a; i <= x; i++) {
		for (int j = b; j <= y; j++) {
			cout << arr[i][j];
		}
		cout << "\n";
	}
}