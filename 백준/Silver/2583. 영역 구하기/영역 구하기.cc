#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, m, k, s;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int arr[101][101];
bool check[101][101];
void dfs(int x, int y) {
	s++;
	check[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx<0 || ny<0 || nx>m || ny>n) {
			continue;
		}
		if (arr[nx][ny] == 1 && check[nx][ny] == false) {
			dfs(nx, ny);
		}
	}
}
int main() {
	vector<int>v;
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = 1;
		}
	}
	int x1, x2, y1, y2;
	while (k--) {
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = x1; i < x2; i++) {
			for (int j = y1; j < y2; j++) {
				arr[i][j] = 0;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1 && check[i][j] == false) {
				s = 0;
				dfs(i, j);
				v.push_back(s);
			}
		}
	}
	sort(v.begin(), v.end());
	cout << v.size() << "\n";
	for (auto& e : v) {
		cout << e << " ";
	}
}