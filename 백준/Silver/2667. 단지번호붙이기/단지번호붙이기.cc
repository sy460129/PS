#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int arr[26][26];
bool visited[26][26];
int house, n;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
void dfs(int x, int y) {
	visited[x][y] = 1;
	house++;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx<0 || nx>n || ny<0 || ny>n) {
			continue;
		}
		if (arr[nx][ny] == 1 && visited[nx][ny] == 0) {
			dfs(nx, ny);
		}
	}
}
int main() {
	vector<int>v;
	string t;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t;
		for (int j = 0; j < n; j++) {
			arr[i][j] = t[j] - '0';
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1 && visited[i][j] == 0) {
				house = 0;
				dfs(i, j);
				v.push_back(house);
			}
		}
	}
	sort(v.begin(), v.end());
	cout << v.size() << "\n";
	for (auto& e : v) {
		cout << e << "\n";
	}
}