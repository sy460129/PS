#include<iostream>
#include<queue>
using namespace std;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
bool visit[31][31];
bool check;
int n, m, t, a, b;
int arr[31][31];
int brr[31][31];
queue<pair<int, int>>q;
void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<0 || ny<0 || nx>n - 1 || ny>m - 1 || visit[nx][ny]) continue;
			else if (arr[nx][ny] == arr[a][b]) {
				visit[nx][ny] = true;
				arr[nx][ny] = t;
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
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> brr[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] != brr[i][j] && !visit[i][j]) {
				q.push({ i,j });
				t = brr[i][j];
				a = i, b = j;
				visit[i][j] = true;
				bfs();
				check = true;
				arr[i][j] = t;
				break;
			}
		}
		if (check) break;
	}
	if (check) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] != brr[i][j]) {
					cout << "NO\n";
					return 0;
				}
			}
		}
	}
	cout << "YES\n";
}