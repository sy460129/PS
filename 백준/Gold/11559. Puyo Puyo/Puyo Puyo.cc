#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
char arr[12][6];
int visit[12][6];
bool FourCnt = false;
queue <pair<int, int>> q;
vector <pair<int, int>> v;
void bfs() {
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		visit[y][x] = 1;
		v.push_back({ y,x });
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 12 && ny >= 0 && nx < 6 && nx >= 0 && !visit[ny][nx] && arr[y][x] == arr[ny][nx]) {
				q.push({ ny, nx });
			}
		}
	}
}
int main() {
	int cnt = 0;
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> arr[i][j];
		}
	}
	while (1) {
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (arr[i][j] != '.' && visit[i][j] != 1) {
					q.push({ i,j });
					bfs();
				}
				if (v.size() >= 4) {
					FourCnt = true;
					for (int i = 0; i < v.size(); i++) {
						arr[v[i].first][v[i].second] = '.';
					}
				}
				if (v.size() < 4) {
					for (int i = 0; i < v.size(); i++) {
						visit[v[i].first][v[i].second] = 0;
					}
				}
				v.clear();
			}
		}
		if (FourCnt == true) {
			cnt += 1;
		}
		else if (FourCnt == false) {
			break;
		}
		char g;
		for (int j = 0; j < 6; j++) {
			int get = 11;
			for (int i = 11; i >= 0; i--) {
				visit[i][j] = 0;
				if (arr[i][j] != '.') {
					g = arr[i][j];
					arr[i][j] = '.';
					arr[get][j] = g;
					get--;
				}
			}
		}
		FourCnt = false;
	}
	cout << cnt;
}