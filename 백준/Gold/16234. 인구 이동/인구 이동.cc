#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int n, l, r, cnt = 0;
int arr[51][51];
int brr[51][51];
bool visit[51][51];
bool c;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
queue<pair<int, int>>q;
vector<pair<int, int>>v;
void bfs() {
	int sum = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		v.push_back({ x,y });
		sum += arr[x][y];
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<0 || ny<0 || nx>n - 1 || ny>n - 1) {
				continue;
			}
			if (abs(arr[x][y] - arr[nx][ny]) >= l && abs(arr[x][y] - arr[nx][ny]) <= r && visit[nx][ny] == false) {
				visit[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}
	sum /= v.size();
	for (int i = 0; i < v.size(); i++) {
		arr[v[i].first][v[i].second] = sum;
	}
	v.clear();
}
int main() {
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			brr[i][j] = arr[i][j];
		}
	}
	while (1) {
		c = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visit[i][j]) {
					visit[i][j] = true;
					q.push({ i,j });
					bfs();
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				visit[i][j] = false;
				if (arr[i][j] != brr[i][j]) {
					brr[i][j] = arr[i][j];
					c = true;
				}
			}
		}
		if (!c) {
			break;
		}
		cnt++;
	}
	cout << cnt;
}