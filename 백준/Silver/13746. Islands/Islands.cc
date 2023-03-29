#include<iostream>
#include<queue>
using namespace std;
char arr[51][51];
bool check[51][51];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int n, m;
queue<pair<int, int>>q;
void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny<0 || nx>n-1 || ny>m-1) {
				continue;
			}
			if ((arr[nx][ny] == 'L' || arr[nx][ny] == 'C') && check[nx][ny] == false) {
				check[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int cnt = 0;
	string s;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			arr[i][j] = s[j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 'L' && check[i][j] == false) {
				check[i][j] = true;
				q.push({ i,j });
				bfs();
				cnt++;
			}
		}
	}
	cout << cnt;
}