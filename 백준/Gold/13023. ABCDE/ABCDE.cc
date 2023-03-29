#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>>v;
bool visited[2001];
void dfs(int num, int cnt) {
	if (cnt >= 4) {
		cout << 1 << "\n";
		exit(0);
	}
	for (int i = 0; i < v[num].size(); i++) {
		if (!visited[v[num][i]]) {
			visited[num] = true;
			dfs(v[num][i], cnt + 1);
			visited[num] = false;
		}
	}
}
int main() {
	int n, m, a, b;
	cin >> n >> m;
	v.resize(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 0; i < v.size(); i++) {
		dfs(i, 0);
	}
	cout << 0 << "\n";
}