#include<iostream>
#include<queue>
#include<vector>
using namespace std;
queue<pair<int, int>>q;
vector<pair<int, int>>sheep;
vector<pair<int, int>>wolf;
int n, m;
bool visit[251][251];
int arr[251][251];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<0 || ny<0 || nx>n - 1 || ny>m - 1 || arr[nx][ny] == '#') {
				continue;
			}
			if (arr[nx][ny] == '.' && !visit[nx][ny]) {
				q.push({ nx,ny });
				visit[nx][ny] = true;
			}
			else if (arr[nx][ny] == 'o' && !visit[nx][ny]) {
				q.push({ nx,ny });
				visit[nx][ny] = true;
				sheep.push_back({ nx, ny });
			}
			else if (arr[nx][ny] == 'v' && !visit[nx][ny]) {
				q.push({ nx,ny });
				visit[nx][ny] = true;
				wolf.push_back({ nx,ny });
			}
		}
	}
	if (wolf.size() >= sheep.size()) {
		for (int i = 0; i < sheep.size(); i++) {
			arr[sheep[i].first][sheep[i].second] = '.';
		}
	}
	else {
		for (int i = 0; i < wolf.size(); i++) {
			arr[wolf[i].first][wolf[i].second] = '.';
		}
	}
	sheep.clear();
	wolf.clear();
}
int main() {
	int w = 0, sh = 0;
	cin >> n >> m;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			arr[i][j] = s[j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 'o' && !visit[i][j]) {
				q.push({ i,j });
				sheep.push_back({ i,j });
				visit[i][j] = true;
				bfs();
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 'v') {
				w++;
			}
			else if (arr[i][j] == 'o') {
				sh++;
			}
		}
	}
	cout << sh << " " << w;
}